import java.util.*; 
public class Solution{
    public static void main(String args[]){

        Scanner input = new Scanner(System.in); 
        
        int t = input.nextInt(); 
        
        while(t-- > 0){
            int n = input.nextInt(); 
            int k = input.nextInt(); 
            int[] arr = new int[n]; 
            int totDistinct = 1; 

            for(int i = 0;i < n; ++i){
                arr[i] = input.nextInt(); 
                if(i != 0 && arr[i] != arr[i-1]){
                    totDistinct++; 
                }
            }

            if(totDistinct == 1){
                System.out.println(1); 
            }

            else if(k == 1){
                System.out.println("-1"); 
            }

            else{   
                int m = 0; 

                for(int i = 1;i < n;){
                    int count = 0;
                    int distinctCount = 1;

                    while(distinctCount < k && i < n){
                        if(arr[i] != arr[i-1]) distinctCount++; 
                        i++;                        
                    }

                    while(i < n && arr[i] == arr[i-1]) i++; 
                                        
                    m++; 
                }   

                System.out.println(m); 
            }
        }

    }
}