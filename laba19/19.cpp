#include <iostream>
#include <string>
using namespace std;

// Структура для хранения информации о поезде
struct Train {
    int number; // Номер поезда
    string destination; // Станция назначения
    string departureTime;  // Время отправления
    Train* next; // Указатель на следующий элемент в списке
};

// Функция для добавления нового поезда в список
void addTrain(Train* &head, int number, string destination, string departureTime) {
    Train* newTrain = new Train; // Создание нового элемента типа Train
    newTrain->number = number;  // Заполнение номера поезда
    newTrain->destination = destination; // Заполнение станции назначения
    newTrain->departureTime = departureTime; // Заполнение времени отправления
    newTrain->next = head; // Присвоение указателю на следующий элемент текущего значения головы списка
    head = newTrain; // Обновление головы списка
}

// Функция для вывода всего списка
void printTrains(Train* head) {
    Train* current = head;
    while (current != nullptr) {
        cout << "Поезд №" << current->number << " отправляется в " << current->destination << " в " << current->departureTime << endl;
        current = current->next;
    }
}

// Функция для вывода информации о конкретном поезде
void findTrain(Train* head, int number) {
    Train* current = head;
    while (current != nullptr) {
        if (current->number == number) {
            cout << "Поезд №" << current->number << " отправляется в " << current->destination << " в " << current->departureTime << endl;
            return;
        }
        current = current->next;
    }
    cout << "Поезд с указанным номером не найден." << endl;
}

// Функция для вывода списка поездов до указанной станции назначения
void findTrainsToDestination(Train* head, string destination) {
    Train* current = head;
    while (current != nullptr) {
        if (current->destination == destination) {
            cout << "Поезд №" << current->number << " отправляется в " << current->destination << " в " << current->departureTime << endl;
        }
        current = current->next;
    }
}

int main() {
    Train* trains = nullptr;

    // Добавление данных в информационную систему
    addTrain(trains, 1001, "Москва", "08:00");
    addTrain(trains, 1002, "Санкт-Петербург", "09:30");
    addTrain(trains, 1003, "Екатеринбург", "12:45");
    addTrain(trains, 1004, "Красноярск", "15:20");
    addTrain(trains, 1005, "Владивосток", "18:10");
    addTrain(trains, 1006, "Владивосток", "20:20");

    // Вывод всего списка
    cout << "Список поездов:" << endl;
    printTrains(trains);

    // Поиск информации о конкретном поезде по его номеру
    int trainNumber;
    cout << "Введите номер поезда: ";
    cin >> trainNumber;
    findTrain(trains, trainNumber);

    // Поиск поездов до указанной станции назначения
    string destination;
    cout << "Введите станцию назначения: ";
    cin >> destination;
    cout << "Поезда до " << destination << ":" << endl;
    findTrainsToDestination(trains, destination);

    return 0;
}
