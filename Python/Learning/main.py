""" ******************************** Python - Basics ************************** """
basic = 0                                                              
oops = 0
goodtoknow :int = 0 # using the 'type annotation' we are making sure that value assigned to 'goodtoknow' is int, if not pycharm will throw an error
if basic == 1:  ################## Ex 1: Concatenation methods for different data types
    name = 'Alpha'
    age = 25
    # in order to concatenate string we can use +, but to concatenate string with different date types than use commas,
    #print("Author name is" +name + "and he is" + age + "years old") ----- This will throw an error as we try to concatenate string and int
    print("Author name is "+name+" and he is",age,"years old") # use commas for concatenate string or other data type
    print("Author name is",name,"and he is",age,"years old") # use commas for all data type and we can see the spacing is properly done with the comma concatentaion

elif basic == 2: ################## Ex 2: Getting user input 
    sentence = input('Enter your Sentence: ')
    print('Your Sentence is : ',sentence)
    word1 = input('Enter the word to replace: ') # Like scanf in c, input is for python which will take the input from user
    word2 = input('Enter the word to replace it with: ')
    print(sentence.replace(word1,word2)) # replace method is used to replace the word which needs to be replaced

elif basic == 3: ################## Ex 3: List - Mutables
    countries = ['Russia', 'India', 'USA', 'Australia', 'Namibia', 'Egypt', 'Canada'] # List
    countries[2] = 'China' # we can able to change any value 
    print(countries[2]) # print the index two list value
    print(countries[2][0]) # print the index two letter 0 of list value
    print(countries[1:]) # print from index 1 to end ---- this is the range specifier as we didnt specify the end so it will print upto the end
    print(countries[1:3]) # print from index 1 to (3-1), where it will not print the last one
    print(countries[-1]) # print the last value in the list 
    print(countries[-2]) # print the last before value in the list 
    print(type(countries)) # to know the data type
    print(len(countries)) # to know the size of the list

    countries = ['Russia', 'India', 23, 'Australia', 3.08, True, 'Canada'] # List which has different data types like string, int, float, and boolean
    # all the above index, range, type and len will work for this too
    print(type(countries)) # List
    print(type(countries[1])) # String
    print(type(countries[2])) # int
    print(type(countries[4])) # float
    print(type(countries[5])) # Boolean
    # We can specify the list using list constructor method too
    countries = list(('Russia', 'India', 23, 'Australia', 3.08, True, 'Canada')) # List constructor method --  we should have two bracess
    print(countries) # List
    print(type(countries)) # List
    print(type(countries[1])) # String
    print(type(countries[2])) # int
    print(type(countries[4])) # float
    print(type(countries[5])) # Boolean

    demo = [1, 2, 3, 4, 5,]
    countries.extend(demo) # extend the list
    print(countries)
    demo.append('10') # Append into the list
    print(demo)
    demo.insert(3,'hai') # insert 'hai' at the index 3 of the list
    print(demo) 
    demo.remove('hai') # remove 'hai' from the list
    print(demo) 
    demo.clear() # clear everything from the list but list will be in memory as empty list
    print(demo) # list is empty
    demo1 = ['yellow', 'white', 'green', 'black', 'blue', 'green']
    print(demo1.index('green')) # to find the index of the member
    print(demo1.count('green')) # to count how many times a member is repeating in the list
    demo1.reverse() # to reverse the list
    print(demo1)
    demo = [4, 0, 9, 3, 10, 2]
    demo.sort() # to sort the list in ascending order
    print(demo)
    demo3 = demo.copy() # copy the list demo into demo3
    print(demo3)
    demo3.pop() # pop the last element in the list
    print(demo3) 
    demo3.pop(1) # pop the specific index in the list
    print(demo3)
    del demo3[2] # this is also another method to delete the member
    print(demo3)
    del demo3 # to delete the list from the memory
    print(demo3) # will get an error saying that its not defined

elif basic == 4: ################## Ex 4: Tuples - Immutables
    countries = ('Russia', 'India', 'USA', 'Australia', 'Namibia', 'Egypt', 'Canada') # Tuple
    ######countries[2] = 'China' # will create an error as 'tuple' object does not support item assignment
    num = (1, 3, 8, 1, 5)
    print(num) # Repeation of members is allowed in tuples
    print(len(num))
    print(type(num))
    """ All the different things like diff data type, duplicate values are allowed in tuples except that we cant change value once it is assigned
     Tuples are used when we dont want to change the value at run time or any one in the program execution """

elif basic == 5: ################## Ex 5: Function
    def test(*names): # * means that we are going to recevive lot of data, like dynamic data
        print('Welcome ' +names[0]) # we should use index to access the proper data
    test('John', 'Hai', 'sfsdf')

