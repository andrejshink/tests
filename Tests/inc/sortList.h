#ifndef SORTLIST
#define SORTLIST
#include "common.h"
#include <iostream>
class SortList
{
public:
    SortList(){head = 0; size = 0;}
    ~SortList(){}

public:
void add(int key, int val)
    {
        Node * n = new Node;
        n->key = key;
        n->val = val;
        if(head == 0 || *head > *n)
        {
            n->next = head;
            head = n;
        }
        else
        {
            Node *cur = head;
            while(cur->next !=0 && (*n > *(cur->next)))
            {
                cur = cur->next;
            }
            n->next = cur->next;
            cur->next = n;
        }
        size++;
    }
    void add1(int key, int val)
    {
        Node * n = new Node;
        n->key = key;
        n->val = val;
        if(head == 0 || head->key > key || (head->key == key && head->val>val))
        {
            n->next = head;
            head = n;
        }
        else
        {
            std::cout <<"1"<<std::endl;
            Node *cur = head;
            while((cur->next !=0 && cur->next->key < key) || (cur->next !=0 && cur->next->key == key && cur->next->val <= val))
            {
                cur = cur->next;
            }
            n->next = cur->next;
            cur->next = n;
        }
        size++;
    }
    Node *head;
    int size;
};
#endif //SORTLIST