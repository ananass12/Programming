//заменить начальные буквы всех слов на прописные буквы и записать результирующий текст в новый файл.
#include <stdio.h>
#include <ctype.h>

int main() {
    char inputFileName[] = "sample2.txt";     
    char outputFileName[] = "sample2_out.txt";     
    
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    int capitalize = 1;     
    int c;
  
    while ((c = fgetc(inputFile)) != EOF) {         
        if (capitalize && isalpha(c)) {
            fputc(toupper(c), outputFile);       //первая буква заглавная
            capitalize = 0;
        } else {
            fputc(tolower(c), outputFile);          //остальные букв слова в строчные
        }

        if (c == ' ' || c == '\n' || c == '\t') {     //если текущий символ-пробел, новая строка, табуляция
            capitalize = 1;
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Преобразование завершено\n");
    
    return 0;
}
