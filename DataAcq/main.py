"""Main engine to tie all the pieces together
"""
from scrape import scrape
from clean import clean
from visualize import visualize

def main():
    scrape()
    visualize(clean(), input("Enter x-axis: "), input("Enter y-axis: "))
    pass

if __name__ == "__main__":
    main()
