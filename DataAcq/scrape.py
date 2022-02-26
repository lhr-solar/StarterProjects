"""Module to scrape information from a fake bookstoor
"""
import requests  
import pandas as pd
from bs4 import BeautifulSoup
import csv
import word2number


def scrape():
    SITE_URL = "http://books.toscrape.com/"
    page = requests.get(SITE_URL)
    soup = BeautifulSoup(page.content, "html.parser")

    #def scrape():
    
    SITE_URL = "http://books.toscrape.com/catalogue/page-xx.html"

    #price_list_total = []
    #rating_list_total= []
    #name_list_total = []
    #stock_list_total = []

    p_list = []  #list is for prices
    r_list = []  #list is for ratings
    n_list = []  #list is for titles
    s_list = []  #list is for in stock 

    for i in range(1,51):
        SITE_URL = "http://books.toscrape.com/catalogue/page-xx.html"   #gets the url of each individual page of products (50 each page)
        SITE_URL = SITE_URL[:-7] + str(i) + '.html'                     #Increments url to a new catalog page 
        page = requests.get(SITE_URL)
        soup = BeautifulSoup(page.content, "html.parser")
        results = soup.find("ol", class_= "row") 

        soup.prettify()
        book_results = soup.find_all("article", class_= 'product_pod')

        
        
        for book in book_results:
            title = book.find("h3").text.strip() #converts html to normal text and deletes whitespace
            n_list.append(title)
            
            rating = book.find("p", class_="star-rating")['class'][1].strip() #specifies that I want the first word element in the class (like an array)
            r_list.append(rating)
           
            price = book.find("p", class_="price_color").text[1:]
            p_list.append(price)

            in_stock = book.find("p", class_="instock availability").text.strip()
            s_list.append(in_stock)
                
            #price_list_total += p_list
            #rating_list_total += r_list
            #name_list_total  += n_list
            #stock_list_total += s_list

            #print(title)
            #print(rating)
            #print(price)
            #print(in_stock)
            #csv.addrows(title, rating, )
        #create a data frame in order to put the lists in each time you complete a page 
        data_frame = {'Title': n_list, 'Rating': r_list, 'Price': p_list, 'In Stock': s_list}
        df = pd.DataFrame(data_frame)
        df.to_csv('data.csv')
            
    


if __name__ == "__main__":
    """TODO: Write code here to test this
    particular module on its own
    """
    scrape()
    
