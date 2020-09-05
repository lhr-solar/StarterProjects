import csv
import time

with open('CAN.csv', 'r') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    while True:
        for row in csv_reader:
            print("ID: " + (str)(row[0]) + " Message:" + (str)(row[1]), end='\r')
            time.sleep(1)