#include<iostream>
#include<cmath>
#define max 1000000000
using namespace std; 
int main(){
    int a, b, c; 
    int count = 0; 
    int sum = 0; 
    int ans[max/1000]; 
    cin >> a >>  b >> c; 

    for(int64_t x = 1;x < max; ++x){
        int sOfx = 0; 
        int temp = x; 
        while(x > 0){
            sOfx += x % 10; 
            x /= 10; 
        }
        x = temp; 
        if((pow(sOfx, a) * b) + c  == x){
            ans[count++] = x; 
        }   
    }

    cout << count << endl; 

    for(int i = 0;i < count; ++i){
        cout << ans[i] << " ";     
    }

    return 0; 
}