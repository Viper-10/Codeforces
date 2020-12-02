#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std; 
int gcd(int a, int b){
    if (b == 0) return a;

    return gcd(b, a % b); 
}
bool checkValid(const int& x1, const int& y1, const int& x2, const int& y2){
    return (x1 == x2 || y1 == y2) ? false : true; 
}
int main(){

    int a, b; 
    scanf("%d%d", &a, &b); 
    
    int x1, y1, x2, y2; 

    for(x1 = 1; x1 < a; ++x1){
        float temp1 = sqrt(pow(a, 2) - pow(x1, 2));
         
        if(ceil(temp1) - temp1 != 0){
            continue; 
        }

        y1 = temp1;
        int g = gcd(x1, y1); 
        x2 = -y1/g; 
        y2 = x1/g; 
        
        int B = (int)sqrt(pow(x2, 2)+pow(y2, 2)); 

        x2 *= b/B; 
        y2 *= b/B; 


        if((int)(pow(x2, 2) + pow(y2, 2)) % b == 0 && checkValid(x1, y1, x2, y2) && pow(a, 2) + pow(b, 2) == (pow(x2-x1, 2))+pow(y2-y1, 2)){
            puts("YES");
            printf("0 0\n%d %d\n%d %d\n", x1, y1, x2, y2); 
            return 0;  
        }
        

        else{
            
            y1 = -temp1;
            int g = gcd(x1, y1); 
            x2 = -y1/g; 
            y2 = x1/g; 
            
            int B = (int)sqrt(pow(x2, 2)+pow(y2, 2)); 

            x2 *= b/B; 
            y2 *= b/B; 
            if((int)(pow(x2, 2) + pow(y2, 2)) % b == 0 && checkValid(x1, y1, x2, y2) && pow(a, 2) + pow(b, 2) == (pow(x2, 2)-pow(x1, 2))+pow(y2, 2)-pow(y1, 2)){
                puts("YES");
                printf("0 0\n%d %d\n%d %d\n", x1, y1, x2, y2); 
                return 0;  
            }
        } 
    }
    
    puts("NO"); 
    return 0; 
}