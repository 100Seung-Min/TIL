package chap02;

import java.util.Scanner;

public class test8 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("������� �ظ��� �������� ? ");
		int a = in.nextInt();		
		System.out.print("������� ���̴� ? ");
		int b = in.nextInt();
		double c = a * a * 3.14 * b;
		System.out.println("������� ���Ǵ� " + c);
	}
}
