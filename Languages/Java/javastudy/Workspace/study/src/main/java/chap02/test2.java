package chap02;

import java.util.Scanner;

public class test2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("점수 입력 : ");
		int a = sc.nextInt();
		char b = (a > 90)? 'A' : (a > 80)? 'B' : (a > 70)? 'C' : (a > 60)? 'D' : (a > 50)? 'E' : 'F';
		System.out.print("학점 : " + b);
		sc.close();
	}
}
