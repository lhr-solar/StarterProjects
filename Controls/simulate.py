import csv
with open('CAN.csv') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=', ')
    for row in csv_reader:
        print("ID: " + row[0])
        print("Message: " + row[1])