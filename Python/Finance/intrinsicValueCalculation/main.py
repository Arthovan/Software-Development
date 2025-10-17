""" (Installation in python)
How to use: 
    1. Create a virtual environment:                    python -m venv venv
                                                        source venv/bin/activate   # Linux/Mac
                                                        # or
                                                        venv\Scripts\activate      # Windows


    2. Install exact versions from requirements.lock:   pip install -r requirements.lock


This ensures all dependencies, including yfinance’s dependencies, are exactly pinned, so the script behaves identically across machines.

How to run in command line : python3 main.py SOUTHBANK.NS IDFCFIRSTB.NS INDUSINDBK.NS KTKBANK.NS BAJAJHFL.NS BAJFINANCE.NS CIPLA.NS DRREDDY.NS HCLTECH.NS HEROMOTOCO.NS ITC.NS JYOTHYLAB.NS KALYANKJIL.NS MANAPPURAM.NS NATCOPHARM.NS SUNPHARMA.NS TATACHEM.NS TATAINVEST.NS TCS.NS TITAN.NS TRIDENT.NS WIPRO.NS ZYDUSLIFE.NS INFY.NS ITCHOTELS.NS TATACAP.NS TATAMOTORS.NS COSMOFIRST.NS FINCABLES.NS MUTHOOTFIN.NS SPANDANA.NS TECHM.NS TATATECH.NS DIVISLAB.NS TATAPOWER.NS TATASTEEL.NS CDSL.NS NSDL.NS BSE.NS 

Either run for all stocks or only run for selective stocks as per your wish 
ARE&M.NS PGINVIT-IV.NS ARE NOT WORKING
"""

"""
Enhanced Intrinsic Value Analyzer with CLI, Price & Fundamental Analysis
- Intrinsic value methods: DCF, DDM, P/E, Book Value
- Fundamental metrics: P/E, P/B, EV/EBITDA, ROE, ROA, Net Margin, Debt/Equity, Interest Coverage, FCF
- Growth metrics: Revenue, EPS, Dividend
- Price Rating: undervaluation based on intrinsic value vs market price
- Fundamental Score: quality of company fundamentals
- Score Breakdown: shows which metrics contributed to the score
- Final Verdict: combination of Price Rating + Fundamental Score
- Color-coded terminal output
- Timestamped CSV export
"""

# ----------------------------
# Import required libraries
# ----------------------------
import sys, os
from datetime import datetime
import yfinance as yf
from tabulate import tabulate
import csv
from colorama import init, Fore, Style

# Initialize colorama (ensures colors reset automatically after each print)
init(autoreset=True)

# ----------------------------
# Intrinsic Value Methods
# ----------------------------
def intrinsic_value_dcf(free_cash_flows, discount_rate, terminal_growth_rate):
    """Discounted Cash Flow (DCF) method with terminal value"""
    n = len(free_cash_flows)
    pv_fcf = sum([fcf / ((1 + discount_rate) ** (i + 1)) for i, fcf in enumerate(free_cash_flows)])
    terminal_value = free_cash_flows[-1] * (1 + terminal_growth_rate) / (discount_rate - terminal_growth_rate)
    pv_terminal = terminal_value / ((1 + discount_rate) ** n)
    return pv_fcf + pv_terminal

def intrinsic_value_ddm(dividend_next_year, discount_rate, dividend_growth_rate):
    """Dividend Discount Model (DDM)"""
    if discount_rate <= dividend_growth_rate:
        raise ValueError("Discount rate must be greater than dividend growth rate.")
    return dividend_next_year / (discount_rate - dividend_growth_rate)

def intrinsic_value_pe(eps, fair_pe):
    """P/E method"""
    return eps * fair_pe

def intrinsic_value_book(book_value):
    """Book Value method"""
    return book_value

def margin_of_safety(avg_intrinsic, market_price):
    """Margin of Safety in percentage"""
    if avg_intrinsic is None or market_price is None:
        return None
    return ((avg_intrinsic - market_price) / avg_intrinsic) * 100

def price_rating_from_mos(mos):
    """Price Rating based on MoS"""
    if mos is None:
        return "Data N/A"
    if mos >= 10:
        return "Strong Buy"
    elif 0 <= mos < 10:
        return "Buy"
    elif -10 <= mos < 0:
        return "Fair"
    else:
        return "Overvalued"

# ----------------------------
# Color Coding Functions
# ----------------------------
def color_price_rating(rating):
    """Color-code Price Rating"""
    if rating == "Strong Buy":
        return Fore.GREEN + rating + Style.RESET_ALL
    elif rating == "Buy":
        return Fore.LIGHTGREEN_EX + rating + Style.RESET_ALL
    elif rating == "Fair":
        return Fore.YELLOW + rating + Style.RESET_ALL
    elif rating == "Overvalued":
        return Fore.RED + rating + Style.RESET_ALL
    else:
        return rating

