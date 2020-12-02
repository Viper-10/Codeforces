#include<iostream>
#include<vector>
using namespace std; 
inline void print_zero(){
    cout << 0 << endl; 
}
int iteration(vector<int>& arr, int& index, int& partial_sum){
    int curr_sum = 0; 

    while(arr.size() > index && curr_sum < partial_sum){
        curr_sum += arr[index]; 
        index++; 
    }

    if(curr_sum > partial_sum ||(curr_sum < partial_sum &&  arr.size() == index)){
        return -1; 
    }

    return index; 
}
int main(){

    int n; 

    cin >> n; 

    vector<int> arr(n, 0); 
    int total_sum = 0; 

    for(int i = 0;i < n; ++i){
        cin >> arr[i]; 
        total_sum += arr[i]; 
    }    

    if(total_sum % 3 != 0){
        print_zero(); 
        return 0; 
    }

    int curr_sum = 0; 
    int partial_sum = total_sum/3; 
    int i = 0, j, k, x; 
    
    x = iteration(arr, x, partial_sum); 
    
    if(x == -1){
        print_zero(); 
        return 0;  
    }
    i = x; 

    x = iteration(arr, x, partial_sum); 

    if(x == -1){
        print_zero(); 
        return 0; 
    }
    j = x; 

    x = iteration(arr, j, partial_sum); 

    if(x == -1){
        print_zero(); 
        return 0; 
    }

    int count = 1; 

    while(arr[i] == 0){
        count++; 
        i++; 
    }

    while(arr[j] == 0){
        count++; 
        j++; 
    }

    cout << count << endl; 

    return 0; 

}