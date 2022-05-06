package chap07;

import java.util.Scanner;

public class Test2 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int scores[] = new int[5];
		int sum = 0;
		for(int i = 0; i < 5; i++) {
			int a = in.nextInt();
			scores[i] = a;
		}
		for(int i = 0; i < scores.length; i++) {
			sum += scores[i];
		}
		System.out.println("ЦђБе : " + sum / (float)(scores.length));
	}
}
