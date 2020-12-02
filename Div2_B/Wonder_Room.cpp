#include<iostream>
#include<cmath>
#define m(a, b) a < b ? a : b
#define mi(a, b) a > b ? a : b
using namespace std; 

int main(){

    int64_t n, a, b; 

    cin >> n >> a >> b; 

    int64_t min = m(a, b); 
    int64_t max = mi(a, b);  
    int64_t intended_sum = 6*n;

    if(intended_sum <= a*b) {
        cout << a * b << endl << a << " " << b << endl; 
        return 0; 
    }
    int squareroot = pow(intended_sum, 0.5);  
    

    for(int i = min; i <= squareroot; ++i){
        if(intended_sum % i == 0){
            int64_t x = intended_sum/i;
            if(a <= b){
                cout << intended_sum << endl;

                cout << i << " " << x << endl; 
            } 
            else {
                cout << intended_sum << endl; 
                cout << x << " " << i << endl; 
            }
            return 0; 
        }
    }

    cout << min * ceil((double)intended_sum/min) << endl << min << " " << ceil((double)intended_sum/min) << endl;    

    return 0; 
}