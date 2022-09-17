"""Main engine to tie all the pieces together
"""
from pandas import DataFrame
from clean import clean
from scrape import scrape
from visualize import visualize



SITE_URL = "http://books.toscrape.com/"
books = []
ratings = []
prices = []
stocks = []


def main():
    """TODO: Implement this
    """
    scrape()
    df = clean()
    visualize(df, 'price', 'rating')
    pass


if __name__ == "__main__":
    main()
