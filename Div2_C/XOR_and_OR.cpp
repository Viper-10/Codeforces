#include<iostream>
#include<algorithm>
using namespace std; 
int main(){

    string s1, s2; 

    cin >> s1; 
    cin >> s2; 

    if(s1.length() != s2.length()){
        cout << "NO" << endl; 
        return 0; 
    }

    if((s1.find('1') == -1) == (s2.find('1') == -1)){
        cout << "YES" << endl; 
    }

    else cout << "NO" << endl; 

    return 0; 
}