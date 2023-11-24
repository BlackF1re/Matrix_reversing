#include <stdio.h>
#include <stdlib.h>

void error()
{
    printf("Вы все сломали. Вводите корректные значения.\n");
    exit(1);
}

int main()
{
    system("chcp 1251");
    printf("Выполнено Левицким Павлом, группа 423-2\nВариант 11.\nНапишите программу, заполняющую матрицу nxn(значение n вводить с клавиатуры) по правилу (по строкам, слева направо):\nНапример, для n = 4 матрица будет выглядеть следующим образом :\n13\t14\t15\t16\n9\t10\t11\t12\n5\t6\t7\t8\n1\t2\t3\t4\t\n\n");
    int n;
    printf("Введите размерность матрицы:\n");
    int isDigit = scanf_s("%d", &n);
    if (n < 1 || isDigit != 1)
        error();
    int* matrix = (int*)malloc(n * n * sizeof(int));

    //fill
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[n * i + j] = count;
            count++;
        }
    }
    //reverse
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp = matrix[n * i + j];
            matrix[n * i + j] = matrix[n * (n - 1 - i) + j];
            matrix[n * (n - 1 - i) + j] = temp;
        }
    }
    //output
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", matrix[n * i + j]);
        }
        printf("\n");
    }
    free(matrix);
    return 0;
}