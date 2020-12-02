#include<iostream>
#include<cmath>
using namespace std; 
string check_t_prime(int64_t n){
    
    if(n == 1) return "NO"; 

    double k =  pow(n, 0.5); 

    int64_t y = k; 

    if(y != k){
        return "NO"; 
    }

    int64_t x = pow(y, 0.5); 

    for(int i = 2;i <= x;){
        if(y % i == 0) return "NO";

        if(i > 2){
            i += 2; 
        } 

        else i++; 
    }

    return "YES"; 
}
int main(){

    int n; 

    cin >> n; 

    int64_t i; 

    while(n--){

        cin >> i; 
        
        cout << check_t_prime(i) << endl; 
                
    }

    return 0; 
}