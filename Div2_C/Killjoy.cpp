#include<iostream>
#include<cmath>
using namespace std; 
int main(){

    int t; 
    cin >> t; 

    while(t--){
        int n; 
        int killjoyvalue; 
        cin >> n; 
        cin >> killjoyvalue; 

        bool isAllkilljoyvalue = true; 
        int sum = 0; 
        bool isOnekilljoyvalue = false; 

        for(int i = 0;i < n; ++i){
            int a; 
            cin >> a; 
            if(a != killjoyvalue) isAllkilljoyvalue = false;

            if(a == killjoyvalue) isOnekilljoyvalue = true; 

            sum += a;      
        }

        if(isAllkilljoyvalue) cout << 0 << endl;

        else if(sum == killjoyvalue*n || isOnekilljoyvalue) cout << 1 << endl; 

        else{
            cout << 2 << endl; 
        } 
    }   

    return 0; 
}