from cs50 import get_int

# Ask user for height (0 < height > 9)
while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

# Printing spaces and hashes in one line of code, woo-hoo!
for row in range(height):
    print(" " * (height - row - 1) + "#" * (row + 1))
