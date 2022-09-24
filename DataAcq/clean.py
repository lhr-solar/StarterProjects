"""Module to clean the data in the CSV file
"""
import csv
import pandas as pd
from currency_converter import CurrencyConverter
from pandas import DataFrame


def clean() -> DataFrame:
    """TODO: Implement this
    """
    df = pd.read_csv('books.csv')
    df.drop(df.index[df['ratings'] == 1], axis=0, inplace=True)
    df.drop(df.index[df['ratings'] == 2], axis=0, inplace=True)
    c = CurrencyConverter()
    for index in df.index:
        df.loc[index, 'price'] = round(c.convert(df.loc[index, 'price'], 'GBP', 'USD'), 2)
    return df
    pass


if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """
    df = clean()
    pass
