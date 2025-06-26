t = (1, "hello", 3.14, True , [1 ,2 ,3 ,4 ,5])

print(t)
print(t[4])

# ❌ t[4] = [1 , 2 , 3]
t[4][2] = 9

print(t[4])

x = 1 , 2 , 3 , 4
print(x)

x1 , _ , x3 , x4 = x
print(x1)
# print(x2)
print(x3)
print(x4)

print(" --------------------------- ")
def stats(nums):
    return min(nums), max(nums), sum(nums)

mn, mx, total = stats([1, 2, 3])
print(mn)
print(mx)
print(total)
