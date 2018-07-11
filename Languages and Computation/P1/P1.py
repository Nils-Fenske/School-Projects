# Nils Fenske
# CS 3400 P1
# 4/8/2016

#This program reads two text files and stores the words from both files into a single dictionary.
#The words are assumed to use characters form the english alphabet only. Punctuation and numbers are removed in the program.
#The program then prints out the words that appear in both files, the most frequent word, and the words that appear only once.

import sys
import operator

fileRead1 = open(sys.argv[1], 'r')
fileRead2 = open(sys.argv[2], 'r')

text1 = fileRead1.read().lower().split()
text2 = fileRead2.read().lower().split()

symbols = "~!@#$%^&*()_+{}:\"<>?`-=[];',.\\/'0123456789"      #symbols to be excluded

cleanText1 = []
for word in text1:
    for i in range(0, len(symbols)):
        word = word.replace(symbols[i], "")
    if len(word) > 0:
        cleanText1.append(word)

cleanText2 = []
for word in text2:
    for i in range(0, len(symbols)):
        word = word.replace(symbols[i], "")
    if len(word) > 0:
        cleanText2.append(word)

collection = {}

for word in cleanText1:
    if word in collection:
        collection[word] += 1
    else:
        collection[word] = 1

for word in cleanText2:
    if word in collection:
        collection[word] += 1
    else:
        collection[word] = 1

print('Words that appear in both files:')
max = cleanText1[0]
for key, value in sorted(collection.items(), key=operator.itemgetter(1), reverse = True):
    if cleanText1.__contains__(key) & cleanText2.__contains__(key):
        print(key, value)
    if collection[key] > collection[max]:
        max = key

print('\nWord with the greatest combined frequency:')
print(max, collection[max])

print('\nWords that appear only once:')
for key, value in sorted(collection.items(), key=operator.itemgetter(0)):
    if collection[key] == 1:
        print(key)