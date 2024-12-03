//Заменить начальные буквы всех слов на прописные буквы и записать результирующий текст в новый файл.

#include <stdio.h>
#include <ctype.h>

int main() {
    // Определение имени входного и выходного файлов
    char inputFileName[] = "sample2.txt";
    char outputFileName[] = "sample2_out.txt";
    
    // Открытие входного и выходного файлов
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    // Проверка успешности открытия файлов
    if (inputFile == NULL || outputFile == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    int capitalize = 1; // Флаг, указывающий на необходимость написания следующей буквы заглавной
    int c;

    // Построчное чтение из входного файла
    while ((c = fgetc(inputFile)) != EOF) {
        if (capitalize && isalpha(c)) {
            fputc(toupper(c), outputFile); // Преобразование первой буквы слова в заглавную
            capitalize = 0;
        } else {
            fputc(tolower(c), outputFile); // Преобразование остальных букв слова в строчные
        }

        // Если текущий символ - пробел, новая строка или табуляция, устанавливаем флаг capitalize
        if (c == ' ' || c == '\n' || c == '\t') {
            capitalize = 1;
        }
    }

    // Закрытие файлов
    fclose(inputFile);
    fclose(outputFile);

    printf("Преобразование завершено\n");
    
    return 0;
}
