#include<iostream>
#include<cmath>
#include<stack>
#include<vector>
using namespace std; 
void findSieve(vector<bool>& prime){
    prime[1] = true; 
    prime[0] = false; 

    for(int i = 2;i*i <= prime.size(); ++i){
        if(prime[i] == true){
            for(int64_t j = i*i; j <= prime.size(); j += i){
                prime[j] = false; 
            }
        }  
    }
}
int main(){

    int t; 
    cin >> t; 

    vector<bool> prime(31624, true); 

    findSieve(prime); 

    while(t--){
        int64_t p, q; 
        cin >> p >> q; 
        stack<int64_t> s; 
        bool found = false;
  
        for(int64_t i = 1; i <= 31624; ++i){
            if(prime[i] && p % i == 0){
                s.push(i); 
                if((p/i) % q){
                    cout << (p/i) << endl; 
                    found = true; 
                    break; 
                } 
            }
        }

        if(!found) cout << s.top() << endl; 
    }

    return 0; 
}