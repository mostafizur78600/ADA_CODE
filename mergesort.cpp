#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;
#define size 10

void merge(int A[], int p, int q, int r)
{
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1 + 1], R[n2 + 1];
  for (int i = 0; i <= n1; i++)
  {
    L[i] = A[p + i - 1];
  }
  for (int j = 0; j <= n2; j++)
  {
    R[j] = A[q + j];
  }
  L[n1 + 1] = __INT_MAX__;
  R[n2 + 1] = __INT_MAX__;
  int i = 1;
  int j = 1;
  for (int k = p; k <= r; k++)
  {
    if (L[i] <= R[j])
    {
      A[k] = L[i];
      i = i + 1;
    }
    else
    {
      A[k] = R[j];
      j = j + 1;
    }
  }
}
void mergesort(int A[], int p, int r)
{
  if (p < r)
  {
    int q = floor((p + r) / 2);
    mergesort(A, p, q);
    mergesort(A, q + 1, r);
    merge(A, p, q, r);
  }
}
int main()
{
  int i, arr[size];

  cout << "\n Unsorted list is as follows\n";
  for (i = 0; i < size; i++) // For loop to generate random numbers
  {
    arr[i] = rand() % 100;
    cout << arr[i] << " ";
  }
  high_resolution_clock::time_point start = high_resolution_clock::now();
  mergesort(arr, 0, size);
  // quicksort(arr,0,size-1);
  high_resolution_clock::time_point stop = high_resolution_clock::now();
  duration<double> time_taken = duration_cast<duration<double>>(stop - start);
  cout << "\n Sorted list is as follows\n";
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl
       << "The time taken is: " << time_taken.count() << " Seconds" << endl;
  cout << endl;
}