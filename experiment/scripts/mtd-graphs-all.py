
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# === CONFIGURATION ===
CSV_FILE = '0-24-mtb-manual-all.csv'  # Replace with your own file path

# === LOAD AND CLEAN ===
df = pd.read_csv(CSV_FILE, delimiter=';')

# Convert values: handle '43,5'-style decimals and split if needed
df['MTD_0'] = df['MTD_0'].astype(str).apply(
    lambda x: float(x.strip().split()[0].replace(',', '.'))
)
df['MTD_SSDL-adequate'] = df['MTD_SSDL-adequate'].astype(str).apply(
    lambda x: float(x.strip().replace(',', '.'))
)

# Drop rows with missing values
df = df.dropna(subset=['MTD_0', 'MTD_SSDL-adequate'])

# Sort by initial debt for clarity
df = df.sort_values(by='MTD_0', ascending=False)

# === PLOT: GROUPED BAR CHART ===
x = np.arange(len(df))
width = 0.35

plt.figure(figsize=(12, 8))
plt.bar(x - width/2, df['MTD_0'], width, label='MTD initial')
plt.bar(x + width/2, df['MTD_SSDL-adequate'], width, label='MTD from SSDL-adequate')

plt.xticks(x, df['PROG'], rotation=90)
plt.ylabel("Mutation Technical Debt (person-hours)")
#plt.title("MTD Comparison per Program: Initial vs SSDL-Adequate")
plt.xlabel("Program")
plt.legend()
plt.grid(axis='y', linestyle='--', alpha=0.5)
plt.tight_layout()
plt.show()
