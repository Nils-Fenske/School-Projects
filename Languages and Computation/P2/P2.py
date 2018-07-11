# Nils Fenske
# CS 3400 P2
# 4/15/2016

#This program reads a base file name and opens a sequnece of files based off that name.
#ASSUMPTIONS:
#   Files are all of same type extension
#   Words are from english dictionary
#   Punctuation and numbers are to be removed by program

import sys
import operator

fileCount = 5

Base_File_Name = sys.argv[1]

symbols = "~!@#$%^&*()_+{}:\"<>?`-=[];',.\\/'0123456789"      #symbols to be excluded

List_of_Sets = []

for i in range(0, fileCount):
    Base_File_Name = Base_File_Name.replace('.', str(i + 1) + '.')

    currentFile = open(Base_File_Name, 'r')
    text = currentFile.read().lower().split()

    wordSet = []

    for word in text:
        word = word.replace(u"\u2018", "'").replace(u"\u2019", "'")
        word = word.replace(u"\u201c", "\"").replace(u"\u201d", "\"")
        for s in range(0, len(symbols)):
            word = word.replace(symbols[s], "")
        if len(word) > 0:
            wordSet.append(word)

    List_of_Sets.append(set(wordSet))
    Base_File_Name = sys.argv[1]

Table_of_Overlaps = {}

# Performs intersections of sets
def overlap(set1: set, set2: set, fileA, fileB):
    combo = set1.intersection(set2)
    Table_of_Overlaps[Base_File_Name.replace('.', str(fileA) + '.').replace('.txt', '')
                      + ' and '
                      + Base_File_Name.replace('.', str(fileB) + '.').replace('.txt', '')] = len(combo)

# Calls to intersect sets
for s in List_of_Sets:
    for i in range((List_of_Sets.index(s) + 1), fileCount):
        overlap(s, List_of_Sets[i], (List_of_Sets.index(s) + 1), i + 1)

wordCollection = {}

# Determines how many files each word appears in
for c in range(0, fileCount):
    for word in List_of_Sets[c]:
        if word in wordCollection:
            wordCollection[word] += 1
        else:
            wordCollection[word] = 1

print('\nIntersections with largest degree of overlap:')
for key, value in sorted(Table_of_Overlaps.items(), key=operator.itemgetter(1), reverse=True):
    print(key, value)

print('\nIntersections with smallest degree of overlap:')
for key, value in sorted(Table_of_Overlaps.items(), key=operator.itemgetter(1)):
    print(key, value)

for n in range(1, fileCount + 1):
    print('\nWords that appear in ' + str(n) + ' file(s):')
    for key, value in sorted(wordCollection.items(), key=operator.itemgetter(0)):
        if wordCollection[key] == n:
            print(key)


