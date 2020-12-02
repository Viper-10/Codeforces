#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
int main(){

    int64_t n, k; 

    cin >> n >> k; 

    vector<int64_t> arr(n, 0); 
     
    for(int64_t i = 0;i < n; ++i){
        cin >> arr[i]; 
    }
    sort(arr.begin(), arr.end());

    int64_t c_sum = 0, s_sum = arr[0], k_req = 0, max_s_length = 1; 
    int64_t ans = arr[0]; 
    int64_t i = 0; 

    for(int64_t j = 1; j < n; ++j){

        int64_t c_s_length = j-i+1; 
        
        s_sum += arr[j];

        c_sum = arr[j] * (c_s_length); 

        k_req = c_sum - s_sum; 

        if(k_req <= k && max_s_length < c_s_length){
            max_s_length = c_s_length; 
            ans = arr[j]; 
        }

        else{
            s_sum -= arr[i]; 
            ++i; 
        }

    }

    cout << max_s_length << " " << ans << endl; 

    return 0; 
}