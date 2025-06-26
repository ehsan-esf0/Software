s = "Hello, World"

# Slicing Strings

print(s[0:5])     
print(s[7:])    
print(s[:5])     
print(s[::2])   
print(s[::-1])  

# Useful String Methods

print(len(s))
print(s.lower())
print(s.upper())
print(s.replace("World", "Python"))
print(s.strip())
print(s.find("Hello"))
print(s.split(","))
print(s.split(" "))
print(s.split("l"))
print(s.join("Python"))

s = "abc"

print(s.isdigit())
print(s.isalpha())