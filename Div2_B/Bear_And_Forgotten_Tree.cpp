#include<iostream>
using namespace std; 

int main(){

    int n, diameter, height; 

    cin >> n >> diameter >> height; 

    if(diameter == 1 && height == 1 && n > 2){
        cout << "-1" << endl; 
        return 0; 
    }
    if(n <= diameter || diameter < height || diameter > 2*height){
        cout << "-1" << endl; 
        return 0; 
    }


    for(int h = 1; h <= height; ++h){
        cout << h << " " << h+1 << endl; 
    }

    int last_node = height; 

    bool first = true; 
    int h = height+2;
    int k = diameter - height; 
    if(k > 0){
        while(k > 0){
            if(first == true){
                cout << 1 << " " << h << endl;  
                last_node = 1; 
                first = false; 
            }

            else{
                cout << h << " " << h+1 << endl;
                last_node = h;  
                ++h;  
            }
            --k; 
        }

        while(h < n){
            cout << last_node << " " << h+1 << endl; 
            h++; 
        }
    }

    else{
        while(h <= n){
            cout << last_node << " " << h << endl; 
            ++h; 
        }
    }

    return 0; 
}