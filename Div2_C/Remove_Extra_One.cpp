#include<iostream>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

int main(){

    int n; 
    cin >> n; 

    vector<int> arr(n+1, 0);

    int a, b, c, i;

    for(i = a = b = c = 0; i < n; ++i){
        cin >> c; 
        if(c > a){
            arr[c]--; 
            b = a; 
            a = c; 
        }    

        else if(c > b){
            arr[a]++; 
            b = c; 
        }
    }

    int ans; 
    int count = -2; 

    for(int i = 1; i <= n; ++i){
        if(count < arr[i]){
            count = arr[i];  
            ans = i; 
        }
    }

    cout << ans << endl; 

    return 0; 
}