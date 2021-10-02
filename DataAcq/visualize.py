"""Module to visualize data from a pandas dataframe
"""
from pandas import DataFrame
import matplotlib.pyplot as plt

def visualize(data: DataFrame, x_col: str, y_col: str):
    plt.scatter(data[x_col], data [y_col])
    plt.xlabel(x_col)
    plt.ylabel(y_col)
    plt.show()


if __name__ == "__main__":
    pass
