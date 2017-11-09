#include <iostream>
#include <stdlib.h>
using namespace std;

#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12
#define NULLKEY -32768

class HashTable
{
	int *elem;
	int count;
	int m;
public:
	HashTable();
	int Hash(int key);
	void InsertHash(int key);
	bool SearchHash(int key);
};
HashTable::HashTable()
{
	int i;
	m = HASHSIZE;
	count = 0;
	elem = new int[m];
	for (int i = 0; i < m; i++)
		elem[i] = NULLKEY;
}

int HashTable::Hash(int key)
{
	return key % m;
}

void HashTable::InsertHash(int key)
{
	int addr = Hash(key);
	while (elem[addr] != NULLKEY)
		addr = (addr + 1) % m;
	elem[addr] = key;
}

bool HashTable::SearchHash(int key)
{
	int addr = Hash(key);
	while (elem[addr] != key)
	{
		addr = (addr + 1) % m;
		if (elem[addr] == NULLKEY || elem[addr] == Hash(key))//not find or return to the 
			return UNSUCCESS;
	}
	return SUCCESS;
}
