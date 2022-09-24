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
def scrape():
    """TODO: Implement this
    """
    page = 1
    for page in range(2):
        SITE_URL = "http://books.toscrape.com/catalogue/page-" + str(page) + ".html"
        r = requests.get(SITE_URL, headers)
        soup = BeautifulSoup(r.content, "html.parser")
        for product in soup.find_all("article"):
            data = [product.contents[5].a["title"], product.contents[3]["class"][1], product.contents[7].p.string, product.contents[7].find_all('p')[1].contents[2].strip()]
            
    pass


if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """
    scrape()
    pass
