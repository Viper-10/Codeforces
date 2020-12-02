#include<iostream>
#include<vector>
using namespace std; 
int main(){
    int n, t;

    cin >> n; 
    cin >> t; 
    vector<int> arr(n, 0); 

    for(int i = 0;i < n; ++i){
        cin >> arr[i]; 
    }

    int64_t max_length = 0, CurrSubarraySum = 0; 
    int j = 0; 
    for(int i = 0;i < n; ++i){
        CurrSubarraySum += arr[i]; 

        while(CurrSubarraySum > t){
            CurrSubarraySum -= arr[j]; 
            j++; 
        }

        int CurrSubarrayLength = i - j + 1; 

        if(CurrSubarrayLength > max_length){
            max_length = CurrSubarrayLength; 
        }
    }

    cout << max_length << endl; 
    return 0; 
}