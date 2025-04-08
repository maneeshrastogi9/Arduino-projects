# compound interest

def CI(principal,rate,time):
    Amount = principal * (pow((1+rate / 100 ),time))
    ci = Amount - principal
    print("Compound intrest is ",ci)
    print(f"Total Amount you will recieve {Amount}")



principal = int(input("Enter the principal amount: "))
rate = int(input("Enter rate of interest: "))
time = int(input("Enter time in years: " ))
CI(principal,rate,time)