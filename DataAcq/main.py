"""Main engine to tie all the pieces together
"""
from scrape import scrape
from clean import clean
from visualize import visualize
def main():
    scrape() # creates csv
    df = clean() # inputs books.csv from directory, returns df
    visualize(df,'rating','price')



if __name__ == "__main__":
    main()
