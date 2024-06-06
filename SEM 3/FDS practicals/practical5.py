#Write a python program to compute following computation on matrix: 
#a) Addition of two matrices 
#b) Subtraction of two matrices 
#c) Multiplication of two matrices 
#d) Transpose of a matrix


def Insertion_Sort ():
    p=[]
    n=int(input("Enter the number of students:"))
    for i in range (n):
        mark=float(input("Enter the percentage:"))
        p.append(mark)
    print("List of percentage of students:",p)
    for i in range (1,len(p)):
        temp=p[i]
        j=i-1
        while(j>=0 and temp<p[j]):
            p[j+1]=p[j]
            j=j-1
            p[j+1]=temp
        print("Pass",i+1,p)
    print("Top 5 scores are:")
    print(p[-5:])
       
def Shell_Sort():
    p=[]
    n=int(input("Enter the number of students:"))
    for i in range (n):
        mark=float(input("Enter the percentage:"))
        p.append(mark)
    print("List of percentage of students:",p)
    gap=len(p)//2
    while(gap>0):
        for i in range (gap,len(p)):
            temp=p[i]
            j=i
            while(j>=gap and temp < p[j-gap]):
                p[j]=p[j-gap]
                j=j-gap
                p[j]=temp
                gap=gap//2
            print("Pass",i+1,p)
        print("Top 5 scores are:")
        print(p[-5:])
            
while True:
    print("*******MENU********")
    print("1.) Insertion Sort")
    print("2.) Shell Sort")
    print("3.) EXIT")
    i = int(input("Enter your choice between (1-2):"))
    if i==1:
        Insertion_Sort()
    elif i == 2:
        Shell_Sort()
    elif i==3:
        print("THANKYOU!!")
        break
    else:
        print("INVALID CHOICE! PLEASE RE-ENTER...")