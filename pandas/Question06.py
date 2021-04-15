# Q6. How To Format The Data in Your Pandas DataFrame
# (source: https://www.datacamp.com/community/tutorials/pandas-tutorial-dataframe-python)

import numpy as np
import pandas as pd

df = pd.DataFrame(
    data=np.array([['OK', 'Perfect', 'Acceptable'], ['Awful', 'Awful', 'Perfect'], ['Acceptable', 'OK', 'Poor']]),
    columns=['Student1', 'Student2', 'Student3'])
print(df)

## Replacing All Occurrences of a String in a DataFrame
# Replace the strings by numerical values (0-4)
print("------------------")
df1 = df.replace(['Awful', 'Poor', 'OK', 'Acceptable', 'Perfect'], [0, 1, 2, 3, 4])
print(df1)

# Replace strings by others with `regex`
print('\n')
df = pd.DataFrame(data=np.array([['1\n', '2', '3\n'], ['4', '5', '6\n'], ['7', '8\n', '9']]),
                  index=range(3))
print(df)
print("------------------")
df1 = df.replace({'\n': '<br>'}, regex=True)
print(df1)

## Removing Parts From Strings in the Cells of Your DataFrame
print('\n')
df = pd.DataFrame(data=np.array([[1, 2, '+3b'], [4, 5, '-6B'], [7, 8, '+9A']]),
                  columns=['class', 'test', 'result'])
print(df)

# Delete unwanted parts from the strings in the `result` column
df['result'] = df['result'].map(lambda x: x.lstrip('+-').rstrip('aAbBcC'))
print("------------------")
print(df)

## Splitting Text in a Column into Multiple Rows in a DataFrame
print('\n')
df = pd.DataFrame(data=np.array([[34, 0, '23:44:55'], [22, 0, '66:77:88'], [19, 1, '43:68:05 56:34:12']]),
                  columns=['Age', 'PlusOne', 'Ticket'])
print(df)

# Split out the two values in the third row
# Make it a Series
# Stack the values
ticket_series = df['Ticket'].str.split(' ').apply(pd.Series).stack()
print("------------------")
print(ticket_series)

# Get rid of the stack:
# Drop the level to line up with the DataFrame
ticket_series.index = ticket_series.index.droplevel(-1)
print("------------------")
print(ticket_series)

# Make your series a dataframe
ticketdf = pd.DataFrame(ticket_series)
print("------------------")
print(ticketdf)

# Delete the `Ticket` column from your DataFrame
del df['Ticket']
print("------------------")
print(df)

# Join the ticket DataFrame to `df`
df_final = df.join(ticketdf)
print("------------------")
print(df_final)

## Applying A Function to Your Pandas DataFrame's Columns or Rows
print('\n')
df = pd.DataFrame(data=np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]]),
                  columns=['A', 'B', 'C'])
print(df)

# Apply the `doubler` function to the `A` DataFrame column
doubler = lambda x: x * 2
df1 = df['A'].apply(doubler)
print("------------------")
print(df1)

# Apply the `doubler` function to the `1` DataFrame Row
df2 = df.loc[1].apply(doubler)
print("------------------")
print(df2)

# Apply the `doubler` function to every element in the entire DataFrame
doubled_df = df.applymap(doubler)
print("------------------")
print(doubled_df)