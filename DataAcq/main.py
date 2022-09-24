"""Main engine to tie all the pieces together
"""
from scrape import *
from clean import *
from visualize import *
def main():
    """TODO: Implement this
    """
    scrape()
    visualize(clean(), 'price', 'ratings')
    pass


if __name__ == "__main__":
    main()
