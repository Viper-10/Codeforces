#include<iostream>
using namespace std; 
int main(){

    int n; 

    cin >>  n; 

    // LHS = 2/n. 
    //     = 1/n + 1/n. 
    //     = 1/n + 1*(n+1)/((n+1)*n)
    //     = 1/n + n/(n+1)*n + 1/(n+1)*n
    //     = 1/n + 1/(n+1) + 1/(n+1)*n

    if(n == 1){
        cout << "-1" << endl; 
        return 0; 
    }
    cout << n << " " << n+1 << " " << (n+1)*n << endl;  

    return 0; 

}