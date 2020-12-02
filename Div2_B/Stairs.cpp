#include<iostream>
using namespace std; 
int solve(long long x){

    long long  h = 1; 
    int count = 0; 

    while(x >= h * (h+1)/2){
        count++; 
        x -= h * (h+1)/2; 
        h = h * 2 + 1; 
    }

    return count; 
}
int main(){

    int t; 
    cin >> t; 

    while(t--){
        long long x; 
        cin >> x;

        cout << solve(x) << endl;  
    }

    return 0; 
}