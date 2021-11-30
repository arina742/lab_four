#include <iostream>
#include "Stack.h"
#include "stdlib.h"
#include <utility>

    //добавление элемента в стек
    void Stack::Push(const int value,const int priority)
    {
        Element* previous = top;//ссылка предыдущий элемент
        Element* current = top;//сссылка на текущий элемент

        Element* element_stack = new Element();
        element_stack->data = value;
        element_stack->priority = priority;
        
        if (top == nullptr)
        {
            top = element_stack;
        }
        else
        {
            if (current->priority >= priority)
            {
                element_stack->next = top;
                top = element_stack;
                return;
            }
            while (current != nullptr && current->priority < priority)
            {
                previous = current;
                current = current->next;
            }
            if (current == nullptr) //последний элемент в стеке
            {
                previous->next = element_stack;
            }
            else //найден элемент с меньшим приоритетом
            {
                previous->next = element_stack;
                element_stack->next = current;
            }
        }
    }

    //выталкивание верхнего элемента из стека
    void Stack::Pop()
    {
        Element value = *top;
        if (IsEmpty())
        {
            std::cout << "\x1b[31mСтек пуст!\x1b[0m" << std::endl;
        }
        else
        {
            Stack::~Stack();
            top = value.next;
        }
    }

    //очищение стека
    void Stack::Clear()
    {
        Stack::~Stack();
        top = nullptr;
        std::cout << "\x1b[32mСтек очищен :)\x1b[0m" << std::endl;
    }

    //удаление элемента определенного приоритета
    void Stack::DeleteByPriority(const int priority)
    {
        Element* previous = top;//ссылка предыдущий элемент
        Element* current = top;//сссылка на текущий элемент

        if (current->priority == priority && current->next == nullptr) //только один элемент в стеке
        {
            top = nullptr;
        }
        else
        {
            while (current != nullptr && current->priority != priority)//перебираем элементы стека
            {
                previous = current;
                current = current->next;
            }

            if (current->priority == priority && current == top && previous == top )//найден элемент с нужным приоритетом в начале стека
            {
                top = current->next;
                delete current;
            }

            if (current->priority == priority && current->next != nullptr && current != top)//найден элемент с нужным приоритетом в середине стека
            {
                previous->next = current->next;
                delete current;
            }

            if (current->next == nullptr && current->priority == priority) //последний элемент в стеке
            {
                previous->next = nullptr;
                delete current;
            }
        }
    }

    //проверка стека на пустоту
    bool Stack::IsEmpty()
    {
        Element* value = top;
        if (value == nullptr)
        {
            return true; //стек пуст
        }
            return false; //стек пуст
    }

    //проверка нахождения элемента в стеке
    bool Stack::IsElementHere(const int data, const int priority)
    {
        Element* element_stack = top;

            while (element_stack != nullptr)//перебираем элементы стека
            {
                if(element_stack->priority == priority && element_stack->data == data)
                {
                    return true;
                }
                element_stack = element_stack->next;
            }          
            return false;
    }
 



