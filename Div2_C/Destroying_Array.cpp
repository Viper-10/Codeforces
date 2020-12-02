#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std; 
int main(){

    int n; 

    cin >> n; 

    vector<int> arr(n+1, 0);
    vector<int64_t> sum(n+1, 0); 
    vector<int> index(n+1, 0); 

    unordered_map<int, bool> log; 

     for(int i = 1;i < n+1; ++i){
        cin >> arr[i]; 
        sum[i] = sum[i-1] + arr[i];        
    }

    for(int i = 1;i < n+1; ++i){
        cin >> index[i]; 
    }

    log[n+1] = true; 

    for(int i = 1; i < n+1; ++i){        
        log[index[i]] = true; 
        for(int j = index[i]+1, k = 0;j < n+1 && log.count(j) != 1; ++j, ++k){
            sum[j] -= sum[index[i]];  
        }

        sum[index[i]] = 0; 
        int64_t maximum = 0; 

        for(auto& i : log){
            maximum = max(sum[i.first-1], maximum); 
        }
        cout << maximum << endl; 
    }

    return 0; 
}