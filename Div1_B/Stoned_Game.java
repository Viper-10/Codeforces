import java.util.*; 
import java.lang.Math;
public class solution{
    public static void main(String args[]){
        
        Scanner input = new Scanner(System.in);
        
        int t = input.nextInt(); 

        while(t-- > 0){
            int n = input.nextInt(); 
            ArrayList<Integer> arr = new ArrayList<>(n);
            int sum = 0; 
            int maxElement = 0; 

            for(int i = 0;i < n; ++i){
                arr.add(input.nextInt()); 
                sum += arr.get(i); 
                maxElement = Math.max(maxElement, arr.get(i)); 
            }

            String ans = ""; 

            if(maxElement > sum/2 || (sum%2) == 1){
                ans = "T"; 
            }

            else{
                ans = "HL";
            }
            System.out.println(ans); 
        }
    }
}