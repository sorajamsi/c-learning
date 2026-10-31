#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

int date_user(int n, int *arr_1)
{
    cout << "Введення власноруч" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "Число " << (i + 1) << ": ";
        cin >> arr_1[i];
    }
    return 0;
}
int date_generated(int n, int *arr_2)
{
    int N;
    cout << "Генерувати числа до якого значення?" << endl << "Введення: ";
    cin >> N;
    cout << "Генерація" << endl;
    for(int i = 0; i < n; i++)
    {
        arr_2[i] = rand() % (N + 1);
    }
    return 0;
}

int search_i(int n, int arr[], int &result)
{
    int max_diff = abs(arr[0] - arr[1]);
    int diff;
    for(int i = 0; (i + 1) < n; i++)
    {
        diff = abs(arr[i] - arr[i + 1]);
        if(diff > max_diff)
        {
            max_diff = diff;
        }
    }
    result = max_diff;
    return 0;
}
int search_r(int n, int arr[], int &result)
{
    if (n == 2)
    {
        result = abs(arr[0] - arr[1]);
        return 0;
    }
    int max_diff;
    int diff;
    search_r((n - 1), arr, max_diff);
    diff = abs(arr[n - 2] - arr[n - 1]);
    result = max(diff, max_diff);
    return 0;
}

int main()
{
    srand(time(NULL));
    int n;
    int choice_1, choice_2;
    int result;
    cout << "Який розмір масиву A[N]?" << endl << "Введення: "; cin >> n;
    int *arr = new int[n];
    if(arr == NULL)
    {
        cout << "Помилка! Не вдалось виділити память." << endl;
        delete[] arr;
        return -1;
    }
    while(true)
    {
        cout << "Дані для масиву які?" << endl << "1. Ввести власноруч" << endl << "2. Згенерувати" << endl << "3. Вихід" << endl << "Введення: ";
        cin >> choice_1;
        switch(choice_1)
        {
            case 1:
            date_user(n, arr);
            break;

            case 2:
            date_generated(n, arr);
            break;

            case 3:
            delete[] arr;
            exit(0);

            default:
            cout << "Невірний вибір!" << endl << "Спробуйте ще раз" << endl;
            continue;
        }
        break;
    }
    cout << "Ваш масив" << endl;
    cout << "|";
    for(int i = 0; i < n; i++)
    {
        cout << "  " << arr[i];
    }
    cout << "  |" << endl;
    if(n < 2)
    {
        cout << "Неможливо знайти пару сусідніх елементів";
        delete [] arr;
        return -1;
    }
    while(true)
    {
        cout << "Як будемо шукати максимальну різницю сусідніх елементів масиву A[N]" << endl << "1. Ітеративно" << endl << "2. Рекурсивно" << endl << "3. Вихід" << endl << "Введення: ";
        cin >> choice_2;
        switch(choice_2)
        {
            case 1:
            search_i(n, arr, result);
            cout << "Максимальну різницю сусідніх елементів масиву A[N] = " << result << endl;
            break;

            case 2:
            search_r(n, arr, result);
            cout << "Максимальну різницю сусідніх елементів масиву A[N] = " << result << endl;
            break;

            case 3:
            delete[] arr;
            exit(0);

            default:
            cout << "Невірний вибір!" << endl << "Спробуйте ще раз" << endl;
            continue;
        }
    }
    delete [] arr;
    return 0;
}
