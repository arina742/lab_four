#pragma once

class Stack
{
private:

    struct Element
    {
        int data;
        Element* next; //указатель на следующий элемент
        int priority;
        Element()
        {
            data = 0;
            next = nullptr;
            priority = 0;
        }

        ~Element()
        {

        }
    };
    Element* top = nullptr;

public:
    //конструктор
    Stack()
    {

    };

    //конструктор копирования
    Stack(const Stack& stack)
    {
        Element* element = stack.top;
        while (element != NULL)
        {
            Stack::Push(element->data, element->priority);
            element = element->next;
        }
    }

    ~Stack()
    {
        delete top;
    }

    //добавление элемента в стек
    void Push(const int value, const int priority);

    //выталкивание верхнего элемента из стека
    void Pop();

    //очищение стека
    void Clear();

    //удаление элемента определенного приоритета
    void DeleteByPriority(const int priority);

    //проверка стека на пустоту
    bool IsEmpty();

    //проверка нахождения элемента в стеке
    bool IsElementHere(const int value, const int data);

    //пересечение стеков
    friend Stack operator+(Stack& stack_1, Stack& stack_2)
    {
        Stack stack_3;
        Element* element_stack_1 = stack_1.top;//сссылка на текущий элемент
        Element* element_stack_2 = stack_2.top; 
        while (element_stack_1 != nullptr)//перебираем элементы стека
        {
            stack_3.Push(element_stack_1->data, element_stack_1->priority);
            element_stack_1 = element_stack_1->next;
        }
        while (element_stack_2 != nullptr)//перебираем элементы стека
        {
            stack_3.Push(element_stack_2->data, element_stack_2->priority);
            element_stack_2 = element_stack_2->next;
        }
        return stack_3;
    }

    //объединение стеков
    friend Stack operator*(Stack& stack_1, Stack& stack_2)
    {
        Stack stack_3;
        Element* element_stack_1 = stack_1.top;//сссылка на текущий элемент
        while (element_stack_1 != nullptr)//перебираем элементы стека
        {
            if (stack_2.IsElementHere(element_stack_1->data, element_stack_1->priority))
            {
                stack_3.Push(element_stack_1->data, element_stack_1->priority);
            }
            element_stack_1 = element_stack_1->next;
        }        
        return stack_3;
    }

    //вывод стека
    friend std::ostream& operator<<(std::ostream& out, const Stack& stack)
    {
        Element* element_stack = stack.top;
        if (element_stack == nullptr)
        {
            out << "Стек пуст!" << std::endl;
        }
        else
        {
            while (element_stack != nullptr)
            {
                out << "(" << element_stack->data << "," << element_stack->priority << ")" << std::endl;
                element_stack = element_stack->next;
            }
        }
        return out;
    }
};


