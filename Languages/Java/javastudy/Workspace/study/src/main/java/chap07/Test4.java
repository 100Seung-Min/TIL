package chap07;

public class Test4 {
	public static void main(String[] args) {
		int[] numArr = new int[10];
		int[] counter = new int[10];
		for(int i = 0; i < numArr.length; i++) {
			numArr[i] = (int)(Math.random() * 10);
			counter[numArr[i]]++;
			System.out.print(numArr[i] + " ");
		}
		System.out.println();
		for(int i = 0; i < numArr.length; i++) {
			System.out.println(i + "ÀÇ °³¼ö : " + counter[i]);
		}
	}
}