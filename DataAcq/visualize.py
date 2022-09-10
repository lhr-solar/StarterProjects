"""Module to visualize data from a pandas dataframe
"""
from pandas import DataFrame
import matplotlib.pyplot as plt
from clean import *

def visualize(data: DataFrame, x_col: str, y_col: str):
    data.sort_values(by=[x_col], inplace=True)
    data.plot(x=x_col, y = y_col, kind='bar')
    plt.show()

if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """
    #visualize(clean(), 'rating', 'price')
    df = clean()

    df = df.cumsum()

    plt.figure()

    visualize(df, 'rating', 'price')
    pass
