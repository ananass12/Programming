#include <iostream>
#include <string>
using namespace std;

struct Train {
    int number;          //номер поезда
    string destination;    //станция назначения
    string departureTime;    //время отправления
    Train* next;   
};

void addTrain(Train* &head, int number, string destination, string departureTime) {
    Train* newTrain = new Train;            
    newTrain->number = number;              
    newTrain->destination = destination;            
    newTrain->departureTime = departureTime;              
    newTrain->next = head;               //присвоение указателю на следующий элемент текущего значения головы списка
    head = newTrain;                     //обновление головы списка
}

void printTrains(Train* head) {
    Train* current = head;
    while (current != nullptr) {
        cout << "Поезд №" << current->number << " отправляется в " << current->destination << " в " << current->departureTime << endl;
        current = current->next;
    }
}

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

    addTrain(trains, 1001, "Москва", "08:00");
    addTrain(trains, 1002, "Санкт-Петербург", "09:30");
    addTrain(trains, 1003, "Екатеринбург", "12:45");
    addTrain(trains, 1004, "Красноярск", "15:20");
    addTrain(trains, 1005, "Владивосток", "18:10");
    addTrain(trains, 1006, "Владивосток", "20:20");

    cout << "Список поездов:" << endl;
    printTrains(trains);

    int trainNumber;
    cout << "Введите номер поезда: ";
    cin >> trainNumber;
    findTrain(trains, trainNumber);

    string destination;
    cout << "Введите станцию назначения: ";
    cin >> destination;
    cout << "Поезда до " << destination << ":" << endl;
    findTrainsToDestination(trains, destination);

    return 0;
}
