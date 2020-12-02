#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std; 
int main(){

    unsigned long long l, r; 

    scanf("%lld%lld", &l, &r); 
    
    unsigned long long i = (unsigned long long)ceil(log2(r-l)); 

    unsigned long long ans = (l ^ r) >> i; 

    printf("%lld\n", (unsigned long long)(ans << i) + ((unsigned long long)1 << i) - 1); 

    return 0; 
}