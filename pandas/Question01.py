# Q1. How To Create a Pandas DataFrame
# (source: https://www.datacamp.com/community/tutorials/pandas-tutorial-dataframe-python)

import numpy as np
import pandas as pd

# Take a 2D array as input to your DataFrame
my_2darray = np.array([[1, 2, 3], [4, 5, 6]])
print(pd.DataFrame(my_2darray))

# Take a dictionary as input to your DataFrame
print("------------------")
my_dict = {1: ['1', '3'], 2: ['1', '2'], 3: ['2', '4']}
print(pd.DataFrame(my_dict))

# Take a DataFrame as input to your DataFrame
print("------------------")
my_df = pd.DataFrame(data=[4, 5, 6, 7], index=range(10, 14), columns=['A'])
print(pd.DataFrame(my_df))

# Take a Series as input to your DataFrame
print("------------------")
my_series = pd.Series(
    {"United Kingdom": "London", "India": "New Delhi", "United States": "Washington", "Belgium": "Brussels"})
print(pd.DataFrame(my_series))

print("------------------")
df = pd.DataFrame(np.array([[1, 2, 3], [4, 5, 6]]))

# Use the 'shape' property
print(df.shape)

# Or use the 'len()' function with the 'index' property
print(len(df.index))
