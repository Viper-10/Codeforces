#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>

using namespace std; 

long double find_minimum_radius(vector<long long>& lamps, long long l, int n){

    long double  d;

    sort(lamps.begin(), lamps.end()); 

    long long max = -1; 

    long long i = 0; 

    while(i != lamps.size()-1){

        long long current = lamps[i+1] - lamps[i]; 

        if(max < current){
            max = current; 
        }

        ++i; 
    }

    long long c_max = -1; 

    if(lamps[0] != 0 && lamps[0] > max/2.0){
        c_max = lamps[0]; 
    }        

    long long last = lamps[lamps.size()-1]; 

    if(l - last > max/2.0 && l - last > c_max){

        c_max = l-last; 
    }   

    if(c_max > max/2.0) return c_max;     

    d = max/2.0;

    return d; 
}
int main(){

    long long n, l; 

    cin >> n >> l; 

    vector<long long> lamps; 
    
    for(long long  i = 0;i < n; ++i){

        long long pos; 

        cin >> pos; 

        lamps.push_back(pos); 

    }
    
    long double d = find_minimum_radius(lamps, l, n); 

    printf("%Lf\n",d); 

    return 0; 
}