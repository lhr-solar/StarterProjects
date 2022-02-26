
import pandas as pd
import csv
Blast = pd.read_csv('data.csv')
from word2number import w2n
#print(Blast.head())  #to test the first several against new blast if you wanted to
#print(Blast.columns)
#print(Blast.shape)

def clean():
    import re
    booleans = []
    Blast.Price = (Blast.Price)*1.36 #converts to dollars
    Blast.Price = Blast.Price.map('{:,.2f}'.format) #formats the currency nicely '${}

    for result in Blast.Star_Rating:
        if re.search('One', result):
            booleans.append(False)
        elif re.search('Two', result):
            booleans.append(False)
        else:
            booleans.append(True)

    print(booleans[0:5]) #to test if first 5 are true or false

    #print(len(booleans)) shows the rows have not yet been omitted

    Filtered = pd.Series(booleans)
    New_blast_df = Blast[Filtered]
    print(New_blast_df.shape)
    df = pd.DataFrame(New_blast_df) 
    df.to_csv('data2.csv') #creates new csv to check data in
    print(df) #returns pandas dataframe

if __name__ == "__main__":
    clean()
    """TODO: Write code here to test this
    particular module on its own
    """