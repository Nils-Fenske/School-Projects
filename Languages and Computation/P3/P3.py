# Nils Fenske
# CS 3400 P3
# 4/20/2016

# This program reads a file of possible prices. It runs them through a test and
# sorts the passing prices into separate files.
# A file containing prices NOT separated by spaces will not pass.
# Prices containing values larger than 999 may or may not contain valid (,)'s

import sys
import re

fileRead = open(sys.argv[1], 'r')

bucks_file = open('bucks.txt', 'w')
sales_file = open('sales.txt', 'w')
misc_file = open('misc.txt', 'w')

test_prices = fileRead.read().lower().split()

myReg = re.compile(r'^([\$][1-9][0-9]*[\.]?[0-9][0-9]|'                         # $xx.xx
                   r'^[\$][1-9][0-9]?|'                                        # $xx
                   r'^[\$][1-9]([0-9]{1,2})?([,][0-9]{3})*([\.][0-9][0-9])?|'  # $xxx,xxx.xxx
                   r'^[\$][1-9]([0-9]{1,2})?([,][0-9]{3})*'                   # $xxx,xxx
                   r'^[`~!@#$%^&*()_+\-=\[\]{}\\\|;\':"<>,.?/]?$)', re.X)
valid_list = []

for word in test_prices:
    myMatch = re.match(myReg, word)
    if (myMatch): valid_list.append(myMatch.string)

for price in valid_list:
    if (price.__contains__('.99')) : sales_file.write(price + '\n')
    elif (price.__contains__('.')) : misc_file.write(price + '\n')
    else: bucks_file.write(price + '\n')