# Q4. How to Delete Indices, Rows or Columns From a Pandas Data Frame
# (source: https://www.datacamp.com/community/tutorials/pandas-tutorial-dataframe-python)

import numpy as np
import pandas as pd

df = pd.DataFrame(data=np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9], [40, 50, 60], [23, 35, 37]]),
                  index=[2.5, 12.6, 4.8, 4.8, 2.5], columns=[48, 49, 50])

print(df)
print("------------------")
print(df.reset_index().drop_duplicates(subset='index', keep='last').set_index('index'))

## Deleting a Column from Your DataFrame
print('\n')
df = pd.DataFrame(data=np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]]), columns=['A', 'B', 'C'])
print(df)

# Drop the columns with label 'A'
df.drop('A', axis=1, inplace=True)
print("------------------")
print(df)

# Drop the column at position 1
df2 = df.drop(df.columns[[1]], axis=1)
print("------------------")
print(df2)

## Removing a Row from Your DataFrame
df = pd.DataFrame(data=np.array([[1, 2, 3, 4], [4, 5, 6, 5], [7, 8, 9, 6], [23, 50, 60, 7], [23, 35, 37, 23]]),
                  index=[2.5, 12.6, 4.8, 4.8, 2.5], columns=[48, 49, 50, 50])
print(df)

# Drop the duplicates in `df`
print("------------------")
df.drop_duplicates([48], keep='last', inplace=True)
print(df)

# Drop the index at position 1
print('\n')
df = pd.DataFrame(data=np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]]),
                  columns=['A', 'B', 'C'])
print(df)
print("------------------")
print(df.drop(df.index[1]))