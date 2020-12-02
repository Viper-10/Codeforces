import java.util.*; 
public class Solution{
    public static void main(String args[]){

        Scanner input = new Scanner(System.in); 

        int n = input.nextInt(); 

        if(n == 2 || n == 3){
            System.out.println(1); 
            return; 
        }
        ArrayList<Integer> arr = new ArrayList<>(); 
        HashMap<Integer, Integer> index = new HashMap<>(); 

        for(int i = 0;i < n; ++i){
            arr.add(input.nextInt()); 
            index.put(arr.get(i), i+1); 
        }

        
        Collections.sort(arr); 

       
        System.out.println(solve(arr, index)); 
    }

    public static int check(ArrayList<Integer> arr){

        int d = arr.get(2) - arr.get(0); 
        boolean ans1 = true; 

        for(int i = 3; i < arr.size(); ++i){
            if(arr.get(i) - arr.get(i-1) != d){
                ans1 = false;         
            }
        }
        
        d = arr.get(2) - arr.get(1); 
        boolean ans0 = true; 

        for(int i = 3; i < arr.size(); ++i){
            if(arr.get(i) - arr.get(i-1) != d){
                ans0 = false;  
            }
        }

        if(ans1) return 1; 

        else if(ans0) return 0; 

        return 2; 
    }

    public static int solve(ArrayList<Integer> arr, HashMap<Integer, Integer> index){
        int cd = -1; 

        int check0 = check(arr); 

        if(check0 == 0){
            return index.get(arr.get(0)); 
        }

        else if(check0 == 1) return index.get(arr.get(1)); 

        else{

            int ans = 0; 
            int d = arr.get(1) - arr.get(0); 
            boolean found = false; 

            for(int i = 2; i < arr.size(); ++i){
                if(arr.get(i) - arr.get(i-1) != d){

                    ans = index.get(arr.get(i)); 
                    if(!found){
                        if((i+1 == arr.size() || arr.get(i+1) - arr.get(i-1) == d)){
                            i += 2; 
                            found = true; 
                        }

                        else{
                            return -1; 
                        }
                    }

                    else return -1;                    
                } 

            }
            return ans; 
        }
    }

    
}