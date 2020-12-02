#include<iostream>
#include<vector>
#include<cmath>
#define max 10000001
using namespace std;
int f[max+1]; 
int frequency[max+1]; 

void Setsieve(vector<bool>& sieve){

    sieve[0] = sieve[1] = false; 
    int k = sqrt(max); 
    
    for(int i = 2;i <= k; ++i){
        if(sieve[i] == false) continue; 
        for(int j = i*i; j <= max; j += i){
            sieve[j] = false; 
        }
    }
}
int main(){

    // vector<int> frequency(max);

    int n; 

    cin >> n; 

    for(int i = 0;i < n; ++i){
        int a; 
        cin >> a; 
        frequency[a]++;  
    } 

    vector<bool> sieve(max, true); 

    // Setsieve(sieve); 

    // vector<int> f(max+1, 0); 
    
    
    for(int i = 2;i <= max/2; ++i){
        f[i] = f[i-1];
        if(sieve[i]){
            int ans = 0; 
            for(int j = i;j <= max/2; j += i){
                ans += frequency[j]; 
                if(j != i){
                    sieve[j] = false; 
                }
            }
            f[i] += ans; 
        } 
    }

    for(int i = max/2; i <= max-1; ++i){
        f[i+1] += f[i]; 
    }

    int m; 

    cin >> m; 

    while(m--){

        int l, r; 

        cin >> l >> r; 

        if(r >= max) r = max; 

        if(l >= max){
            cout << 0 << endl; 
        }

        else{
            cout << f[r]-f[l-1] << endl; 
        }
    }



    return 0; 
}