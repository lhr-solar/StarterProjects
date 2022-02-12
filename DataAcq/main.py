"""Main engine to tie all the pieces together
"""

from clean import clean
from scrape import scrape
from visualize import visualize


def main():
    scrape()
    df = clean()
    visualize(df, 'price', 'rating')
    pass


if __name__ == "__main__":
    main()
