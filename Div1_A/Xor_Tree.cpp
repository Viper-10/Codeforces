#include<iostream>
#include<vector>
#include<queue>
using namespace std; 
void DFS(int currentNode, vector<vector<int>>& arr, vector<int>& A, vector<int>& B, vector<int>& output){

    A[currentNode] = !A[currentNode];    
  //  output.push_back(currentNode); 
    
    for(int i = 0;i < arr[currentNode].size(); ++i){
        for(int j = 0; j < arr[arr[currentNode][i]].size(); ++j){
            DFS(arr[arr[currentNode][i]][j], arr, A, B, output); 
        }
    }  
}
vector<int> solve(vector<vector<int>>& arr, vector<int>& A, vector<int>& B, const int& n){

    vector<int> output;
    queue<int> q; 

    q.push(1); 

    while(!q.empty()){
        int currentNode = q.front(); 
        q.pop(); 

        for(int i = 0;i < arr[currentNode].size(); ++i){
            q.push(arr[currentNode][i]); 
        }

        if(A[currentNode] != B[currentNode]){
            DFS(currentNode, arr, A, B, output);
            output.push_back(currentNode); 
        }
    }   

    return output; 
}
int main(){

    int n; 

    cin >> n;  

    vector<int> A(n+1), B(n+1); 
    vector<vector<int>> arr(n+1); 

    for(int i = 0;i < n-1; ++i){
        int a, b; 
        cin >> a >> b; 
        arr[b].push_back(a); 
    }

    for(int i = 1;i <= n; ++i){
        cin >> A[i]; 
    }

    for(int i = 1;i <= n; ++i){
        cin >> B[i]; 
    }
    
    vector<int> output = solve(arr, A, B, n); 

    cout << output.size() << endl; 
    for(int i = 0;i < output.size(); ++i){
        cout << output[i] << endl ; 
    }
    return 0; 
}