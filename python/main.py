# Insertion sort in Python

def insertionSort(array):
    for step in range(1, len(array)):
        key = array[step]
        j = step - 1

        # Compare key with each element on the left of it until an element smaller than it is found
        # For descending order, change key<array[j] to key>array[j].        
        while j >= 0 and key < array[j]:
            array[j + 1] = array[j]
            j = j - 1
            increment(array)
        
        # Place key at after the element just smaller than it.
        array[j + 1] = key
        increment(array)


# MergeSort in Python

def mergeSort(array):
    if len(array) > 1:

        #  r is the point where the array is divided into two subarrays
        r = len(array)//2
        L = array[:r]
        M = array[r:]

        # Sort the two halves
        mergeSort(L)
        mergeSort(M)
        i = j = k = 0

        # Until we reach either end of either L or M, pick larger among
        # elements L and M and place them in the correct position at A[p..r]
        while i < len(L) and j < len(M):
            if L[i] < M[j]:
                array[k] = L[i]
                i += 1
                increment(array)
            else:
                array[k] = M[j]
                j += 1
                increment(array)
            k += 1

        # When we run out of elements in either L or M,
        # pick up the remaining elements and put in A[p..r]
        while i < len(L):
            array[k] = L[i]
            i += 1
            k += 1
            increment(array)

        while j < len(M):
            array[k] = M[j]
            j += 1
            k += 1
            increment(array)


# Quick sort in Python

# Function to partition the array on the basis of pivot element
def partition(array, low, high):
    # Select the pivot element
    pivot = array[high]
    i = low - 1

    # Put the elements smaller than pivot on the left and greater 
    #than pivot on the right of pivot
    for j in range(low, high):
        if array[j] <= pivot:
            i = i + 1
            (array[i], array[j]) = (array[j], array[i])
            increment(array)

    (array[i + 1], array[high]) = (array[high], array[i + 1])
    increment(array)

    return i + 1


def quickSort(array, low, high):
    increment(array)
    if low < high:

        # Select pivot position and put all the elements smaller 
        # than pivot on left and greater than pivot on right
        pi = partition(array, low, high)

        # Sort the elements on the left of pivot
        quickSort(array, low, pi - 1)

        # Sort the elements on the right of pivot
        quickSort(array, pi + 1, high)

# print the array every time it is overwritten 
def increment(array):
    global count
    count+=1
    print("#" + str(count) +  " " + str(array))
    

# Print the array
def printList(array):
    for i in range(len(array)):
        print(array[i], end=" ")
    print()

# gloabl variable to count array updates
count = 0

# Driver program
if __name__ == '__main__':
    array = [13, 14, 11, 15, 12]
    print("\nCurrent Array: " + str(array))
    size = len(array)

    option = ""
    while(option==""):
        option = input("\nCommands:\n\ni: Insertion Sort\nm: Merge Sort\nq: Quick Sort\nQ: Quit\n\n:")
        if(option=="i" or option=="m" or option=="q" or option =="Q"):
            break
        else:
            option=""
    
    if(option=="i"):
        insertionSort(array)
    elif(option=="m"):
        mergeSort(array)
    elif(option=="q"):
        quickSort(array, 0, size - 1)
    elif(option=="Q"):
        exit(1)
