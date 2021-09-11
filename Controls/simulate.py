import csv #get CAN.csv file 

while True:
    with open("CAN.csv", newline="") as CANFILE:   #open CAN file to read from
        CANREADER = csv.reader(CANFILE,delimiter=",") #make file reader that splits things from CANFILE
        for row in CANREADER:
            if len(row)==2:
                print("ID: "+row[0]+", Message: "+row[1])
