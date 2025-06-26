my_list = [1, 2, 3, 4, 5]

print(my_list[-2])

# List Slicing

print(my_list[1:])
print(my_list[:3])
print(my_list[1:4])
print(my_list[::-1])

# Modifying List Elements

my_list[0] = 100
print(my_list)
my_list[1:3] = [200, 300]
print(my_list)

my_list[1:3] = [200, 300 , 400 , 500]
print(my_list)


my_list[::2] = [0 , 0 , 0 , 0] 
# It does not work like a iterator 
print(my_list)

my_list = [1, 2, 3, 4, 5]


# Adding Elements
my_list.append(60)        
print(my_list) 
my_list.insert(2, 25)      
print(my_list) 
my_list.extend([70, 80]) 
print(my_list)

# Removing Elements
my_list.remove(25)    
print(my_list) 
del my_list[1]        
print(my_list) 
last = my_list.pop()
print(my_list) 

# Methods
my_list = [ 3 ,5 ,8 ,4 ,2 ,1]
my_list.sort()
print(my_list) 

print(my_list.count(3)) 

# Nested Lists
matrix = [[1, 2], [3, 4], [5, 6]]

print(matrix[1])   
print(matrix[1][0])

# Copying Lists

list_1 = [ 1 , 2 , 3 ]

print(id(list_1))

list_2 = list_1

print(id(list_2))
print(id(list_2) == id(list_1))

list_2[0] = 100

print(list_1)

list_3 = list_2.copy()
list_2[0] = 200
print(list_3)
print(list_2)
print(list_1)

