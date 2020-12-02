#include<iostream>
#include<unordered_map>
using namespace std; 
int solve(int n, int k){
    unordered_map<int, int> frequency; 
    frequency[0] = INT32_MIN; 
    int x; 

    for(int i = 0;i < n; ++i){
        cin >> x; 
        if(x % k == 0) continue; 

        if(frequency.count(k - x % k) % k == 0){
            frequency[(k - x % k) % k] = (k - x % k) % k; 
        }

        else frequency[(k - x % k) % k] += k; 
    }

    int max_val = -1; 
    int max_deviation = 0; 

    for(auto& it : frequency){
        if(it.second >= max_val && it.first > max_deviation){
            max_deviation = it.first; 
            max_val = it.second;   
        }   
    }    

    return max_val+1; 
}
int main(){

    int t;  
    int n; 
    int k; 

    cin >> t; 
    while(t--){

        cin >> n; 
        cin >> k;

        cout << solve(n, k) << endl;                

    }
    return 0; 
}