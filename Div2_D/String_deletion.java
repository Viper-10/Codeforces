import java.util.*;

public class Solution{
    public static void main(String args[]){

        Scanner input = new Scanner(System.in); 

        int t = input.nextInt(); 

        while(t-- > 0){
            int n = input.nextInt(); 

            char[] str = input.next().toCharArray(); 
            
           System.out.println(solve(str)); 
        }
    }

    public static int solve(char[] str){

        Queue<Integer> q = new LinkedList<>(); 
        
        int period = 0; 

        // we're putting every l-r range into the queue with a key value(period). 
        
        for(int i = 1;i < str.length; ++i){

            if(str[i] == str[i-1]){
                q.add(period); 
            }

            else{
                period += 1; 
            }
        }

        int i = 0;
        int NoDeleted = 0, OperationCount = 0;
        // i is not the index number. 

        // i gives the first element that will be deleted in second step. 
        // q.peek() gives the first element of the range that will be deleted. 
        // if q.peek() == i, then every element gets deleted until q.peek() is not equal to i. 


        while(!q.isEmpty()){

            q.remove(); 
            
            NoDeleted += 2; 
            OperationCount++; 

            while(!q.isEmpty() && q.peek() == i){
                NoDeleted++; 
                q.remove(); 
            }            

            ++i; 
        }

        OperationCount += (str.length - NoDeleted + 1)/2; 

        return OperationCount; 

    }
}