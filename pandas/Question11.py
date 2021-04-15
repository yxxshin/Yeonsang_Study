# Q11. How To Write a Pandas DataFrame to a File
# (source: https://www.datacamp.com/community/tutorials/pandas-tutorial-dataframe-python)

# [INFO] This file does not get compiled

import numpy as np
import pandas as pd

## Output a DataFrame to CSV
df.to_csv('myDataFrame.csv')

# To delimit by a tab, use `sep`
df.to_csv('myDataFrame.csv', sep='\t')

# To use a specific character encoding, use `encoding`
df.to_csv('myDataFrame.csv', sep='\t', encoding='utf-8')

## Writing a DataFrame to Excel
writer = pd.ExcelWriter('myDataFrame.xlsx')
df.to_excel(writer, 'DataFrame')
writer.save()

