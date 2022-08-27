"""Module to visualize data from a pandas dataframe
"""
from pandas import DataFrame
import matplotlib.pyplot as plt
plt.close("all")

def visualize(data: DataFrame, x_col: str, y_col: str):
    #data.plot(x=x_col, y=y_col)
    plt.hexbin(x=data[x_col], y=data[y_col], gridsize=(30, 20), mincnt=1)
    plt.title("Hexbin of " + y_col + " vs. " + x_col)
    plt.xlabel(x_col)
    plt.ylabel(y_col)
    plt.yticks([3, 4, 5])
    plt.colorbar()
    plt.show()
    pass


if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """
    pass
