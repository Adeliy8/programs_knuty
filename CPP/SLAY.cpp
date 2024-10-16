#include <iostream>
#include <vector>
#include <iomanip>
#include <thread>
#include <stdexcept>


using namespace std;

// Функция для выполнения прямого хода метода Гаусса a-матрица коэффициентов, b-свободные члены, startRow - начальная строка, endRow - конечная строка, n - размерность СЛАУ
void forwardElimination(vector<vector<double>>& a, vector<double>& b, int startRow, int endRow, int n) {
    for (int k = 0; k < n - 1; ++k) { //проходит по каждому столбу матрицы а, короме последнего 
            cout << "-------------------------" << endl;
            cout << "№ столбца: " << k << endl; 
        // Приведение к верхнетреугольному виду
        for (int i = startRow; i < endRow; ++i) { //проходит по строкам матрицы а
            if (i > k) {
        
                cout << "Обработка строки: " << i << endl;
                cout << "  Текущая строка a[" << i << "] = [";
                for(int j = 0; j < n; ++j){
                    cout << fixed << setprecision(2) << a[i][j] << ", ";
                }
                cout << "], b[" << i << "] = " << fixed << setprecision(2) << b[i] << endl;
                double factor = a[i][k] / a[k][k];
                cout << "  Множитель (factor): " << fixed << setprecision(2) << factor << endl;
                b[i] = (factor * b[k]) - b[i];
                cout << "  Обновленный вектор b[" << i << "]: " << fixed << setprecision(2) << b[i] << endl;
               
                for (int j = k; j < n; ++j) {
                     
                    a[i][j] = (factor * a[k][j]) - a[i][j];
                    cout << "  Обновленный элемент a[" << i << "][" << j << "]: " << fixed << setprecision(2) << a[i][j] << endl;
                    
                }
            }
        }
        cout << "--------------------------" << endl;
    }
}

// Функция для обратного хода метода Гаусса
vector<double> backSubstitution(const vector<vector<double>>& a, const vector<double>& b) {
    int n = a.size();
    vector<double> x(n);
    x[n - 1] = b[n - 1] / a[n - 1][n - 1];
    cout << "Обратный ход" << endl;
    cout << "  x[" << n - 1 << "] = " << fixed << setprecision(2) << x[n - 1] << endl;


    for (int i = n - 2; i >= 0; --i) {
        cout << "  Обработка строки: " << i << endl;
        double sum = b[i];
        cout << "  Начальное значение sum: " << fixed << setprecision(2) << sum << endl;
        for (int j = i + 1; j < n; ++j) {
            cout << "  Слагаемое a[" << i << "][" << j << "] * x[" << j << "]: " << fixed << setprecision(2) << a[i][j] << " * " << fixed << setprecision(2) << x[j] << endl;

            sum -= a[i][j] * x[j];
            cout << "  Обновленное значение sum: " << fixed << setprecision(2) << sum << endl;
        }
        x[i] = sum / a[i][i];
        cout << "  x[" << i << "] = " << fixed << setprecision(2) << x[i] << endl;
        cout << "  -------------------------" << endl;
    }
    
    return x;
}

// Основная функция для решения СЛАУ
vector<double> solveGauss(vector<vector<double>>& a, vector<double>& b) {
    int n = a.size();

    // Параллельное выполнение прямого хода, создаются два потока, 1-ый поток для строк с 1 по n/2, 2-ой поток для строк с n/2 и до n
    thread t1(forwardElimination, ref(a), ref(b), 1, n / 2, n);
    thread t2(forwardElimination, ref(a), ref(b), n / 2, n, n);

    // Ожидание завершения потоков
    t1.join();
    t2.join();

    // Обратный ход
    return backSubstitution(a, b);
}

int main() {
    setlocale(LC_ALL, "Rus");

    // Пример матрицы коэффициентов и свободных членов
    vector<vector<double>> a = {
        {2, 1, 1},
        {4, 3, 3},
        {8, 7, 9}
    };
    vector<double> b = {8, 20, 36};

    try {
        vector<double> x = solveGauss(a, b);
        cout << "Решение СЛАУ:" << endl;
        for (int i = 0; i < x.size(); ++i) {
            cout << "x" << i + 1 << " = " << fixed << setprecision(2) << x[i] << endl;
        }
    } catch (const runtime_error& error) {
        cerr << "Ошибка: " << error.what() << endl;
        return 1;
    }

    return 0;
}
