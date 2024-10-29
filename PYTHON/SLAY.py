# метод Гаусса
import numpy as np
import threading

def forward_elimination(a, b, start_row, end_row, k, n):
    for i in range(start_row, end_row):
        if i > k:
            print(f"Обработка строки: {i}")
            print(f"  Текущая строка a[{i}] = {a[i]}")
            factor = a[i][k] / a[k][k]
            print(f"  Множитель (factor): {factor:.2f}")
            b[i] = (factor * b[k]) - b[i]
            print(f"  Обновленный вектор b[{i}]: {b[i]:.2f}")

            for j in range(k, n):
                a[i][j] = (factor * a[k][j]) - a[i][j]
                print(f"  Обновленный элемент a[{i}][{j}]: {a[i][j]:.2f}")

def back_substitution(a, b):
    n = len(a)
    x = np.zeros(n)
    x[n - 1] = b[n - 1] / a[n - 1][n - 1]
    print("Обратный ход")
    print(f"  x[{n - 1}] = {x[n - 1]:.2f}")

    for i in range(n - 2, -1, -1):
        print(f"  Обработка строки: {i}")
        sum_ = b[i]
        print(f"  Начальное значение sum: {sum_:.2f}")
        for j in range(i + 1, n):
            print(f"  Слагаемое a[{i}][{j}] * x[{j}]: {a[i][j]} * {x[j]:.2f}")
            sum_ -= a[i][j] * x[j]
            print(f"  Обновленное значение sum: {sum_:.2f}")
        x[i] = sum_ / a[i][i]
        print(f"  x[{i}] = {x[i]:.2f}")
        print("  -------------------------")

    return x

def solve_gauss(a, b):
    n = len(a)

    # Прямой ход
    for k in range(n - 1):
        print("-------------------------")
        print(f"№ столбца: {k}")

        threads = []
        # Создаем потоки для обработки строк
        for i in range(k + 1, n):
            thread = threading.Thread(target=forward_elimination, args=(a, b, i, i + 1, k, n))
            threads.append(thread)
            thread.start()

        # Ждем завершения всех потоков
        for thread in threads:
            thread.join()

        print("--------------------------")

    # Обратный ход
    return back_substitution(a, b)

if __name__ == "__main__":
    # Пример матрицы коэффициентов и свободных членов
    a = np.array([[2, 1, 1],
                  [4, 3, 3],
                  [8, 7, 9]], dtype=float)
    b = np.array([8, 20, 36], dtype=float)

    try:
        x = solve_gauss(a, b)
        print("Решение СЛАУ:")
        for i in range(len(x)):
            print(f"x{i + 1} = {x[i]:.2f}")
    except Exception as e:
        print(f"Ошибка: {e}")