elif basic == 6: ################## Ex 6: Dictonaries - Key value pair
    my = {
        'Name': 'Tim', 
        'Name': 'John', # It will print the most recent one means the index value should be high to get the recent value
        'Nationality': 'Africa', 
        'Age': 34,
        'Is tall': True,
        'Qualification': 'College',
        'Friends': ['sam', 'brook', 'yoyo']
        }
    print(my) 
    # Duplicates keys are not allowed, even if we try to add to many same name than dictionary will automatically remove,
    # Duplicate values are allowed but not duplicate key
    print(my['Friends']) 

elif basic == 7: ################## Ex 7: Loops
    i = 10

    while i < 15 and i ==10: # using and keyword
        print(i)
        i=i+1

    i = 18

    while i < 20 or i ==5: # using or keyword
        print(i)
        i=i-1
        if i == 1:
            break # break the loop when condition satisfies

    for letter in 'Hello': # iterate the Hello by variable letter
        print(letter) 

    for x in range(10): 
        print(x) # print from 0 to 10 -1

    for x in range(3, 7): # print from 3 to 7-1
        print(x)
    else:  # we can use else in for loop also to show that we finished Iteration
        print('Finished Looping')

elif basic == 8: ################## Ex 8: 2D List
    my_list = [
            [1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]
    ]
    print(my_list[2][1])

elif basic == 9: ################## Ex 9: Try Except in Python
    try: # Execute his code
        x = int(input('Enter an integer: '))
        print(x)
    except: # If anything wrong than this will execute
        print('Something went wrong')
    else: # If nothing is wrong than this will execute --- Even wihtout else also this will try and execute work fine
        print('Perfect')
    finally: # Even if try executes or except executes this will execute
        print('Try executed successfully')

elif basic == 10: ################## Ex 10: File System
    file = open('C:/Users/arun.p/Desktop/Mine/Python/Learning/Countries.txt','r') # Open the file and store it in file descriptor
    # r = read only, w = write only, a = append only (only at the end we can append, not allowed to modify)
    # r+ = read and write,
    """ 
    print(file.readable()) # To check whether the file is readable or not
    print(file.readline()) # To read the first line of the file
    print(file.readline()) # To read the second line of the file
    # readline automatically read the line and move the file descriptor to the next line
    # Most recommended is the readlines because it reads all the lines and store it in temporary list
    print(file.readlines()) # To read all the file contents
    """
    #print(file.readlines()[3]) # To read the first line of the file or use any number to read that specific line

    for lines in file.readlines():
        print(lines)
    file.close() # Close the file descriptor

oops = 7
""" ******************************** Python - OOP ****************************** """
if oops == 1:    ################# Ex 1: Python data type is a class ############################
    item = 'phone' # All data types of python are associated with the instances of classes like string, integer, float,
    item1 = 12 # instances of int class
    item2 = 12.09 # instances of float class
    print(type(item))
    print(type(item1))
    print(type(item2))

elif oops == 2:  ################# Ex 2: Object created is always a first parameter for class methods ########################
    # Python always sends object name as a 1st parameter for the methods which is defined in the class
    class Item:
        # we can use any name instead of 'self' but by python convention it is recommended to use 'self'
        def calculate_total_price(self,x,y): # if self keyword is not there than we will get an error
            return x*y                         

    product1 = Item() # object product1 is created from the class Item()
    product1.name = "Phone"
    product1.price = 200
    product1.quantity = 5
    # Whenever the method of the class is invoked than object name is the 1st parameter, here product1 object is the 1st parameter for the calculate_total_price 
    val = product1.calculate_total_price(product1.quantity,product1.price)# Even though we send only two parameters, by default method will take object name as 1st parameter
    print(val)

elif oops == 3:  ################## Ex 3: Magic method or default method or constructor is __init__() ############################
    class Item:
        # python automatically calls this method during the instance of the object 
        def __init__(self,name,price,quantity=0): # default value for quantity is 0 if we didnt pass any parameter for it
            self.name = name # assigned the name to the object name
            self.price = price # assigned the price to the object price
            self.quantity = quantity # assigned the quantity to the object quantity

        def calculate_total_price(self):
            return self.price * self.quantity                     

    product1 = Item("phone",100,5)
    val = product1.calculate_total_price()
    print(val)

