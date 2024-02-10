list = []
list2 = []
n = input("Number of records :- ")
x = int(n)
for i in range(x) :
    a = input("Enter the Name of student "+str(i+1)+"             :-   ")
    b = input("Enter the RollNumber of student "+str(i+1)+"       :-   ")
    c = input("Enter the marks in maths of student "+str(i+1)+"   :-   ")
    d = input("Enter the marks in CSE of student "+str(i+1)+"     :-   ")
    e = input("Enter the marks in science of student "+str(i+1)+" :-   ")
    print()
    dict = {"Name":a,"Roll-Number": b ,"Mean":(float(c)+float(d)+float(e))/3}
    dict["Maths"] = c
    dict["Science"] = e
    dict["CSE"] = d
    if(float(c)<=float(d) and float(d)<=float(e)) :
        dict["Median"] = d
    elif(float(c)<=float(d) and float(c)>=float(e)) :
        dict["Median"] = c
    else :
        dict["Median"] = e
    list2.append((float(c)+float(d)+float(e))/3)
    list.append(dict)
print("\n\tRoll-Number\t\t"+"Name")
for i in range(x) :
    print("\t"+str(list[i]["Roll-Number"])+"\t\t\t"+list[i]["Name"])
print()
list2.sort(reverse=True)
for i in range(x) :
    for j in range(x):
        if(list2[i]==list[j]["Mean"]) :
            list[j]["Rank"] = i+1
            break
y = input("Enter name or rollnumber to give his or her details :- ")
ch = 0
for i in range(x):
    if(y==str(list[i]["Name"]) or y==list[i]["Roll-Number"]):
        ch = 1
        print(list[i])
        break
if (ch == 0) :
    print("Check again ! Name or Rollnumber entered is not there in the data")
    