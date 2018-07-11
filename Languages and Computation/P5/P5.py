# Nils Fenske
# CS 3400 P5 version: 1.0
# 5/15/2016

# This program reads a file of possible prices. It runs them through a test and
# sorts the passing prices into separate files.
# A file containing prices NOT separated by spaces will not pass.
# Prices containing values larger than 999 must contain valid (,)'s
# The default normalization value is 1. This is used if normalize value is missing or 0. Negative values area OK.
# Prices in input file must be positive.
# Negative prices are enclosed in parenthesis in output files.

import sys
import re
import locale

try:
    fileRead = open(sys.argv[1], 'r')
except OSError:
    print("File not found.")
    sys.exit()

bucks_file = open('bucks.txt', 'w')
sales_file = open('sales.txt', 'w')
misc_file = open('misc.txt', 'w')

test_prices = fileRead.read().lower().split()

non_prices = []

for s in test_prices:
    if re.match(r'^(?!\$).*', s):
        non_prices.append(s)

for word in non_prices:
    index = non_prices.index(word)
    if not word.__contains__("$"):
        non_prices[index] = ''.join(re.findall('-?\d*', word))

while non_prices.__contains__(''): non_prices.remove('')

try:
    normalize = int(non_prices[0])
except IndexError:
    print("No normalize value present in file. Default: 1")
    normalize = 1

myReg = re.compile(r'^(\$[1-9]([0-9]{0,2})?(,[0-9]{3})*(\.[0-9]{2})?[`!\.,]*)$|(\$0\.[0-9]{2})$')

valid_list = []

for price in test_prices:
    myMatch = re.match(myReg, price)
    if myMatch:
        myMatch = ''.join(filter(lambda x: x in '0123456789.', price))
        valid_list.append(myMatch)

locale.setlocale(locale.LC_ALL, '')

for price in valid_list:
    try:
        price = float(price) / normalize
    except ZeroDivisionError:
        price = float(price) / 1

    formatted_price = locale.currency(price, grouping=True)

    if re.match('(\(?\$\d*\.99[0-4]*\))$', str(formatted_price)):
        sales_file.write(str(locale.currency(price, grouping=True)) + '\n')
    elif re.match('(?!\(?\$\d*\.0{1,2}\)$)\(?\$\d*\.[0-9]*\)', str(formatted_price)):
        misc_file.write(str(formatted_price) + '\n')
    else: bucks_file.write(str(locale.currency(price, grouping=True)) + '\n')
