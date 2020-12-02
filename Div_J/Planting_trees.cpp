#include<iostream>
#include<vector>
using namespace std;
int dx[4] = {0, 0, 1, -1}; 
int dy[4] = {1, -1, 0, 0}; 
bool solve(const short int& n, const short int& m, short int height, vector<vector<short int>>& matrix, const short int& max_height){

    if(height == max_height){
        return true; 
    }
    for(int i = 0;i < n; ++i){
        for(int j = 0;j < m; ++j){
            bool isPossible = true; 
            if(matrix[i][j] == -1){
                for(int k = 0; k < 4; ++k){
                    int newi = i+dx[k]; 
                    int newj = j+dy[k]; 

                    if(newi >= n || newj >= m || newi < 0 || newj < 0) continue; 
                    if(abs(matrix[newi][newj]-height) <= 1){
                        isPossible = false; 
                        break; 
                    }
                }

                if(isPossible == true){
                    matrix[i][j] = height; 
                    bool result = solve(n, m, height+1, matrix, max_height);
                    if(result == true){
                        return result; 
                    } 
                    matrix[i][j] = -1; 
                }
            }
        }
        
    }        

    return false;  
} 
int main(){

    short int n, m; 
    short int height = 1; 

    cin >> n >> m; 

    vector<vector<short int>> matrix(n, vector<short int>(m, -1)); 

    bool ans = solve(n, m, height, matrix, n*m+1); 

    if(ans == false){
        cout << "-1" << endl; 
    }

    else{
        for(int i = 0;i < n; ++i){
            for(int j = 0;j < m; ++j){
                cout << matrix[i][j] << " "; 
            }
            cout << endl; 
        }
    }
    return 0; 
}