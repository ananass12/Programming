#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>

using namespace std;

class Square {        
private:
    double side;       

public:
    Square(double side) : side(side) {}       

    double Side() const {            //методы класса
        return side;
    }

    double diagonal() const {
        return sqrt(2) * side;
    }

    double perimeter() const {
        return 4 * side;
    }

    double area() const {
        return side * side;
    }

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
    vector<Square> largeSquares;          //квадраты со стороной больше 50

    int N;
    cout << "Введите количество квадратов: ";
    cin >> N;

    if (N <= 0) {
        cout << "Некорректное количество квадратов." << endl;
        return 1;
    }

    for (int i = 0; i < N; ++i) {     //добавление нового квадрата
        double side;
        cout << "Введите длину стороны квадрата " << i + 1 << ": ";
        cin >> side;

        Square square(side);
        squares.push_back(square);

        if (square.area() > 50) {
            largeSquares.push_back(square);
        }
    }

    if (largeSquares.empty()) {
        cout << "Новый вектор пуст." << endl;
    } else {
        sort(largeSquares.begin(), largeSquares.end(), [](const Square& a, const Square& b) {         //сортировка нового вектора по длине стороны квадрата
            return a.Side() < b.Side();
        });

        for (const auto& square : largeSquares) {     //вывод отсортированных объектов
            square.outputTo();
            cout << endl;
        }
    }    
    return 0;
}
