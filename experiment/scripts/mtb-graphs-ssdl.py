import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import os

# === CONFIGURATION ===
CSV_FILE = '0-24-mtb-syntesis.csv'  # Replace with your actual path
OUTPUT_DIR = 'mtb_plots'
os.makedirs(OUTPUT_DIR, exist_ok=True)

# === LOAD AND PARSE ===
df = pd.read_csv(CSV_FILE, delimiter=';')
programs = df['PROG']
mtb_columns = [col for col in df.columns if col.startswith("MTB_")]

# Parse and normalize values (use first number, replace ',' with '.')
mtb_values = pd.DataFrame()
for col in mtb_columns:
    mtb_values[int(col.replace('MTB_', ''))] = df[col].astype(str).apply(
        lambda x: float(x.strip().split()[0].replace(',', '.')) if x.strip() else 0.0
    )
mtb_values['Program'] = programs

# Sort columns numerically (in case)
mtb_values = mtb_values[[i for i in range(11)] + ['Program']]

# === Plot 1: Combined Line Plot ===
plt.figure(figsize=(14, 8))
for i, row in mtb_values.iterrows():
    plt.plot(range(11), row[list(range(11))], label=row['Program'])

plt.xticks(ticks=range(11), labels=[str(i) for i in range(11)])
plt.xlabel("Number of Test Cases")
plt.ylabel("Mutation Technical Debt (person-hours)")
#plt.title("MTB Evolution by Number of Test Cases (All Programs)")

plt.xlim(0, 10)  # Align X=0 with Y-axis
plt.grid(True)

plt.legend(loc='upper right', bbox_to_anchor=(1.25, 1.0), fontsize='small', ncol=1)
plt.tight_layout()
plt.savefig(os.path.join(OUTPUT_DIR, "all_programs_line_plot.png"))
plt.show()

# === Plot 2: Individual Line Plots ===
for i, row in mtb_values.iterrows():
    plt.figure(figsize=(8, 4))
    plt.plot(range(11), row[list(range(11))], marker='o')
    plt.xticks(ticks=range(11), labels=[str(i) for i in range(11)])
    plt.xlabel("Number of Test Cases")
    plt.ylabel("Mutation Technical Debt (person-hours)")
    #plt.title(f"MTB Evolution - {row['Program']}")
    plt.grid(True)
    plt.tight_layout()
    filename = f"{row['Program'].replace(' ', '_')}_line_plot.png"
    plt.savefig(os.path.join(OUTPUT_DIR, filename))
    plt.close()

# === Melt data for seaborn plots ===
mtb_long = mtb_values.melt(id_vars=['Program'], var_name='TestCases', value_name='MTB')
mtb_long['TestCases'] = mtb_long['TestCases'].astype(int)
heatmap_data = mtb_long.pivot(index='Program', columns='TestCases', values='MTB')

# === Plot 3: Heatmap (Preserving CSV order) ===
program_order = df['PROG'].tolist()
mtb_long['Program'] = pd.Categorical(mtb_long['Program'], categories=program_order, ordered=True)

heatmap_data = mtb_long.pivot(index='Program', columns='TestCases', values='MTB')

plt.figure(figsize=(12, 10))
sns.heatmap(heatmap_data, annot=True, fmt=".1f", cmap="YlGnBu", cbar_kws={'label': 'MTB (person-hours)'})
#plt.title("Heatmap of Mutation Technical Debt by Number of Test Cases")
plt.xlabel("Number of Test Cases")
plt.ylabel("Program")
plt.tight_layout()
plt.savefig(os.path.join(OUTPUT_DIR, "heatmap_mtb.png"))
plt.show()

# === Plot 4: Bar Plot for 0 test cases ===
plt.figure(figsize=(12, 6))
sns.barplot(data=mtb_long[mtb_long["TestCases"] == 0], x="Program", y="MTB")
#plt.title("MTB with 0 Test Cases by Program")
plt.ylabel("MTB (person-hours)")
plt.xticks(rotation=90)
plt.tight_layout()
plt.savefig(os.path.join(OUTPUT_DIR, "barplot_mtb0.png"))
plt.show()

# === Plot 5: Small Multiples (Faceted Line Plots, no axis labels) ===
g = sns.FacetGrid(mtb_long, col="Program", col_wrap=5, height=2.5, sharey=False)
g.map_dataframe(sns.lineplot, x="TestCases", y="MTB", marker="o")
g.set_titles(col_template="{col_name}")

# Remove axis labels for subplots to avoid overlap
g.set_axis_labels("", "")  # no x or y labels
g.set_xticklabels(rotation=45)

# Adjust spacing for better readability of subplot titles
g.fig.subplots_adjust(top=0.92, hspace=0.6)

# Only a global title
#g.fig.suptitle("Program-wise MTB Evolution by Number of Test Cases", fontsize=16)

# Save and show
g.savefig(os.path.join(OUTPUT_DIR, "small_multiples_lineplots.png"))
plt.show()