while(True):
    f = open("CAN.csv", "r")
    string0 = f.readline()
    stringlist = string0.split(", ")
    print("ID: " + stringlist[0] + ", Message: " + stringlist[1])
    f.close()
