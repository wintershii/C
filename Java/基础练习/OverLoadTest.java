

public class OverLoadTest {
	public static int add(int a,int b) {
		return a + b;
	}
	
	public static double add(double a,double b) {
		return a + b;
	}
	
	public static int add(int a) {
		return a;
	}
	
	public static int add(int a, double b) {
		return 1;
	}
	
	public static int add(double b,int a) {
		return 1;
	}
	
	public static void main(String[] args) {
		System.out.println("调用add(int,int)方法:"+add(1,2));
		System.out.println("调用add(double,double)方法:"+add(2.1,3.3));
		System.out.println("调用add(int)方法:"+add(2));
	}
	
}
