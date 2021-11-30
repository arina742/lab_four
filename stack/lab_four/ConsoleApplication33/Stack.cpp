#include <iostream>
#include "Stack.h"
#include "stdlib.h"
#include <utility>

    void Stack::Push(const int value,const int priority)
    {
        Element* previous = top;//ññûëêà ïðåäûäóùèé ýëåìåíò
        Element* current = top;//ñññûëêà íà òåêóùèé ýëåìåíò

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
            if (current == nullptr) //ïîñëåäíèé ýëåìåíò â ñòåêå
            {
                previous->next = element_stack;
            }
            else //íàéäåí ýëåìåíò ñ ìåíüøèì ïðèîðèòåòîì
            {
                previous->next = element_stack;
                element_stack->next = current;
            }
        }
    }

    //âûòàëêèâàíèå âåðõíåãî ýëåìåíòà èç ñòåêà
    void Stack::Pop()
    {
        Element value = *top;
        if (IsEmpty())
        {
            std::cout << "\x1b[31mÑòåê ïóñò!\x1b[0m" << std::endl;
        }
        else
        {
            Stack::~Stack();
            top = value.next;
        }
    }

    //î÷èùåíèå ñòåêà
    void Stack::Clear()
    {
        Stack::~Stack();
        top = nullptr;
        std::cout << "\x1b[32mÑòåê î÷èùåí :)\x1b[0m" << std::endl;
    }


    void Stack::DeleteByPriority(const int priority)
    {
        Element* previous = top;//ññûëêà ïðåäûäóùèé ýëåìåíò
        Element* current = top;//ñññûëêà íà òåêóùèé ýëåìåíò

        if (current->priority == priority && current->next == nullptr) //òîëüêî îäèí ýëåìåíò â ñòåêå
        {
            top = nullptr;
        }
        else
        {
            while (current != nullptr && current->priority != priority)//ïåðåáèðàåì ýëåìåíòû ñòåêà
            {
                previous = current;
                current = current->next;
            }

            if (current->priority == priority && current == top && previous == top )//íàéäåí ýëåìåíò ñ íóæíûì ïðèîðèòåòîì â íà÷àëå ñòåêà
            {
                top = current->next;
                delete current;
            }

            if (current->priority == priority && current->next != nullptr && current != top)//íàéäåí ýëåìåíò ñ íóæíûì ïðèîðèòåòîì â ñåðåäèíå ñòåêà
            {
                previous->next = current->next;
                delete current;
            }

            if (current->next == nullptr && current->priority == priority) //ïîñëåäíèé ýëåìåíò â ñòåêå
            {
                previous->next = nullptr;
                delete current;
            }
        }
    }

    //ïðîâåðêà ñòåêà íà ïóñòîòó
    bool Stack::IsEmpty()
    {
        Element* value = top;
        if (value == nullptr)
        {
            return true; //ñòåê ïóñò
        }
            return false; //ñòåê ïóñò
    }

    //ïðîâåðêà íàõîæäåíèÿ ýëåìåíòà â ñòåêå
    bool Stack::IsElementHere(const int data, const int priority)
    {
        Element* element_stack = top;

            while (element_stack != nullptr)//ïåðåáèðàåì ýëåìåíòû ñòåêà
            {
                if(element_stack->priority == priority && element_stack->data == data)
                {
                    return true;
                }
                element_stack = element_stack->next;
            }          
            return false;
    }
 