elif oops == 4:  ################## Ex 4: __init__ special cases ################################
    class Item:
        pay_rate = 0.8 # Class Attribute
        def __init__(self,name: str, price: float, quantity=0): # (: data type) force that to be a specified data type to avoid wrong data manipultaion if we pass int for string or otherwise
            # Run validation to the received arguments
            assert price >= 0   # assert is an statement keyword, it can check the received value is in the specified range, if not assertion error will be triggered
            # Another method to get the user defined error messages 
            assert quantity >= 0, f"Quantity {quantity} is not greater or equal to zero!"             
            # Assign to self object
            self.name = name 
            self.price = price 
            self.quantity = quantity 

        def calculate_total_price(self):
            return self.price * self.quantity     

        def apply_discount(self):
            self.price = self.price * self.pay_rate

    product1 = Item("phone", 100, 4)
    print(product1.name)
    val = product1.calculate_total_price()
    print(val)
    print(Item.pay_rate) # we called by a class name itself so it has the attirbute pay_rate in class
    print(product1.pay_rate) # we called via instances product1 where it dont have attibute pay-rate in instance level and it went ahead to look for it in class level
    # Instance and Class attribute is visible by using the __dict__ keyword
    print(Item.__dict__) # all the attibutes for class level in dictionary format
    print(product1.__dict__) # all the attibutes for instance level in dictionary format
    product1.apply_discount()
    print(product1.price)

elif oops == 5:  ################## Ex 5: Class Attributes #####################################
    class Item:
        pay_rate = 0.8 # Class Attribute

        def __init__(self,name: str, price: float, quantity=0): 
            # Run validation to the received arguments
            assert price >= 0   
            assert quantity >= 0, f"Quantity {quantity} is not greater or equal to zero!"             
            # Assign to self object
            self.name = name 
            self.price = price 
            self.quantity = quantity 

        def calculate_total_price(self):
            return self.price * self.quantity     

        def apply_discount(self):
            self.price = self.price * self.pay_rate 

    product1 = Item("phone", 100, 4)
    product1.apply_discount()
    print(product1.price)
    product2 = Item("Laptop", 1000,3)
    product2.pay_rate = 0.7 # Even Though pay_rate is in class still it takes 1st instances (object) attibute as priority
    product2.apply_discount()
    print(product2.price)

elif oops == 6:  ################## Ex 6: List to store all the instances created for class #########################
    class Item:
        pay_rate = 0.8 # Class Attribute
        all = [] # Empty list to store the instances which are created for this class

        def __init__(self,name: str, price: float, quantity=0): 
            # Run validation to the received arguments
            assert price >= 0   
            assert quantity >= 0, f"Quantity {quantity} is not greater or equal to zero!"             
            # Assign to self object
            self.name = name 
            self.price = price 
            self.quantity = quantity 
            # Item = Class name
            # all = Class attributes which is a list
            # append(self) = append the currently created instances into the list 
            Item.all.append(self)

        def calculate_total_price(self):
            return self.price * self.quantity     

        def apply_discount(self):
            self.price = self.price * self.pay_rate 

    product1 = Item("Phone", 100, 4)
    Product2 = Item("Laptop", 1000,3)
    product3 = Item("Cable", 10, 5)
    product4 = Item("Mouse", 50, 7)
    product5 = Item("Keyboard", 75, 2)
    for object in Item.all:
        print(object.name)

elif oops == 7:  ################## Ex 7: Represent a object in user defined way ####################
    class Item:
        pay_rate = 0.8 # Class Attribute
        all = [] # Empty list to store the instances which are created for this class

        def __init__(self,name: str, price: float, quantity=0): 
            # Run validation to the received arguments
            assert price >= 0   
            assert quantity >= 0, f"Quantity {quantity} is not greater or equal to zero!" 
            
            # Assign to self object 
            self.name = name 
            self.price = price 
            self.quantity = quantity 
            Item.all.append(self)

        def calculate_total_price(self):
            return self.price * self.quantity     

        def apply_discount(self):
            self.price = self.price * self.pay_rate 
        
        # without the __repr__ method, this will show objects in some number format. Inorder to display in understable format we use __repr__ method
        def __repr__(self):
            return f"Item('{self.name}',{self.price},{self.quantity})"

    product1 = Item("Phone", 100, 4)
    product1.temp_val = 10
    print(product1.temp_val)
    #print(Item.temp_val)
    Product2 = Item("Laptop", 1000,3)
    product3 = Item("Cable", 10, 5)
    product4 = Item("Mouse", 50, 7)
    product5 = Item("Keyboard", 75)
    print(product5.quantity)
    product6 = Item("Keyboard", 8, -67)
    print(product6.quantity)
    print(product6.price)
    print(Item.all)

