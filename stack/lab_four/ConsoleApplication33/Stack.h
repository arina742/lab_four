#pragma once

class Stack
{
private:

    struct Element
    {
        int data;
        Element* next; //óêàçàòåëü íà ñëåäóþùèé ýëåìåíò
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
    //êîíñòðóêòîð
    Stack()
    {

    };

    
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

    //äîáàâëåíèå ýëåìåíòà â ñòåê
    void Push(const int value, const int priority);

    //âûòàëêèâàíèå âåðõíåãî ýëåìåíòà èç ñòåêà
    void Pop();

    //î÷èùåíèå ñòåêà
    void Clear();

    //óäàëåíèå ýëåìåíòà îïðåäåëåííîãî ïðèîðèòåòà
    void DeleteByPriority(const int priority);

    //ïðîâåðêà ñòåêà íà ïóñòîòó
    bool IsEmpty();

    //ïðîâåðêà íàõîæäåíèÿ ýëåìåíòà â ñòåêå
    bool IsElementHere(const int value, const int data);

    //ïåðåñå÷åíèå ñòåêîâ
    friend Stack operator+(Stack& stack_1, Stack& stack_2)
    {
        Stack stack_3;
        Element* element_stack_1 = stack_1.top;//ñññûëêà íà òåêóùèé ýëåìåíò
        Element* element_stack_2 = stack_2.top; 
        while (element_stack_1 != nullptr)//ïåðåáèðàåì ýëåìåíòû ñòåêà
        {
            stack_3.Push(element_stack_1->data, element_stack_1->priority);
            element_stack_1 = element_stack_1->next;
        }
        while (element_stack_2 != nullptr)//ïåðåáèðàåì ýëåìåíòû ñòåêà
        {
            stack_3.Push(element_stack_2->data, element_stack_2->priority);
            element_stack_2 = element_stack_2->next;
        }
        return stack_3;
    }

    //îáúåäèíåíèå ñòåêîâ
    friend Stack operator*(Stack& stack_1, Stack& stack_2)
    {
        Stack stack_3;
        Element* element_stack_1 = stack_1.top;//ñññûëêà íà òåêóùèé ýëåìåíò
        while (element_stack_1 != nullptr)//ïåðåáèðàåì ýëåìåíòû ñòåêà
        {
            if (stack_2.IsElementHere(element_stack_1->data, element_stack_1->priority))
            {
                stack_3.Push(element_stack_1->data, element_stack_1->priority);
            }
            element_stack_1 = element_stack_1->next;
        }        
        return stack_3;
    }

    //âûâîä ñòåêà
    friend std::ostream& operator<<(std::ostream& out, const Stack& stack)
    {
        Element* element_stack = stack.top;
        if (element_stack == nullptr)
        {
            out << "Ñòåê ïóñò!" << std::endl;
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


