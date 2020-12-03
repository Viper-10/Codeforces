#include<iostream>
#include<vector>
using namespace std; 
int binarySearch(vector<int>& arr, const int& x){

    int start = 0, end = arr.size()-1; 
    int index = -1; 

    while(start < end){
        int mid = (end+start)/2; 

        if(arr[mid] >= x){
            index = mid; 
            end = mid-1; 
        }

        else start = mid+1; 
    }

    return index; 
}
int main(){

    int t; 
    cin >> t; 

    vector<int> arr;
    
    arr[0] = 0; 
    arr[1] = 1; 
 
    for(int i = 2; arr.back() < 1000000; ++i){
        arr.push_back(i * (i+1)/2); 
    }

    while(t--){
        int n; 
        cin >> n; 

        int index = binarySearch(arr, n); 

        int pos = arr[index];

        if(pos == n){
            cout << index << endl; 
        }

        else{
            (pos - n == 1) ? cout << index+1 << endl : cout << index + 2 << endl;   
        }
    }

    return 0; 
}
