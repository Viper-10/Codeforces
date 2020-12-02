#include<iostream>
using namespace std; 
int main(){
    
    int n, k; 
    int count = 0; 
    string s; 

    cin >> n >> k; 
    cin >> s; 

    for(int i = 0;i < n; ++i){
        if(s[i] == s[i+1]){
            int indexTobeChanged; 

            if(i+2 < n && s[i+1] != s[i+2]){
                indexTobeChanged = i;     
                
            }

            else{
                indexTobeChanged = i+1; 
                 
                 
            }

            char a = 'A'; 
            for(int i = 0;i < k; ++i){
                if(s[indexTobeChanged-1] == a+i || s[indexTobeChanged+1] == a+i) continue;

                else{
                    s[indexTobeChanged] = a+i; 
                    break; 
                }                 
            }
            count++; 
        }
    }

    cout << count << endl << s << endl; 

    return 0; 
}