#include <bits/stdc++.h>
using namespace std;

// Deterministic variant
int partition(vector<int> &arr, int start, int end)
{
    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

// Randomized variant
int getRandomPivot(int start, int end)
{
    // Generate a random index between start and end
    return start + rand() % (end - start + 1);
}

int randomizedPartition(vector<int> &arr, int start, int end)
{
    int pivotIndex = getRandomPivot(start, end);
    swap(arr[pivotIndex], arr[start]);

    int pivot = arr[start];
    int i = start + 1;

    for (int j = start + 1; j <= end; j++)
    {
        if (arr[j] <= pivot)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[start], arr[i - 1]);
    return i - 1;
}

void quickSort(vector<int> &arr, int start, int end, bool randomized)
{
    if (start >= end)
        return;

    int p;
    if (randomized)
    {
        p = randomizedPartition(arr, start, end);
    }
    else
    {
        p = partition(arr, start, end);
    }

    quickSort(arr, start, p - 1, randomized);
    quickSort(arr, p + 1, end, randomized);
}

int main()
{
    srand(time(0)); // Seed for random number generation

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Deterministic quicksort
    quickSort(arr, 0, n - 1, false);
    cout << "Deterministic Quicksort: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Reset array for randomized quicksort
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Randomized quicksort
    quickSort(arr, 0, n - 1, true);
    cout << "Randomized Quicksort: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}