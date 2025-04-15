#include <iostream>
#include <vector> // Include this for vector
using namespace std;

//time complexity O(log(n))

int binarysearch(vector<int> &arr, int target) {
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    while (s <= e) {
        int m = s + (e - s) / 2; 
        if (arr[m] == target) {
            return m;
        } else if (arr[m] < target) {
            s = m + 1;
        } else {
            e = m - 1;
        }
    }

    return -1;
}

int binarySearchRecursive(vector<int>& arr, int target, int s, int e) {
    if (s > e) {
        return -1;
    }
    int m = s + (e - s) / 2;
    
    if (arr[m] == target) {
        return m;
    } else if (arr[m] < target) {
        return binarySearchRecursive(arr, target, m + 1, e);
    } else {
        return binarySearchRecursive(arr, target, s, m - 1);
    }
}

int main() {
    vector<int> sortedArray = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 23;

    int result = binarysearch(sortedArray, target); // Use correct function name

    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
