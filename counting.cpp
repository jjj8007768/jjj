#include <iostream>
#include <vector> 
using namespace std;

//time complexity O(n+d) where d is largest element
//is not stable

void countingsort(vector <int> &a) {
    int n=a.size();
    int max = 0;
    for (int i = 0; i < n; i++) 
        if (a[i] > max) 
            max = a[i];
    vector <int> freq(max + 1);
    for (int i = 0; i < n; i++){
        freq[a[i]]++;}
    int x = 0;
    for(int i=0; i<freq.size(); i++){
        for(int j=0; j<freq[i]; j++){
            a[x++]=i;
        }
    }
}

int main(){
    
    vector<int> sort = {2, 5, 8, 12, 16, 23, 38, 98, 72, 91};
    countingsort(sort);

    for (int num : sort)
        cout << num << " ";
    cout << endl;

}