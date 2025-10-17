# Enhanced Intrinsic Value Analyzer

A Python CLI tool to calculate intrinsic value, fundamental scores, and final verdicts for multiple stocks.  
Supports DCF, DDM, P/E, Book Value methods, margin of safety, and color-coded terminal output.  

---

## Features

- **Intrinsic Value Methods**: DCF, DDM, P/E, Book Value  
- **Fundamental Metrics**: P/E, P/B, EV/EBITDA, ROE, ROA, Net Profit Margin, Debt/Equity, Interest Coverage, FCF  
- **Growth Metrics**: Revenue, EPS, Dividend  
- **Price Rating**: Based on Margin of Safety  
- **Fundamental Score**: Evaluates financial health and quality  
- **Score Breakdown**: Shows which metrics contributed to the fundamental score  
- **Final Verdict**: Combines Price Rating & Fundamental Score  
- **Color-coded terminal output** for easy visualization  
- **CSV Export**: Timestamped file with all metrics  

---

## Installation

1. **Clone or download the repository**  

```bash
git clone https://github.com/Arthovan/Software-Development/Python/Finance/intrinsicValueCalculation
cd intrinsicValueCalculation
```

2. **Create a virtual environment (recommended)**
```bash
python -m venv venv
# Activate virtual environment
source venv/bin/activate   # Linux / Mac
# or
venv\Scripts\activate      # Windows
```

3. **Install dependencies**
```bash
pip install -r requirements.txt
```

For exact reproducibility, install from requirements.lock:
```bash
pip install -r requirements.lock
```
4. **Usage**

Run the script using Python CLI with stock tickers:
```bash
python3 main.py <TICKER1> <TICKER2> <TICKER3> ...
```
**Example:**
```bash
python3 main.py SOUTHBANK.NS IDFCFIRSTB.NS INDUSINDBK.NS
```

* Supports multiple tickers at once.

* Some tickers like ARE&M.NS or PGINVIT-IV.NS may not work due to Yahoo Finance limitations.

**Output**

1. Terminal Table:
    *   Columns: Ticker, Market Price, Avg Intrinsic, MoS (%), Price Rating, Fundamental Score, Final Verdict, Score Breakdown
    *   Color-coded for easy scanning:
        *   Green → Strong Buy
        *   Light Green → Buy
        *   Yellow → Fair
        *   Red → Overvalued

2. CSV Export:

    *   Timestamped file intrinsic_results_YYYYMMDD_HHMMSS.csv

    *   Contains all intrinsic value metrics, fundamental ratios, MoS, ratings, and breakdowns

**Dependencies**

    *   Python 3.10+
    *   yfinance
    *   tabulate
    *   colorama

Install using:
```bash
pip install -r requirements.txt
```