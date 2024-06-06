# Write a python program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using quick sort and display top five scores.

import random

# Quick Sort function
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def main():
    students = [random.uniform(50, 100) for _ in range(10)]

    print("Unsorted array: ", students)

    sorted_arr = quick_sort(students)
    print("Sorted array: ", sorted_arr)

    # Display top five scores
    top_five = sorted_arr[-5:]
    print("Top five scores: ", top_five)

if __name__ == "__main__":
    main()
