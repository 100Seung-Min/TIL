package chap16;

import java.util.Scanner;

public class Test03 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		int jali = 0;
		int sum = 0;
		for(;num > 0;) {
			int mul = 1;
			jali = num % 10;
			for(int j = 1;j <= jali;j++) {
				mul *= j;
			}
			sum += mul;
			num /= 10;
		}
		System.out.println("totalsum = " + sum);
	}
}
