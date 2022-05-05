#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    int j;

    if (low < high)
    {
        j = partition(arr, low, high);
        quickSort(arr, low, j);
        quickSort(arr, j + 1, high);
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, 32767};
    int n = sizeof(A)/sizeof(A[0]);
    quickSort(A, 0, n-1);
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    return 0;
}