// Варіант 25(Рекурсивний спосіб)
#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

void InitArray(int a[], const int size, int i)
{
    if (i < size)
    {
        a[i] = -40 + rand() % 61;
        InitArray(a, size, i + 1);
        return;
    }
}


void PrintArray(int a[], const int size, int i) {
    if (i < size)
    {
        if (i == 0)
            cout << "{";
        cout << a[i];
        if (i != size - 1)
            cout << ", ";
        else cout << "}" << endl;
        PrintArray(a, size, i + 1);
        return;
    }
}

int SumArray(int a[], const int size, int i)
{
    if (i < size) {
        if (a[i] < 0 || i % 2 == 0)
            return a[i] + SumArray(a, size, i + 1);
        else
            return SumArray(a, size, i + 1);
    }
    else return 0;
}


int CountElementArray(int a[], const int size, int i)
{
    if (i < size)
    {
        if (a[i] < 0 || i % 2 == 0)
            return 1 + CountElementArray(a, size, i + 1);
        else
            return CountElementArray(a, size, i + 1);
    }
    else return 0;
}


void ReplaceElementArray(int a[], const int size, int i)
{
    if (i < size)
    {
        if (a[i] < 0 || i % 2 == 0)
            a[i] = 0;
        ReplaceElementArray(a, size, i + 1);
        return;
    }
}

int main()
{
    srand(time(0));
    const int size = 26;
    int a[size];

    InitArray(a, size, 0);
    PrintArray(a, size, 0);
    cout << "Array sum by condition = " << SumArray(a, size, 0) << endl;
    cout << "Count element by condition = " << CountElementArray(a, size, 0) << endl;
    ReplaceElementArray(a, size, 0);
    PrintArray(a, size, 0);

    return 0;
}
