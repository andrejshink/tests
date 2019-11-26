#ifndef COMMON_H
#define COMMON_H
#define MAX_LEN_DATA 10
#include <iostream>
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
/*
struct Node
{
    int key;
    int val;
    char data[MAX_LEN_DATA];
    Node *next;
    Node *prev;
    bool operator> ( Node &right)
    {
        if(key > right.key)
            return true;
        if(key == right.key && val > right.val)
            return true;
        return false;
    }
};
*/

#endif //COMMON_H