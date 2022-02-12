
# import modules (requests)
import requests
import csv
import pandas as pd  # import pandas as an alias called pd
from bs4 import BeautifulSoup # from the bs4 module, import the Beautiful Soup function/method





# scrape function has a double loop, outer for the pages
# inner loop is for actually scraping
def scrape():
    headers = ['title','rating','price', 'stock status']
    with open("books.csv", "w", encoding="utf-8", newline = '') as csv_file:
        writer = csv.writer(csv_file)
        writer.writerow(headers)
        for i in range(1,51):
            SITE_URL = "http://books.toscrape.com/catalogue/page-xx.html"
            SITE_URL = SITE_URL[:-7] + str(i) + '.html'
            page = requests.get(SITE_URL)


            soup = BeautifulSoup(page.content, "html.parser")
            soup.prettify()
            book_results = soup.find_all("article", class_= 'product_pod')
            
            for book in book_results:
                rating = book.find('p', class_ ="star-rating")
                score = rating['class'][1]


                price = book.find('p', class_ ="price_color").text


                name = book.find('div',class_='image_container').find('img')['alt']

                stock = book.find('p',class_='instock availability').text.strip()
                writer.writerow([name,score,price,stock])
            
    return 

    

# For testing purposes
# If this is chosen to be a script, run the code in this section
# if __name__ == "__main__":
if __name__ == "__main__":
    scrape()


