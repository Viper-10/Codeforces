import java.util.*; 
public class Solution{
    public static void main(String args[]){
        Scanner input = new Scanner(System.in); 

        int nV = input.nextInt(); 
        int nE = nV-1; 

        int k = input.nextInt(); 
        
        ArrayList<Integer>[] tree = new ArrayList<>[nV]; 

        for(int i = 0; i < nV; i++){
            tree[i] = new ArrayList<Integer>(2); 
        }       

        for(int i = 0;i < nE; ++i){
            tree.get(i)
        }
        
        System.out.println(Solve(tree, ))
    }
}