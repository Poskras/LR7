#include <stdio.h>
#include <locale.h>
#include <windows.h>

int dzdayTask(int day);
float calculatorTask(float number1, char operation, float number2, int* valid);
float percent(float number, float percentValue);
float module(float number);
int symbolTask1(char symbol);

int main()
{
    int day;
    int daysToSunday;
    float number1;
    float number2;
    float result;
    char operation;
    char symbol;
    int valid;

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    setlocale(LC_ALL, ".UTF8");

    printf("ЗАДАНИЕ 1. Дни недели\n");
    printf("Введите номер дня недели (1-7): ");

    if (scanf_s("%d", &day) != 1)
    {
        printf("Ошибка ввода дня недели.\n\n");
    }
    else
    {
        daysToSunday = dzdayTask(day);
        if (daysToSunday == -1)
        {
            printf("Ошибка: неверный номер дня!\n\n");
        }
        else
        {
            switch (day)
            {
            case 1: printf("Понедельник\n"); break;
            case 2: printf("Вторник\n"); break;
            case 3: printf("Среда\n"); break;
            case 4: printf("Четверг\n"); break;
            case 5: printf("Пятница\n"); break;
            case 6: printf("Суббота\n"); break;
            case 7: printf("Воскресенье\n"); break;
            }
            printf("Осталось дней до воскресенья: %d\n\n", daysToSunday);
        }
    }

    printf("ЗАДАНИЕ 2. Калькулятор\n");
    printf("Введите число, знак операции и второе число.\n");
    printf("Операции: +, -, *, /, %% (процент), m (модуль первого числа).\n");
    printf("Пример: 289 - 19\n");

    if (scanf_s("%f %c %f", &number1, &operation, 1, &number2) == 3)
    {
        result = calculatorTask(number1, operation, number2, &valid);
        if (valid == 1)
        {
            printf("Результат: %.3f\n\n", result);
        }
        else if (valid == 0)
        {
            printf("Ошибка: на ноль делить нельзя!\n\n");
        }
        else
        {
            printf("Ошибка: неизвестная операция!\n\n");
        }
    }
    else
    {
        printf("Ошибка ввода данных калькулятора.\n\n");
    }

    printf("ЗАДАНИЕ 3. Определение символа\n");
    printf("Введите символ: ");
    if (scanf_s(" %c", &symbol, 1) == 1)
    {
        valid = symbolTask1(symbol);
        if (valid == 1)
        {
            printf("Это цифра.\n");
        }
        else if (valid == 2)
        {
            printf("Это буква латинского алфавита.\n");
        }
        else
        {
            printf("Неизвестный символ.\n");
        }
    }
    else
    {
        printf("Ошибка ввода символа.\n");
    }

    return 0;
}

int dzdayTask(int day)
{
    if (day < 1 || day > 7)
    {
        return -1;
    }
    return 7 - day;
}

float calculatorTask(float number1, char operation, float number2, int* valid)
{
    *valid = 1;
    switch (operation)
    {
    case '+': return number1 + number2;
    case '-': return number1 - number2;
    case '*': return number1 * number2;
    case '/':
        if (number2 == 0)
        {
            *valid = 0;
            return 0;
        }
        return number1 / number2;
    case '%': return percent(number1, number2);
    case 'm': return module(number1);
    default:
        *valid = -1;
        return 0;
    }
}

float percent(float number, float percentValue)
{
    return number * percentValue / 100.0f;
}

float module(float number)
{
    if (number < 0)
    {
        return -number;
    }
    return number;
}

int symbolTask1(char symbol)
{
    switch (symbol)
    {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        return 1;

    case 'a': case 'b': case 'c': case 'd': case 'e':
    case 'f': case 'g': case 'h': case 'i': case 'j':
    case 'k': case 'l': case 'm': case 'n': case 'o':
    case 'p': case 'q': case 'r': case 's': case 't':
    case 'u': case 'v': case 'w': case 'x': case 'y':
    case 'z':
    case 'A': case 'B': case 'C': case 'D': case 'E':
    case 'F': case 'G': case 'H': case 'I': case 'J':
    case 'K': case 'L': case 'M': case 'N': case 'O':
    case 'P': case 'Q': case 'R': case 'S': case 'T':
    case 'U': case 'V': case 'W': case 'X': case 'Y':
    case 'Z':
        return 2;

    default:
        return 0;
    }
}
