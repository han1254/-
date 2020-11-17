import numpy as np


def strassen_matrix_multiply(A, B):
    """
    :param A: n*n矩阵
    :param B: n*n矩阵
    :return: A * B
    """
    n = len(A)
    C = [[0 for i in range(n)] for j in range(n)]

    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] = C[i][j] + A[i][k] * B[k][j]

    return C

def square_matrix_multiply_recursive(A, row_a, col_a, B, row_b, col_b):
	

if __name__ == '__main__':
    A = [[1, 3, 5, 4, 2],
         [6, 1, 7, 3, 9],
         [8, 6, 5, 7, 4],
         [2, 4, 2, 5, 9],
         [4, 4, 6, 8, 0]]
    
    B = [[3, 3, 6, 4, 2],
         [6, 6, 7, 4, 9],
         [9, 4, 8, 3, 2],
         [2, 1, 6, 4, 3],
         [3, 8, 0, 9, 4]]

    print(strassen_matrix_multiply(A, B))

    print(np.dot(A, B))
