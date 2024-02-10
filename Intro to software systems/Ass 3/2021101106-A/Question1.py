val = input("Enter an even number: ")

x = int(val)
if(x%2==1) :
  print("Error! print only an even number")
  exit(0)

for i in range(x):
  if i < x/2 :
    for j in range(i):
     print(" ",end="")
    for j in range(i,x-i):
     print("*",end="")
    print(" ")
  else :
    for j in range(x-i-1):
     print(" ",end="")
    for j in range(x-i-1,i+1):
     print("*",end="")
    print(" ")