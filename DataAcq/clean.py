"""Module to clean the data in the CSV file
"""
from pandas import DataFrame
import pandas as pd


def clean() -> DataFrame:
    df = pd.read_csv('books.csv')
    for word in ['One','Two',]:
        df.drop(df[df['rating'] == word].index, inplace = True)
    df['price'] = df['price'].apply(lambda x:eval(x[1:])*1.36)
    df_filtered = df
    return df_filtered


    """TODO: Implement this
    """
    pass


if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """
    pass
