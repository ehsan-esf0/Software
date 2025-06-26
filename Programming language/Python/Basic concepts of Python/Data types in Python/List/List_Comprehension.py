squares = [x**2 for x in range(5)]
print(squares)

my_list = [ x for x in range(10) if x % 2 == 0 ]
print(my_list)

my_list = [ (((x + 2) * 3) / 10) for x in range(10) if x != 5 ]
print(my_list)

table = [[i * j for j in range(1, 6)] for i in range(1, 6)]
print(table)
