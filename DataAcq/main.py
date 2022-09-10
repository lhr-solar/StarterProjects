"""Main engine to tie all the pieces together
"""
from clean import *
from visualize import *
from scrape import *
def main():
    data = clean()
    visualize(data, 'rating', 'price')


if __name__ == "__main__":
    main()
