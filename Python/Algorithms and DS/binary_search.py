def binary_search(list,target) -> int:
    first = 0
    last = len(list) - 1 # To get the last element index of the list

    while first <= last:
        midpoint = (first + last) // 2 # // is the floor division to round off the value as index cannot be in decimal
        if list[midpoint] == target:
            return midpoint
        elif list[midpoint] < target:
            first = midpoint + 1
        else:
            last = midpoint - 1    
    return None # if the index is not found in the list

def verify(index) -> None:
    if index is not None:
        print("Target found at index: ",index)
    else:
        print("Target not found in list")
    
numbers = [1,2,3,4,5,6,7,8,9,10] # for binary search the list should be sorted before the search, if not we will never find the value even if it is there in the list
result = binary_search(numbers,8)
verify(result)