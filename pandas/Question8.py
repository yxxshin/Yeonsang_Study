# Q8. Does Pandas Recognize Dates When Importing Data?
# (source: https://www.datacamp.com/community/tutorials/pandas-tutorial-dataframe-python)

# [INFO] This File does not get compiled

import numpy as np
import pandas as pd

# Using `parse_dates`
pd.read_csv('yourFile.csv', parse_dates=True)

# This is also okay
pd.read_csv('yourFile.csv', parse_dates=['columnName'])

# Make your own parser and use
dateparser = lambda x: pd.datetime.strptime(x, '%Y-%m-%d %H:%M:%S')
pd.read_csv('yourFile.csv', parse_dates=['columnName'], date_parser=dateparser)