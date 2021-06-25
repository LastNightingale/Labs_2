#include <iostream>
#include <forward_list>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>
double M_PI = 3.14159265358979323846;

using namespace std;
int enter();

double fx(double x)
{
    return cos(fabs(x));
}

int main()
{
    int k=0;
    setlocale(LC_ALL, "rus");
    forward_list<double> listx;
    forward_list<double> listy;
    forward_list<double>::iterator itx = listx.before_begin();
    forward_list<double>::iterator ity = listy.before_begin();
    string path = "Lab3file.txt";
    ofstream fout;
    fout.open(path);
    for (int i = 0; i < 11; i++) //запись в файл точек
    {
        fout << fixed << setprecision(6) << M_PI * (i) / 40 << "\t";
        fout << fixed << setprecision(6) << fx(M_PI * (i) / 40) << endl;
    }
    fout.close();
    ifstream fin;
    fin.open(path);
    double x, y;
    for (int i = 0; i < 11; i++) //считка из файла в список
    {
        fin >> x >> y;
        listx.insert_after(itx, x);
        listy.insert_after(ity, y);
        itx++;
        ity++;
    }
   fin.close();
   itx = listx.begin();
   ity = listy.begin();
   cout << setw(5) << 'X' << "\t" << setw(13) << 'Y' << endl;
    while (ity != listy.end()) //вывод на экран
    {
        cout << fixed << setprecision(6) << *itx++<< "\t";
        cout << fixed << setprecision(6) << *ity++ << endl;
    }
    itx = listx.begin();
    ity = listy.begin();
    for (int j = 0; j < 10; j++) //добавление элементов в список
    {
            itx=listx.emplace_after(itx, (M_PI * (j) / 40)+ M_PI/80);
            ity=listy.emplace_after(ity, fx((M_PI * (j) / 40) + M_PI / 80));            
            itx++;            
            ity++;
    }
    itx = listx.begin();
    ity = listy.begin();
    cout << setw(5) << 'X' << "\t" << setw(13) << 'Y' << endl;
    while (ity != listy.end())//вывод нового списка
    {
        cout << fixed << setprecision(6) << *itx++ << "\t";
        cout << fixed << setprecision(6) << *ity++ << endl;
    }
  
    int a,b;
    do {
        cout << "З якого елемента почати видалення?" << endl;
        a = enter();
        if (a < 1 || a>21) cout << "Тiльки вiд 1 до 21" << endl;
    } while (a < 1 || a>21);
    /*cout << "Яким елементом закiнчити видалення?" << endl;
    do
    {
        b = enter();
        if (b < 2 || b>20) cout << "Тiльки вiд 2 до 21, число має бути бiльше ніж a" << endl;
    }
    while (b <= a|| a < 2 || a>21);*/

    auto iter1 = listx.before_begin();//очистка х
    auto iter2 = listx.before_begin();
    auto iter11 = listy.before_begin();//очистка у
    auto iter22 = listy.before_begin();    
    for (int i = 0; i < a-1; i++) iter1++;
    for (int i = 0; i < a - 1; i++) iter11++;
    if (a < 17)
    {
        for (int i = 0; i < a+5; i++) iter2++;
        for (int i = 0; i < a+5; i++) iter22++;
    }
    else
    {
        iter2 = listx.end();
        iter22 = listy.end();
    }
    
    listx.erase_after(iter1, iter2); 
    listy.erase_after(iter11, iter22);
    
    itx = listx.begin();//вывод третьего списка
    ity = listy.begin();
    cout << setw(5) << 'X' << "\t" << setw(13) << 'Y' << endl;
    while (ity != listy.end())
    {
        cout << fixed << setprecision(6) << *itx++ << "\t";
        cout << fixed << setprecision(6) << *ity++ << endl;
    }
    system("pause");
}
int enter()
{
    int a;
    do {
        cin >> a;
        if (cin.fail() || a <= 0 || a > 100)
        {
            //cout << a <<endl;
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