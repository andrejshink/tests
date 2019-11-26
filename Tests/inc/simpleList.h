#include <iostream>
#include "common.h"

class List
{
public:
    Node *head;
    List(){head = 0;}
    void add(int key, int val, char *data)
    {
        Node *newNode = new Node;
        newNode->key = key;
        newNode->val = val;
        m_strcpy(newNode->data, data);
        newNode->next = 0;
        if(!head)
            head = newNode;
        else
        {
            Node *cur = head;
            while(cur->next)
                cur = cur->next;
            cur->next = newNode;
        }
        
    }
    int get(int key)
    {
        Node *cur = head;
        while(cur)
        {
            if(cur->key == key)
                return cur->val;
            cur = cur->next;
        }
        return 0;
    }
    Node* getNode(char * data)
    {
        Node *cur = head;
        while(cur)
        {
            if(m_strcmp(cur->data, data) == 0)
                return cur;
            cur = cur->next;
        }
        return 0;
    }
    Node *delNode(char *data)
    {
        Node *cur = head;
        if(m_strcmp(cur->data, data) == 0)
        {
            head = head->next;
            delete cur;
        }
        while(cur->next)
        {
            if(m_strcmp(cur->next->data, data) == 0)
            {
                Node * tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
                
            cur = cur->next;
        } 
        return 0;
    }

    ~List()
    {
        Node* cur = head;
        Node* tmp = NULL;
        while(cur)
        {
            tmp = cur->next;
            delete cur;
            cur = tmp;
        }
    }
    
};