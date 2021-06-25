#include <iostream>
#include <conio.h>
#include <string>
#include <stack>

using namespace std;

class Deque {
private:

	int count;
	int* array;
public:
	Deque() {
		count = 0;
	}
	void push_back(int number) {
		if (!count) {
			array = new int;
			array[0] = number;
			count++;
		}
		else {
			int* old = array;
			array = new int[++count];
			for (int i = 0; i < count - 1; i++) {
				array[i] = old[i];
			}
			delete[] old;
			array[count - 1] = number;
		}
	}
	void pop_front() {
		if (!count) cout << "Дек пустий" << endl;
		else {
			int* old = array;
			array = new int[--count];
			for (int i = 0; i < count; i++) {
				array[i] = old[i + 1];
			}
			delete[] old;
		}
	}
	void print() {
		using namespace std;
		if (!count) cout << "Дек пустий" << endl;
		else
		{
			for (int i = 0; i < count; i++) {
				cout << array[i] << " ";
			}
			cout << endl;
		}
	}
	void push_front(int number)
	{
		if (!count) {
			array = new int;
			array[0] = number;
			count++;
		}
		else {
			int* old = array;
			array = new int[++count];
			array[0] = number;
			for (int i = 0; i < count - 1; i++) {
				array[i + 1] = old[i];
			}
			delete[] old;
		}
	}
	void pop_back() {
		if (!count) cout << "Дек пустий" << endl;
		else {
			int* old = array;
			array = new int[--count];
			for (int i = 0; i < count; i++) {
				array[i] = old[i];
			}
			delete[] old;
		}
	}
};


int enter()
{
	int a;
	do {
		cin >> a;
		if (cin.fail() || a <= 0 || a > 100)
		{
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "You entered wrong data, please try again" << endl;
			continue;
		}
		char c[255];
		fgets(c, 255, stdin);
		if (strlen(c) > 1) {
			cout << "You entered wrong data, please try again" << endl;
			continue;
		}
		return a;
	} while (true);
}

Deque dq;


void palindrome() {
	string str;
	cout << "Введiть рядок:" << endl;
	getline(cin, str);
	stack<char> stack1, stack2;
	for (char c : str) stack1.push(c);
	int size = stack1.size();

	for (int i = 0; i < size / 2; i++) {
		stack2.push(stack1.top());
		stack1.pop();
	}

	if (size % 2 != 0) stack1.pop();

	if (stack1 == stack2) cout << "Рядок є палiндромом" << endl;
	else cout << "Рядок не є палiндромом" << endl;
}

int prior(char op) {
	if (op == '*' || op == '/')
		return 1;
	else if (op == '+' || op == '-')
		return 0;
	else
		return -1;
}

bool isOp(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/') return true;
	else return false;
}

void postfix()
{
	cout << "Введiть вираз:" << endl;
	string str;
	getline(cin, str);
	stack<char> st;
	string res;
	for (char c : str) {
		if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) res += c;
		else if (c == ')') {
			while (!st.empty() && st.top() != '(') {
				res += st.top();
				st.pop();
			}
			if (!st.empty()) st.pop();
		}
		else if (c == '(') st.push('(');
		else if (isOp(c)) {
			while (!st.empty() && isOp(st.top()) && prior(st.top()) >= prior(c)) {
				res += st.top();
				st.pop();
			}
			st.push(c);
		}
	}

	while (!st.empty()) {
		res += st.top();
		st.pop();
	}
	cout << res << endl;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	char c, sym, s;
	int a;
	do {
		system("cls");
		cout << "Виберть що ви хочете зробити\n1.Додати елемент\n2.Видалити елемент\n3.Побачити дек\n4.Визначити палiндром\n5.Постфiкс" << endl;
		do {
			c = _getch();
		} while (c < '1' || c > '5');
		system("cls");
		switch (c)
		{
		case '1':
		{
			cout << "Виберiть куди додати елемент\n1.Початок\n2.Кiнець" << endl;
			do {
				sym = _getch();
			} while (sym < '1' || sym>'2');
			cout << "Введiть число" << endl;
			a = enter();
			if (sym == '1') dq.push_front(a);
			else dq.push_back(a);
		}
		break;
		case '2':
		{
			cout << "Виберть звiдки видалити елемент\n1.Початок\n2.Кiнець" << endl;
			do {
				s = _getch();
			} while (s < '1' || s >'2');
			if (s == '1') dq.pop_front();
			else dq.pop_back();
		}
		break;
		case '3':
			dq.print();
			break;
		case '4':
			palindrome();
			break;
		case '5':
			postfix();
			break;
		}
		cout << "Натиснiть щось щоб продовжити або ESC для виходу" << endl;
	} while (_getch() != 27);
	return 0;
	system("pause");
}




