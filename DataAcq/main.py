"""Main engine to tie all the pieces together
"""
from scrape import scrape
import clean
from visualize import visualize
import clean
def main():
    scrape()
    df = clean.clean()
    visualize(df, 'Rating', 'Price')
    


if __name__ == "__main__":
    main()
