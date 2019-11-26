#ifndef LINKEDLIST
#define LINKEDLIST

#include "common.h"
#include <iostream>

class LinkedList
{
public:
    LinkedList(){head = 0; tail = 0; size = 0;}
    ~LinkedList(){clear();}

public:
    void clear()
    {
        while(head)
        {
            if(head != tail)
            {
                head = head->next;
                delete head->prev;
            }
            else
            {
                delete head;
                head = 0;
            }   
        }
    }
    void delLast()
    {
        
        if(size == 0)
            return;
        else if(size == 1)
        {
            delete head;
            head = 0;
            tail = 0;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = 0;
        }
        size--;
        
    }
    void delFirst()
    {
        if(size == 0)
            return;
        else if(size == 1)
        {
            delete head;
            head = 0;
            tail = 0;
        }
        else
        {
            head = head->next;
            delete head->prev;
            head->prev = 0;
        }
        size--;
    }
    void del(int key)
    {
        if(size == 0)
            return;
        else if(size == 1 && head->key == key)
        {
            delete head;
            head = 0;
            tail = 0;
            size--;
            return;
        }
        
        Node *tmp = head;
        
        while(tmp != 0 && tmp->key != key)
        {
            tmp = tmp->next;
        }
        if(tmp == 0)
            return;
        else if(tmp == head)
        {
            head = tmp->next;
            head->prev = 0;
        }
        else if(tmp == tail)
        {
            tail = tmp->prev;
            tail->next = 0;
        }
        else
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
        }
        size--;
        delete tmp;
        
    }
    void delNumber(int num)
    {
        int count = 0;
        Node *tmp = head;
        while(count != num && tmp != 0)
        {
            tmp = tmp->next;
            count++;
        }
        if(tmp == 0)
            return;
        else if(tmp == head)
        {
            head = tmp->next;
            head->prev = 0;
        }
        else if(tmp == tail)
        {
            tail = tmp->prev;
            tail->next = 0;
        }
        else
        {
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
        }
        size--;
        delete tmp;
    }
    void add(int key, int val)
    {
        Node * node = new Node;
        node->key = key;
        node->val = val;
        node->next = 0;
        if(head == 0)
        {
            node->prev = 0;
            head = node;
            tail = node;
        }
        else
        {
            node->prev = tail;
            tail->next = node;
            tail = tail->next;
        }
        size++;
    }
    Node *get(int key)
    {
        Node *tmp = head;
        while(tmp != 0 && tmp->key !=key)
        {
            tmp = tmp->next;
        }
        return tmp;
    }


public:
    Node *head;
    Node *tail;
    unsigned int size;
    
};
#endif //LINKEDLIST