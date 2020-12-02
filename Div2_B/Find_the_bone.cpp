#include<cstdio>
#include<vector>
using namespace std; 
int main(){

    int n, m, k, a, l, r; 

    scanf("%d%d%d", &n,&m, &k); 

    long long int holes[n+1] = {0}; 

    for(int i = 0;i < m; ++i){
        scanf("%d", &a);  
        holes[a] = true; 
    }

    int BoneAtIndex = 1; 
    while(k-- && holes[BoneAtIndex] == false){
        scanf("%d%d", &l, &r);  
        if(l == BoneAtIndex){
            BoneAtIndex = r; 
        }

        else if(r == BoneAtIndex) BoneAtIndex = l; 
    } 
    
    printf("%d\n", BoneAtIndex); 
    return 0; 
}