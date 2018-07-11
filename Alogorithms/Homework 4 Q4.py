# Nils Fenske
# HW 4 Q 4

import random

random.seed()

n = 4

A = []
for i in range(0, n):
    A.append([])
    for j in range(0, n):
        A[i].append(random.randint(-10, 10))

B = []
for l in range(0, n):
    B.append([])
    for k in range(0, n):
        B[l].append(random.randint(-10, 10))

#print(A)
#print(B)

def SQUARE_MARTIX_MULTIPLY_RECURSIVE(current_A, current_B):
    r = len(current_A)
    C = []
    for f in range(0, r):
        C.append([])
        for v in range(0, r):
            C[f].append(0)
    if len(current_A) == 1: C[0][0] = current_A[0][0] * current_B[0][0]
    else:
        new_A = []
        new_B = []
        for x in range(0, int(r/2)):
            new_A.append([])
            new_B.append([])
            for y in range(0, int(r/2)):
                new_A[x].append([])
                new_B[x].append([])
                for z in range(0, int(r/2)):
                    new_A[y][z].append(current_A[y][z])
                    new_B[y][z].append(current_B[y][z])


        C[0][0] = SQUARE_MARTIX_MULTIPLY_RECURSIVE(new_A[0][0], new_B[0][0]) + SQUARE_MARTIX_MULTIPLY_RECURSIVE(new_A[0][1], new_B[1][0])
        C[0][1] = SQUARE_MARTIX_MULTIPLY_RECURSIVE(new_A[0][0], new_B[0][1]) + SQUARE_MARTIX_MULTIPLY_RECURSIVE(new_A[0][1], new_B[1][1])
        C[1][0] = SQUARE_MARTIX_MULTIPLY_RECURSIVE(new_A[1][0], new_B[0][0]) + SQUARE_MARTIX_MULTIPLY_RECURSIVE(new_A[1][1], new_B[1][0])
        C[1][1] = SQUARE_MARTIX_MULTIPLY_RECURSIVE(new_A[1][0], new_B[0][1]) + SQUARE_MARTIX_MULTIPLY_RECURSIVE(new_A[1][1], new_B[1][1])
    return(C)

print(SQUARE_MARTIX_MULTIPLY_RECURSIVE(A,B))


