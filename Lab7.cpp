#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <conio.h>

using namespace std;

char pick(int a)
{
		return 'a' + a - 1;
}

int rid(char c)
{
	return c - 'a';
}

class Graph
{
private:
	const int neor_mat_ints[6][8] = {
		1,1,1,0,0,0,0,0,
		1,0,0,1,1,0,0,0,
		0,0,0,1,0,1,0,0,
		0,1,0,0,0,0,1,0,
		0,0,1,0,1,0,0,1,
		0,0,0,0,0,1,1,0
	};

	const int or_mat_ints[6][12] = {
		-1,-1,-1,1,0,1,0,0,0,0,0,0,
		0,0,0,-1,-1,0,0,0,0,0,0,0,
		1,0,0,0,1,-1,-1,-1,0,0,0,0,
		0,0,0,0,0,0,1,0,-1,1,0,0,
		0,1,0,0,0,0,0,1,1,-1,-1,1,
		0,0,1,0,0,0,0,0,0,0,1,-1
	};

	const int neor_mat_sum[6][6] = {
		0,1,0,1,1,0,
		1,0,1,0,1,0,
		0,1,0,0,0,1,
		1,0,0,0,0,1,
		1,1,0,0,1,0,
		0,0,1,1,0,0
	};

	const int or_mat_sum[6][6] = {
		0,0,1,0,1,1,
		1,0,1,0,0,0,
		1,0,0,1,1,0,
		0,0,0,0,1,0,
		0,0,0,1,0,1,
		0,0,0,0,1,0
	};

	const char neor_spis_reb[16][2] = {
		'a','b',
		'a','d',
		'a','e',
		'b','c',
		'b','e',
		'c','f',
		'd','f',
		'e','e',
		'e','e',
		'f','d',
		'f','c',
		'e','b',
		'c','b',
		'e','a',
		'd','a',
		'b','a'
	};

	const char or_spis_reb[12][2] = {
		'a','c',
		'a','e',
		'a','f',
		'b','a',
		'b','c',
		'c','a',
		'c','d',
		'c','e',
		'd','e',
		'e','d',
		'e','f',
		'f','e'
	};

	const string neor_spys_sum[6]
	{
		"bde",
		"ace",
		"bf",
		"af",
		"abe",
		"cd"
	};

