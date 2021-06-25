#include <iostream>
#include <list>
#include <fstream>
#include <string>
#include <conio.h>

using namespace std;

struct tovar
{
    string name;
    int amount;
    double buy;
    double sell;
};

void addrecord(list <tovar>* tov_list);
void printlist(list <tovar> tov_list);
void deleterecord(list <tovar>* tov_list);
void list_to_file(list <tovar> tov_list);
void list_from_file(list <tovar>* tov_list);
void findInList(list <tovar> tov_list);
bool sortByAmount(tovar& a, tovar& b);
void indiv(list <tovar> tov_list);

int main()
{
    
    list <tovar> tov_list;
    char choose;
    string name;
    tovar inlist;
    setlocale(LC_ALL, "Rus");
    do {
        system("cls");
        cout << "Що ви хочете зробити?\n1.Додати запис\n2.Видалити запис\n3.Вивести список на екран\n4.Записати список у файл\n5.Зчитати список з файлу\n6.Знайти по елементу\n7.Вiдсортувати за кiлькiстю\n8.Iндивiдуальне завдання" << endl;
        do {
            choose = _getch();
        } while (choose < '1' || choose>'8');
        cout << choose << endl;
        switch (choose)
        {
        case '1':   
            system("cls");
            addrecord(&tov_list);
            break;
        case '2':
            system("cls");
            deleterecord(&tov_list);
            break;
        case '3':
            system("cls");
            printlist(tov_list);            
            break;
        case '4':
            system("cls");
            list_to_file(tov_list);
            break;
        case '5':
            system("cls");
            list_from_file(&tov_list);
            break;
        case '6':
            system("cls");
            findInList(tov_list);
            break;
        case '7':
            system("cls");
            tov_list.sort(sortByAmount);
            cout << "Сортування виконано!\nНатиснiть ESC для виходу або будь-яку кнопку, щоб продовжити" << endl;
            break;
        case '8':
            system("cls");
            tov_list.sort(sortByAmount);
            indiv(tov_list);
            break;
        }
    } while (_getch()!=27);
    system("pause");
    return 0;
}


void addrecord(list <tovar>* tov_list)
{
    int a;
    char symbol;
    cout << "Куди додати запис?\n1.Кiнець\n2.Початок\n3.Середина" << endl;
    do {
        symbol = _getch();
    } while (symbol < '1' || symbol>'3');
    system("cls");
    string name;
    tovar inlist;
    cout << "Введiть назву" << endl;
    getline(cin, inlist.name);
    cout << "Введiть кiлькiсть" << endl;
    cin >> inlist.amount;
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Введiть цiну закупки" << endl;
    cin >> inlist.buy;
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Введiть цiну продажу" << endl;
    cin >> inlist.sell;
    cin.clear();
    cin.ignore(10000, '\n');
    switch (symbol)
    {
    case '1':
        (*tov_list).push_back(inlist);
        break;
    case '2':
        (*tov_list).push_front(inlist);
        break;
    case '3':
        cout << "Введiть номер, яким треба вставити запис" << endl;
        cin >> a;
        cin.clear();
        cin.ignore(10000, '\n');
        auto iter = (*tov_list).begin();
        for (int i = 0; i < a - 1; ++i) iter++;
        (*tov_list).insert(iter, inlist);
        break;
    }        
    cout << "Натиснiть ESC для виходу або будь-яку кнопку, щоб продовжити" << endl;
}

void printlist(list <tovar> tov_list)
{
    char symbol;
    cout << "Виводити в звичайному чи зворотньому порядку?\n1.Звичайний\n2.Зворотнiй" << endl;
    do {
        symbol = _getch();
    } while (symbol < '1' || symbol>'2');
    system("cls");
    if (tov_list.empty()) cout << "Список пустий" << endl;
    else {
        if (symbol=='1') for (auto iter : tov_list)
        {
            cout << iter.name << "\t" << iter.amount << "\t" << iter.buy << "\t" << iter.sell << "\t" << endl;
        }
        else {
            tov_list.reverse();
            for (auto iter : tov_list)
            {
                cout << iter.name << "\t" << iter.amount << "\t" << iter.buy << "\t" << iter.sell << "\t" << endl;
            }
            tov_list.reverse();
        }
    }
    cout << "Натиснiть ESC для виходу або будь-яку кнопку, щоб продовжити" << endl;
}

