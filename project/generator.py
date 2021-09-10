import random;
print('\"args\": [\"', end='')
print('\", \"'.join(str(i) for i in random.sample(range(-2147483648, 2147483647), 500)), end='')
print('\"],')
