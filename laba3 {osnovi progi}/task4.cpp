#include <iostream>
#include <stdio.h>
#include <string.h>

size_t my_strlen(const char *s) //Для подсчета длины без учета переноса строки
{
    const char *start = s;
    while (*s && *s != '\n')
        s++;
    return s - start;
}

int main(void)
{   
    
    char text[1024];
    const char cons[22] = "bcdfghjklmnpqrstvwxyz"; //Строка согласных
    
    std::cout << "Enter text: ";
    fgets(text, 1024, stdin); //Считываем строку из входного потока

    int length;

    std::cout << "Select length: ";
    std::cin >> length;

    
    char new_text[1024];
    char *word = strtok(text, " ,."); //Получаем указатель на первое слово
    while (word != NULL)
    {   
        char *ach = strchr(cons, word[0]); //Ищем 1 букву в строке согласных
        if (ach == 0 || my_strlen(word) != length) //Если буквы нет в согласных и длина не равне удаляемой длине
        {   
            strcat(new_text, " "); //Добавляем пробел между словами
            strcat(new_text, word); //Добавляем слово в наш текст
        }
        word = strtok(NULL, " ,."); //Переходим на следующее слово
    }

    puts(new_text);

    return 0;
}
