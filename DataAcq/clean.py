"""Module to clean the data in the CSV file
"""
import pandas as pd
from pandas import DataFrame
from forex_python.converter import CurrencyRates



def clean() -> DataFrame:
    df = pd.read_csv('books.csv')

    # Adjusts to live currency rate
    rate = CurrencyRates().get_rate('EUR', 'USD')

    df['2'] = df['2']*rate
    print(df['2'])

    new_df = ([df['0'], df['1'], df['2'], df['3']])

    df = df[df['1']!="Two"][df['1']!="One"]

    print(df)

    df.to_csv('books_cleaned.csv')

    pass


if __name__ == "__main__":
    clean()
    pass
