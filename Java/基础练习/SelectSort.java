
public class SelectSort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] array = {63,4,24,1,3,15};
		SelectSort sorter = new SelectSort();
		sorter.sort(array);
	}
	
	/**
	 * 		选择排序
	 * @param array
	 * 			要排序的数组
	 */
	
	public void sort(int[] array) {
		for(int i = 0; i < array.length - 1; i++) {
			int min = i;
			for(int j = i + 1; j < array.length; j++) {
				if(array[j] < array[min])
					min = j;
			}
			if(i != min) {
				int temp = array[i];
				array[i] = array[min];
				array[min] = temp;
			}
		}
		showArray(array);
	}
	
	
	public void showArray(int[] array) {
		for(int x:array)
			System.out.print(x+" ");
	}
}
