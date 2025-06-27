def recursive_binary_search(list, target):
    if len(list) == 0:
        return False
    else:
        midpoint = (len(list)//2)
        if list[midpoint] == target:
            return True
        else:
            if list[midpoint] < target:
                return recursive_binary_search(list[midpoint+1:],target) # we are sending the list from midpoint+1 to the end of the list
            else:
                return recursive_binary_search(list[:midpoint],target)
        
def verify(result) -> None:
    print("Target Found: ",result)


numbers = [1,2,3,4,5,6,7,8,9,10] # for binary search the list should be sorted before the search, if not we will never find the value even if it is there in the list
result = recursive_binary_search(numbers,5)
verify(result)


