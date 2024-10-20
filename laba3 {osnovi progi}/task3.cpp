#include <iostream>
#include <stdio.h>
#define ROWS 3
#define COLS 2

int abs(int x)
{
    return (x >= 0) ? x : -x;
}

int mat_har(int n, int m, int matrix[][ROWS], int target)   //Характеристика числа по заданию
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        if (matrix[i][target] < 0 && (i + target) % 2 == 1)
            sum += abs(matrix[i][target]);
    return sum;
}

void swap(int arr[], int n, int n2)  //Меняем местами значения 2 переменных в одном массиве
{
        int tmp = arr[n];
        arr[n] = arr[n2];
        arr[n2] = tmp;
}

void col_swap(int n, int m, int matrix[][ROWS], int t, int t_to_change) //Меняем столбцы в матрице
{
    for (int i = 0; i < n; i++)
    {
        swap(matrix[i], t, t_to_change);
    }

}

void puts_array(int, int, int matrix[][ROWS]); //Для вывода 2 мерного массива

void gets_array(int, int, int matrix[][ROWS]); //Для ввода 2 мерного массива

int main(void)
{   
    int matrix[COLS][ROWS];
    
    gets_array(COLS, ROWS, matrix); //Вводим 0 -2 0 -3 0 -1
    puts_array(COLS, ROWS, matrix);
    printf("------------------------\n");

    int arr_har[ROWS];  //Сохраняем характеристики столбцов (при перемещении столбцов они могут перестать подходить по условию)
    for (int i = 0; i < ROWS; i++)
    {
        arr_har[i] = mat_har(COLS, ROWS, matrix, i);
    }

    int length = ROWS;
    while (length--) //Пузырьковая сортировка по возрастанию
    {
        for (int i = 0; i < length; i++)
            if (arr_har[i] > arr_har[i + 1]) //Если характериста в arr_har больше следующей то меняем местами столбцы и значения характеристик
            {
                col_swap(COLS, ROWS, matrix, i, i + 1);
                swap(arr_har, i, i + 1);
            }
    }

    puts_array(COLS, ROWS, matrix);

    return 0;
}

void puts_array(int n, int m, int matrix[][ROWS]) //Определение для функции вывода
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%3d", matrix[i][j]);
        printf("\n");
    }
}

void gets_array(int n, int m, int matrix[][ROWS]) //Определение для функции ввода
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            std::cin >> matrix[i][j];
}
