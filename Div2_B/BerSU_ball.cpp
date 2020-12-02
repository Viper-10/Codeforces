#include<iostream>
#include<unordered_map>
#include<algorithm> 
using namespace std; 
int main(){
    int n, m; 

    cin >> n; 
    
    int* girls = new int[n]; 

    for(int i = 0;i < n;++i){
        cin >> girls[i]; 
    }

    cin >> m; 
    
    int* boys = new int[m]; 

    for(int i = 0;i < m; ++i){
        cin >> boys[i];
    }    

    sort(boys, boys+m);     
    sort(girls, girls+n); 
    
    int i = 0, j = 0; 
    int k; 
    int count = 0; 

    while(i < m && j < n){
        k = boys[i] - girls[j]; 
        
        if(abs(k) == 0 || abs(k) == 1){
            ++i; 
            ++j;
            count++;  
        }

        else{   
            if(k < 0){
                i++; 
            }

            else{
                j++; 
            }
        }     
    }

    cout << count << endl; 

    return 0; 
}