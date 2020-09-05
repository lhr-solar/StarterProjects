import csv
import time

while True:
    with open('CAN.csv', 'r') as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        for row in csv_reader:
            print("ID: " + (str)(row[0]) + " Message:" + (str)(row[1]), end='\r')
