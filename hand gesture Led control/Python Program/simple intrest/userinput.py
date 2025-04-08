


def Simple_interest(Amount,rate,Time):
   
    simple_interest =(Amount * rate * Time)/100
    print(f"Intrest on principal Amount {Amount} and rate of intrest {rate} and Time {Time} year is {simple_interest} Rupees")



Amount = int(input("Enter the Principal Amount"))
rate =int(input("Enter Rate of Interest"))
Time = int(input("Enter the Time in Year "))
Simple_interest(Amount,rate,Time)