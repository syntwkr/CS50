from cs50 import get_string
from collections import Counter

text = get_string("Text: ")

# Count letters, words and sentences

cnt = Counter(text)
total_alphas = total_mods = total_space = 0

for key, value in cnt.items():
    if key.isalpha():
        total_alphas += value
    elif key.isspace():
        total_space += value + 1
    elif key in '.!?':
        total_mods += value

# Count grade level
L = (total_alphas / total_space) * 100
S = (total_mods / total_space) * 100
grade_level = round(0.0588 * L - 0.296 * S - 15.8)

# Print result
if grade_level <= 1:
    print("Before Grade 1")
elif grade_level >= 16:
    print("Grade 16+")
else:
    print("Grade " + str(grade_level))