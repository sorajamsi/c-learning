#include <stdio.h>
#include <math.h>

int main(void)
{
    double x = 1, eps = 0, sum = 0.0, term;
    int n = 1;

    while(fabs(x) >=1)
    {
        printf("Введіть x (-1 < x < 1): ");
        scanf("%lf", &x);
        if(fabs(x) >= 1)
        {
            printf("Помилка: |x| повинен бути < 1.\n");
        } 
    }
    while(eps <= 0)
    {
        printf("Введіть eps (eps > 0): ");
        scanf("%lf", &eps);
        if (eps <= 0)
        {
            printf("Помилка: eps повинен бути > 0.\n");
        }
    }
    term = x;

    while(fabs(term) >= eps)
    {
        sum = sum + term;
        n++;
        term = term * x * x * (2.0 * n - 3.0) / (2.0 * n - 1.0);
    }

    printf("Результат:\n");
    printf("Сума елементів ряду S = %lf\n", sum);
    printf("Кількість ітерацій n = %d\n", n - 1);
    sum = atan(x);
    printf("Перевірка суми елементів ряду S = %lf\n", sum);

    return 0;
}
