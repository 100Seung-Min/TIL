package chap07;

public class Test5 {
	public static void main(String[] args) {
		int[][] score = {{1,2,3},{1,2,3},{1,2,3},{1,2,3},{1,2,3}};
		int sum = 0;
		for(int[] x : score) {
			for(int y : x) {
				sum += y;
			}
		}
		System.out.println(sum);
	}
}
