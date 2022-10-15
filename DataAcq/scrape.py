from bs4 import BeautifulSoup
import requests
import csv
import pandas as pd


headers = {
    'Access-Control-Allow-Origin': '*',
    'Access-Control-Allow-Methods': 'GET',
    'Access-Control-Allow-Headers': 'Content-Type',
    'Access-Control-Max-Age': '3600',
    'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:52.0) Gecko/20100101 Firefox/52.0'
    }

titles = []
prices = []
ratings = []
stock = []

data = []

def scrape():

    page = 1

    for page in range(51):

        print(f"Page {page} -----------------------------")

        SITE_URL = f"http://books.toscrape.com/catalogue/page-{page}.html"

        req = requests.get(SITE_URL, headers)
        soup = BeautifulSoup(req.content, 'html.parser')

        for product in soup.find_all('article'):
            
            # print("Book title: " + product.contents[5].a['title'])
            # print("Book rating: " + product.contents[3]["class"][1])
            # print("Book price: " + product.contents[7].p.string)
            # print("In Stock: " + product.contents[7].find_all('p')[1].contents[2].strip())

            titles.append(product.contents[5].a['title'])
            ratings.append(product.contents[3]["class"][1])
            prices.append(product.contents[7].p.string)
            stock.append(product.contents[7].find_all('p')[1].contents[2].strip())

            data.append([product.contents[5].a['title'], product.contents[3]["class"][1], float(product.contents[7].p.string[1:]), product.contents[7].find_all('p')[1].contents[2].strip()])
            # with open('books.csv', 'a+') as file:
            #     writer = csv.writer(file)
            #     writer.writerow(data)
        # pass
    
    # page+=1

    columns = [titles, ratings, prices, stock]
    df = pd.DataFrame(data)
    df.to_csv('books.csv')

    


if __name__ == "__main__":
    scrape()
    
    pass
