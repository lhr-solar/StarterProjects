"""Module to visualize data from a pandas dataframe
"""
from pandas import DataFrame
import matplotlib.pyplot as plt
from clean import *
import seaborn as sns


def visualize(data: DataFrame, x_col: str, y_col: str):
    """TODO: Implement this
    """
    data.sort_values(by=[x_col], inplace=True)
    sns.stripplot(data=data, x=y_col, y=x_col, jitter=.2, size=2)
    plt.show()
    pass


if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """
    visualize(clean(), 'price', 'ratings')
    pass
