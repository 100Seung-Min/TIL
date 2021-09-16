package chap08;

public class Array1 {
	public static void main(String[] args) {
		int[][] scores = {{100, 100, 100},{20, 20, 20}, {30, 30, 30}, {40, 40, 40}, {50, 50, 50}};
		int sum = 0;
		scores[0] = new int[] {2,2};
		for (int i = 0; i < scores.length; i++) {
			for (int j = 0; j < scores[i].length; j++) {
//				sum += scores[i][j];
				System.out.println(scores[i][j]);
			}
		}
		System.out.println(sum);
	}
}
