#include<iostream>
#include<algorithm>
using namespace std; 
void isArithmetic(int* arr, int n){
    int d1 = arr[1] - arr[0];
    int d2 = arr[2] - arr[1]; 

    int d = min(d1, d2); 
    int index = 0; 
    bool First = false; 

    if(d1 != d2) {
        First = true; 
        if(d1 * 2 == d2){
            index = 1;
        }

        else if(d1 == d2 * 2){
            index = 0; 
        }

        else {
            cout << 0 << endl; 
            return; 
        }
    }
    for(int i = 2;i < n-1; ++i){
        int curr_d = arr[i+1] - arr[i]; 
        
        if(curr_d == d) continue; 

        if(curr_d == 2*d){
            if(!First){
                index = i;
                First = true; 
            }
            else{
                cout << "0" << endl; 
                return; 
            }
        }

        else{
            cout << "0" << endl; 
            return; 
        }
    }
    if(First == false){

        if(d == 0){
            cout << 1 << endl; 
            cout << arr[0] << endl; 
        }
        else{
            cout << 2 << endl; 
            cout << arr[0] - d << " " << arr[n-1]+d << endl;  
        }
    }


    else{
        cout << 1 << endl; 
        cout << arr[index] + d << endl; 
    }

}
int main(){

    int n; 

    cin >> n; 

    int* arr = new int[n]; 

    for(int i = 0;i < n; ++i){
        cin >> arr[i]; 
    }

    sort(arr, arr+n); 

    switch(n){
        case 1 : 
                cout << "-1" << endl;
                break; 
        case 2 :{ 
                int d = arr[1] - arr[0]; 
                
                if(d == 0){
                    cout << 1 << endl; 
                    cout << arr[0] << endl; 
                }
                else if((d & 1) == 1){
                    cout << 2 << endl; 

                    cout << arr[0]-d << " " << arr[1]+d << endl; 
                }

                else{
                    cout << 3 << endl; 

                    cout << arr[0]-d << " "  << (arr[0] + arr[1])/2 << " " << arr[1]+d << endl; 
                }
                break;
        } 
        default : 
                isArithmetic(arr, n);

    }
    return 0; 
}