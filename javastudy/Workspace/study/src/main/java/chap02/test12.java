package chap02;

import java.util.Scanner;

public class test12 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("정수 입력 : ");
		int a = in.nextInt();
		boolean b = a % 4 == 0 && a % 5 == 0;
		boolean c = a % 4 == 0 || a % 5 == 0;
		boolean d = a % 4 == 0 && a % 5 != 0 || a % 4 != 0 && a % 5 == 0;
		System.out.println("a % 4 = 0 && a % 5 = 0 : " + b);
		System.out.println("a % 4 = 0 || a % 5 = 0 : " + c);
		System.out.println("a % 4 ! 0 && a % 5 ! 0 : " + d);
	}
}
