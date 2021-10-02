"""Main engine to tie all the pieces together
"""
import scrape
import clean
import visualize

def main():
    scrape.scrape()
    visualize.visualize(clean.clean(), clean.clean().axes[1][0], clean.clean().axes[1][3])


if __name__ == "__main__":
    main()
