#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int choice;
    int n, i, j, N;
    printf("Скільки чисел ви хочете ввести:"); scanf("%d", &n);
    int *arr = (int*) calloc(n * n, sizeof(int));
    if (arr == NULL)
    {
        printf("Помилка! Не вдалося виділити память.\n");
        return 1;
    }
    while(1)
    {
        printf("Елементи масивів які?\n1.Автоматична генерація\n2.Введення власноруч\n3.Вихід\nВиберіть:"); scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            printf("До якого числа робити генерацію?\nЧисло:"); scanf("%d", &N);
            printf("Автоматична генерація...\n");
            for(int i = 0; i < n * n; i++)
            {
                arr[i] = rand() % (N + 1);
            }
            printf("Ваша матриця\n");
            printf("|");
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    printf("  %d", arr[i * n + j]);
                }
                printf(" |");
            }
            printf("\n");
            printf("Верхній трикутник матриці(включаючи елементи головної діагоналі), по рядках як матрицю\n");
            for(int i = 0; i < n; i++)
            {
                printf("| ");
                for(int j = 0; j < n; j++)
                {
                    if(j >= i)
                    {
                        printf("%2d", arr[i * n + j]);
                    }
                    else
                    {
                        printf("  ");
                    }
                    if(j < n - 1)
                    {
                        printf("\t");
                    }
                }
                printf(" |\n");
            }
            break;
            case 2:
            printf("Введення власноруч\n");
            for(int i = 0; i < n * n; i++)
            {
                printf("Елемент %d:", (i + 1));
                scanf("%d", &arr[i]);
            }
            printf("Ваша матриця\n");
            printf("|");
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    printf("  %d", arr[i * n + j]);
                }
                printf(" |");
            }
            printf("\n");
            printf("Верхній трикутник матриці(включаючи елементи головної діагоналі), по рядках як матрицю\n");
            for(int i = 0; i < n; i++)
            {
                printf("| ");
                for(int j = 0; j < n; j++)
                {
                    if(j >= i)
                    {
                        printf("%2d", arr[i * n + j]);
                    }
                    else
                    {
                        printf("  ");
                    }
                    if(j < n - 1)
                    {
                        printf("\t");
                    }
                }
                printf(" |\n");
            }
            break;
            case 3:
            exit(0);
            default:
           printf("Невірний вибір!\nПовторіть спробу\n");
        }
    }
}