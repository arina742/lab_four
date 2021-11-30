#include <iostream>
#include "Stack.h"
#include "stdlib.h"
#include <utility>

    //���������� �������� � ����
    void Stack::Push(const int value,const int priority)
    {
        Element* previous = top;//������ ���������� �������
        Element* current = top;//������� �� ������� �������

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
            if (current == nullptr) //��������� ������� � �����
            {
                previous->next = element_stack;
            }
            else //������ ������� � ������� �����������
            {
                previous->next = element_stack;
                element_stack->next = current;
            }
        }
    }

    //������������ �������� �������� �� �����
    void Stack::Pop()
    {
        Element value = *top;
        if (IsEmpty())
        {
            std::cout << "\x1b[31m���� ����!\x1b[0m" << std::endl;
        }
        else
        {
            Stack::~Stack();
            top = value.next;
        }
    }

    //�������� �����
    void Stack::Clear()
    {
        Stack::~Stack();
        top = nullptr;
        std::cout << "\x1b[32m���� ������ :)\x1b[0m" << std::endl;
    }

    //�������� �������� ������������� ����������
    void Stack::DeleteByPriority(const int priority)
    {
        Element* previous = top;//������ ���������� �������
        Element* current = top;//������� �� ������� �������

        if (current->priority == priority && current->next == nullptr) //������ ���� ������� � �����
        {
            top = nullptr;
        }
        else
        {
            while (current != nullptr && current->priority != priority)//���������� �������� �����
            {
                previous = current;
                current = current->next;
            }

            if (current->priority == priority && current == top && previous == top )//������ ������� � ������ ����������� � ������ �����
            {
                top = current->next;
                delete current;
            }

            if (current->priority == priority && current->next != nullptr && current != top)//������ ������� � ������ ����������� � �������� �����
            {
                previous->next = current->next;
                delete current;
            }

            if (current->next == nullptr && current->priority == priority) //��������� ������� � �����
            {
                previous->next = nullptr;
                delete current;
            }
        }
    }

    //�������� ����� �� �������
    bool Stack::IsEmpty()
    {
        Element* value = top;
        if (value == nullptr)
        {
            return true; //���� ����
        }
            return false; //���� ����
    }

    //�������� ���������� �������� � �����
    bool Stack::IsElementHere(const int data, const int priority)
    {
        Element* element_stack = top;

            while (element_stack != nullptr)//���������� �������� �����
            {
                if(element_stack->priority == priority && element_stack->data == data)
                {
                    return true;
                }
                element_stack = element_stack->next;
            }          
            return false;
    }
 



