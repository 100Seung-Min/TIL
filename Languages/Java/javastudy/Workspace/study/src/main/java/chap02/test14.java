package chap02;

import java.util.Scanner;

public class test14 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("���� �̼� ���� : ");
		int a = in.nextInt();
		System.out.print("���� �̼� ���� : ");
		int b = in.nextInt();
		System.out.print("�Ϲ� �̼� ���� : ");
		int c = in.nextInt();
		boolean d = a + b + c == 140 && a >= 70 && b >= 30 && c >= 30 || b + c >= 80;
		System.out.println((d)? "��������" : "�����Ұ�");
	}
}
