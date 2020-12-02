#include<iostream>
using namespace std;
int recursion(bool* arr, int n, bool isMyfriendTurn = true){
    
    if(n <= 0){
        return 0; 
    }

    else if(isMyfriendTurn){
        int ans1, ans2; 

        ans1 = recursion(arr+1, n-1, false);
        ans2 = recursion(arr+2, n-2, false);

        if(arr[0] && arr[1]) ans2 += 2; 

        else if(arr[0] || arr[1]) ans2 += 1; 

        if(arr[0]) ans1 += 1;

        return min(ans1, ans2);                 
    }

    else return min(recursion(arr+1, n-1, true),recursion(arr+2, n-2, true)); 
    
}
int memoization(bool* arr, int n, int** log, bool isMyFriendTurn = true){

    // base case. 
    if(n <= 0) return 0; 

    if(log[n-1][isMyFriendTurn] == -1){
        int ans; 

        if(isMyFriendTurn){
            int ans1 = memoization(arr+1, n-1, log, false);
            int ans2 = memoization(arr+2, n-2, log, false); 

            if(arr[0] && arr[1]){
                ans2 += 2; 
            }

            else if(arr[0] || arr[1]){
                ans2 += 1; 
            }             

            if(arr[0]) ans1 += 1; 

            ans = min(ans1, ans2);    
        }

        else ans = min(memoization(arr+1, n-1, log, true), memoization(arr+2, n-2, log, true)); 
        
        log[n-1][isMyFriendTurn] = ans; 
    }

    return log[n-1][isMyFriendTurn]; 
} 
int solve(bool* arr, const int& n){

    // return recursion(arr, n);
    int** log = new int*[n]; 

    for(int i = 0;i < n; ++i){
        log[i] = new int[2];
        log[i][0] = log[i][1] = -1; 
    }

    return memoization(arr, n, log); 
}
int main(){

    int t; 
    cin >> t; 

    while(t--){
        
        int n; 
        cin >> n; 

        bool* arr = new bool[n]; 

        for(int i = 0;i < n; ++i){
            cin >> arr[i]; 
        }        

        cout << solve(arr, n) << endl; 
    }

    return 0; 
}