void deleterecord(list <tovar>* tov_list)
{
    int a=0;
    int k;
    string name;
        cout << "Введiть назву" << endl;
        getline(cin, name);
        cin.clear();
        auto itery = tov_list->begin();
        for (auto iter : *tov_list)
        {
            if (iter.name == name)
            {
                k = a;
            }
            a++;
        }   
        for (int i = 0; i < k; i++)
        {
            itery++;
        }
        tov_list->erase(itery);
    cout << "Натиснiть ESC для виходу або будь-яку кнопку, щоб продовжити" << endl;
}

void list_to_file(list <tovar> tov_list)
{
    string path = "Lab4file.txt";
    ofstream fout;
    fout.open(path);
    for (auto iter : tov_list)
    {
        fout << iter.name << "\t" << iter.amount << "\t" << iter.buy << "\t" << iter.sell << "\t" << endl;
    }
    fout.close();
    cout << "Запис виконано!" << endl;
    cout << "Натиснiть ESC для виходу або будь-яку кнопку, щоб продовжити" << endl;
}

void list_from_file(list <tovar>* tov_list)
{
    string path = "Lab4file.txt";
    ifstream fin;
    fin.open(path);   
    (*tov_list).clear();
    int ant=0;  
    tovar inlist;
    while (fin >> inlist.name >> inlist.amount >> inlist.buy >> inlist.sell)
    {      
        (*tov_list).push_back(inlist);      
    }    
    fin.close();
    cout << "Список зчитано!" << endl;
    cout << "Натиснiть ESC для виходу або будь-яку кнопку, щоб продовжити" << endl;
}

void findInList(list <tovar> tov_list)
{
    char choose;
    cout << "Що ви хочете знайти?\n1.Назву\n2.Кiлькiсть\n3.Цiну закупки\n4.Цiну продажу" << endl;
    do {
        choose = _getch();
    } while (choose < '1' || choose>'4');
    tovar inlist;
    string name;
    int amount;
    double buy, sell;
    int k = 0;        
    switch (choose)
    {
    case '1':
        cout << "Введiть назву" << endl;
        getline(cin, name);

        for (auto iter : tov_list)
        {
            if (iter.name == name)
            {
                cout << iter.name << "\t" << iter.amount << "\t" << iter.buy << "\t" << iter.sell << "\t" << endl;
                ++k;
            }
        }
        break;
    case '2':
        cout << "Введiть кiлькiсть" << endl;
        cin >> amount;
        cin.clear();
        cin.ignore(10000, '\n');
        for (auto iter : tov_list)
        {
            if (iter.amount == amount)
            {
                cout << iter.name << "\t" << iter.amount << "\t" << iter.buy << "\t" << iter.sell << "\t" << endl;
                ++k;
            }
        }
        break;
    case '3':
        cout << "Цiна закупки" << endl;
        cin >> buy;
        cin.clear();
        cin.ignore(10000, '\n');
        for (auto iter : tov_list)
        {
            if (iter.buy == buy)
            {
                cout << iter.name << "\t" << iter.amount << "\t" << iter.buy << "\t" << iter.sell << "\t" << endl;
                ++k;
            }
        }
        break;
    case '4':
        cout << "Цiна продажу" << endl;
        cin >> sell;
        cin.clear();
        cin.ignore(10000, '\n');
        for (auto iter : tov_list)
        {
            if (iter.sell == sell)
            {
                cout << iter.name << "\t" << iter.amount << "\t" << iter.buy << "\t" << iter.sell << "\t" << endl;
                ++k;
            }
        }
        break;
    }    
    cout << "Натиснiть ESC для виходу або будь-яку кнопку, щоб продовжити" << endl;
}

bool sortByAmount(tovar& a, tovar& b) 
{
    return a.amount < b.amount;
}

void indiv(list <tovar> tov_list)
{
    string name;
    cout << "Введiть назву" << endl;
    getline(cin, name);
    for (auto iter : tov_list)
    {
        if (iter.name == name)
        {
            cout << (iter.sell-iter.buy) * (iter.amount) << endl;
        }
    }
}
