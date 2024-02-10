from rule import *
arr = []
file = open('q3/config.txt','r')
output = open('q3/output.txt','w')
j=0
m=0
n=0
c = []
d = []
k=0
res = []
lines = file.readlines()
for i in lines:
    if(j==0):
        m,n,k = map(int,i.split())
        res = [ [0 for x in range(m+2)] for y in range(n+2)  ]
        arr = [ [0 for x in range(m+2)] for y in range(n+2)  ]
    else:
        x,y = map(int,i.split())
        arr[n + 1-y][x]=1
        c.append(x)
        d.append(y)
    j += 1
print("THE INITIAL STATE:\n\n")
for i in range(1,n+1):
    print()
    output.write("\n")
    for j in range(1,m+1):
        res[i][j] = arr[i][j]
        print(str(arr[i][j]),end='')
        if(res[i][j]==1):
            output.write("X")
        else:
            output.write(("O"))
print("\n")
itr = 0
output.close()
itr = int(input("Enter the number of iterations: "))
while (itr != -1):
    output = open('q3/output.txt','w')
    for tc in range(0,itr):  
        for i in range(1,n+1):
            for j in range(1,m+1):
                res[i][j] = rule(arr[i][j],[arr[i][j-1],arr[i][j+1],arr[i+1][j],arr[i-1][j],arr[i+1][j+1],arr[i-1][j+1],arr[i+1][j-1],arr[i-1][j-1]])
        for i in range(0,n):
            for j in range(0,m):
                arr[i][j] = res[i][j]
    for i in range(1,n+ 1):
        print()
        output.write("\n")
        for j in range(1,m + 1):
            print(str(res[i][j]),end='')
            if(res[i][j]==1):
                output.write("X")
            else:
                output.write(("O"))
    print('\n')
    output.close()
    itr = int(input("Enter the number of iterations: "))