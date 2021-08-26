package chap02;

import java.util.Scanner;

public class test1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("두 수 입력 : ");
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = (a > b)? a : (a == b)? 0 : b;
		System.out.print("출력 : " + c);
		sc.close();
	}
}
