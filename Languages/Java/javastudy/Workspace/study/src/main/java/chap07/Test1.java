package chap07;

public class Test1 {
	public static void main(String[] args) {
//		System.out.println(Math.random());
//		System.out.println((int)(Math.random() * 100));
//		System.out.println((int)(Math.random() * 100) + 1);
		
		int[] lotto = new int[6];
		for(int i = 0; i < lotto.length; i++) {
			lotto[i] = (int)(Math.random() * 45) + 1;
			System.out.print(lotto[i] + " ");
		}
	}
}
