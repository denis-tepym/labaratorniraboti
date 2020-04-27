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
