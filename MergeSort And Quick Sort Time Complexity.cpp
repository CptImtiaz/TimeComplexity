#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

void merge1(int *arr, int left, int mid, int right) {

  int n1 = mid - left + 1;
  int n2 = right - mid;

  int leftArr[n1], rightArr[n2];

  for (int i = 0; i < n1; i++)
    leftArr[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
    rightArr[j] = arr[mid + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = left;

  while (i < n1 && j < n2) {
    if (leftArr[i] < rightArr[j]) {
      arr[k] = leftArr[i];
      i++;
      k++;
    } else {
      arr[k] = rightArr[j];
      j++;
      k++;
    }

  }

  while (i <= n1-1) {
    arr[k] = leftArr[i];
    i++;
    k++;
  }

  while (j <= n2-1) {
    arr[k] = rightArr[j];
    j++;
    k++;
  }

}

void mergeSort(int *arr, int left, int right) {
  if (left < right) {
    int mid =  (right + left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge1(arr, left, mid, right);
  }
}
void GenerateRandomNumber(int *arr, int n)
{
   for(int i=0;i<n;i++)
    {
        arr[i]=rand() % 1000;
    }
}

int main()
{
    srand(time(0));
    int n = 900000000;
    int *arr = new int[n];
    GenerateRandomNumber(arr,n);
    auto start1 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    mergeSort(arr,arr[0],arr[n-1]);
    auto end1 = chrono::high_resolution_clock::now();
    double time_taken1 =chrono::duration_cast<chrono::nanoseconds>(end1 - start1).count();
    time_taken1 *= 1e-6;
    cout << "Time taken for Selection Sort :" << fixed << time_taken1 << " ms" << setprecision(9) << endl;


    return 0;
}
