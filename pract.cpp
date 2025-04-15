#include <iostream>
#include <vector>
using namespace std;

// void merge(vector<int> &arr, int l, int m, int u){
//     int n1=m-l+1;
//     int n2=u-m;
//     vector<int> left(n1),right(n2);
//     for(int i=0; i<n1; i++){
//         left[i]=arr[i+l];
//     }
//     for(int i=0; i<n2; i++){
//         right[i]=arr[m+1+i];
//     }

//     int i=0, j=0, k=l;
//     while(i<n1 && j<n2){
//         if(left[i]<=right[j]){
//             arr[k]=left[i];
//             i++;
//         }
//         else{
//             arr[k]=right[j];
//             j++;
//         }
//         k++;
//     }
    
//     while(i<n1){
//         arr[k]=left[i];
//         i++;
//         k++;
//     }

//     while(j<n2){
//         arr[k]=right[j];
//         j++;
//         k++;
//     }

// }

// void mergesort(vector<int> &arr, int l, int u){
//     if(l<u){
//         int m=l+(u-l)/2;
//         mergesort(arr, l,m);
//         mergesort(arr, m+1,u);
//         merge(arr,l,m,u);
//     }
// }

// int main() {
//     vector<int> arr = {12, 11, 13, 5, 6, 7};
//     int n = arr.size();

//     mergesort(arr, 0, n - 1);

//     for (int num : arr)
//         cout << num << " ";

//     return 0;
// }

int partition(vector<int> &arr, int l, int u){
    int pivot=arr[u];
    int j=l-1;
    for(int i=l; i<u; i++){
        if(pivot>arr[i]){
            j++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[u],arr[j+1]);
    return j+1;
}

void quicksort(vector<int> &arr, int l, int u){
    if(l<u){
        int pi=partition(arr,l,u);
        quicksort(arr,l, pi-1);
        quicksort(arr,pi+1, u);
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