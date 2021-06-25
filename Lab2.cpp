#include <iostream>
#include <ctime>

using namespace std;

void choicesSort(int* arr, int length_array);
void insertSort(int* arr, int length_array);
void boobbleSort(int* arr, int length_array);
//void shakerSort(int* arr, int length_array);

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int* arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 580 + 1;
        cout << arr[i] << " ";
    }
    cout << endl;

    //choicesSort(arr, 10);
    //insertSort(arr, 10);
    boobbleSort(arr, 28);
    //shakerSort(arr, 10);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

    delete[] arr;
    system("pause");
}

void choicesSort(int* arr, int length_array){
    for (int a = 0; a < length_array-1; a++)
    {
        int t = 0; 
        int min = arr[a];
        int num = a;
        for (int b = a + 1; b < length_array; b++)
        {
            if (arr[b]<min)
            {
                num = b;
                min = arr[b];
                t = 1;
            }
        }
        if (t == 1)
        {
            arr[num] = arr[a];
            arr[a] = min;
        }
    }
}

void insertSort(int* arr, int length_array)
{
    int t,j;
    t = 0;
    if (arr[0] > arr[1])
    {
        t=arr[0];
        arr[0] = arr[1];
        arr[1] = t;

    }
   cout << arr[0] << arr[1] << endl;
    for (int i = 2; i < length_array; i++)
    {
        t = arr[i];
        j = i - 1;
        while (t < arr[j] && j>-1)
        {
            arr[j + 1] = arr[j];
            --j;
            arr[j+1] = t;
        }
    }
}

void boobbleSort(int* arr, int length_array)
{
    int t;
    for (int a = 0; a < length_array - 1; a++)
    {
        for (int b = a + 1; b < length_array; b++)
        {
            if (arr[a] > arr[b])
            {
                t = arr[a];
                arr[a] = arr[b];
                arr[b] = t;
            }
        }
    }
}

/*void shakerSort(int* arr, int length_array) {
    long j, k = length_array - 1;
    long lb = 1, ub = length_array - 1;
    int x;
    do
    {
        for (j = ub; j > 0; j--) { 
            {
                if (arr[j - 1] > arr[j]) {
                    x = arr[j - 1]; 
                    arr[j - 1] = arr[j];
                    arr[j] = x;
                    k = j;
                }
            }
            lb = k + 1;
            for (j = 1; j <= ub; j++) { 
                if (arr[j - 1] > arr[j]) {
                    x = arr[j - 1];
                    arr[j - 1] = arr[j];
                    arr[j] = x;
                    k = j;
                }
            }
            }
            ub = k - 1;
        } while (lb < ub);
    }
 */