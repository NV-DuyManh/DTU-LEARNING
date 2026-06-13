import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

# 1. Load Data
df = pd.read_csv('assignment.csv')

# 2. Preprocessing (Handle Missing & Outliers exactly as reported)
df_clean = df.copy()
df_clean['Annual Income'] = df_clean['Annual Income'].fillna(df_clean['Annual Income'].median())

Q1 = df['Average Purchase Price'].quantile(0.25)
Q3 = df['Average Purchase Price'].quantile(0.75)
IQR = Q3 - Q1
lower_bound = Q1 - 1.5 * IQR
upper_bound = Q3 + 1.5 * IQR
df_clean['Average Purchase Price'] = np.clip(df_clean['Average Purchase Price'], lower_bound, upper_bound)

# 3. Setup Visualization Theme
sns.set_theme(style="whitegrid")
num_cols = ['Age', 'Annual Income', 'Purchase Frequency', 'Average Purchase Price', 'App Usage Frequency']

# --- Chart 1: Histogram ---
plt.figure(figsize=(8, 5))
sns.histplot(df_clean['Age'], bins=20, kde=True, color='blue')
plt.title('Histogram: Age Distribution')
plt.savefig('1_Histogram.png', bbox_inches='tight')
plt.close()

# --- Chart 2: Bar Chart ---
plt.figure(figsize=(10, 5))
order = df_clean['Most Purchased Category'].value_counts().index
sns.countplot(data=df_clean, x='Most Purchased Category', palette='viridis', order=order)
plt.title('Bar Chart: Most Purchased Category')
plt.xticks(rotation=45)
plt.savefig('2_BarChart.png', bbox_inches='tight')
plt.close()

# --- Chart 3: Scatter Plot ---
plt.figure(figsize=(8, 5))
sns.scatterplot(data=df_clean, x='Annual Income', y='Average Purchase Price', alpha=0.6, color='green')
plt.title('Scatter Plot: Annual Income vs Average Purchase Price')
plt.savefig('3_ScatterPlot.png', bbox_inches='tight')
plt.close()

# --- Chart 4: Heatmap ---
plt.figure(figsize=(8, 6))
corr = df_clean[num_cols].corr()
sns.heatmap(corr, annot=True, cmap='coolwarm', fmt=".2f", vmin=-1, vmax=1)
plt.title('Heatmap: Correlation Matrix')
plt.savefig('4_Heatmap.png', bbox_inches='tight')
plt.close()

# --- Chart 5: Pair Plot ---
pp = sns.pairplot(df_clean[num_cols], corner=True, diag_kind='kde', plot_kws={'alpha': 0.5})
pp.fig.suptitle('Pair Plot: Key Numerical Variables', y=1.02)
plt.savefig('5_PairPlot.png', bbox_inches='tight')
plt.close()

# --- Chart 6: Bubble Chart (Strictly following prompt rules) ---
plt.figure(figsize=(10, 6))
scatter = plt.scatter(x=df_clean['Annual Income'], y=df_clean['Average Purchase Price'], 
                      c=df_clean['Purchase Frequency'], cmap='plasma', 
                      s=100, alpha=0.6, edgecolors='w', marker='o')
plt.colorbar(scatter, label='Purchase Frequency')
plt.xlabel('Annual Income')
plt.ylabel('Average Purchase Price')
plt.title('Bubble Chart: Income vs Purchase Price (Color by Frequency)')
plt.savefig('6_BubbleChart.png', bbox_inches='tight')
plt.close()

# --- Chart 7: Business Question Chart ---
plt.figure(figsize=(10, 5))
category_revenue = df_clean.groupby('Most Purchased Category')['Average Purchase Price'].mean().sort_values(ascending=False)
sns.barplot(x=category_revenue.index, y=category_revenue.values, palette='magma')
plt.title('Average Purchase Price by Product Category')
plt.ylabel('Average Purchase Price ($)')
plt.xticks(rotation=45)
plt.savefig('7_BusinessQuestion_Chart.png', bbox_inches='tight')
plt.close()

print("Hoàn tất! Hãy kiểm tra thư mục để lấy 7 ảnh biểu đồ.")