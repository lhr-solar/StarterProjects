"""Module to visualize data from a pandas dataframe
"""
from pandas import DataFrame
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('books.csv')

def visualize():
    

    df  = pd.read_csv("books.csv")
    print(df)
    # df.plot()  # plots all columns against index
    # df.plot(kind='scatter') # scatter plot
    # df.plot(kind='density')
    plt.plot(df['2'])
    plt.show()
    pass


if __name__ == "__main__":
    visualize(df, 1, 4)
    pass
