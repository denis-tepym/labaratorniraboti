#include <iostream>
using namespace std;

struct TreeElement
{
	int value;
	TreeElement* right;
	TreeElement* left;

	TreeElement()
	{
		value = 0;
		right = NULL;
		left = NULL;
	}
};
struct sps {
	int value;
	sps* pointer;
	sps() {
		value = 0;
		pointer = NULL;
	}
};

void Input(TreeElement*& el, int v)
{
	if (el == NULL)
	{
		el = new TreeElement();
		el->value = v;
	}
	else if (el->value > v)
	{
		Input(el->left, v);
	}
	else if (el->value < v)
	{
		Input(el->right, v);
	}
}
void Output(TreeElement* el)
{
	if (el != NULL)
	{
		Output(el->left);
		cout << el->value << " ";
		Output(el->right);
	}
}
void spos(sps*& head, TreeElement* el, sps*& p)
{
	if (el != NULL)
	{
		spos(head, el->left, p);
		sps* p1 = new sps;
		p1->value = el->value;
		if (p == NULL)
		{
			head = p1;
			p = p1;
		}
		else
		{
			p->pointer = p1;
			p = p1;
		}
		spos(head, el->right, p);
	}
}

void Out(sps* l) {
	cout << "Список: ";
	while (l != NULL) {
		cout << l->value << " ";
		l = l->pointer;
	}
	cout << endl;
}
void Detach(TreeElement* root, TreeElement* el)
{
	if (root == NULL || el == NULL)
	{
		return;
	}
	else if (root->left == el)
	{
		root->left = NULL;
	}
	else if (root->right == el)
	{
		root->right = NULL;
	}
	{
		Detach(root->left, el);
		Detach(root->right, el);
	}
}

TreeElement* Find(TreeElement* el, int v)
{
	TreeElement* result = NULL;
	if (el == NULL) { result = NULL; }
	else if (el->value == v) { result = el; }
	else
	{
		result = Find(el->left, v);
		if (result == NULL) { result = Find(el->right, v); }
	}
	return result;
}
void Remove(TreeElement* el)
{
	if (el != NULL) {
		Remove(el->left);
		Remove(el->right);
		delete el;
	};
}
int main() {
	setlocale(LC_ALL, "Russian");
	sps* first = NULL;
	sps* second = NULL;
	TreeElement* root = NULL;
	int a, b ;
	cout << "Количество элементов в дереве:  ";
	cin >> b;
	cout << "Элементы дерева:  ";
	for (int i = 0; i < b; i++) {
		cin >> a;
		Input(root, a);
	}
	Output(root);
	cout << endl;
	spos(first, root, second);
	Out(first);
	int z;
	cout << "Введите поддерево, которое хотите удалить:  ";
	cin >> z;
	TreeElement* e = Find(root, z);
	Detach(root, e);
	Remove(e);
	Output(root);
	cout << endl;
	TreeElement* e1 = Find(root, z);
	Detach(root, e1);
	Remove(e1);
	Output(root);
	cout << endl;
	system("pause");
}
