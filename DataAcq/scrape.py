"""Module to scrape information from a fake bookstore
"""
from bs4 import BeautifulSoup
import csv
import requests

SITE_URL = "http://books.toscrape.com/"

def scrape():
    with open("books.csv", "w", newline="") as file:
        fieldnames = ["title", "rating", "price", "in-stock"]
        writer = csv.DictWriter(file, fieldnames=fieldnames)
        writer.writeheader()
        page = 1
        while True:
            currURL = SITE_URL+"catalogue/page-"+str(page)+".html"
            soup = BeautifulSoup(requests.get(currURL).content, "html.parser")
            for data in soup.find_all("article"):
                book = {
                    "title": data.h3.a.get("title"),
                    "rating": data.find("p", class_="star-rating").get("class")[1],
                    "price": data.find("p", class_="price_color").get_text(strip=True),
                    "in-stock": data.find("p", class_="instock availability").get_text(strip=True)
                }
                writer.writerow(book)
            if not soup.find("li", class_="next"):
                break
            page += 1
    pass

if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """
    pass
