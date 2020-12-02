#include<iostream>
#include<queue>
using namespace std; 
int main(){
    
    int n, t, r; 
    int candleCount = 0; 
    queue<int> q; 
    cin >> n >> t >> r; 

    if(t < r){
        cout << "-1" << endl; 
        return 0; 
    }

    while(n--){
        int Entry_time; 
        cin >> Entry_time; 

        while(!q.empty() && q.front() < Entry_time){
            q.pop(); 
        }

        int req_candles = r-q.size();

        while(req_candles > 0){
            candleCount++; 
            q.push(Entry_time-req_candles+t); 
            req_candles--; 
        }

    }

    cout << candleCount << endl; 

    return 0; 
}