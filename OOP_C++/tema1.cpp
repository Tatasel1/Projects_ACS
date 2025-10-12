#include <stdio.h>
#include <iostream>

using namespace std;

class Sorter
{
public:
    void sortingAlgBubble(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (arr[i] < arr[j])
                {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
    }

    void sortingAlgInsertion(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            int temp = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] < temp)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = temp;
        }
    }

    void sortingAlgSelection(int arr[], int n)
    {

        int p = 0;

        for (int i = 0; i < n; i++)
        {
            p = i;
            int maxi = arr[i];

            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] > maxi)
                {
                    maxi = arr[j];
                    p = j;
                }
            }

            int temp = arr[p];
            arr[p] = arr[i];
            arr[i] = temp;
        }
    }

    void merge(int arr[], int st, int mid, int dr)
    {
        int nr1 = mid - st + 1;
        int nr2 = dr - mid;
        int stg[nr1], drt[nr2];

        for (int i = 0; i < nr1; i++)
        {
            stg[i] = arr[st + i];
        }

        for (int j = 0; j < nr2; j++)
        {
            drt[j] = arr[mid + j + 1];
        }

        int i = 0, j = 0, k = st;

        while (i < nr1 && j < nr2)
        {
            if (stg[i] > drt[j])
            {
                arr[k] = stg[i];
                i++;
            }
            else
            {
                arr[k] = drt[j];
                j++;
            }
            k++;
        }

        while (i < nr1)
        {
            arr[k] = stg[i];
            i++;
            k++;
        }

        while (j < nr2)
        {
            arr[k] = drt[j];
            j++;
            k++;
        }
    }

    void sortingAlgMerge(int arr[], int st, int dr)
    {
        if (st < dr)
        {
            int mid = st + ((dr - st) / 2);

            sortingAlgMerge(arr, st, mid);
            sortingAlgMerge(arr, mid + 1, dr);
            merge(arr, st, mid, dr);
        }
    }

    int partition(int arr[], int st, int dr)
    {
        int pivot = arr[dr];
        int i = st - 1;
        for (int j = st; j < dr; j++)
        {
            if (arr[j] > pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp2 = arr[i + 1];
        arr[i + 1] = arr[dr];
        arr[dr] = temp2;

        return i + 1;
    }

    void sortingAlgQuick(int arr[], int st, int dr)
    {
        if (st < dr)
        {
            int pivot = partition(arr, st, dr);
            sortingAlgQuick(arr, st, pivot - 1);
            sortingAlgQuick(arr, pivot + 1, dr);
        }
    }

    void printArray(int arr[], int n)
    {
        int i;
        for (i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    int arr[5] = {40, 8, 11, 2, 99};
    int n = 5;
    Sorter sorting;

    int arr2[n], arr3[n], arr4[n], arr5[n];
    for (int i = 0; i < n; i++)
    {
        arr2[i] = arr[i];
        arr3[i] = arr[i];
        arr4[i] = arr[i];
        arr5[i] = arr[i];
    }

    sorting.sortingAlgBubble(arr, n);
    cout << "Sortat cu Bubble-Sort" << endl;
    sorting.printArray(arr, n);

    sorting.sortingAlgInsertion(arr2, n);
    cout << "Sortat cu Insertion Sort" << endl;
    sorting.printArray(arr2, n);

    sorting.sortingAlgSelection(arr3, n);
    cout << "Sortat cu Selection Sort" << endl;
    sorting.printArray(arr3, n);

    sorting.sortingAlgMerge(arr4, 0, n - 1);
    cout << "Sortat cu Merge Sort" << endl;
    sorting.printArray(arr4, n);

    sorting.sortingAlgQuick(arr5, 0, n - 1);
    cout << "Sortat cu Quick Sort" << endl;
    sorting.printArray(arr5, n);

    return 0;
}
