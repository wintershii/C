public class Calculation{
	public static void main(String[] args){
		int a = 5;
		int b = 6;
		boolean result = ((a > b) && (a != b));
		boolean result2 = ((a > b) || (a != b));
		System.out.println(result);
		System.out.println(result2);	
	}
}