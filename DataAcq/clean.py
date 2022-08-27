"""Module to clean the data in the CSV file
"""
import pandas as pd
from pandas import DataFrame

def clean() -> DataFrame:
    df = pd.read_csv("books.csv", encoding="cp1252")
    for x in df.index:
        switch = {  "One"   : False,
                    "Two"   : False,
                    "Three" : 3,
                    "Four"  : 4,
                    "Five"  : 5,
                 }
        num = switch.get(df.loc[x, "rating"])
        if(num):
            df.loc[x, "rating"] = num
        else:
            df.drop(x, inplace = True)
    df["price"] = round(df["price"].str.strip("£").astype(float)*1.21, 2)
    return df

if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """
    pass