def color_fundamental_score(score):
    """Color-code Fundamental Score"""
    if score == "Strong Buy":
        return Fore.GREEN + score + Style.RESET_ALL
    elif score == "Buy":
        return Fore.LIGHTGREEN_EX + score + Style.RESET_ALL
    elif score == "Fair":
        return Fore.YELLOW + score + Style.RESET_ALL
    elif score == "Overvalued":
        return Fore.RED + score + Style.RESET_ALL
    else:
        return score

def final_verdict(price_rating, fundamental_score):
    """Combine Price Rating and Fundamental Score for final verdict"""
    if price_rating == "Strong Buy" and fundamental_score == "Strong Buy":
        return "Strong Buy"
    elif price_rating in ["Strong Buy", "Buy"] and fundamental_score in ["Strong Buy", "Buy"]:
        return "Buy"
    elif price_rating == "Fair" or fundamental_score == "Fair":
        return "Fair"
    else:
        return "Overvalued"

# ----------------------------
# Analyze a single stock
# ----------------------------
def analyze_stock(ticker_symbol, fair_pe=20, discount_rate=0.11, growth_rate=0.04):
    """
    Fetch stock data from Yahoo Finance and calculate:
    - Intrinsic values (DCF, DDM, P/E, Book)
    - Margin of Safety & Price Rating
    - Fundamental Score & Breakdown
    - Final Verdict combining Price & Fundamentals
    """
    ticker = yf.Ticker(ticker_symbol)
    info = ticker.info

    # ----------------------------
    # Basic Market & Financials
    # ----------------------------
    current_price = info.get("currentPrice")
    if current_price is None:
        raise ValueError(f"No market price data for {ticker_symbol}")

    eps = info.get("trailingEps", 0)
    book_value = info.get("bookValue", 0)
    dividend = info.get("dividendRate", 0)
    fcf = info.get("freeCashflow", None)
    shares_outstanding = info.get("sharesOutstanding", None)
    revenue = info.get("totalRevenue", None)
    net_income = info.get("netIncomeToCommon", None)
    total_debt = info.get("totalDebt", None)
    interest_expense = info.get("interestExpense", None)
    ev = info.get("enterpriseValue", None)
    ebitda = info.get("ebitda", None)

    # ----------------------------
    # Fundamental Ratios
    # ----------------------------
    pe_ratio = info.get("trailingPE", None)
    pb_ratio = info.get("priceToBook", None)
    ps_ratio = info.get("priceToSalesTrailing12Months", None)
    ev_ebitda = ev / ebitda if ev and ebitda else None

    roe = info.get("returnOnEquity", None)
    roa = info.get("returnOnAssets", None)
    net_profit_margin = (net_income / revenue * 100) if net_income and revenue else None

    debt_to_equity = total_debt / book_value if total_debt and book_value else None
    interest_coverage = ebitda / interest_expense if ebitda and interest_expense else None

    operating_cf = info.get("operatingCashflow", None)
    ocf_vs_net_income = operating_cf / net_income if operating_cf and net_income else None

    revenue_growth = info.get("revenueGrowth", None)
    eps_growth = info.get("earningsQuarterlyGrowth", None)
    dividend_growth = growth_rate if dividend else None

    # ----------------------------
    # Intrinsic Value Calculations
    # ----------------------------
    dcf_value = None
    if fcf and shares_outstanding:
        fcf_proj = [fcf * (1.06 ** i) for i in range(5)]  # project 5 years
        total_value = intrinsic_value_dcf(fcf_proj, discount_rate, growth_rate)
        dcf_value = total_value / shares_outstanding

    ddm_value = None
    if dividend and dividend > 0:
        ddm_value = intrinsic_value_ddm(dividend * (1 + growth_rate), discount_rate, growth_rate)

    pe_value = intrinsic_value_pe(eps, fair_pe)
    book_val = intrinsic_value_book(book_value)

    intrinsic_values = [v for v in [pe_value, book_val, ddm_value, dcf_value] if v]
    avg_intrinsic = sum(intrinsic_values) / len(intrinsic_values) if intrinsic_values else None

    # ----------------------------
    # Price Rating based on Margin of Safety
    # ----------------------------
    mos = margin_of_safety(avg_intrinsic, current_price)
    price_rating = price_rating_from_mos(mos)

    # ----------------------------
    # Fundamental Score & Breakdown
    # ----------------------------
    score = 0
    score_details = []

    if pe_ratio and pe_ratio < fair_pe:
        score += 1
        score_details.append("Low P/E")
    if pb_ratio and pb_ratio < 1:
        score += 1
        score_details.append("P/B < 1")
    if roe and roe > 0.15:
        score += 1
        score_details.append("ROE > 15%")
    if fcf and fcf > 0:
        score += 1
        score_details.append("Positive FCF")
    if debt_to_equity and debt_to_equity < 1:
        score += 1
        score_details.append("Debt/Equity < 1")

    fundamental_score = "Strong Buy" if score >= 4 else "Buy" if score == 3 else "Fair" if score == 2 else "Overvalued"
    score_breakdown = ", ".join(score_details) if score_details else "No points"

    # ----------------------------
    # Final Verdict combining Price Rating & Fundamentals
    # ----------------------------
    final = final_verdict(price_rating, fundamental_score)

    # ----------------------------
    # Return all metrics as dictionary
    # ----------------------------
    return {
        "Ticker": ticker_symbol,
        "Price": current_price,
        "P/E Value": pe_value,
        "Book Value": book_val,
        "DDM Value": ddm_value,
        "DCF Value": dcf_value,
        "Avg Intrinsic": avg_intrinsic,
        "Margin of Safety (%)": mos,
        "Price Rating": price_rating,
        "Fundamental Score": fundamental_score,
        "Score Breakdown": score_breakdown,
        "Final Verdict": final,
        # Fundamental metrics
        "P/E Ratio": pe_ratio,
        "P/B Ratio": pb_ratio,
        "P/S Ratio": ps_ratio,
        "EV/EBITDA": ev_ebitda,
        "ROE (%)": roe*100 if roe else None,
        "ROA (%)": roa*100 if roa else None,
        "Net Profit Margin (%)": net_profit_margin,
        "Debt/Equity": debt_to_equity,
        "Interest Coverage": interest_coverage,
        "FCF": fcf,
        "OCF vs Net Income": ocf_vs_net_income,
        "Revenue Growth (%)": revenue_growth*100 if revenue_growth else None,
        "EPS Growth (%)": eps_growth*100 if eps_growth else None,
        "Dividend Growth (%)": dividend_growth*100 if dividend_growth else None
    }

