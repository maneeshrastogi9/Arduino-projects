num = int(input("enter Factorial Number "))

factorial = 1

for i in range(1,num+1):
    factorial *= i

print(f"the factorial of {num} is {factorial}")