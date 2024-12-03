#include <stdio.h>
#include <stdlib.h>

// Структура узла списка
typedef struct Node {
    struct Node* nextList; // указатель на следующий элемент в списке
    int data;              // данные, хранимые в узле
    struct Node* nextNode; // указатель на следующий узел
} Node;

// Функция добавления узла в список
Node* addNode(Node* head, int data, Node** tail) {
    // Выделение памяти под новый узел
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->nextList = NULL;

    // Если список пустой, новый узел становится головой списка
    if (head == NULL) {
        *tail = newNode; // Обновление указателя на хвост списка
        return newNode;
    } else {
        (*tail)->nextNode = newNode; // Связывание текущего хвоста с новым узлом
        *tail = newNode; // Обновление указателя на хвост списка
        return head;
    }
}

// Функция добавления узла в список и установки связи между списками
Node* addNodeS(Node* head, int data, Node** tail) {
    // Выделение памяти под новый узел
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->nextList = NULL;

    // Если список пустой, новый узел становится головой списка
    if (head == NULL) {
        *tail = newNode; // Обновление указателя на хвост списка
        return newNode;
    } else {
        newNode->nextList = *tail; // Установка связи между списками
        *tail = newNode; // Обновление указателя на хвост списка
        return head;
    }
}

// Функция печати значений всех узлов в списке
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->nextNode;
    }
    printf("\n");
}

// Функция освобождения памяти, выделенной для списка
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->nextNode;
        free(temp);
    }
}

int main() {
    Node* firstList = NULL; 
    Node* secondList = NULL; 
    Node *firstTail = NULL, *secondTail = NULL;
    Node* S = NULL;
    int data, count = 0;

    printf("Введите последовательность чисел (0 для окончания ввода)\n");
    
    // Ввод чисел пользователем и добавление их в списки
    while (1) { // Пока условие истинно, цикл будет выполняться
        scanf("%d", &data); // считывается целое число с клавиатуры
        if (data == 0) break; // если число равно 0 то цикл прерывается

        count++;
        if (count % 2 == 1) { // проверяет четность счетчика (если нечетно, то продолжается выполнение до else)
            firstList = addNode(firstList, data, &firstTail); // вызов функции addNode 
            if (S == NULL) { S = firstList; firstTail->nextList = NULL; } // Если S = NULL то присваивается значение первого списка, а затем устанавливается указатель на след список NULL
        } else {
            secondList = addNodeS(secondList, data, &secondTail); // если значение счетчика четное
            if (count == 2) secondTail->nextList = firstList; // если счетчик равен двум, то устанавливает указатель на следующий список в хвосте второго списка равным первому списку.
            else firstTail->nextList = secondTail; // если счетчик не равен двум...
        }
    }

    // Установка связи между последними элементами списков
    if (firstTail && secondTail) {
        firstTail->nextList = secondTail;
    }

    // Вывод значений обоих списков
    printf("Первый список:\n");
    printList(firstList);
    
    printf("Второй список:\n");
    printList(secondList);

    // Перемещение по узлам списков с помощью клавиш 'a' и 'd'
    printf("Press 'a' to go left and 'd' to go right. Any other key to exit\n");
    Node *lst_ptr = firstList;
    getchar();
    while (1) {
        char key;

        printf("Value: %d; Addr prev: %p next: %p\n", lst_ptr->data, (void*)lst_ptr->nextList, (void*)lst_ptr->nextNode);
        scanf("%c%*c", &key);
        
        if (key == 'a') {
            if (lst_ptr->nextList)
                lst_ptr = lst_ptr->nextList;
            else 
                printf("Can't go here: prev is NULL\n");
            
        } else if (key == 'd') {
            if (lst_ptr->nextNode)
                lst_ptr = lst_ptr->nextNode;
            else
                printf("Can't go here: next is NULL\n");

        } else {
            printf("Exiting..\n");
            break;
        }
    }

    // Освобождение памяти
    freeList(firstList);
    freeList(secondList);

    return 0;
}
