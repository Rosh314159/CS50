from cs50 import get_string

words = 1
letters = 0
sentences = 0
text = get_string("Text: ")

for i in range(len(text)):
    if text[i] == ' ':
        words += 1
    elif text[i] == '.' or text[i] == '!' or text[i] == '?':
        sentences += 1
    elif ord(text[i].lower()) >= 97 and ord(text[i].lower()) <= 122:
        letters += 1
L = (letters / words) * 100
S = (sentences/words) * 100
index = round(0.0588 * L - 0.296 * S - 15.8) 
if index >= 16:
    print("Grade 16+")
if index < 1:
    print("Before Grade 1")
else:
    print("Grade " + str(index))