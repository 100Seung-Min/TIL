package chap02;

import java.util.Scanner;

public class test4 {
	public static void main(String[] args) {
		double w,h,area;
		Scanner in = new Scanner(System.in);
		System.out.print("���簢���� ���� ���̸� �Է��ϼ��� : ");
		w = in.nextDouble();
		System.out.print("���簢���� ���� ���̸� �Է��ϼ��� : ");
		h = in.nextDouble();
		area = w * h;
		System.out.print("���簢���� ���̴� "+ area + "�Դϴ�.");
	}
}
