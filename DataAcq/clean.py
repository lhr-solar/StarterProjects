"""Module to clean the data in the CSV file
"""
import pandas
from pandas import DataFrame

USD_PER_EURO = 1.17

def clean() -> DataFrame:
    books = pandas.read_csv("book_file.csv", encoding = "ISO-8859-1")
    top_rated = books[(books["rating"].notnull()) & (books["rating"] != "Two") & (books["rating"] != "One") & (books["rating"] != "Zero")]
    top_rated["usd_price"] = books.price * USD_PER_EURO
    top_rated.drop(columns = "price", inplace = True)
    #print(top_rated)
    return top_rated

if __name__ == "__main__":
    clean()
