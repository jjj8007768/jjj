#include <iostream>
#include <vector> // Include this for vector
using namespace std;

//time complexity: best case O(n)
// worst case: O(n2)
//pehle sabse bede wale ko last me fhekta he aur fhir oosse nhi chedta
//stable

void bubblesort(vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

int main(){
    
    vector<int> sort = {2, 5, 8, 12, 16, 23, 38, 98, 72, 91};
    bubblesort(sort);

    for (int num : sort)
        cout << num << " ";
    cout << endl;

}