# Nils Fenske
# CS 3400 P4 version: 1.0
# 5/7/2016

# Acceptable extensions are 2 or 3 characters long and NOT ‘.bat’ or ‘.exe’.
# Extensions are case sensitive. (all lowercase OR all uppercase)
# Invalid extensions will be denied.
# Files are assumed to not be empty.
# Files may contain words with upper and lower-case characters.
# Plural forms of words will be translated and then appended with the correct pluralism i.e. (...)s, (...)'s.

import sys
import re

fileRead = None
fileName = sys.argv[1]

validExt = re.match(r'(.*)\.(?!exe|bat|EXE|BAT)([a-z_]{2,3})|([A-Z_]{2,3})', fileName)

if validExt:
    fileRead = open(fileName, 'r')

    file_words = fileRead.read().split()

    for word in file_words:
        l337_word = re.sub(r'ant|and|anned', '&', word)    # words containing "anned" will be translated to end with "&"
        l337_word = re.sub(r'(ed)$', 'd', l337_word)       # before they would have been translated to "ann&"
        l337_word = re.sub(r'(er)$', 'xor', l337_word)
        l337_word = re.sub(r'(eds)$', 'ds', l337_word)
        l337_word = re.sub(r'(ers)$', 'xors', l337_word)
        l337_word = re.sub(r'(ed\'s)$', 'd\'s', l337_word)
        l337_word = re.sub(r'(er\'s)$', 'xor\'s', l337_word)
        l337_word = re.sub(r'^f', 'ph', l337_word)
        file_words[file_words.index(word)] = l337_word

    output_file = open('n00b.txt', 'w')

    l337_list = ['d00d', 'w00t', 'sk1llz', 'h4xx', 'n0sc0p3', 'pwn4g3', 'r0f1']

    def l337_gen():
        x = 0
        while x < len(l337_list):
            yield l337_list[x]
            x += 1
            if x == len(l337_list): x = 0

    def int_gen():
        x = 10
        y = 10
        while True:
            yield x
            x += y
            y += 5

    index = int_gen()
    i = next(index)
    word = l337_gen()

    for x in range(0, len(file_words)):
        if x < (i - 1):
            output_file.write(file_words[x] + ' ')

        else:
            output_file.write(next(word) + ' ')
            i = next(index)

        if (x + 1) % 14 == 0: output_file.write('\n')
else:
    raise ValueError("Invalid Extension")

