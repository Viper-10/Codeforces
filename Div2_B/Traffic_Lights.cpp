#include<iostream>
#include<cmath>
using namespace std; 
int main(){

    int l, d, v, g, r; 

    cin >> l >> d >> v >> g >> r; 

    double time_to_light = (double)d / v; 
    
    double totalTime = time_to_light; 

    bool isRed = true; 
    int time_at_light = (int)ceil(time_to_light) % (g+r); 

    double t = floor(time_to_light); 

    t += time_to_light - floor(time_to_light); 

    if((float)time_at_light != 0 && time_at_light < g){
        totalTime += g+r-t;      
    } 

    totalTime += (l-d)/(double)v; 

    cout << totalTime << endl; 

    return 0; 
}