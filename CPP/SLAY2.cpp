// Метод Крамера 

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// Функция для вычисления определителя матрицы
double determinant(const vector<vector<double>>& matrix) {
    int n = matrix.size();
    double det = 1;
    vector<vector<double>> temp = matrix;

    for (int i = 0; i < n; i++) {
        // Находим строку с максимальным элементом в текущем столбце
        double maxEl = abs(temp[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(temp[k][i]) > maxEl) {
                maxEl = abs(temp[k][i]);
                maxRow = k;
            }
        }

        // Меняем местами текущую строку и строку с максимальным элементом
        swap(temp[i], temp[maxRow]);
        if (i != maxRow) {
            det = -det; // Изменяем знак определителя
        }

        // Если элемент на главной диагонали равен нулю, определитель равен нулю
        if (temp[i][i] == 0) {
            return 0;
        }

        // Приводим матрицу к верхнетреугольному виду
        for (int k = i + 1; k < n; k++) {
            double factor = temp[k][i] / temp[i][i];
            for (int j = i; j < n; j++) {
                temp[k][j] -= factor * temp[i][j];
            }
        }
        det *= temp[i][i];
    }

    return det;
}

// Функция для решения системы уравнений методом Крамера
vector<double> kramer(const vector<vector<double>>& A, const vector<double>& b) {
    int n = A.size();
    if (b.size() != n) {
        throw invalid_argument("Размеры матрицы и вектора не совпадают");
    }

    double det_A = determinant(A);
    if (det_A == 0) {
        cout << "Определитель матрицы равен нулю. Решения не существует или их бесконечно много." << endl;
        return {};
    }

    vector<double> x(n);
    for (int i = 0; i < n; i++) {
        vector<vector<double>> Ai = A;
        for (int j = 0; j < n; j++) {
            Ai[j][i] = b[j];
        }
        x[i] = determinant(Ai) / det_A;
    }

    return x;
}

int main() {
    setlocale(LC_ALL, "Rus");
    vector<vector<double>> A = {{2, -1, -3}, {3, 4, -5}, {0, 2, 7}};
    vector<double> b = {3, -8, 17};

    try {
        vector<double> x = kramer(A, b);
        cout << "Решение системы уравнений: ";
        for (double val : x) {
            cout << val << " ";
        }
        cout << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
