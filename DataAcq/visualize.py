"""Module to visualize data from a pandas dataframe
"""
from pandas import DataFrame
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
def visualize(data: DataFrame, x_col: str, y_col: str):
    #data = pd.read_csv("new_csv.csv") 
    #data = pd.DataFrame(data, columms=['Rating','Price'])
    #data.plot(x_col = 'Rating', y_col = 'Price', kind = 'scatter')
    #df = pd.DataFrame(data)
    #df.plot(x = 'Ratings', y = 'Price', kind = "scatter") 
    x = data[x_col]
    #y = data[y_col]

    # plt.xticks(np.arange(7), ['10', '20', '30','40','50','60','70'])
    y = data[y_col].astype(float, errors = 'raise')
    plt.scatter(y, x)
    
    plt.show()


if __name__ == "__main__":
   
   pass 
