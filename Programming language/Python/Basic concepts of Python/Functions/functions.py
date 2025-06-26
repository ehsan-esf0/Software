def sey_hello(name):
    """Print a greeting message."""
    print(f"Hello, {name}!")


sey_hello("ehsan")


def add(x, y):
    return x + y

print(add(3, 4)) 


def sey_hello_2(name = "ali"):
    """Print a greeting message."""
    print(f"Hello, {name}!")


sey_hello_2()


def power(base, exponent=2):
    return base ** exponent

print(power(exponent=3, base=4))  
print(power(3))  # default value of exponent is 2

def func(*args):
    return sum(args)

print(func(1, 2, 3, 3, 4, 5, 6, 7)) 

def func(**kwargs):
    print(kwargs)

func(a=1, b=2) 


def min_max(numbers):
    return min(numbers), max(numbers)

minimum, maximum = min_max([3, 1, 7, 4])
print(minimum, maximum)


def greet(name: str) -> None:
    print(f"Hello, {name}!")

def add(x: int, y: int) -> int:
    return x + y


def factorial(n: int) -> int:
    """
    Calculate factorial of n recursively.
    
    Args:
        n (int): non-negative integer
    
    Returns:
        int: factorial of n
    """
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

factorial(4)

count = 0

def increment():
    global count
    count += 1

increment()
increment()
increment()
increment()
print(count) 


square = lambda x: x * x
print(square(5))

points = [(1, 2), (4, 1), (5, -1)]
points_sorted = sorted(points, key=lambda point: point[1])
print(points_sorted) 

def apply_function(f, value):
    return f(value)

print(apply_function(lambda x: x ** 2, 5)) 
print(apply_function(square, 5))
 


