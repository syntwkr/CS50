import sys
import csv
import re

if len(sys.argv) != 3:
    print("Usage: dna.py database.csv sequence.txt")
    sys.exit(1)

db_file = sys.argv[1]
sequence = sys.argv[2]
patterns = []
strs = {}

with open(sequence, "r") as f:
    seq = f.read().rstrip()

with open(db_file, "r") as csv_file:
    csv_reader = csv.DictReader(csv_file)
    line_num = 0
    for line in csv_reader:
        # Start with the header to get the STRs
        if line_num == 0:
            # Parse the patterns, slice out "name"
            patterns = list(line.keys())[1:]
            for pat in patterns:
                # Compile regex object with pattern
                cpt = re.compile(rf'({pat})\1*')
                # Make a list of matches, counting them in groups of consecutive patterns
                matches = [match.group().count(pat) for match in cpt.finditer(seq)]
                # Assign max consecutive patterns if there's no matches of str in a sequence, assign 0
                strs[pat] = str(max(matches)) if matches else 0
        strs['name'] = line['name']
        if strs == line:
            print(strs['name'])
            sys.exit(0)
        line_num += 1

print('No match')