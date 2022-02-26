"""Module to scrape information from a fake bookstoor
"""

#directory: iCloudDrive\Documents\College Baby\Spring 2022\LHRS Data Acquisition\StarterProjects\DataAcq
#virtual environment should already be created in this directory: python -m venv venv
#activate virtual environment for CMD: venv\Scripts\activate.bat

import requests
from bs4 import BeautifulSoup
import pandas as pd
import csv
from word2number import w2n

def scrape():
    SITE_URL = "http://books.toscrape.com/"

    title_big = []
    price_big = []
    rating_big = []
    availability_big = []

    for i in range(1,51):
        URL = "http://books.toscrape.com/catalogue/page-" + str(i) + ".html"
        page = requests.get(URL)
        soup = BeautifulSoup(page.content, "html.parser")
        results = soup.find("ol", class_="row")
        '''print(results.prettify())''' #if I wanted to print everything
        elements = results.find_all("article", class_= "product_pod")

        title_column = []
        price_column = []
        star_rating_column = []
        in_stock_status_column = []


        for element in elements:
            title = element.find("h3").text.strip()  #text converts html to text, strip deletes whitespace
            title_column.append(title)

            price = element.find("p", class_= "price_color").text.strip()[1:] #the brackets read the string from the 1st index on, which gets rid if the euro sign
            price_column.append(price)

            star_rating = element.find("p", class_= "star-rating")['class'][1].strip() #specify first word of class index. goes from 0 to 1
            #star_rating1 = w2n.word_to_num(star_rating)
            star_rating_column.append(star_rating)

            availability = element.find("p", class_= "instock availability").text.strip()
            in_stock_status_column.append(availability)
            #can use print function here if you'd like to print
            #print(title)
        
        title_big += title_column
        price_big += price_column
        rating_big += star_rating_column
        availability_big += in_stock_status_column

    data = {'Title' : title_big, 'Price' : price_big, 'Star_Rating' : rating_big, 'In-Stock_Status' : availability_big} #organize data from panda to read
    df = pd.DataFrame(data) #index=0 numbers the books!
    df.to_csv('data.csv')

if __name__== "__main__":
    scrape()
#SOMETHING IS WRONG WITH THE INDEXING!
#TRY THIS WITH {} for DATA!

