#include<iostream>
#include<vector>
using namespace std; 
int main(){

    int l, s; 
    vector<int> result; 

    cin >> s >> l; 

    for(int i = l; i >= 1; --i){
        int k = i & -i; 

        if(k > s) continue;

        else{
            s -= k; 
            result.push_back(i); 
        } 
    }

    if(s == 0){
        cout << result.size() << endl; 

        for(int i = 0;i < result.size(); ++i){
            cout << result[i] << " "; 
        }

        cout << endl;
    }

    else{
        cout << "-1" << endl; 
    } 
    return 0; 
}