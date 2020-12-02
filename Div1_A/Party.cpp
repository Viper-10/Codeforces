#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& height, const int& n, int i, const vector<int>& arr){
    if(height[i] != 0) return height[i]; 

    if(arr[i] == -1) return 1; 

    height[arr[i]] = solve(height, n, arr[i], arr); 

    return height[arr[i]] + 1; 
} 
int main(){

    int n; 

    cin >> n; 
    
    n += 1; 
    vector<int> arr(n, 0); 
    vector<int> height(n, 0);

    for(int i = 1;i < n; ++i){
        cin >> arr[i]; 
    }

    int maxi = -1; 

    for(int i = 1;i < n; ++i){
        if(height[i] == 0) height[i] = solve(height, n, i, arr); 
        maxi = max(maxi, height[i]); 
    }

    cout << maxi << endl; 
    
    return 0; 
}