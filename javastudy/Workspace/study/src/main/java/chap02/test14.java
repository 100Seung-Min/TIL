package chap02;

import java.util.Scanner;

public class test14 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("전공 이수 학점 : ");
		int a = in.nextInt();
		System.out.print("교양 이수 학점 : ");
		int b = in.nextInt();
		System.out.print("일반 이수 학점 : ");
		int c = in.nextInt();
		boolean d = a + b + c == 140 && a >= 70 && b >= 30 && c >= 30 || b + c >= 80;
		System.out.println((d)? "졸업가능" : "졸업불가");
	}
}
