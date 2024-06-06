
marklist=[]

n=int(input("Enter number of student : "))

for i in range(n):
    mark=(input(f"Enetr mark for {i+1} student : ")) 
    marklist.append(mark)    
    
# Calculate the average score of the class  
total=0
average_score=total/len(marklist)


for mark in marklist:
    if(int(mark)>=0):
        total=total+int(mark)
print(f"/nAverage score of the class = {average_score}")

# Calculate the highest and the lowest score of the class 
max_value = marklist[0]
min_value = marklist[0]

for mark in marklist:
    if mark < min_value:
        min_value=mark 
    if mark > max_value:
        max_value= mark     
    
print(f"The Highest score is {max_value}  and the lowest score is {min_value}")

# Calculating the absent student 

absent_student =0
for mark in marklist :
    if int(mark) < 0:
        absent_student += 1
        
print(f"Student Absent for the test are :{absent_student} ")

# calculating the highest frequency 

freq={}

for mark in marklist:
    if mark !=None :
        if freq.get(mark)==None :
            freq[mark] =1 
        else :
            freq[mark] +=1
            
highest_freq = 0
highest_freq_mark=0

for mark in freq:
    if freq[mark]  > highest_freq :
        highest_freq = freq[mark]
        highest_freq_mark = mark         
                  
print(f"The highest frequency is : {highest_freq_mark}")