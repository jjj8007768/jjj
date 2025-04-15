#include <iostream>
#include <vector> 
using namespace std;

//time complexity: best case and worst case me same hi rhegi-- muje fadak nhi pedta
// O(n2)
//bubble sort ka oolta kaam krta he jiss me ye chote wale ko pehle le aata he 
//not a stable sort

void selectionsort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int mini = i;

        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }

        if (mini != i) {
            swap(arr[i], arr[mini]);
        }
    }
}

int main(){
    
    vector<int> sort = {2, 5, 8, 12, 16, 23, 38, 98, 72, 91};
    selectionsort(sort);

    for (int num : sort)
        cout << num << " ";
    cout << endl;

}