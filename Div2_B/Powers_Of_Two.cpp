#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std; 
int main(){
    int n; 

    cin >> n; 

    vector<int> arr(n, 0); 
    unordered_map<int, int> freq; 
    int max = INT32_MIN; 

    for(int i = 0;i < n; ++i){
        cin >> arr[i]; 
        freq[arr[i]]++; 
        max = (arr[i] > max) ? arr[i] : max; 
    }

    int64_t limit = 2*max; 
    int64_t count = 0;

    for(int i = 0;i < n; ++i){
        int64_t p = 0;
        int k = 1; 
        while(p <= limit){
            if(p-arr[i] > 0){
                int flag = 0; 
                if(p-arr[i] == arr[i]){
                    flag = 1; 
                }

                count += freq[p-arr[i]] - flag; 
            }
            p =  pow(2, k);
            k++;  
        } 
    }

    cout << count/2 << endl; 

    return 0; 
}