import tkinter as tk
from tkinter import ttk, messagebox, filedialog
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
import json
import os
import pandas as pd
#from kiteconnect import KiteConnect

# Zerodha API integration class
'''class ZerodhaIntegration:
    def __init__(self, api_key, api_secret, access_token_file="access_token.txt"):
        self.api_key = api_key
        self.api_secret = api_secret
        self.access_token_file = access_token_file
        self.kite = KiteConnect(api_key=self.api_key)
        self.access_token = None
        self.login_url = None

        # Try loading saved access token
        if os.path.exists(self.access_token_file):
            with open(self.access_token_file, "r") as f:
                self.access_token = f.read().strip()
                self.kite.set_access_token(self.access_token)

    def login(self):
        """Get login URL and manually generate request_token"""
        self.login_url = self.kite.login_url()
        print(f"Login here to generate request_token: {self.login_url}")

    def generate_session(self, request_token):
        """Exchange request_token for access_token (one-time login step)"""
        data = self.kite.generate_session(request_token, api_secret=self.api_secret)
        self.access_token = data["access_token"]
        self.kite.set_access_token(self.access_token)

        # Save token for reuse
        with open(self.access_token_file, "w") as f:
            f.write(self.access_token)

        print("Access Token generated & saved successfully!")

    def get_holdings(self):
        try:
            holdings = self.kite.holdings()
            return holdings
        except Exception as e:
            print(f"Error fetching holdings: {e}")
            return []
'''


