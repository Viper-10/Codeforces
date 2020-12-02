    #include<iostream>
    using namespace std; 
    int main(){
        
        int n; 
        cin >> n; 
        
        int TotTcount = 0;
        string arr; 
        cin >> arr; 

        for(int i = 0;i < n; ++i){
            if(arr[i] == 'T') TotTcount++; 
        }
        
        int l = 0, r = 0, currTcount = 0; 
        
        while(r < TotTcount){
            if(arr[r++] == 'T') currTcount++; 
        }
        
        int minAns = INT32_MAX; 
        
        while(l < n){
            if(r >= n) r %= n; 
            
            if(arr[l] == 'T') currTcount--; 
            l++; 
            if(arr[r] == 'T') currTcount++; 
            r++;
            
            minAns = min(minAns, TotTcount-currTcount); 
        }
        
        cout << minAns << endl; 
        
        return 0; 
}
