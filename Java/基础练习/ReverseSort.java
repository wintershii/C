
public class ReverseSort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] array = {10,20,30,40,50,60,70};
		ReverseSort sorter = new ReverseSort();
		sorter.sort(array);
	}
	
	/**
	 * 		反转排序
	 * @param array
	 * 			要反转的数组
	 */			
	public void sort(int[] array) {
		System.out.println("反转之前：");
			showArray(array);
			System.out.println("");
		int len = array.length;
		for(int i = 0; i < len / 2; i++) {
			int temp = array[i];
			array[i] = array[len - i - 1];
			array[len - i - 1] = temp;
		}
		System.out.println("反转之后：");
		showArray(array);
	}
	
	/**
	 * 		显示反转后的数组
	 * @param array
	 */
	public void showArray(int[] array) {
		for(int x: array)
			System.out.print(x+" ");
	}
}
