"""Module to scrape information from a fake bookstoor
"""
from bs4 import BeautifulSoup
import requests
import csv

SITE_URL = "http://books.toscrape.com/"
ADDITION_URL = "catalogue/category/books_1/page-"

def getBookInfo(soup):
    title = soup.find('h3').a['title']
    rating = soup.find('p', class_='star-rating')['class'][1]
    price = soup.find('p', class_='price_color').text[2:]
    inStock = soup.find('p', class_='instock availability').text.strip()
    return [title, rating, price, inStock]

def scrape():
    soup = BeautifulSoup(requests.get(SITE_URL + "catalogue/category/books_1/index.html").text, 'html.parser')
    soupList = soup.find_all('article')
    for i in range(2, 51):
        soup = BeautifulSoup(requests.get(SITE_URL + ADDITION_URL + str(i) + ".html").text, 'html.parser')
        soupList2 = soup.find_all('article')
        soupList += soupList2

    with open('books.csv', 'w', newline='') as csvfile:
        writer = csv.writer(csvfile)
        writer.writerow(['title', 'rating', 'price', 'in-stock'])
        for soupInd in soupList:
            writer.writerow(getBookInfo(soupInd))



if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """
    scrape()
    pass
