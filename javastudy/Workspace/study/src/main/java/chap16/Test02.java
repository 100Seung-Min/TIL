package chap16;

public class Test02 {
	public static void main(String[] args) {
		int[] arr = {5, 10, 13, 22, 25};
		int sum = 0;
		for(int i : arr) {
			if(i % 5 == 0) {
				sum += i;
			}
		}
		System.out.println("sum = " + sum);
	}
}
