import csv
#f = open("test.txt","r")
#print(f.read)
while(True):
    with open('CAN.csv','r') as csv_file:
        csv_reader=csv.reader(csv_file,delimiter=",")
        line_count=0
        try:
            for row in csv_reader:
                if line_count==0:
                    print("ID: "+row[0])
                    line_count=1
                if line_count==1:
                    print("Message: "+row[1])
                    line_count=0
        except IndexError:
            pass


        
        