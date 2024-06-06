# Define a function for deposit
def deposit(net_amount, amount):
    net_amount += amount
    return net_amount

# Define a function for withdraw
def withdraw(net_amount, amount):
    if net_amount >= amount:
        net_amount -= amount
    else:
        print("Insufficient balance")
    return net_amount

# Initialize the net amount to zero
net_amount = 0

# Use a while loop to read the user input
while True:
    # Get the user input as a string
    user_input = input()
    # Break the loop if the input is blank
    if user_input == "":
        break
    # Split the input by a space
    user_input = user_input.split(" ")
    # Get the operation and the amount
    operation = user_input[0].upper()
    amount = int(user_input[1])
    # Check the operation and perform the calculation
    if operation == "D":
        net_amount = deposit(net_amount, amount)
    elif operation == "W":
        net_amount = withdraw(net_amount, amount)
    else:
        print("Invalid operation")

# Print the final net amount
print(net_amount)