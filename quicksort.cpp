#include <iostream>
#include <vector>
using namespace std;

//worst case being O(n2) which happens in array which is either
// completely sorted or reverse
//unstable
//sapce being O(log n)

int partition(vector<int> &a, int s, int e)
{
    int pivot = a[e];
    int i = s - 1;
    for (int j = s; j < e; j++)
        if (a[j] < pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    swap(a[i + 1], a[e]);
    return i + 1;
}

void quicksort(vector<int> &a, int s, int e)
{
    if (s < e)
    {
        int pi = partition(a, s, e);
        quicksort(a, s, pi - 1);
        quicksort(a, pi + 1, e);
    }
}

int main()
{

    vector<int> sort = {2, 5, 8, 12, 16, 23, 38, 98, 72, 91};
    quicksort(sort, 0, 9);

    for (int num : sort)
        cout << num << " ";
    cout << endl;
}