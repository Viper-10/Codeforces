#include<iostream>
#include<vector>
using namespace std; 
int dx[4] = {0, 0, 1, -1}; 
int dy[4] = {1, -1, 0, 0}; 
bool isValid(int i, int j, int n, int m){
    return (i >= 0 && i < n && j >= 0 && j < m); 
}
void dfs(vector<vector<char>>& result, int i, int j, int& ReqDotCount){
    if(ReqDotCount == 0) return; 

    result[i][j] = '.'; 
    ReqDotCount--; 

    for(int a = 0; a < 4; ++a){
        int newi = i+dx[a]; 
        int newj = j+dy[a]; 

        if(isValid(newi, newj, result.size(), result[i].size()) && result[newi][newj] == 'X'){
            dfs(result, newi, newj, ReqDotCount); 
        }
    }
}
int main(){

    int n, m, k; 

    cin >> n >> m >> k; 

    vector<vector<char>> graph(n, vector<char>(m)); 

    for(int i = 0;i < n; ++i){
        for(int j = 0;j < m; ++j){
            cin >> graph[i][j]; 
        }
    }

    vector<vector<char>> result(n, vector<char>(m, 'X')); 
    int dotCount = 0; 

    for(int i = 0;i < n; ++i){
        for(int j= 0;j < m; ++j){
            if(graph[i][j] == '#'){
                result[i][j] = '#'; 
            }
            else dotCount++; 
        }
    }

    int ReqDotCount = dotCount - k; 
    // since k dots are converted to X. 

    for(int i = 0;i < n; i++){
        for(int j = 0;j < m; ++j){
            if(ReqDotCount != 0 && result[i][j] == 'X') dfs(result, i, j, ReqDotCount); 
        }
    }

    for(int i = 0;i < n; ++i){
        for(int j = 0;j < m; ++j){
            cout << result[i][j]; 
        }
        cout << endl; 
    }

    return 0; 
}