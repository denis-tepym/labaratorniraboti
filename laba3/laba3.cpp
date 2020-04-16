#include <iostream>
using namespace std;

struct element {
	int value;
	element* pointer;
	element() {
		value = 0;
		pointer = NULL;
	}
};

void In(element*& s, int n)
{
	element* p = NULL;
	int i = 0;
	cout << "Elementi: ";
	while (i < n) {
		element* p1 = new element();
		cin >> p1->value;
		if (s == NULL) {
			s = p1;
			p = p1;
		}
		else {
			p->pointer = p1;
			p = p1;
		}
		i++;
	}
}

void Out(element* l) {
	cout << "Spisok: ";
	while (l != NULL) {
		cout << l->value << " ";
		l = l->pointer;
	}
	cout << endl;
}



void Add(element*& head)
{
	element* new_head = 0;
	for (element* pos = head; pos;)
	{
		element* next = pos->pointer;
		pos->pointer = new_head;
		new_head = pos;
		pos = next;
	}
	head = new_head;
}

int main()
{
	element* first = NULL;
	int n;
	cout << "Razmer spiska: ";
	cin >> n;
	In(first, n);
	Out(first);
	Add(first);
	Out(first);
	system("pause");

	return 0;
}
