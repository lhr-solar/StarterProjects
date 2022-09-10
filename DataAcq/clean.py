"""Module to clean the data in the CSV file
"""
from pandas import DataFrame
import csv

def clean() -> DataFrame:
    data = []
    with open('books.csv', 'r', newline='') as csvfile:
        reader = csv.reader(csvfile)
        next(reader)
        data = list(reader)
    newList = []
    for i in range(len(data)):
        if(data[i][1] == 'One'):
            data[i][1] = 1
        elif(data[i][1] == 'Two'):
            data[i][1] = 2
        elif(data[i][1] == 'Three'):
            data[i][1] = 3
        elif(data[i][1] == 'Four'):
            data[i][1] = 4
        elif(data[i][1] == 'Five'):
            data[i][1] = 5
        if(int(data[i][1] >= 3)):
            data[i][2] = round(float(data[i][2]) * 1.16, 2)
            newList.append(data[i])

    return DataFrame(newList, columns=['title', 'rating', 'price', 'in-stock'])


if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """

    pass
