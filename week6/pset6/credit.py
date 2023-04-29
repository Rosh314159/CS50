from cs50 import get_string

sum1 = 0
sum2 = 0
number = get_string("Number: ")
for i in range(len(number) - 2, -1, -2):
    total = 0
    digit = int(number[i]) * 2
    if digit >= 10:
        total = (digit % 10) + 1
    else:
        total = digit
    sum1 += total
for j in range(len(number) - 1, -1, -2):
    sum2 += int(number[j])
sum3 = sum1 + sum2
if sum3 % 10 == 0:
    if (int(number[0]) == 4) and (len(number) == 13 or len(number) == 16):
        print("VISA")
    elif len(number) == 15 and int(number[0]) == 3 and (int(number[1]) == 4 or int(number[1]) == 7):
        print("AMEX")
    elif len(number) == 16 and int(number[0]) == 5 and (int(number[1]) >= 1 and int(number[1]) <= 5):
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")
    