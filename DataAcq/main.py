"""Main engine to tie all the pieces together
"""
import scrape
import clean
import visualize

def main():
    """TODO: Implement this
    """
    scrape.scrape()
    clean.clean()
    visualize.visualize()
    pass


if __name__ == "__main__":
    main()
