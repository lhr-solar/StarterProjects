"""Module to clean the data in the CSV file
"""
import pandas as pd
from pandas import DataFrame
import csv

def clean() -> DataFrame:
    data = pd.read_csv("data.csv")
    data['Price'] = data['Price']*1.36
    #data = data.applymap("${0:.2f}".format)
    #pd.options.display.float_format = '${:,.2f}'.format
    #data = pd.data['Price']
    data.Price = data.Price.map('{:,.2f}'.format)
    data['Rating'].replace({'One': 1, 'Two': 2,'Three': 3,'Four': 4,'Five': 5}, inplace = True) 
    f = ((data['Rating']==3) | (data['Rating']==4) | (data['Rating']==5))
    nf = data[f]
    return nf
    #f.to_csv('data.csv')
    #nf.to_csv('new_csv.csv', sep=',')
    

    


if __name__ == "__main__":

    clean()
