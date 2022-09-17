"""Module to visualize data from a pandas dataframe
"""
from re import sub
import numpy as np
from pandas import DataFrame
from clean import clean
import seaborn as sns
import matplotlib.pyplot as plt

dict = {
    "Three": 3,
    "Four": 4,
    "Five": 5
}
def visualize(data: DataFrame, x_col: str, y_col: str):
    """TODO: Implement this
    """
    data['price'] = data['price'].str.replace("$", "")
    data["price"] = data["price"].apply(lambda x: float(x))
    data['rating'] = data["rating"].map(dict)
    sns.stripplot(data =data, x=y_col, y=x_col, jitter=0.2, size=2)
    plt.show()
    pass


if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """
    df = clean()
    visualize(df, 'price', 'rating')
    pass
