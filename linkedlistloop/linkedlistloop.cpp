#include <iostream>
#include  <string.h>
using namespace std;

class Node
{
public:
	int noMhs;
	char nama[20];
	Node* next;
};

class list
{
	Node* START;
public:
	list();
	void addNode();
	bool Search(int nim, Node** current, Node** previous);
	bool listEmpty();
	bool delNode(int element);
	void traverse();
};

list::list()
{
	START = NULL;
}
void list::addNode()/*menambah sebuah node ke dalam list*/
{
	int nim;
	char nm[20];
	cout << "\nMasukkan Nomor Mahasiswa :";
	cin >> nim;
	cout << "\nMasukkan Nama :";
	cin >> nm;

	Node* nodeBaru = new Node;
	nodeBaru->noMhs = nim;
	strcpy_s(nodeBaru->nama, nm);

	if (START == NULL || nim < -START->noMhs)
	{
		if ((START != NULL) && (nim == START->noMhs))
		{
			cout << "\nDuplikat noMhs tidak diizinkan\n";
			return;
		}
		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}
	Node* previous, * current;

	current = START;
	previous = START;

	while ((current != NULL) && (nim >= current->noMhs))
	{
		if (nim == current->noMhs)
		{
			cout << "\nDuplikat noMhs tidak diizinkan\n";
			return;
		}
		previous = current;
		current = current->next;
	}
	/*jika loop di atas di eksekusi, previous dan current akan menempati posisi dimana*/
	nodeBaru->next = current;
	previous->next = nodeBaru;
}


