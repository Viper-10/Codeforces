#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 
bool compare(const pair<int, int>& a, const pair<int, int>& b){return a.second < b.second;}
int main(){
    int64_t n, avg, max_marks; 
    cin >> n >> max_marks >> avg;

    vector<pair<int, int>> arr(n, pair<int, int>(0, 0)); 
    int64_t ReqTotMarks = avg * n; 
    int64_t CurrTot = 0; 
    
    for(int i = 0;i < n; ++i){
        cin >> arr[i].first >> arr[i].second; 
        CurrTot += arr[i].first; 
    }

    if(CurrTot >= ReqTotMarks){
        cout << "0" << endl; 
        return 0; 
    }

    int64_t reqMarks = ReqTotMarks-CurrTot; 
    int64_t ans = 0; 

    sort(arr.begin(), arr.end(), compare); 

    int i = 0; 
    while(i < n && reqMarks > max_marks-arr[i].first){
        ans += (max_marks - arr[i].first) * arr[i].second; 
        reqMarks -= max_marks-arr[i].first;  
        ++i; 
    }

    if(reqMarks > 0){
        ans += reqMarks * arr[i].second; 
    }

    cout << ans << endl; 

    return 0; 
}