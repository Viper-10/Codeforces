#include<iostream>
#include<vector>
#include<stdio.h>
#define min(a, b) a < b ? a : b
using namespace std; 
int main(){
	
	int t; 
	scanf("%d", &t); 

	while(t--){
	
		int n, p, k; 
		scanf("%d%d%d", &n, &p, &k); 

		char* s = new char[n]; 

		scanf("%s", s); 
		
		int x, y; 

		scanf("%d%d", &x, &y); 

		int* log = new int[n-p]; 
		
		for(int i = n-1; i >= p; --i){
			if(s[i] == '0'){
				log[i] = x; 
			}

			if(i+k < n){
				log[i] += log[i+k]; 
			}
		}

		int64_t minCost = INT32_MAX; 
		
		for(int i = 0;i < n-p; ++i){
			minCost = min(minCost, log[i] + y * i); 			
		}			

		printf("%d\n", minCost); 
	}
	return 0; 
}
