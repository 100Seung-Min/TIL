package chap02;

import java.util.Scanner;

public class test13 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		int b = (a > 100)? a / 100 + a / 10 % 10 + a % 10 : (a > 10)? a / 10 + a % 10 : a;
		System.out.println(b);
	}
}
