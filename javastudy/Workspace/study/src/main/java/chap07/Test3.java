package chap07;

public class Test3 {
	public static void main(String[] args) {
		int[] score = {70, 88, 90, 100, 55};
		int max = score[0];
		for(int i = 0; i < score.length; i++) {
			max = (max < score[i]) ? score[i] : max;
		}
		System.out.println(max);
	}
}