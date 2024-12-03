#include <stdio.h>
#include <string.h>

struct Toy {
    char name[100];
    float price;
    int quantity;
};

int main() {
    FILE *file;
    struct Toy toys[] = {
        {"Кукла", 2500, 5},
        {"Мягкая игрушка мишка", 900, 3},
        {"Автомобиль-трансформер", 3200, 5},
        {"Набор LEGO \"Замок\"", 8599.99, 6},
        {"Настольная игра \"Монополия\"", 1800, 23},
        {"Развивающий конструктор \"Мозаика\"", 800, 15},
        {"Игрушечный пистолет с пульками", 70000, 12},
        {"Плюшевый котенок", 1300, 9},
        {"Детский набор для рисования", 950, 21},
        {"Робот-трансформер", 6000.5, 5}
    };

    file = fopen("PRICE.dat", "wb");
    if (file == NULL) {
        printf("Ошибка при создании файла.\n");
        return 1;
    }

    fwrite(toys, sizeof(struct Toy), 10, file); // Записываем все игрушки в файл
    fclose(file);

    file = fopen("PRICE.dat", "rb");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }

    struct Toy maxToy;
    float maxPrice = 0;

    while (fread(&maxToy, sizeof(struct Toy), 1, file) == 1) {
        if (maxToy.price > maxPrice) {
            maxPrice = maxToy.price;
        }
    }

    rewind(file);

    printf("Самая дорогая игрушка:\n");
    while (fread(&maxToy, sizeof(struct Toy), 1, file) == 1) {
        if (maxToy.price == maxPrice) {
            printf("Название: %s \nЦена: %.2f \n", maxToy.name, maxToy.price);
        }
    }

    fclose(file);

    return 0;
}


