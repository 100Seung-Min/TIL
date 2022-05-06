package chap12;

public class Test02 {
	public static void main(String[] args) {
		int[][] arr = {{5,5,5,5,5}, {10,10,10,10,10}, {20,20,20,20,20}, {30,30,30,30,30}};
		int sum = 0;
		float avg = 0;
		int cnt = 0;
		for(int[] x: arr)
			for(int y: x) {
				sum += y;
				cnt++;
				}
		avg = (float)(sum) / cnt;
		System.out.printf("total = %d\naverage = %.2f", sum, avg);
	}
}
