#include<iostream>
#include<vector>
using namespace std; 
bool solve(vector<int>& A, vector<int>& G, int64_t A_sum, int64_t G_sum, string tempOutput, string& output, int n){

    if(n == 0){
        if(abs(A_sum - G_sum) <= 500){
            output = tempOutput; 
            return true; 
        }
        else return false; 
    }

    bool ans1 = solve(A, G, A_sum+A[n-1], G_sum, tempOutput+"A",output, n-1); 
    bool ans2 = solve(A, G, A_sum, G_sum+G[n-1], tempOutput+"G", output, n-1); 

    if(ans1 == true){
        return true; 
    }   

    else if(ans2 == true){
        return true; 
    } 

    return false; 
}
int main(){

    int n; 

    cin >> n; 

    int64_t ASum = 0, GSum = 0; 
    string output = ""; 
    for(int i = 0;i < n; ++i){
        int a, b; 
        cin >> a >> b; 

        if(ASum + a > GSum + 500){
            GSum += b; 
            output += "G"; 
        }

        else {
            output += "A"; 
            ASum += a; 
        }

    }
    cout << output << endl; 
    
    // vector<int> A(n); 
    // vector<int> G(n); 

    // for(int i = 0;i < n; ++i){
    //     cin >> A[i] >> G[i]; 
        
    // }
    // string output = ""; 
    // string tempOutput = ""; 
    // int64_t A_sum = 0, G_sum = 0; 

    // bool ans = solve(A, G, A_sum, G_sum, tempOutput, output, n); 

    // if(ans){
    //     cout << output << endl; 
    // }

    // else cout << "-1" << endl; 


    return 0; 
}