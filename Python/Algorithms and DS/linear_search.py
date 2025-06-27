def linear_search(list, target) -> int:
    """ 
    Returns the index position of the target if found, else returns None
    """
    for index in range(0, len(list)):
        if list[index] == target:
            return index
    return None

def verify(index) -> None:
    if index is not None:
        print("Target found at index: ",index)
    else:
        print("Target not found in list")
    
numbers = [1,2,3,4,5,6,7,8,9,10]
result = linear_search(numbers,10)
verify(result)

        

