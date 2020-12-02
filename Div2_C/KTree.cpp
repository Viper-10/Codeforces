#include<iostream>
#define mod 1000000007
using namespace std; 
int dp(int n, int k, int d){ 

}
int findn(int n, int k, int d, bool isMin = false){

    // base case. 
    if(isMin == false && n < d) return 0; 

    if(n == 0) return 1; 

    if(n < 0) return 0;  
    

    // recursive calls and small calculation. 
    int ans = 0; 

    for(int i = 1; i <= k; ++i){
        if(i >= d) isMin = true; 

        ans += findn(n-i, k, d, isMin);        
    }

    return ans; 
}
int main(){

    int n, k, d; 

    cin >> n >> k >> d; 

    cout << dp(n, k, d) % mod << endl; 
    //cout << findn(n, k, d) % mod << endl; 
    
    return 0; 
}