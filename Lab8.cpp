#include <iostream>
#include <iomanip>
#include <stack>
#include <string>
#include <list>

using namespace std;
int inf = 9999;

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
int graph_matrix[6][6] =
{
    0,10,5,inf,inf,inf,
    inf,0,inf,inf,2,5,
    inf,4,0,5,8,inf,
    inf,inf,inf,0,5,inf,
    inf,inf,inf,inf,0,inf,
    inf,inf,inf,inf,5,0
};

public:

void Deykstra(char c)
{
    int matrix[6][6], path[6], last[6];
    int visited[6], min = 0, current = 0,  a = 0, start = rid(c);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++) 
        {
            if (graph_matrix[i][j] == 0) matrix[i][j] = inf;
            else matrix[i][j] = graph_matrix[i][j]; 
        }
    }
    for (int i = 0; i < 6; i++) {
        path[i] = matrix[start][i];
        last[i] = start;
        visited[i] = 0;
    }
    visited[start] = 1;
    path[start] = 0;
    int k = 1;
    while (k < 5) 
    {
        min = inf;
        for (int i = 0; i < 6; i++)
            if (path[i] < min && !visited[i]) {
                min = path[i];
                current = i;
            }
        visited[current] = 1;
        for (int i = 0; i < 6; i++)
            if (!visited[i])
                if (min + matrix[current][i] < path[i]) 
                {
                    path[i] = min + matrix[current][i];
                    last[i] = current;
                }
        k++;
    }
    for (int i = 0; i < 6; i++)
    {
        list<int> tops;
        string res;
        if (i != start)
        {
            cout << "Вiдстань до вершини " << pick(i + 1) << " : ";
            if (path[i] == inf) cout << "Шляху немає " << endl;
            else
            {
                cout << path[i] << endl;
                cout << "Шлях: ";
                tops.push_front(i);
                a = i;
                do {
                    a = last[a];
                    if (a != start) tops.push_front(a);
                    else res += pick(a + 1);
                } while (a != start);
                for (auto iter : tops)
                {
                    res += " -> ";
                    res += pick(iter + 1);
                }
                cout << res << endl;
            }
        }
    }
    cout << endl;
}


void FloydWarshall() 
{
    int res[6][6];

    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            res[i][j] = graph_matrix[i][j];

    for (int a = 0; a < 6; a++) 
        for (int i = 0; i < 6; i++) 
            for (int j = 0; j < 6; j++) 
                if (res[i][a] + res[a][j] < res[i][j])
                    res[i][j] = res[i][a] + res[a][j];
    for (int i = 0; i < 6; i++) 
    {
        for (int j = 0; j < 6; j++) {
            if (res[i][j] == inf)
                cout << fixed << setw(4) << "inf";
            else
                cout << fixed << setw(4) << res[i][j];
        }
        cout << endl;
    }
}   

};


int main()
{
    setlocale(LC_ALL, "Rus");
    Graph graph;
    cout << "Алгоритм Дейкстри" << endl;
    graph.Deykstra('a');
    cout << "==============================" << endl << endl;
    cout << "Алгоритм Флойда-Уоршола" << endl;
    graph.FloydWarshall();
    system("pause");
    return 0;
}