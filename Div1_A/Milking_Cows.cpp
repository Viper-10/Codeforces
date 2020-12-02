#include<iostream>
#include<vector>
using namespace std; 
int main(){

    int n; 
    cin >> n; 
    vector<int> arr(n, 0); 
    
    for(int i =0;i < n; ++i){
        cin >> arr[i]; 
    }

    vector<int> suffix_0(n, 0); 

    for(int i = n-2; i >= 0; --i){
        suffix_0[i] = (arr[i+1] == 0) ? suffix_0[i+1] + 1: suffix_0[i+1];  
    }

    long long min_count = 0; 
    
    for(int i = n-2; i >= 0; --i){
        if(arr[i] == 1) min_count += suffix_0[i]; 
    }

    cout << min_count << endl; 
    return 0; 
}