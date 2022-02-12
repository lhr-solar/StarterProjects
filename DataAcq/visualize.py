"""Module to visualize data from a pandas dataframe
"""
from pandas import DataFrame
import pandas as pd
import matplotlib.pyplot as plt
from clean import clean

def visualize(data: DataFrame, x_col: str, y_col: str):
    x_val = data[x_col]
    y_val = data[y_col]
    plt.scatter(x_val,y_val)
    plt.show()



    """TODO: Implement this
    """
    pass


if __name__ == "__main__":
    pass
