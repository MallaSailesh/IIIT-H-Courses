c = -1
x = []
for i in range(10) :
    y = input("Enter string "+str(i+1)+" :- ")
    x.append(y)
# x = list(map(str, input("Enter 10 words with space seperating them: ").split()))
y = input("write ascending if u want print the elements in ascending order or descending if you want to print the elements in descending order :-  ")
print(" ")
if y=="ascending" :
    x.sort()
    print("\tAscending Order\n")
    for i in range(10) :
        print(x[i])
    print(" ")
    c = 0
elif y=="descending" :
    x.sort(reverse=True)
    print("\tDescending Order\n")
    for i in range(10) :
        print(x[i])
    print(" ")
    c = 1
else :
    print("Invalid Input")
if c!=-1:
 z = input("Enter another word :- ")
 x.append(z)
 print(" ")
if c==0 :
    x.sort()
    print("\tUpdated Ascending Order\n")
    for i in range(11) :
        print(x[i])
elif c==1:
    x.sort(reverse=True)
    print("\tUpdated Descending Order\n")
    for i in range(10) :
        print(x[i])
    
