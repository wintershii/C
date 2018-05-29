
interface drawTest{
	public void draw();
	
}

class ParallelogramgleUseInterface extends QuadrangleUseInterface
	implements drawTest{
	public void draw() {
		System.out.println("平行四边形.draw()");
	}
}

class SquareUseInterface extends QuadrangleUseInterface
	implements drawTest{
	public void draw() {
		System.out.println("正方形.draw()");
	}
}

public class QuadrangleUseInterface {
	public void doAnything() {
		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		drawTest d[] = {
			new ParallelogramgleUseInterface(),new SquareUseInterface()};
		for(int i = 0; i < d.length; i++)
			d[i].draw();
	}

}
