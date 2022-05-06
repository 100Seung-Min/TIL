package chap11;

import java.util.Scanner;

public class Test05 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int sum = 0;
		int num = in.nextInt();
		for(; num > 0;) {
			sum += num % 10;
			num /= 10;
		}
		System.out.println("sum = " + sum);
	}
}
