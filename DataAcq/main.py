"""Main engine to tie all the pieces together
"""



def main():
    """TODO: Implement this
    """
    import scrape
    scrape.scrape()
    import clean
    clean.clean()
    import visualize
    visualize.visualize()

if __name__ == "__main__":
    main()
