package chap02;

import java.util.Scanner;

public class test7 {
	 public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("정수를 입력하세요 : ");
		int a = in.nextInt();
		System.out.print(a + "의 제곱은 " + a*a);
	}
}
