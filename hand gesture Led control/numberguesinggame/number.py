""" Module for generating random numbers """
import random

def initialize_game():
    """
    Initializes the game parameters and returns initial values.
    """
    counter = 0
    chance = 7
    return counter, chance

# Initialize the game parameters
counter, chance = initialize_game()

# Generate a random number to guess
number_to_guess = random.randint(0, 99)

# Open and read the welcome file
try:
    with open("welcome.txt", 'r', encoding="utf-8") as f:
        print(f.read())
except FileNotFoundError:
    print("Welcome file not found. Starting the game...")

# Game loop
while counter < chance:
    try:
        my_guess = int(input(f'Attempt {counter + 1}/{chance} - Please enter your guess: '))
    except ValueError:
        print("Invalid input! Please enter a valid number.")
        continue

    counter += 1  # Increment the counter for each attempt

    if my_guess == number_to_guess:
        print(f"You guessed the number {number_to_guess} correctly in {counter} attempt(s).")
        break
    elif my_guess > number_to_guess:
        print("Your guess is too high.")
    else:
        print("Your guess is too low.")

    if counter >= chance:
        print(f"Oops! You've used all your chances. The correct number was {number_to_guess}. Better luck next time!")
