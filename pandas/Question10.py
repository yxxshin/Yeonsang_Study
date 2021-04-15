# Q10. How To Iterate Over a Pandas DataFrame
# (source: https://www.datacamp.com/community/tutorials/pandas-tutorial-dataframe-python)

import numpy as np
import pandas as pd

df = pd.DataFrame(data=np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]]), columns=['A', 'B', 'C'])
print(df)

# `iterrows()` gives your DataFrame rows as (index, Series) pairs
print("------------------")
for index, row in df.iterrows():
    print(row['A'], row['B'])

