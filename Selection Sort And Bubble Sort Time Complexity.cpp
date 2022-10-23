#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void bubbleSort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void selectionSort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {

            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

void generateRandomInt(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000;
    }
}

int main()
{
    srand(time(0));
    int n = 100000;
    int *arr = new int[n];
    generateRandomInt(arr, n);

auto start1 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    selectionSort(arr, n);

    auto end1 = chrono::high_resolution_clock::now();
    double time_taken1 =chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
        time_taken1 *= 1e-9;
cout << "Time taken for Selection Sort :" << fixed << time_taken1 << "sec" << setprecision(9) << endl;

auto start2 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);

    bubbleSort(arr, n);

    auto end2 = chrono::high_resolution_clock::now();
    double time_taken2 =chrono::duration_cast<chrono::nanoseconds>(end2 - start2).count();
        time_taken2 *= 1e-9;
cout << "Time taken for Bubble Sort :" << fixed << time_taken2 << "sec" << setprecision(9) << endl;
}
