"""Module to visualize data from a pandas dataframe
"""
from pandas import DataFrame
import matplotlib.pyplot as plt

def visualize(data: DataFrame, x_col: str, y_col: str):
    data.plot(x_col, y_col, kind='scatter')
    plt.show()


if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """
    pass
