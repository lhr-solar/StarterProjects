"""Module to scrape information from a fake bookstoor
"""
from bs4 import BeautifulSoup
import requests
import csv
headers = {
    'Access-Control-Allow-Origin': '*',
    'Access-Control-Allow-Methods': 'GET',
    'Access-Control-Allow-Headers': 'Content-Type',
    'Access-Control-Max-Age': '3600',
    'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:52.0) Gecko/20100101 Firefox/52.0'
}
def book_data(product):
    title = product.contents[5].a["title"]
    star_rating = product.contents[3]["class"][1]
    int_star_rating = 0
    if star_rating == 'One':
        int_star_rating = 1
    elif star_rating == 'Two':
        int_star_rating = 2
    elif star_rating == 'Three':
        int_star_rating = 3
    elif star_rating == 'Four':
        int_star_rating = 4
    elif star_rating == 'Five':
        star_rating = 5
    price = float(product.contents[7].p.string[2:])
    stock = product.contents[7].find_all('p')[1].contents[2].strip() == 'In stock'
    return [title, int_star_rating, price, stock]

def scrape():
    """TODO: Implement this
    """
    for page in range(5):
        SITE_URL = "http://books.toscrape.com/catalogue/page-" + str(page) + ".html"
        r = requests.get(SITE_URL, headers)
        soup = BeautifulSoup(r.text, "html.parser")
        for product in soup.find_all("article"):
            data = book_data(product)
            print(data)
    pass


if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """
    scrape()
    pass
