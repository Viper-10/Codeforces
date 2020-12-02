#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std; 
int main(){

    int n, m; 
    scanf("%d", &n); 

    vector<pair<int, char>> distance; 

    for(int i = 0;i < n; ++i){
        int k ; 
        scanf("%d", &k); 
        distance.push_back(make_pair(k, 'a')); 
    }

    cin >> m; 

    for(int i = 0;i < m; ++i){
        int k;
        scanf("%d", &k); 
        distance.push_back(make_pair(k, 'b'));  
    }
    
    sort(distance.begin(), distance.end()); 

    int A_value = 3 * n; 
    int B_value = 3 * m; 

    int i = 0; 
    int MaxDiff = A_value-B_value, Aans = A_value, Bans = B_value; 

    while(i < n+m){
        int currDistance = distance[i].first; 

        while(i < n+m && currDistance == distance[i].first){
            if(distance[i].second == 'a') A_value--; 
            else B_value--; 
            i++; 
        }
        
        if(A_value - B_value > MaxDiff){
            MaxDiff = A_value-B_value; 
            Aans = A_value; 
            Bans = B_value; 
        }        
    }

    printf("%d:%d\n", Aans, Bans); 

    return 0; 
}