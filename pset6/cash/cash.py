from cs50 import get_float

# Ask user for change
while True:
    change = get_float("Change owed: ")
    if change > 0:
        break

# Converting dollars to cents
cents = round(int(change * 100))

coins = 0

change_rem = cents

# Using lists[]
nominals = [25, 10, 5, 1]
for nom in nominals:
    coins += change_rem // nom
    change_rem %= nom

print(coins)