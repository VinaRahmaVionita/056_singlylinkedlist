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

bool list::listEmpty()
{
	if (START == NULL)
		return true;
	else
		return false;
}
bool list::delNode(int nim)/*menghapus node dari dalam list*/
{
	Node* current, * previous;
	if (Search(nim, &previous, &current) == false)
		return false;
	previous->next = current->next;
	if (current == START)
		START = START->next;

	delete current;
	return true;
}

/*check apakah node yang di maksud ada di dalam list atau tidak*/
bool list::Search(int nim, Node** previous, Node** current)
{
	*previous = START;
	*current = START;
	while ((*current != NULL) && (nim != (*current)->noMhs))
	{
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}

void list::traverse()/*mengunjungi dan membaca data dalam list*/
{
	if (listEmpty())
		cout << "\nList Kosong\n";
	else
	{
		cout << endl << "Data di dalam list adalah:" << endl;
		Node* currentNode;
		for (currentNode = START; currentNode != NULL; currentNode = currentNode->next)
		{
			cout << currentNode->noMhs << "  " << currentNode->nama << "\n";
		}
		cout << endl;
	}
}
int main()
{
	list mhs;
	int nim;
	char ch;
	while (1)
	{
		cout << endl << "Menu";
		cout << endl << "1. Menambah data ke dalam list" << endl;
		cout << "2. Menghapus data dari dalam list" << endl;
		cout << "3. Menampilkan semua data di dalam list" << endl;
		cout << "4. Mencari data dalam list" << endl;
		cout << "5. Keluar " << endl;
		cout << endl << "masukkan pilihan (1-5) : ";
		cin >> ch;
		switch (ch)
		{
		case '1':
		{
			mhs.addNode();
		}
		break;

		case'2':
		{
			if (mhs.listEmpty())
			{
				cout << endl << "list kosong" << endl;
				break;
			}
			cout << endl << "\nmasukkan no mahasiswa yang akan di hapus :";
			cin >> nim;
			if (mhs.delNode(nim) == false)
				cout << endl << "data tidak di temukan" << endl;
			else
				cout << endl << "data dengan nomor mahasiswa" << nim << " berhasil dihapus" << endl;
		}
		break;
		case '3':
		{
			mhs.traverse();
		}
		break;

		case '4':
		{
			if (mhs.listEmpty() == true)
			{
				cout << "\nlist kosong\n";
				break;
			}
			Node* previous, * current;
			cout << endl << "masukkan no mahasiswa yang di cari :";
			cin >> nim;
			if (mhs.Search(nim, &previous, &current) == false)
				cout << endl << "data tidak di temukan" << endl;
			else
			{
				cout << endl << "data tidak di temukan" << endl;
				cout << "\nno mahasiswa:" << current->noMhs;
				cout << "\n\nnama:" << current->nama;
				cout << "\n";

			}
		}
		





