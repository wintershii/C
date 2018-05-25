
public class TransferProperty {
	int i = 47;							//定义成员变量
	public void call() {				//定义成员方法
		System.out.println("调用call()方法");
		for(int i = 0; i < 3; i++) {
			System.out.print(i+" ");
			if(i == 2)
				System.out.print("\n");
		}
	}
	
	public TransferProperty() {				//定义构造方法
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		TransferProperty t1 = new TransferProperty();
		TransferProperty t2 = new TransferProperty();
		t2.i = 60;
		// 使用第一个对象调用成员变量
		System.out.println("第一个实例对象调用变量i的结果："+t1.i++);
		t1.call();
		System.out.println(t1.i);
		// 使用第二个对象调用成员变量
		System.out.println("第二个实例对象调用变量i的结果："+t2.i);
		t2.call();
	}

}
