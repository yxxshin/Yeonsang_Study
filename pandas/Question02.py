# Q2. How To Select an Index or Column From a Pandas DataFrame
# (source: https://www.datacamp.com/community/tutorials/pandas-tutorial-dataframe-python)

import numpy as np
import pandas as pd

df = pd.DataFrame(data=[[1, 2, 3], [4, 5, 6], [7, 8, 9]], columns=['A', 'B', 'C'])
print(pd.DataFrame(df))
print("------------------")

# Using `iloc[]`
print(df.iloc[0][0])

# Using `loc[]`
print(df.loc[0]['A'])

# Using `at[]`
print(df.at[0, 'A'])

# Using `iat[]`
print(df.iat[0, 0])

# Use `iloc[]` to select row `0`
print("------------------")
print(df.iloc[0])

# Use `loc[]` to select a column
print("------------------")
print(df.loc[:, 'A'])
