#include<iostream>
#include<vector>
using namespace std; 
int MarkTheBs(vector<vector<int>>& graph, vector<char>& nodes){

    int b_count = 0; 

    for(int i = 0;i < nodes.size(); ++i){
        bool B = true; 
        for(int j = 0;j < nodes.size(); ++j){
            if(i != j && graph[i][j] != 1){
                B = false; 
            }
        }
        if(B) nodes[i] = 'b', b_count++; 
    }
    return b_count; 
}
void MarkAsAndCs(vector<vector<int>>& graph, vector<char>& nodes, const char letter, int k, int& count){ 

    if(nodes[k] != 'x') return; 

    nodes[k] = letter; 
    count++; 

    for(int i = 0;i < nodes.size(); ++i){
        if(graph[k][i] == 1){
            MarkAsAndCs(graph, nodes, letter, i, count); 
        }
    } 
} 
int main(){
    
    int t, n; 

    cin >> n >> t; 

    vector<vector<int>> graph(n, vector<int>(n, 0)); 

    int sv, ev; 

    while(t--){
        cin >> sv >> ev; 

        graph[sv-1][ev-1] = 1; 
        graph[ev-1][sv-1] = 1; 
    }

    vector<char> nodes(n, 'x');
    int a_count, b_count, c_count; 

    b_count = MarkTheBs(graph, nodes);   

    bool first = false, second = false; 
    
    for(int i = 0;i < n; ++i){
        if(nodes[i] == 'x'){
            int count = 0; 
            if(first == false){
                MarkAsAndCs(graph, nodes, 'a', i, count), first = true;
                a_count = count; 
            }
            else if(second == false){
                MarkAsAndCs(graph, nodes, 'c', i, count), second = true;
                c_count = count; 
            }
            else {
                cout << "No" << endl;
                return 0;
            }            
        }
    }

    bool Invalid = false; 

    for(int i = 0;i < n; ++i){
        int count = 0; 
        if(nodes[i] == 'a'){
            for(int j = 0;j <n; ++j){
                if(graph[i][j] == 1 && nodes[j] == 'a'){
                    count++; 
                }
            }
            if(count != a_count-1){
                Invalid = true; 
                break; 
            }
        }

        else if(nodes[i] == 'b'){
            for(int j = 0; j < n; ++j){
                if(graph[i][j] == 1 && nodes[j] == 'b'){
                    count++; 
                }
            }
            if(count != b_count-1){
                Invalid = true; 
                break; 
            }
        }

        else{
            for(int j = 0; j < n; ++j){
                if(graph[i][j] == 1 && nodes[j] == 'c'){
                    count++; 
                }
            }

            if(count != c_count-1){
                Invalid = true; 
                break; 
            }
        }
    }

    if(Invalid){
        cout << "No" << endl; 
    }

    else{
        cout << "Yes" << endl; 
        for(int i = 0;i < n; ++i){
            cout << nodes[i]; 
        }
    }

    cout << endl; 
    return 0; 
}