#include<iostream>
#include<queue>
#include<set> 
#include<algorithm>
using namespace std;
bool compare(int& a, int& b){return a > b;}
int main(){

    int n, q; 
    priority_queue<long long> pq; 

    cin >> n >> q; 
    vector<int> arr(n+1, 0); 

    int i = 0; 

    while(i < n){
        int x; 
        cin >> x; 
        pq.push(x); 
        ++i; 
    }   


    while(q--){
        int a, b; 
        cin >> a; 
        cin >> b; 

        arr[a-1]++; 
        arr[b]--; 
    }

    for(int i = 1;i < n+1; ++i){
        arr[i] += arr[i-1]; 
    }

    sort(arr.begin(), arr.end(), compare); 

    int64_t sum = 0; 

    for(i = 0;i < n; ++i){
        sum += arr[i]*pq.top(); 
        pq.pop();     
    }

    cout << sum << endl; 

    return 0; 
}