import java.util.*; 
public class Create_The_Teams{

    public static void main(String args[]){

        Scanner input = new Scanner(System.in); 

        int t = input.nextInt(); 
        
        while(t-- > 0){
            int n = input.nextInt(); 
            int x = input.nextInt(); 

            ArrayList<Integer> arr = new ArrayList<>(); 

            for(int i = 0;i < n; ++i){
                arr.add(input.nextInt()); 
            }

            Collections.sort(arr, Collections.reverseOrder()); 
            
            int ans = 0; 
            int i = 0; 

            while(i < n && arr.get(i) >= x){
                i++;
                ans++; 
            }
            
            ++i; 

            while(i < n){
                
                int count = 2; 
                while(i < n && count * arr.get(i) < x){
                    i++; 
                    count++; 
                }
                
                if(i == n) break; 

                ans++;
                i += 2; 
            }

            System.out.println(ans); 

        }
    }
}