	const string or_spys_sum[6]
	{
		"cef",
		"ac",
		"ade",
		"e",
		"df",
		"e"
	};
public:
	void mat_int(bool isTrue)
	{
		if (isTrue)
		{
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 12; j++)
				{
					cout << or_mat_ints[i][j] << ' ';
				}
				cout << endl;
			}
		}
		else
		{
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					cout << neor_mat_ints[i][j] << ' ';
				}
				cout << endl;
			}
		}
	}

	void mat_sum(bool isTrue)
	{
		if (isTrue)
		{
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					cout << or_mat_sum[i][j] << ' ';
				}
				cout << endl;
			}
		}
		else
		{
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					cout << neor_mat_sum[i][j] << ' ';
				}
				cout << endl;
			}
		}
	}

	void spys_reb(bool isTrue)
	{
		if (isTrue)
		{
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					cout << or_spis_reb[i][j] << ' ';
				}
				cout << endl;
			}
		}
		else
		{
			for (int i = 0; i < 16; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					cout << neor_spis_reb[i][j] << ' ';
				}
				cout << endl;
			}
		}
	}

	void spys_sum(bool isTrue)
	{
		if (isTrue)
		{
			for (int i = 0; i < 6; i++)
			{				
					cout << or_spys_sum[i] << endl;
			}
		}
		else
		{
			for (int i = 0; i < 6; i++)
			{
				cout << neor_spys_sum[i] << endl;
			}
		}
	}

	void mat_sum_to_spys_reb(bool isTrue)
	{
		if (isTrue)
		{
			int k = 0;
			char res[12][2];
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
				{
					if (or_mat_sum[i][j] == 1)
					{
						res[k][0] = pick(i + 1);
						res[k][1] = pick(j + 1);
						++k;
						if (j == i)
						{
							res[k][0] = pick(i + 1);
							res[k][1] = pick(j + 1);
							++k;
						}
					}
				}
			for (int i = 0; i < 12; i++)
			{
				cout << res[i][0] << ' ' << res[i][1] << endl;
			}
		}
		else
		{
			int k = 0;
			char res[16][2];
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
				{
					if (neor_mat_sum[i][j] == 1)
					{
						res[k][0] = pick(i + 1);
						res[k][1] = pick(j + 1);
						++k;
						if (j == i)
						{
							res[k][0] = pick(i + 1);
							res[k][1] = pick(j + 1);
							++k;
						}
					}
				}
			for (int i = 0; i < 16; i++)
			{
				cout << res[i][0] << ' ' << res[i][1] << endl;
			}
		}
	}

	void mat_sum_to_spys_sum(bool isTrue)
	{
		string res[6];
		if (isTrue)
		{
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
					if (or_mat_sum[i][j] == 1)
						res[i] += pick(j + 1);
		}
		else
		{
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
					if (neor_mat_sum[i][j] == 1)
						res[i] += pick(j + 1);
		}
		for (int i = 0; i < 6; i++)
		{
			cout << res[i] << endl;
		}
	}

	void mat_sum_to_mat_ints(bool isTrue)
	{
		if (isTrue)
		{
			int res[6][12]{ 0 };
			int k = 0;
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
				{
					if (or_mat_sum[i][j] == 1)
					{
						res[i][k] = -1;
						res[j][k] = 1;
						++k;
					}
				}
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 12; j++)
				{
					cout << res[i][j] << " ";
				}
				cout << endl;
			}
		}
		else
		{
			int res[6][8]{ 0 };
			int k = 0;
			int example[6][6];
			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
					example[i][j] = neor_mat_sum[i][j];

			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 6; j++)
				{
					if (example[i][j] == 1)
					{
						res[i][k] = 1;
						res[j][k] = 1;
						example[j][i] = 0;
						++k;
					}
				}
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					cout << res[i][j] << " ";
				}
				cout << endl;
			}
		}
	}

	void mat_ints_to_spys_sum(bool isTrue)
	{
		string res[6];
		if (isTrue)
		{
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 12; j++)
				{
					if (or_mat_ints[i][j] == -1)
					{
						for (int a = 0; a < 6; a++)
							if (or_mat_ints[a][j] == 1) res[i] += pick(a + 1);
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < 6; i++)
			{
				for (int j = 0; j < 8; j++)
				{
					if (neor_mat_ints[i][j] == 1)
					{
						int k = 0;
						for (int a = 0; a < 6; a++)
							if (neor_mat_ints[a][j] == 1 && a != i)
							{
								res[i] += pick(a + 1);
								++k;
							}
						if (k == 0) res[i] += pick(i + 1);
					}
				}
			}
		}
		for (int i = 0; i < 6; i++)
		{
			cout << res[i] << endl;
		}
	}

	void mat_ints_to_mat_sum(bool isTrue)
	{
		int res[6][6]{ 0 };
		int a[2]{ 0 };
		if (isTrue)
		{
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					if (or_mat_ints[j][i] == -1) a[0] = j;
					if (or_mat_ints[j][i] == 1) a[1] = j;
				}
				res[a[0]][a[1]] = 1;
			}
		}
		else
		{
			int k = 0;
			for (int i = 0; i < 8; i++)
			{
				k = 0;
				for (int j = 0; j < 6; j++)
				{
					if (neor_mat_ints[j][i] == 1)
					{
						a[k] = j;
						++k;
					}
				}
				if (k == 1) a[1] = a[0];
				res[a[0]][a[1]] = 1;
				res[a[1]][a[0]] = 1;
			}
		}
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}

	void mat_ints_to_spys_reb(bool isTrue)
	{
		if (isTrue)
		{
			char res[12][2];
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 6; j++)
				{
					if (or_mat_ints[j][i] == -1) res[i][0] = pick(j + 1);
					if (or_mat_ints[j][i] == 1) res[i][1] = pick(j + 1);
				}
			}
			for (int i = 0; i < 12; i++)
			{
				cout << res[i][0] << ' ' << res[i][1] << endl;
			}
		}
		else
		{
			char res[16][2];
			int k = 0, l = 0;
			int a[2]{ 0 };
			for (int i = 0; i < 8; i++)
			{
				k = 0;
				for (int j = 0; j < 6; j++)
				{
					if (neor_mat_ints[j][i] == 1)
					{
						a[k] = j;
						++k;
					}
				}
				if (k == 1) a[1] = a[0];
				res[l][0] = pick(a[0] + 1);
				res[l][1] = pick(a[1] + 1);
				++l;
				res[l][1] = pick(a[0] + 1);
				res[l][0] = pick(a[1] + 1);
				++l;
			}
			for (int i = 0; i < 16; i++)
			{
				cout << res[i][0] << ' ' << res[i][1] << endl;
			}
		}
	}	

	void DFS(bool isTrue, char start)
	{
		stack<int> visited;
		int tops[6];
		for (int i = 0; i < 6; i++) tops[i] = 0;
		visited.push(rid(start));
		while (!visited.empty())
		{
			int last = visited.top();
			visited.pop();
			if (tops[last] == -1) continue;
			tops[last] = -1;
			for (int j = 5; j >= 0; j--)
			{
				if (isTrue)
				{
					if (or_mat_sum[last][j] == 1 && tops[j] != -1)
					{
						visited.push(j);
						tops[j] = 1;
					}
				}
				else
				{
					if (neor_mat_sum[last][j] == 1 && tops[j] != -1)
					{
						visited.push(j);
						tops[j] = 1;
					}
				}
			}
			cout << pick(last + 1) << ' ';
		}
		cout << endl;
	}

	void BFS(bool isTrue, char start)
	{
		queue<int> last;
		int tops[6];
		for (int i = 0; i < 6; i++)
			tops[i] = 0;
		last.push(rid(start));
		while (!last.empty())
		{
			int node = last.front();
			last.pop();
			tops[node] = -1;
			for (int j = 0; j < 6; j++)
			{
				if (isTrue)
				{
					if (or_mat_sum[node][j] == 1 && tops[j] == 0)
					{
						last.push(j);
						tops[j] = 1;
					}
				}
				else
				{
					if (neor_mat_sum[node][j] == 1 && tops[j] == 0)
					{
						last.push(j);
						tops[j] = 1;
					}
				}
			}
			cout << pick(node + 1) << ' ';
		}
		cout << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	bool isOr;
	Graph gr;
	char c,s;
	do {
		system("cls");
		cout << "Граф орiєнтований?\n1.Так\n2.Нi" << endl;
		do
		{
			c = _getch();
		} while (c < '1' || c>'2');
		isOr = (c == '1' ? true : false);
		system("cls");
		cout << "Виберiть дiю?\n1.Вивiд графа\n2.Матриця сумiжностi->Матриця iнцидентностi" << endl;
		cout << "3.Матриця iнцидентностi->Список ребер\n4.Матриця сумiжностi->Список сумiжностi" << endl;
		cout << "5.Матриця iнцидентностi->Матриця сумiжностi\n6.Матриця сумiжностi->Список ребер" << endl;
		cout << "7.Матриця iнцидентностi->Список сумiжностi\n8.DFS\n9.BFS" << endl;
		do
		{
			s = _getch();
		} while (s < '1' || s >'9');
		system("cls");
		switch (s)
		{
		case '1':
		{
			gr.mat_int(isOr);
			cout << "===========================" << endl;
			gr.mat_sum(isOr);
			cout << "===========================" << endl;
			gr.spys_reb(isOr);
			cout << "===========================" << endl;
			gr.spys_sum(isOr);
			break;
		}
		case '2':
			gr.mat_sum_to_mat_ints(isOr);
			break;
		case '3':
			gr.mat_ints_to_spys_reb(isOr);
			break;
		case '4':
			gr.mat_sum_to_spys_sum(isOr);
			break;
		case '5':
			gr.mat_ints_to_mat_sum(isOr);
			break;
		case '6':
			gr.mat_sum_to_spys_reb(isOr);
			break;
		case '7':
			gr.mat_ints_to_spys_sum(isOr);
			break;
		case '8':
		{
			cout << "Введiть вершину" << endl;
			char sym;
			cin >> c;
			gr.DFS(isOr, c);
			break;
		}
		case '9':
		{
			cout << "Введiть вершину" << endl;
			char sym;
			cin >> c;
			gr.BFS(isOr, c);
			break;
		}
		}
	} while (_getch() != 27);
	system("pause");
}