#include <iostream>
#include <vector> 
using namespace std;

//O(n) for a sorted array in which no shifting is required
//O(n2) for worst case time complexity
//stable

void insertionsort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

int main(){
    
    vector<int> sort = {2, 5, 8, 12, 16, 23, 38, 98, 72, 91};
    insertionsort(sort);

    for (int num : sort)
        cout << num << " ";
    cout << endl;

}