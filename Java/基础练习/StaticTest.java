
public class StaticTest {

	final static double PI = 3.1415;
	static int id = 8;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		method1();

	}
	
	public static void method1() {
		System.out.println("这是静态方法");
		System.out.println(StaticTest.id);
		System.out.println(StaticTest.PI);
	}
	

}
