#include <iostream>
#include <ctime>

#define MAX_M 101

struct Node 
{
    int key;
    int val;
    bool flag;
};

int len(char* str)
{
    char *p = str;
    while(*p)p++;
    return p - str;
}
void m_strcpy(char *dst, char *src)
{
    while(src)
    {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
}
char* split(char* str, char sym)
{
    char * p = str;
    while(*p !=0 && *p != sym)
    {
        p++;
    }
    if(*p)
    {
        *p = 0;
        p++;
        return p;
    }
    else
        return 0;
}
bool m_strcmp(char * src, char *dst)
{
    if(len(src) != len(dst))
        return false;
    while(src)
    {
        if(*src != *dst)
            return false;
    }
    return true;
}

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
        n->flag = false;
        if(hashMap[res] == 0)
        {
            hashMap[res] = n;
            n->flag = false;
        }
        else
        {
            count++;
            while(hashMap[res] != 0 && hashMap[res]->flag == false)
            {
                res++;
                if(res == MAX_M)
                    res = 0;
            }
            if(hashMap[res] != 0)
                delete hashMap[res];
            hashMap[res] = n;  
        }
    }
    bool delNode(Node* n)
    {
        int hash = getHash(n->key);
        while(hashMap[hash] != 0)
        {
            if(hashMap[hash]->key == n->key && hashMap[hash]->flag != true)
            {
                std::cout<< hash << std::endl;
                hashMap[hash]->flag = true;
                return true;
            }
            else
            {
                hash++;
                if(hash == MAX_M)
                    hash = 0;
            }
        }
        return false;

    }
    Node *getData(int key)
    {
        int hash = getHash(key);
        while(hashMap[hash] != 0)
        {
            if(hashMap[hash]->key == key && hashMap[hash]->flag != true)
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

    void print()
    {
        for(int i = 0; i<MAX_M; ++i)
        {
            std::cout <<"i: " << i <<", ";
            if(hashMap[i]  && hashMap[i]->flag == false)
                std::cout <<hashMap[i]->key << " ";
            else 
            std::cout <<0<< " ";
        }
        std::cout << std::endl;
    }

    ~HashMap()
    {
        clear();
    }
    
};


int main()
{
    HashMap hmap;
    
    int key;
    char command;
    while(1)
    {
        std::cin>>command;
        std::cin>>key;
        Node *n = new Node;
        
        n->key = key;
        if(command =='a')
            hmap.add(n);
        if(command == 'd')
            std::cout <<hmap.delNode(n) <<std::endl;
        hmap.print();
    }
}