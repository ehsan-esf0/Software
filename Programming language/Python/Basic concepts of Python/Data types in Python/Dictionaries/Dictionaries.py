my_dict = {
    "name": "Alice",
    "age": 25,
    "is_student": True
}


print(my_dict.get("age"))
print(my_dict.get("city"))    
# print(my_dict["city"])

print(my_dict.items()) 

print(" --------------------------- ")

for k in my_dict:
    print(k)
    
for k, v in my_dict.items():
    print(k, v)
    
print(" --------------------------- ")
    
squares = {x: x**2 for x in range(5)}
print(squares)

dec = { x : f"number {x}" for x in range(5) if x % 2 == 0}
print(dec)

dec = {x : {y : y for y in range(2)} for x in range(2)}
print(dec)

d1 = {"a": 1}
d2 = {"b": 2}
merged = d1 | d2
print(merged)

merged = {**d1, **d2}
print(merged)


locations = {
    (35.7, 51.4): "Tehran",
    (48.8, 2.3): "Paris"
}
