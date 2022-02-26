"""Module to visualize data from a pandas dataframe
"""
#from pandas import DataFrame
import pandas as pd
import csv
import matplotlib.pyplot as plt
from word2number import w2n

#NOTES
#I had to modify the columns, so that they were both numbers since the star rating wasn't a number

Blast2 = pd.read_csv('data2.csv')
Star_Rating2 = []
Price2 = []
A = []
B = []
for result in Blast2.Star_Rating:
    StarNum = w2n.word_to_num(result) #changes Three to 3 and so on
    Star_Rating2.append(StarNum)
A = Star_Rating2
for result in Blast2.Price:
    StarNum2 = result
    Price2.append(StarNum2)
B = Price2
print(A)
print(B) #just shows the columns to make sure it works
data = {'C' : A, 'D' : B}


def visualize(): #data: pd.DataFrame(data), x_col: str, y_col: str): #Do I need to do this?
    """TODO: Implement this
    """
    df = pd.DataFrame(data) 
    df.plot(x = 'C', y = 'D', kind = "scatter")
    plt.show()
    #plt.ylabel('Price')  -if you wanted to label


if __name__ == "__main__":
    visualize()
    """TODO: Write code here to test this
    particular module on its own
    """
