import sys
import csv

if len(sys.argv) != 3:
    sys.exit("Usage: python dna.py data.csv sequence.txt")  # check for correct usage
database = open(sys.argv[1], "r")
sequence = open(sys.argv[2], "r")

headers = [] 
STR = []
STRDICT = {}
person = []
dna = []

reader = csv.reader(database)
headers = next(reader)  # reads first line of csv file
database.close()
for i in range(1, len(headers)):
    STR.append(headers[i])  # adds STRs to list
dna = sequence.read()  # reads sequence file and adds to a list
for j in range(0, len(STR), 1):  # checks for each STR combo
    checker = STR[j]
    counter = 0
    maxstr = 0
    for k in range(len(dna)):  # iterates over dna list and checks if matches the corresponding STR
        n = dna[k:k+len(checker)]
        if n in checker:
            for l in range(k, len(dna), len(checker)):
                a = dna[l:l+len(checker)]
                if a in checker:
                    counter += 1
                    if counter > maxstr:
                        maxstr = counter
                else:
                    break
            counter = 0
    STRDICT[checker] = maxstr

file = open(sys.argv[1], "r")
reader = csv.DictReader(file)
for name in reader:
    person.append(name)
file.close

for i in range(len(person)):
    match = 0
    for j in range(len(STR)):
        if person[i][STR[j]] == str(STRDICT[STR[j]]):
            match += 1
        if match == len(STR):
            sys.exit(person[i]['name'])
print("No Match")
