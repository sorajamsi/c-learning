#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void task1()
{
    int choice_2;
    float a = 0.1f, b = 88.0f, c = 0.2f * powf(10.0f, -6.0f), k;
    float x, y, pid_koren;
    printf("Дані які?\n1. Табличні\n2. Ввести власноруч\n3. Повернутись назад\nВибір:");
    scanf("%d", &choice_2);
    switch(choice_2)
    {
        case 1:
        printf("Дані обрані табличні, але вам потрібно ввести ще одну змінну k:\nk=");
        scanf("%f", &k);
        printf("a=%f, b=%f, c=%.7f, k=%f\n", a, b, c, k);
        break;
        case 2:
        printf("Дані обрано ввести власноруч\n");
        printf("a="); scanf("%f", &a);
        printf("b="); scanf("%f", &b);
        printf("c="); scanf("%f", &c);
        printf("k="); scanf("%f", &k);
        printf("a=%f, b=%f, c=%f, k=%f\n", a, b, c, k);
        break;
        case 3:
        return;
        default:
        printf("Невірний вибір!\n");
        return;
    }
    if(k == 0.0f)
    {
        printf("Помилка: k не може дорівнювати 0 (ділення на нуль)!\n");
        return;
    }
    pid_koren = powf(a, 2.0f) * c / (4.0f * k);
    if(pid_koren < 0)
    {
        printf("Помилка: під час визначенням y виявлено що вираз під коренем від'ємний, вираз під коренем не визначається!\n");
        return;
    }
    x = powf(a, 2.0f) * expf(-powf(a / b, 2.0f));
    y = atanf(sqrtf(pid_koren));
    printf("Обрахунок виконано!\nВідповідь:\nx=%.3f\ny=%.5f\n", x, y);
}
void task2()
{
    int choice_3;
    float a = 0.2f;
    float x, y;
    printf("Дані які?\n1. Табличні\n2. Ввести власноруч\n3. Повернутись назад\nВибір:");
    scanf("%d", &choice_3);
    switch(choice_3)
    {
        case 1:
        printf("Дані обрані табличні\n");
        printf("a=%.1f\n", a);
        break;
        case 2:
        printf("Дані обрано ввести власноруч\n");
        printf("a="); scanf("%f", &a);
        break;
        case 3:
        return;
        default:
        printf("Невірний вибір!\n");
        return;
    }
    for(x = -2.0f; x <= 2.0f; x += 0.5f)
    {
        if(x <= 0.5f)
        {
            y = (powf(x, 2.0f) - 5.0f * x + 6.0f) / (powf(x, 2.0f) + 1.0f);
        }
        else 
        {
            y = powf(x, 2.0f / 3.0f) - powf(powf(x, 2.0f) - 1.0f, 1.0f / 3.0f) + expf(a);
        }
        printf("x=%6.3f, y=%7.5f\n", x ,y);
    }
}
int main ()
{
    int choice_1;
    while(1)
    {
        printf("Яке завдання будем виконувати?\n1. Завдання 1\n2. Завдання 2\n3. Вийти\nВибір:");
        scanf("%d", &choice_1);

        switch(choice_1) 
        {
            case 1:
            task1();
            break;
            case 2:
            task2();
            break;
            case 3:
            printf("Вихід...\n");
            exit(0);
            default:
            printf("Невірний вибір!\n");
        }
    }
    return 0;
}
