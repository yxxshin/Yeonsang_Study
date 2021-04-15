# Q9. When, Why And How You Should Reshape Your Pandas DataFrame
# (source: https://www.datacamp.com/community/tutorials/pandas-tutorial-dataframe-python)

import numpy as np
import pandas as pd

## Pivotting Your DataFrame
# Create your DataFrame
products = pd.DataFrame({'category': ['Cleaning', 'Cleaning', 'Entertainment', 'Entertainment', 'Tech', 'Tech'],
                         'store': ['Walmart', 'Dia', 'Walmart', 'Fnac', 'Dia', 'Walmart'],
                         'price': [11.42, 23.50, 19.99, 15.95, 55.75, 111.55],
                         'testscore': [4, 3, 5, 7, 5, 8]})
print(products)

# Use `pivot()` to pivot the DataFrame
print("------------------")
pivot_products = products.pivot(index='category', columns='store', values='price')
print(pivot_products)

# When you don't specifically fill in what values you expect to be present in your resulting table,
# you will pivot by multiple columns
print("------------------")
pivot_products2 = products.pivot(index='category', columns='store')
print(pivot_products2)

# Using `pivot_table()` when you can't ensure the uniqueness of your data
print("------------------")
pivot_products3 = products.pivot_table(index='category', columns='store', values='price', aggfunc='mean')
print(pivot_products3)

## Using `stack()` and `unstack()` to Reshape Your Pandas DataFrame
# - Refer to Question5.py

## Reshape Your DataFrame With `melt()`
print('\n')
people = pd.DataFrame({'FirstName': ['John', 'Jane'],
                       'LastName': ['Doe', 'Austen'],
                       'BloodType': ['A-', 'B+'],
                       'weight': [90, 64]})
print(people)

# Use `melt()` on the `people` DataFrame
people_melt = pd.melt(people, id_vars=['FirstName', 'LastName'], var_name='measurements')
print("------------------")
print(people_melt)
