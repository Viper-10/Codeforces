#include<iostream>
#include<vector>
#include<stdio.h>
#define min(a, b) a < b ? a : b
using namespace std; 
char s[1000000]; 
int main(){
	
	int t; 
	scanf("%d", &t); 

	while(t--){
	
		int n, p, k; 
		scanf("%d%d%d", &n, &p, &k); 

		scanf("%s", s); 
		
		int x, y; 

		scanf("%d%d", &x, &y); 

		vector<int> log(n, 0); 	

		p -= 1; 

		int64_t minCost = INT32_MAX; 
		
		for(int i = n-1;i >= p; --i){
			if(s[i] == '0') log[i] = x; 

			if(i+k < n) log[i] += log[i+k]; 

			minCost = min(minCost, log[i]+y * (i-p)); 
		}


		printf("%ld\n", minCost); 
	}
	return 0; 
}
