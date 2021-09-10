# Data Acquisition Starter Project

## Summary
The purpose of this project is to get you familiarized with the tools, technologies, and processes we use here on this team. The main language we'll be using is `Python`, and we'll be using it to do **web scraping**, **data cleaning**, and **data visualization** using `Beautiful Soup`, `pandas`, and `matplotlib`, respectively. 

## The Setup
1. Create a python virtual environment called `venv/` by running the following command (substituting python for python3 if necessary)

    ```bash
    python -m venv venv
    ```

2. Activate the virtual environment

    ```bash
    source venv/bin/activate    # Unix
    venv\Scripts\activate.bat   # CMD
    venv\Scripts\Activate.ps1   # PowerShell
    ```

3. Install the requirements

    ```bash
    pip install -r requirements.txt
    ```
    If you need to install any additional packages during development, be sure to update the requirements.

## The Task
You will be provided with the link to this GitHub repository. You will need to **clone** the repository, create and checkout your own **branch**, complete the task, **push** to the remote repository, and open a **pull request**. The actual task is comprised of the following steps:

1. `scrape.py`: Scrape [this bookstore](http://books.toscrape.com/) using Beautiful Soup for information regarding the books, and store the data in a CSV file. Be sure to include the **title**, **rating**, **price**, and **in-stock** status in your CSV file. There are 1000 books in this fictional bookstore, so make sure to save the information for all of them to allow us to get the most data possible. 

2. `clean.py`: Now that we have all the data, we're going to provide a method to read it and clean it. This method should read the CSV data into a pandas dataframe, remove all the entries with a rating below 3 stars, and convert all the prices from pounds to US Dollars. It should then simply return this pandas dataframe object with the cleaned data.

3. `visualize.py`: We will now provide a generic method that accepts a pandas dataframe along with an x variable and y variable. It will simply plot all the data points in the pandas dataframe using the x and y variables as the columns to plot on the x and y axes respectively. 

4. `main.py`: With all these pieces, we can finally put everything together. Write a main engine that calls upon the `scrape` module to scrape the data, then calls the `clean` module to clean it, and finally passes the cleaned dataframe to the `visualize` module to plot the cleaned data. 

## Sources of Information
- Beautiful Soup
    - https://www.crummy.com/software/BeautifulSoup/bs4/doc/
- CSV
    - https://docs.python.org/3/library/csv.html
- Pandas
    - https://pandas.pydata.org/
- Matplotlib
    - https://matplotlib.org/stable/tutorials/index.html
    - https://pandas.pydata.org/pandas-docs/stable/user_guide/visualization.html
- Race Strategy (current design)
    - https://github.com/lhr-solar/RaceStrategy/tree/master/DataAcquisition
- Python
    - https://wiki.python.org/moin/BeginnersGuide
    - https://docs.python.org/3/library/venv.html

## Tips
- Make sure to commit frequently. Not every time you save a file, but enough to show a good history of your work.
- Make sure you are working on your own branch and not the master branch.
- **If you have any questions that cannot be answered by the resources above or the task instructions, feel free to ask.**