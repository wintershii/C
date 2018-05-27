
public class MathRandomChar {
	
	public static char GetRandomChar(char cha1,char cha2) {
		return (char)(cha1 + Math.random()*(cha2 - cha1 +1));
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("任意小写字母："+GetRandomChar('a','z'));
		System.out.println("任意大写字母："+GetRandomChar('A','Z'));
		System.out.println("0-9任意数字字符："+GetRandomChar('0','9'));
	}

}
