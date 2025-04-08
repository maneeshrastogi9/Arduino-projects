# compound interest

def CI(principal,rate,time):
    Amount = principal * (pow((1+rate / 100 ),time))
    ci = Amount - principal
    print("Compound intrest is ",ci)
    print(f"Total Amount you will recieve {Amount}")


CI(100000,15,7)