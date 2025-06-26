my_set = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

my_set.add(11)
print(my_set)

my_set.remove(2) # delete value
print(my_set)

a = {1, 2, 3}
b = {3, 4, 5}

print(a | b)  
print(a & b) 
print(a - b) 
print(a ^ b) 

# my_set[3] = 100
# object does not support item assignment 
print(my_set)

print(set([1 ,2 ,3 ,4 , 3, 2, 1, 2]))
# The set is made for unique storage

