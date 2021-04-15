# Q5. How to Rename the Index or Columns of a Pandas DataFrame
# (source: https://www.datacamp.com/community/tutorials/pandas-tutorial-dataframe-python)

import numpy as np
import pandas as pd

df = pd.DataFrame(data=np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]]),
                  columns=['A', 'B', 'C'])
print(df)

# Define the new names of your columns
newcols = {
    'A': 'new_column_1',
    'B': 'new_column_2',
    'X': 'new_column_3',
    'C': 'new_column_4'
}

# Use `rename()` to rename your columns
df.rename(columns=newcols, inplace=True)
print("------------------")
print(df)

# Rename your index
df.rename(index={1: 'a'}, inplace=True)
print("------------------")
print(df)