elif oops == 8 :################## Ex 8: Why object name is the 1st parameter in class methods ######################### 
    """ By default while calling a method in the class, the object name will be passed as an 1st argument
     as we know already the every object created via a class will have a different memory address
     as the methods needs to know for which object it has been called. """
    class Item:
        pay_rate = 0.8 # Class Attribute

        def __init__(self,name: str, price: float, quantity=0): 
            # Run validation to the received arguments
            assert price >= 0   
            assert quantity >= 0, f"Quantity {quantity} is not greater or equal to zero!"             
            # Assign to self object
            self.name = name 
            self.price = price 
            self.quantity = quantity 

        def calculate_total_price(self):
            return self.price * self.quantity     

        def apply_discount(self):
            self.price = self.price * self.pay_rate 
    
    product1 = Item("Phone",1000,1)
    # calling the method "calculate_total_price" by normal way
    print(product1.calculate_total_price())
    # calling the method "calculate_total_price" by class way with object as 1st parameter
    print(Item.calculate_total_price(product1))

elif oops == 9 :################## Ex 9: First Class Function #########################    
    """ First Class Function  :   A programming language is said to have first class functions if it treats functions as first class citizens
        First Class Citizens  :   A first-class citizen (sometimes called first-class objects) in a programming language is an entity which supports all the operations generally available
                                  to other entities. These operations typically include being passed as an argument, returned from a function, and assigned to a variable. """
    Test = 1
    def square(x):
        return x * x
        
    if Test == 1: # Assigning the function to variable
        f = square(5) # we are executing the function 
        g = square # we are assigning the square function to the variable g
        print(f"Function address of square is {square}") # function address
        print(f"Square of f is {f}") # function return value

        print(f"Function address of square is {square}") # function address
        print(f"Function address of g is {g}") # function address
        print(f"Square of g is {g(7)}") # we are executing the function with value 7
    
    #elif Test == 2: # Assign the function to the variable with parameters  

elif oops == 10 :################## Ex 10: Represent a object in user defined way #########################
    class Item:
        pay_rate = 0.8 # Class Attribute
        all = [] # Empty list to store the instances which are created for this class

        def __init__(self,name: str, price: float, quantity=0): 
            # Run validation to the received arguments
            assert price >= 0   
            assert quantity >= 0, f"Quantity {quantity} is not greater or equal to zero!" 
            
            # Assign to self object 
            self.name = name 
            self.price = price 
            self.quantity = quantity 
            Item.all.append(self)

        def calculate_total_price(self):
            return self.price * self.quantity     

        def apply_discount(self):
            self.price = self.price * self.pay_rate 
        
        @classmethod
        def instantiate_from_csv(cls):
            pass
        
        def __repr__(self):
            return f"Item('{self.name}',{self.price},{self.quantity})"

    product1 = Item("Phone", 100, 4)
    Product2 = Item("Laptop", 1000,3)
    product3 = Item("Cable", 10, 5)
    product4 = Item("Mouse", 50, 7)
    product5 = Item("Keyboard", 75, 2)

    print(Item.all) 
    
if goodtoknow == 1: ################## Ex 1: Modules Importing ways and why #########################
    # Method 1 -> Import without __name__ == '__main__' in module.py ( connect will execute 2 times)
    # Method 2 -> Import with __name__ == '__main__' in module.py ( connect will execute 1 time)
    from module import connect

    if __name__ == '__main__':
        connect()

elif goodtoknow == 2: ################## Ex 2: Always use main function in python for good practice #########################
    def greet() -> None: # using the 'type annotation' we are informing that the return type is None
        print('Hai Welcome')
    
    def bye() -> None:
        print('Bye, World!')
    
    def main() -> None: # Good to invoke from main to have a better code readability and flow control
        greet()
        bye()

    if __name__ == '__main__':
        main()

elif goodtoknow == 3: ################## Ex 3: Type Annotations #########################
    number :int = 10 # variable of int, if we assign anything other than int than pycharm will throw an highlight in editor but not interpretation error

    def upper(elements :list[str]) -> list[str]:
        return[elem.upper() for elem in elements] # editor will automatically pop out different methods we can use on string if we use type annotations
    
    loud_list: list[str] = upper(['Mario','James','Sandr'])
    print(loud_list)
    loud_list2: list[int] = upper(['Mario','James','Sandr'])  #pycharm will throw highlight as we are trying to send 'int' in place of 'str'
    print(loud_list2)

    """ We can install pip install mypy or run the program by mypy main.py to invoke the static type checker """
goodtoknow = 4
if goodtoknow == 4: ################## Ex 4: List Comprehension #########################
    people: list[str] = ['James', 'Charlotte', 'Stephany', 'Mario', 'Sandra']
    # Without list comprehension
    long_names: list[str] = []
    for person in people:
        if len(person) > 7:
            long_names.append(person)

    print(f'Long Names: {long_names}')

    # with list comprehension
    """ Return type     ==> p
        loop iterator   ==> p
        condition       ==> len(p) > 7 """ 
    long_names: list[str] = [p for p in people if len(p) > 7] 

    print(f'Long Names: {long_names}')


