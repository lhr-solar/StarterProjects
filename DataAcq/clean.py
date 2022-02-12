"""Module to clean the data in the CSV file
"""
import pandas as pd
from pandas import DataFrame

def clean() -> DataFrame:
    df = pd.read_csv('data.csv')
    df['price'] = df['price'] * 1.36
    df['rating'].replace({'One': 1, 'Two': 2, 'Three': 3, 'Four': 4, 'Five': 5}, inplace=True)
    filter = ((df['rating'] == 3) | (df['rating'] == 4) | (df['rating'] == 5))
    newdf = df[filter]
    return newdf
    '''
    newdf.to_csv('updated.csv', sep=',')
    '''

if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """
    clean()
    pass
