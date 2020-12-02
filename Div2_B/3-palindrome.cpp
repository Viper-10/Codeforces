#include<iostream>
using namespace std; 
int main(){

    int n; 
    cin >> n; 
    string notPalindrome = "aabb"; 
    while(n >= 4){
        cout << "aabb"; 
        n -= 4; 
    }

    if(n > 0){
        cout << notPalindrome.substr(0, n) << endl;  
    }

    return 0; 
}