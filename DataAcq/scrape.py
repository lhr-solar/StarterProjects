"""Module to scrape information from a fake bookstoor
"""

import requests
import pandas as pd
import bs4
import csv

def scrape():
    output = open('data.csv', mode='w', encoding="utf-8", newline='')
    csv_writer = csv.writer(output, delimiter=',')
    csv_writer.writerow(["title", "rating", "price", "stock availablity"])
    for i in range(1, 51):
        result = requests.get("https://books.toscrape.com/catalogue/page-" + str(i) + ".html")
        soup = bs4.BeautifulSoup(result.text, "lxml")
        elements = soup.select('.product_pod')
        for el in elements:
            title = el.find('h3').text
            rating = el.find('p', class_ = 'star-rating')["class"][1]
            price = el.find('p',class_= 'price_color').text[3:]
            stock = el.find('p', 'instock availability').text.strip()
            csv_writer.writerow([title, rating, price, stock])

if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """
    scrape()


