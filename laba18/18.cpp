#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

// Класс для квадратов
class Square {
private:
    double side; // Длина стороны квадрата

public:
    // Конструктор
    Square(double side) : side(side) {}

    // Метод для получения длины стороны квадрата
    double Side() const {
        return side;
    }

    // Метод вычисления диагонали
    double diagonal() const {
        return sqrt(2) * side;
    }

    // Метод вычисления периметра
    double perimeter() const {
        return 4 * side;
    }

    // Метод вычисления площади
    double area() const {
        return side * side;
    }

    // Метод для вывода информации о квадрате
    void outputTo() const {
        cout << "Квадрат: " << endl;
        cout << "Длина стороны: " << side << endl;
        cout << "Длина диагонали: " << diagonal() << endl;
        cout << "Периметр: " << perimeter() << endl;
        cout << "Площадь: " << area() << endl;
    }
};

int main() {
    vector<Square> squares;
    vector<Square> largeSquares;

    int N;
    cout << "Введите количество квадратов: ";
    cin >> N;

    if (N <= 0) {
        cout << "Некорректное количество квадратов." << endl;
        return 1;
    }

    for (int i = 0; i < N; ++i) {
        double side;
        cout << "Введите длину стороны квадрата " << i + 1 << ": ";
        cin >> side;

        Square square(side);
        squares.push_back(square);

        // Переписываем квадраты с площадью больше 50 в новый вектор
        if (square.area() > 50) {
            largeSquares.push_back(square);
        }
    }

    if (largeSquares.empty()) {
        cout << "Новый вектор пуст." << endl;
    } else {
        // Сортировка нового вектора по длине стороны квадрата
        sort(largeSquares.begin(), largeSquares.end(), [](const Square& a, const Square& b) {
            return a.Side() < b.Side();
        });

        // Вывод отсортированных объектов
        for (const auto& square : largeSquares) {
            square.outputTo();
            cout << endl;
        }
    }

    return 0;
}
