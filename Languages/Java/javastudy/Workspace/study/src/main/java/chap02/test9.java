package chap02;

import java.util.Scanner;

public class test9 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("�� ���� ������ �Է��ϼ��� : ");
		int a = in.nextInt();
		int min = a / 60 % 60;
		int hour = a / 60 / 60;
		int sec = a % 60;
		System.out.println(hour + "�ð� " + min + "�� " + sec + "��");
	}
}
