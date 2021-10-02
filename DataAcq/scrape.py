"""Module to scrape information from a fake bookstoor
"""
import requests
import csv

SITE_URL = "http://books.toscrape.com/catalogue/page-"

from bs4 import BeautifulSoup

def scrape():
    bookstore = []

    for x in range(1, 50):
    
        r = requests.get(f"{SITE_URL}{x}.html")

        soup = BeautifulSoup(r.content, 'html.parser')

        book_elements = soup.find_all("article", class_ = "product_pod")
        for book_element in book_elements:
            anchor_element = book_element.h3.a
            title_element = anchor_element['title']

            icon_element = book_element.find("p", class_ = "star-rating")
            star_element = icon_element['class']
            rating_element = star_element[1]

            tag_price_element = book_element.find("p", class_ = "price_color")
            full_price_element = tag_price_element.text.strip()
            price_element = full_price_element[1:]
            float(price_element)

            status_element = book_element.find("p", class_ = "instock availability")

            bookstore.append([title_element.strip(), rating_element.strip(), price_element, status_element.text.strip()])

    with open('book_file.csv', mode = 'w') as book_file:
        fieldnames = ['title', 'rating', 'price', 'status']
        book_writer = csv.DictWriter(book_file, fieldnames = fieldnames)
        book_writer.writeheader()
        for row in bookstore:
            book_writer.writerow({'title': row[0], 'rating': row[1], 'price': row[2], 'status': row[3]})

if __name__ == "__main__":
    scrape()