# Q3. How To Add an Index, Row or Column to a Pandas DataFrame
# (source: https://www.datacamp.com/community/tutorials/pandas-tutorial-dataframe-python)

import numpy as np
import pandas as pd

df = pd.DataFrame(data=[[1, 2, 3], [4, 5, 6]], columns=['A', 'B', 'C'])

# Print out your DataFrame `df` to check it out
print(df)

# Set 'C' as the index of your DataFrame
print("------------------")
df1 = df.set_index('C')
print(df1)

print('\n')
df = pd.DataFrame(data=np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]]), index=[2, 'A', 4], columns=[48, 49, 50])
print(df)

# Pass `2` to `loc`
print("------------------")
print(df.loc[2])

# Pass `2` to `iloc`
print("------------------")
print(df.iloc[2])

# Adding a Column to Your DataFrame
print('\n')
df = pd.DataFrame(data=np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]]), columns=['A', 'B', 'C'])
print(df)

# Use `.index`
df['D'] = df.index

# Print `df`
print("------------------")
print(df)

# Appending a column to `df`
print('\n')
df = pd.DataFrame(data=np.array([[1, 1, 2], [3, 2, 4]]), columns=range(1, 4))
print(df)

df.loc[:, 4] = pd.Series(['5', '6'], index=df.index)
print("------------------")
print(df)

# Resetting the Index of Your DataFrame
print('\n')
df = pd.DataFrame(data=np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]]), index=[2.5, 12.6, 4.8])
print(df)

print("------------------")
df_reset = df.reset_index(level=0, drop=True)
print(df_reset)