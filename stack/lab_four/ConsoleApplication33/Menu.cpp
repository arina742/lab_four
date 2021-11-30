#include <iostream>
#include "Stack.h"
#include "Menu.h"

Stack stack_1, stack_2;
int main()
{
	setlocale(LC_ALL, "Russian");
	ShowMenu();
}

void ShowMenu()
{
    int choice = -1;
    while (choice != 9)
    {
        std::cout << "Введите номер команды:\n"; 
        std::cout << "1 - Добавить элемент в стек\n";
        std::cout << "2 - Показать стек\n";
        std::cout << "3 - Убрать верхний элемент из стека\n";
        std::cout << "4 - Объединение стеков \n";
        std::cout << "5 - Проверка стека на пустоту\n";
        std::cout << "6 - Удалить элемент с определённым приоритетом\n";
        std::cout << "7 - Очистить стек\n";
        std::cout << "8 - Пересечение стеков\n";
        std::cout << "9 - Выход\n";
        std::cin >> choice;
        OptionMenu(choice);
    }
}

void OptionMenu(const int choice)
{
    switch (choice)
    {
    case 1:
        ProcessTask1();
        break;
    case 2:
        ProcessTask2();
        break;
    case 3:
        ProcessTask3();
        break;
    case 4:
        ProcessTask4();
        break;
    case 5:
        ProcessTask5();
        break;
    case 6:
        ProcessTask6();
        break;
    case 7:
        ProcessTask7();
        break;
    case 8:
        ProcessTask8();
        break;
    }
    system("pause");
    std::cout << std::endl;
}
void ProcessTask1()
{
    int value, priority;
    std::cout << "Введите элемент и его приоритет: ";
    std::cin >> value >> priority;
    if (((ChoiceStack() == 1))) stack_1.Push(value, priority);
    else stack_2.Push(value, priority);
}

void ProcessTask2()
{
    if ((ChoiceStack() == 1)) std::cout << stack_1;
    else std::cout << stack_2;
}

void ProcessTask3()
{
    if ((ChoiceStack() == 1)) stack_1.Pop();
    else stack_2.Pop();
}

void ProcessTask4()
{
    std::cout << "Результат объединения: " << std::endl;
    std::cout << stack_1 + stack_2;
}

void ProcessTask5()
{
    if ((ChoiceStack() == 1))
    {
        if (stack_1.IsEmpty()) std::cout << "\x1b[31mСтек пуст!\x1b[0m\n";
        else std::cout << "\x1b[32mСтек заполнен!\x1b[0m\n";
    }
    else
    {
        if (stack_2.IsEmpty()) std::cout << "\x1b[31mСтек пуст!\x1b[0m\n";
        else std::cout << "\x1b[32mСтек заполнен!\x1b[0m\n";
    }
}

void ProcessTask6()
{
    int priority;
    std::cout << "Введите приоритет элемента для удаления: ";
    std::cin >> priority;
    if ((ChoiceStack() == 1)) stack_1.DeleteByPriority(priority);
    else stack_2.DeleteByPriority(priority);
}

void ProcessTask7()
{
    if (ChoiceStack() == 1) stack_1.Clear();
    else stack_2.Clear();
}

void ProcessTask8()
{
    std::cout << "Результат пересечения: " << std::endl;
    std::cout << stack_1 * stack_2;
}

int ChoiceStack()
{
    int choice;
    std::cout << "Выберите стек?\n1 - stack_1, 2 - stack_2: ";
    std::cin >> choice;
    return choice;
}

