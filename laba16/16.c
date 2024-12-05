#include <stdio.h>
#include <stdlib.h>

typedef struct Node {        
    struct Node* nextList;   //следующий список
    int data;                 
    struct Node* nextNode;    //следующий узел
} Node;

Node* addNode(Node* head, int data, Node** tail) {
    Node* newNode = (Node*)malloc(sizeof(Node));       //выделение памяти под новый узел
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->nextList = NULL;

    if (head == NULL) {         //если список пустой, новый узел становится головой списка
        *tail = newNode;        //обновление указателя на хвост списка
        return newNode;
    } else {
        (*tail)->nextNode = newNode;     //связывание текущего хвоста с новым узлом
        *tail = newNode;                //обновление указателя на хвост списка
        return head;
    }
}

Node* addNodeS(Node* head, int data, Node** tail) {    //добавления узла в список и установки связи между списками
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->nextList = NULL;

    if (head == NULL) {
        *tail = newNode; 
        return newNode;
    } else {
        newNode->nextList = *tail;          //установка связи между списками
        *tail = newNode;                    //обновление указателя на хвост списка
        return head;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->nextNode;
    }
    printf("\n");
}

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
    
    while (1) { 
        scanf("%d", &data);  //добавление чисел
        if (data == 0) break; 
        count++;
        
        if (count % 2 == 1) {             //проверяет четность счетчика 
            firstList = addNode(firstList, data, &firstTail);  // вызов функции addNode 
            if (S == NULL) { S = firstList; firstTail->nextList = NULL; } //если S=NULL, присваивается значение 1 списка, а затем устанавливается указатель на след список NULL
        } else {
            secondList = addNodeS(secondList, data, &secondTail); 
            if (count == 2) secondTail->nextList = firstList; //если счетчик равен двум, то устанавливает указатель на следующий список в хвосте второго списка равным первому списку.
            else firstTail->nextList = secondTail;    // если счетчик не равен 2
        }
    }

    if (firstTail && secondTail) {    //если оба списка не пустые
        firstTail->nextList = secondTail;   //установка связи между последними элементами списков
    }

    printf("Первый список:\n");
    printList(firstList);
    
    printf("Второй список:\n");
    printList(secondList);

    //перемещение по узлам списков с помощью клавиш 'a' и 'd'
    printf("Нажмите 'a' для перемещения налево и 'd' направо. Другое для выхода\n");
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
                printf("Предыдущий эелмент NULL\n");
            
        } else if (key == 'd') {
            if (lst_ptr->nextNode)
                lst_ptr = lst_ptr->nextNode;
            else
                printf("Следующий элемент NULL\n");

        } else {
            printf("Выход\n");
            break;
        }
    }

    freeList(firstList);
    freeList(secondList);

    return 0;
}
