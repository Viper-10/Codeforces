#include<iostream>
using namespace std;
int solve(string& a, string& b){

    int cost = 0; 

    for(int i = 0; i < a.length(); ++i){
        if(a[i] != b[i]){
            if(i != a.length() && a[i] != a[i+1] && a[i+1] != b[i+1]){
                a[i] = b[i]; 
                a[i+1] = b[i+1]; 
                cost += 1; 
                ++i; 
            }

            else cost += 1; 
        }
    }

    return cost; 
}
int main(){
    string a, b; 
    int k; 

    cin >> k >> a >> b; 

    cout << solve(a, b) << endl;  

    return 0; 
}