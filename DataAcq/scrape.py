"""Module to scrape information from a fake bookstoor
"""
from bs4 import BeautifulSoup
import requests
import pandas as pd

SITE_URL = "http://books.toscrape.com/"
books = []
ratings = []
prices = []
stocks = []


def scrape():
    """TODO: Implement this
    """
    home = requests.get(SITE_URL)
    # find number of pages to scrape
    if home:
        soup = BeautifulSoup(home.content, 'html.parser')
        numPages = int(soup.find('li', class_='current').text.strip().split(' ')[3])
        print("Found " + str(numPages) + " pages to scrape")
        current = 1
        while current <= numPages:
            url = f"{SITE_URL}/catalogue/page-{str(current)}.html"
            page = requests.get(url)

            if page:
                soup = BeautifulSoup(page.text, 'html.parser')
                print("Scraping page " + str(current))

                items = soup.find_all("article")

                for item in items:
                    title = item.find('img', class_="thumbnail")['alt']
                    books.append(title)
                    rating = item.find('p')['class']
                    ratings.append(rating[1])
                    price = item.find('p', class_="price_color").string.strip("Â")
                    prices.append(price)
                    stock = item.find('p', class_="instock availability").contents[2].strip()
                    stocks.append(stock)
                current += 1
        home.close()
    dict = {'title': books, 'rating': ratings, 'price': prices, 'in-stock': stocks}
    df = pd.DataFrame(dict)
    df.to_csv('catalog.csv')
    pass


if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """
    scrape()
    pass
