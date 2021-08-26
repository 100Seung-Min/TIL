package chap02;

import java.util.Scanner;

public class test5 {
	public static void main(String[] args) {
//		Scanner in = new Scanner(System.in);
//		System.out.print("정수를 입력하세요 : ");
//		int a = in.nextInt();
//		String su = (a % 2 == 0)? "짝수" : "홀수";
//		System.out.print(su);
//		int x = 1, y = 2;
//		System.out.print(x++);
//		System.out.print(++x + y--);
//		System.out.print(++x / 3 + x * ++y);
		char c1 = 'a';
		final int ONE = 1;
		int i1 = 0x11;
		float f1 = 1.5f;
		double d1 = 2.8;
		int i = 1;
		System.out.println((int)c1 + ONE);
		System.out.println(c1 + ONE);
		System.out.printf("%d\n", i1 / 2);
		System.out.printf("%5s\n", c1 + ONE);
		System.out.printf("%d\n", (int)f1 + (int)d1);
	}
}
