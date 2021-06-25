#include <iostream>
#include <string>

using namespace std;

class Data
{
public:
	int number;
	char surname[30];
	int age;
	int experience;
	int salary;
	void Print()
	{
		cout << this->number << " " << this->surname << " " << this->age << " "	<< this->experience << " " << this->salary << " " << endl;
	}
};

class Node
{
public:
	Data data;
	Node* left;
	Node* right;
	Node(Data data)
	{
		this->data = data;
		left = nullptr;
		right = nullptr;
	}
};

class Tree
{
private:	
	int count;
	Node* root;
	int sum;
public:
	Tree()
	{
		count = 0;
		root = nullptr;
		sum = 0;
	}	
	~Tree()
	{
		Clear();
	}
	Node* GetRoot()
	{
		return root;
	}
	void AddNodeSurname(Data data, Node *leaf)
	{		
			if (strcmp(data.surname, leaf->data.surname)>0)
			{
				if (leaf->right != NULL) AddNodeSurname(data, leaf->right);
				else
				{
					leaf->right = new Node(data);
					++count;
				}
			}
			else
			{
				if (leaf->left != NULL) AddNodeSurname(data, leaf->left);
				else
				{
					leaf->left = new Node(data);
					++count;
				}
			}

	}

	void AddNodeNumber(Data data, Node* leaf)
	{
		if (data.number > leaf->data.number)
		{
			if (leaf->right != NULL) AddNodeNumber(data, leaf->right);
			else
			{
				leaf->right = new Node(data);
				++count;
			}
		}
		else
		{
			if (leaf->left != NULL) AddNodeNumber(data, leaf->left);
			else
			{
				leaf->left = new Node(data);
				++count;
			}
		}

	}

	void AddNodeSur(Data data)
	{
		if (root == NULL)
		{
			root = new Node(data);
			++count;
		}
		else AddNodeSurname(data, root);
	}

	void AddNodeNum(Data data)
	{
		if (root == NULL)
		{
			root = new Node(data);
			++count;
		}
		else AddNodeNumber(data, root);
	}

	void Show(Node* leaf)
	{
		if (!count) cout << "Дерево пусте" << endl;
		else
		{
			cout << "Елемент:";
			leaf->data.Print();
			if (leaf->left != NULL)
			{
				cout << "Лiвий елемент:";
				leaf->left->data.Print();
			}
			if (leaf->right!= NULL)
			{
				cout << "Правий елемент:";
				leaf->right->data.Print();
			}
			cout << endl;
			if (leaf->left != NULL) Show(leaf->left);
			if (leaf->right != NULL) Show(leaf->right);
		}
	}	

	void Print()
	{
		Show(root);
	}

	void ClearTree(Node* leaf)
	{
		if (leaf != NULL)
		{
			if (leaf->left != NULL) ClearTree(leaf->left);
			if (leaf->right != NULL) ClearTree(leaf->right);
			delete leaf;
			--count;
		}
	}

	void Clear()
	{
		if(count) ClearTree(root);
	}

	void Counted()
	{
		if (!count) cout<< 0;
		else
		{
			cout << ToCount(root)/count<< endl;
		}
		
	}

	int ToCount(Node* leaf)
	{
		sum += leaf->data.salary;
		if (leaf->left != NULL) ToCount(leaf->left);
		if (leaf->right != NULL) ToCount(leaf->right);
		return sum;
	}
};
Tree tree1, tree2;
void remake(Node *leaf)
{
	if (leaf == NULL) return;
	tree2.AddNodeNum(leaf->data);
	remake(leaf->left);
	remake(leaf->right);
}


int main()
{
	Data value;
	setlocale(LC_ALL, "Rus");
	tree1.Print();
	tree1.AddNodeSur({ 12,"Kanwald",13,45,1333 });
	tree1.AddNodeSur({ 13,"Doppler",13,45,1500 });
	tree1.AddNodeSur({ 16,"Nielsen",13,45,200 });
	tree1.AddNodeSur({ 11,"Tidemann",13,45,3500 });
	tree1.Print();
	for (int i = 0; i < 2; i++)
	{
		cout << "Введiть номер" << endl;
		cin >> value.number;
		cout << "Введiть назву" << endl;
		cin >> value.surname;
		cout << "Введiть вiк" << endl;
		cin >> value.age;
		cout << "Введiть досвiд" << endl;
		cin >> value.experience;
		cout << "Введiть зарплатню" << endl;
		cin >> value.salary;
		tree1.AddNodeSur(value);
		cout << endl;
	}
	tree1.Counted();
	tree1.Print();
	cout << "==============================" << endl;
	remake(tree1.GetRoot());
	tree2.Print();
	tree1.Clear();
	tree1.Print();
	system("pause");
	return 0;
}