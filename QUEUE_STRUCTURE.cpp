//
//  main.cpp
//  QUEUE_STRUCTURE
//
//  Created by user on 07.02.16.
//  Очередь.
//

#include <iostream>

class Element
{
public:
    int value;
    Element *next;
    Element *prev;
public:
    Element()
    {
        value = 0;
        next = NULL;
        prev = NULL;
    }
    Element(int data)
    {
        value = data;
        next = NULL;
        prev = NULL;
    }
};


struct List {
    
    Element* head; //голова  очереди
    Element* tail; //конец очереди
    unsigned int size;
    
    void Next(Element** pCurNode)
    {
        *pCurNode = (*pCurNode)->next;
    }
    void Prev(Element** pCurNode)
    {
        *pCurNode = (*pCurNode)->prev;
    }
    
    
    
    Element* insertBefore(Element* Where, int data)                       //вставить до элемента
    {
        if (Where == NULL && size != 0) // некорретный указатель
            return NULL;
        
        Element* NewElement = new Element(data);
        
        if (Where == NULL && size == 0) // список пуст
        {
            head = NewElement;
            tail = NewElement;
        }
        else
        {
            // Есть предыдущий элемент
            if (Where->prev)
            {
                Element* PrevElement = Where->prev;
                PrevElement->next = NewElement;
                NewElement->prev = PrevElement;
                NewElement->next = Where;
                Where->prev = NewElement;
            }
            // Where = _pBegin
            else
            {
                head->prev = NewElement;
                NewElement->next = head;
                head = NewElement;
            }
        }
        size++;
        return NewElement;
    }
    
    
    Element* insertAfter(Element* Where, int data)                       //вставить после элемента
    {
        if (Where == NULL && size !=0)
            return NULL;
        
        Element* NewElement = new Element(data);
        
        if (Where == NULL && size ==0){
            head = NewElement;
            tail = NewElement;
        }
        else {
            //есть следующий элемент
            if(Where->next)
            {
                Element* NextElement = Where->next;
                Where->next = NewElement;
                NewElement->prev = Where;
                NewElement->next = NextElement;
                NextElement->prev = NewElement;
            }
            // Where = _pEnd
            else
            {
                tail->next = NewElement;
                NewElement->prev = tail;
                tail = NewElement;
            }
        }
        size++;
        return NewElement;
    }
    
    
    Element* erase(Element* Where)                                      //удалить элемент
    {
        if (Where == NULL)
            return NULL;
        
        if (Where == head)
            Next(&head);
        else if (Where == tail)
            Prev(&tail);
        
        Element* PrevElement = Where->prev;
        Element* NextElement = Where->next;
        if (NextElement)
            NextElement->prev = PrevElement;
        if (PrevElement)
            PrevElement->next = NextElement;
        
        delete Where;
        size--;
        return NextElement;
    }
    
    void _delete()                                      //удалить весь список
    {
        Element* temp1;
        Element* temp2;
        temp2 = head;
        temp1 = head->next;
        
        while (temp1->next){
            erase(temp2);
            temp2 = temp1;
            temp1 = temp1->next;
        }
    }
    
    
    void pushFront(int data) {insertBefore(head, data);};                     //вставить в начало
    
    void pushBack(int data) {insertAfter(tail, data);};                       //вставить в конец
    
    void popFront(int dat) {erase(head);};                                    //удалить из начала
    
    void popBack(int dat) {erase(tail);};                                    //удалить из начала
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