# ----------------------------
# CSV Export Function
# ----------------------------
def export_to_csv(results, filename=None):
    """Export analysis results to a CSV file with timestamp"""
    if not results:
        print("No data to export")
        return

    if filename is None:
        timestamp = datetime.now().strftime("%Y%m%d_%H%M%S")
        filename = f"intrinsic_results_{timestamp}.csv"

    fieldnames = list(results[0].keys())
    # Open file in write mode (overwrites if exists)
    with open(filename, mode='w', newline='', encoding='utf-8') as csvfile:
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()
        for data in results:
            writer.writerow(data)
    print(f"\n✅ Results exported to {filename}")

# ----------------------------
# Main CLI Execution
# ----------------------------
if __name__ == "__main__":
    # Check if at least one ticker is provided
    if len(sys.argv) < 2:
        print("Usage: python main.py <TICKER1> [<TICKER2> ...]")
        sys.exit(1)

    tickers = sys.argv[1:]  # List of tickers from command-line
    results = []  # Store analyzed data
    failed_tickers = []  # Track tickers that fail

    # ----------------------------
    # Analyze each ticker
    # ----------------------------
    for symbol in tickers:
        print(f"Fetching data for {symbol}...")
        try:
            data = analyze_stock(symbol)
            results.append(data)
        except Exception as e:
            print(f"⚠️ Error analyzing {symbol}: {e}")
            failed_tickers.append(symbol)

    # ----------------------------
    # Sort results by Margin of Safety (descending)
    # ----------------------------
    results_sorted = sorted(results, key=lambda x: (x['Margin of Safety (%)'] if x['Margin of Safety (%)'] else -999), reverse=True)

    # ----------------------------
    # Display in color-coded table
    # ----------------------------
    if results_sorted:
        table = []
        for r in results_sorted:
            mos_display = f"{r['Margin of Safety (%)']:.1f}%" if r['Margin of Safety (%)'] else "N/A"
            table.append([
                r["Ticker"],
                f"₹{r['Price']:.2f}" if r["Price"] else "N/A",
                f"₹{r['Avg Intrinsic']:.2f}" if r["Avg Intrinsic"] else "N/A",
                mos_display,
                color_price_rating(r["Price Rating"]),
                color_fundamental_score(r["Fundamental Score"]),
                color_fundamental_score(r["Final Verdict"]),
                r["Score Breakdown"]
            ])

        headers = ["Ticker", "Market Price", "Avg Intrinsic", "MoS (%)", "Price Rating",
                   "Fundamental Score", "Final Verdict", "Score Breakdown"]
        print("\n📊 Intrinsic Value, Fundamental Analysis & Final Verdict")
        print(tabulate(table, headers=headers, tablefmt="fancy_grid"))

        # Export to CSV
        export_to_csv(results_sorted)

    # ----------------------------
    # Print failed tickers if any
    # ----------------------------
    if failed_tickers:
        print("\n⚠️ Failed tickers:", ", ".join(failed_tickers))
