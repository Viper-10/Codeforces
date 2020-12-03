import java.util.*; 
public class Main{    
	
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		
		int t = input.nextInt(); 
		
		while(t-- > 0) {
			int x, y; 
			
			x = input.nextInt();  
			y = input.nextInt(); 
			
			System.out.println(x-1 + " " + y); 
		}
		
		input.close(); 
	}
	
}