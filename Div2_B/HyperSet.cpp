#include<iostream>
#include<map>
#include<vector>
using namespace std; 
int main(){

    int n, k; 

    map<string, int> cards; 
    int ans = 0; 

    cin >> n >> k; 

    vector<string> arr(n); 

    for(int i = 0;i <n; ++i){
        cin >> arr[i]; 
    }

    for(int i = 0;i < n; ++i){
        for(int j = i+1;j < n; ++j){
            string temp = ""; 
            for(int l = 0; l < k; l++){
                if(arr[i][l] == arr[j][l]){
                    temp += arr[i][l]; 
                }

                else{
                    temp += 'S' + 'E' + 'T' -  arr[i][l] - arr[j][l]; 
                }
            }       
            if(cards.find(temp) != cards.end()){
                ans += 1; 
            }
        }
        cards[arr[i]] = 1; 
    }

    cout << ans << endl; 

    return 0; 
}