#include <iostream>
#include <ctime>
#include "common.h"
#include "simpleList.h"
#define MAX_M 1000001

int count = 0;
class HashMap
{
public:
    Node * hashMap[MAX_M];
    HashMap()
    {
        for(int i = 0; i<MAX_M; ++i)
        {
            hashMap[i] = 0;
        }
    }

    int getHash(int key)
    {
        return key % (MAX_M-1);
    }

    void add(Node *n)
    {
        int key = n->key;
        int res = getHash(key);
        if(hashMap[res] == 0)
        {
            hashMap[res] = n;
        }
        else
        {
            count++;
            while(hashMap[res] != 0)
            {
                res++;
                if(res == MAX_M)
                    res = 0;
            }
            hashMap[res] = n;   
        }
    }
    Node *getData(int key)
    {
        int hash = getHash(key);
        while(hashMap[hash] != 0)
        {
            if(hashMap[hash]->key == key)
            {
                std::cout<< hash << std::endl;
                return hashMap[hash];
            }
            else
            {
                hash++;
                if(hash == MAX_M)
                    hash = 0;
            }
        }
        return 0;
    }

    void clear()
    {
        for (int i = 0; i < MAX_M; ++i)
        {
            if (hashMap[i])
            {
                delete hashMap[i];
                hashMap[i] = 0;
            }
        }
    }

    ~HashMap()
    {
        clear();
    }
    
};

unsigned int DJBHash(char* str, unsigned int len)
{
   unsigned int hash = 5381;
   unsigned int i    = 0;

   for(i = 0; i < len; str++, i++)
   {   
      hash = ((hash << 5) + hash) + (*str);
   }   

   return hash % MAX_M;
}

class HashMapList
{
public:
    List * hashMap[MAX_M];
    HashMapList()
    {
        for(int i = 0; i<MAX_M; ++i)
        {
            hashMap[i] = 0;
        }
    }

    

    void add(Node *n) 
    {
        char * msg = n->data;
        int res = DJBHash(msg, len(msg));
        List * lst = hashMap[res];
        if(lst == 0)
        {
            lst = new List;
            lst->add(n->key, n->val, msg);

            hashMap[res] = lst;
        }
        else
        {
            lst->add(n->key, n->val, msg);
        }
    }
    Node *getData(char * msg)
    {
        int hash = DJBHash(msg, len(msg));
        List *lst = hashMap[hash];
        if(lst)
        {
            return lst->getNode(msg);

        }
        
        return 0;
    }

    void clear()
    {
        for (int i = 0; i < MAX_M; ++i)
        {
            if (hashMap[i])
            {
                delete hashMap[i];
                hashMap[i] = 0;
            }
        }
    }

    ~HashMapList()
    {
        clear();
    }
    
};
