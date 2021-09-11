import csv #get CAN.csv file 

while True:
    with open("CAN.csv", newline="") as CANFILE:   #open CAN file to read from, and "with" automatically closes file when finished reading
        reader = csv.reader(CANFILE, delimiter=",") #make file reader that splits things from by comma
        for row in reader:                          #read row by row
            if len(row)==2:                         #check if there's 2 items per row (ID and random number)
                print("ID: "+row[0]+ ", Message: "+row[1])
