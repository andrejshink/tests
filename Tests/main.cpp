
#include <iostream>
#include "inc/common.h"
#define MAX_M 100

struct Node
{
	int count;
	char name[11];
	Node *prev;
};
struct Node2
{
	unsigned int hash;
	Node2* next;
};
struct Node3
{
	char name[11];
	int count;
	int array;
};
Node3 *Map[100];

class HashList
{
	public:
		HashList(){head = 0;}
		void add(int hash)
		{
			Node2 * newNode = new Node2;
			newNode->hash = hash;
			if(!head)
			{
				newNode->next = 0;
				head = newNode;
			}
			else
			{
				newNode->next = head;
				head = newNode;
				
			}

		}
		void clearMap()
		{
			Node2 *tmp = head;
			while(tmp)
			{
				if(Map[tmp->hash])
					{
						delete M[tmp->hash];
						Map[tmp->hash] = 0;
					}
			}
		}
		Node2 * head;

};
unsigned int getHash(char *msg)
{
	unsigned hash = 5381;
	for(int i = 0; i<len(msg);msg++, ++i)
		hash = ((hash<<5) + hash) +(*msg);
	return hash % MAX_M;
}
 
Node* M[10][10];
void merge(int r1, int c1, int r2, int c2, int opt)
{
	Node *n1 = M[r1][c1];
	Node *n2 = M[r2][c2];
	while(n1->prev != 0)
		n1 =n1->prev;
	while(n2->prev != 0)
		n2 = n2->prev;
	if(opt == 1)
	{
		n2->prev = n1;
		n1->count +=n2->count;
	}
	else
	{
		n1->prev = n2;
		n2->count +=n1->count;
	}
}

int main()
{


    return 0;
} 