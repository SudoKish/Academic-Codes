def input_percentage():
    perc = []
    number_of_students = int(input("Enter the number of Students : "))
    for i in range(number_of_students):
        perc.append(float(input(f"Enter the percentage of Student {i + 1} : ")))
    return perc

def print_percentage(perc):
    for i, percentage in enumerate(perc, start=1):
        print(f"Percentage of Student {i}: {percentage}")

def percentage_partition(perc, start, end):
    pivot = perc[start]
    lower_bound = start + 1
    upper_bound = end
    while True:
        while lower_bound <= upper_bound and perc[lower_bound] <= pivot:
            lower_bound += 1
        while lower_bound <= upper_bound and perc[upper_bound] >= pivot:
            upper_bound -= 1
        if lower_bound <= upper_bound:
            perc[lower_bound], perc[upper_bound] = perc[upper_bound], \
            perc[lower_bound]
        else:
            break
    perc[start], perc[upper_bound] = perc[upper_bound], perc[start]
    return upper_bound

def quick_sort(perc, start, end):
    if start < end:
        partition = percentage_partition(perc, start, end)
        quick_sort(perc, start, partition - 1)
        quick_sort(perc, partition + 1, end)

def display_top_five(perc):
    print("Top Five Percentages are : ")
    for i, percentage in enumerate(perc[-5:], start=1):
        print(f"Top {i}: {percentage}")

unsorted_percentage = []
flag = 1
while flag == 1:
    print("\n--------------------MENU--------------------")
    print("1. Accept the Percentage of Students")
    print("2. Display the Percentages of Students")
    print("3. Perform Quick Sort on the Data")
    print("4. Display Top 5 Percentages")
    print("5. Exit")
    ch = int(input("Enter your choice (from 1 to 5) : "))
    if ch == 1:
        unsorted_percentage = input_percentage()
    elif ch == 2:
        print_percentage(unsorted_percentage)
    elif ch == 3:
        sorted_percentage = unsorted_percentage.copy()
        quick_sort(sorted_percentage, 0, len(sorted_percentage) - 1)
        print("Percentages of Students after performing Quick Sort : ")
        print_percentage(sorted_percentage)
    elif ch == 4:
        if unsorted_percentage:
            display_top_five(unsorted_percentage)
        else:
            print("Please input percentages first.")
    elif ch == 5:
        print("Thanks for using this program!!")
        flag = 0
    else:
        print("Invalid Choice!!")

        
