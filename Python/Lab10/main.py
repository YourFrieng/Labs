import numpy as np

my_file = open("input.txt", "r")
matrix = []
with open("input.txt") as f:
    for line in f:
        matrix.append([int(x) for x in line.split()])

conv_matrix = np.array(matrix)
print(matrix)
print(conv_matrix)
det = np.linalg.det(conv_matrix)
print(np.linalg.det(conv_matrix))

