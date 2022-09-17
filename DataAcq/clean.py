"""Module to clean the data in the CSV file
"""
# Convert pounds to dollars, remove books with less than 3 stars
import pandas as pd
import numpy as np
from currency_converter import CurrencyConverter
from pandas import DataFrame

def clean() -> DataFrame:
    """TODO: Implement this
    """
    df = pd.read_csv('catalog.csv')
    df.drop(df.index[(df["rating"] == "One")], axis=0, inplace=True)
    df.drop(df.index[(df["rating"] == "Two")], axis=0, inplace=True)

    df["price"] = df["price"].str.replace("£", "")
    c = CurrencyConverter()
    for index in df.index:
        df.loc[index, "price"] = "$" + "{:.2f}".format(round(c.convert(df.loc[index, "price"], 'GBP', 'USD'), 2))

    return df
    pass


if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """
    new_df = clean()

    # print(new_df.to_string())
    pass
