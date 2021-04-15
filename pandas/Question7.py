# Q7. How To Create an Empty DataFrame
# (source: https://www.datacamp.com/community/tutorials/pandas-tutorial-dataframe-python)

import numpy as np
import pandas as pd

# Using `numpy.nan`
df = pd.DataFrame(np.nan, index=[0, 1, 2, 3], columns=['A'])
print(df)

# Using `dtype`
print('\n')
df = pd.DataFrame(index=range(0, 4), columns=['A'], dtype='float')
print(df)