class InvestmentTracker:
    def __init__(self, root):
        self.root = root
        self.root.title("Investment Tracker")
        self.root.geometry("850x650")

        # Data storage
        self.investments = {}
        self.data_file = "investments.json"
        self.chart_type = tk.StringVar(value="Pie")

        '''
        # Zerodha API setup (replace with your credentials)
        self.zerodha = ZerodhaIntegration(api_key="your_api_key", api_secret="your_api_secret")
        '''
        # Load previous data if exists
        self.load_data()

        # Input fields
        self.name_label = ttk.Label(root, text="Investment Name:")
        self.name_label.pack(pady=5)
        self.name_entry = ttk.Entry(root)
        self.name_entry.pack(pady=5)

        self.amount_label = ttk.Label(root, text="Amount:")
        self.amount_label.pack(pady=5)
        self.amount_entry = ttk.Entry(root)
        self.amount_entry.pack(pady=5)

        # Buttons
        self.button_frame = ttk.Frame(root)
        self.button_frame.pack(pady=10)

        self.add_button = ttk.Button(self.button_frame, text="Add Investment", command=self.add_investment)
        self.add_button.grid(row=0, column=0, padx=5)

        self.delete_button = ttk.Button(self.button_frame, text="Delete Investment", command=self.delete_investment)
        self.delete_button.grid(row=0, column=1, padx=5)

        self.save_button = ttk.Button(self.button_frame, text="Save Data", command=self.save_data)
        self.save_button.grid(row=0, column=2, padx=5)

        self.load_button = ttk.Button(self.button_frame, text="Load Data", command=self.load_data)
        self.load_button.grid(row=0, column=3, padx=5)

        self.excel_button = ttk.Button(self.button_frame, text="Import Excel", command=self.import_excel)
        self.excel_button.grid(row=0, column=4, padx=5)

        '''
        self.fetch_button = ttk.Button(self.button_frame, text="Fetch from Zerodha", command=self.fetch_from_zerodha)
        self.fetch_button.grid(row=0, column=3, padx=5)
        '''

        # Chart type selection
        self.chart_frame = ttk.Frame(root)
        self.chart_frame.pack(pady=10)


        ttk.Label(self.chart_frame, text="Select Chart Type:").pack(side=tk.LEFT, padx=5)
        chart_options = ["Pie", "Bar", "Line"]
        self.chart_menu = ttk.OptionMenu(self.chart_frame, self.chart_type, self.chart_type.get(), *chart_options, command=lambda _: self.update_chart())
        self.chart_menu.pack(side=tk.LEFT)

        # Matplotlib Figure
        self.fig, self.ax = plt.subplots(figsize=(6,5))
        self.canvas = FigureCanvasTkAgg(self.fig, master=root)
        self.canvas.get_tk_widget().pack(fill=tk.BOTH, expand=True)

        # Initial chart
        self.update_chart()

    def add_investment(self):
        name = self.name_entry.get().strip()
        try:
            amount = float(self.amount_entry.get().strip())
        except ValueError:
            messagebox.showerror("Invalid Input", "Amount must be a number")
            return

        if not name:
            messagebox.showerror("Invalid Input", "Investment name cannot be empty")
            return

        # Add or update investment
        if name in self.investments:
            self.investments[name] += amount
        else:
            self.investments[name] = amount

        # Clear inputs
        self.name_entry.delete(0, tk.END)
        self.amount_entry.delete(0, tk.END)

        # Update chart
        self.update_chart()

    def delete_investment(self):
        name = self.name_entry.get().strip()
        if name in self.investments:
            del self.investments[name]
            self.update_chart()
            messagebox.showinfo("Deleted", f"{name} removed successfully!")
        else:
            messagebox.showerror("Error", "Investment not found!")

    def update_chart(self):
        self.ax.clear()
        labels = list(self.investments.keys())
        sizes = list(self.investments.values())

        if not sizes:
            self.ax.text(0.5, 0.5, "No Data", ha="center")
        else:
            if self.chart_type.get() == "Pie":
                self.ax.pie(sizes, labels=labels, autopct="%1.1f%%", startangle=140)
                self.ax.set_title("Investment Distribution (Pie Chart)")
            elif self.chart_type.get() == "Bar":
                self.ax.bar(labels, sizes)
                self.ax.set_ylabel("Amount")
                self.ax.set_title("Investment Distribution (Bar Chart)")
            elif self.chart_type.get() == "Line":
                self.ax.plot(labels, sizes, marker="o")
                self.ax.set_ylabel("Amount")
                self.ax.set_title("Investment Distribution (Line Chart)")
        self.canvas.draw()

    def save_data(self):
        try:
            with open(self.data_file, "w") as f:
                json.dump(self.investments, f, indent=4)
            messagebox.showinfo("Success", "Data saved successfully!")
        except Exception as e:
            messagebox.showerror("Error", f"Could not save data: {e}")

    def load_data(self):
        if os.path.exists(self.data_file):
            try:
                with open(self.data_file, "r") as f:
                    self.investments = json.load(f)
                self.update_chart()
            except Exception as e:
                messagebox.showerror("Error", f"Could not load data: {e}")
    
    def import_excel(self):
        file_path = filedialog.askopenfilename(title="Select Excel File", filetypes=[("Excel files", "*.xlsx;*.xls")])
        if not file_path:
            return
        try:
            df = pd.read_excel(file_path)
            if "Name" not in df.columns or "Amount" not in df.columns:
                messagebox.showerror("Error", "Excel file must have 'Name' and 'Amount' columns")
                return
            for _, row in df.iterrows():
                name = str(row["Name"]).strip()
                try:
                    amount = float(row["Amount"])
                except:
                    continue
                if name in self.investments:
                    self.investments[name] += amount
                else:
                    self.investments[name] = amount
            self.update_chart()
            messagebox.showinfo("Success", "Excel data imported successfully!")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to import Excel file: {e}")
'''
def fetch_from_zerodha(self):
    holdings = self.zerodha.get_holdings()
    if not holdings:
        messagebox.showerror("Error", "No data fetched. Please check your Zerodha login.")
        return

    for h in holdings:
        name = h.get("tradingsymbol", "Unknown")
        value = h.get("last_price", 0) * h.get("quantity", 0)
        if name in self.investments:
            self.investments[name] += value
        else:
            self.investments[name] = value

    self.update_chart()
    messagebox.showinfo("Success", "Fetched data from Zerodha!")
'''
if __name__ == "__main__":
    root = tk.Tk()
    app = InvestmentTracker(root)
    root.mainloop()