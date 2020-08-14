
import csv

while True:
    with open("CAN.csv", newline="") as CANFILE:
        CANREADER = csv.reader(CANFILE,delimiter=",")
        for row in CANREADER:
            if len(row)==2:
                print("ID: "+row[0]+"Message: "+row[1])