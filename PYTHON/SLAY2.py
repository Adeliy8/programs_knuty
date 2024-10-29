# метод Крамера

import numpy as np

def kramer(A, b):
    n = len(A)
    if len(b) != n:
        raise ValueError("Размеры матрицы и вектора не совпадают")

    det_A = np.linalg.det(A)
    if det_A == 0:
        print("Определитель матрицы равен нулю. Решения не существует или их бесконечно много.")
        return None

    x = np.zeros(n)
    for i in range(n):
        Ai = A.copy()
        Ai[:, i] = b
        x[i] = np.linalg.det(Ai) / det_A

    return x

if __name__ == "__main__":
    A = np.array([[2, -1, -3], [3, 4, -5], [0, 2, 7]])
    b = np.array([3, -8, 17])
    
    x = kramer(A, b)
    if x is not None:
        print("Решение системы уравнений:", x)
