package chap11;

import java.util.Scanner;

public class Test07 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int com = (int)(Math.random() * 10) + 1;
		int user;
		int test = 0;
		for(;;) {
			System.out.print("1 �� 10������ ���� �Է��ϼ��� : ");
			user = in.nextInt();
			if(user == com){
				System.out.println("������ϴ�.");
				test++;
				break;
			}
			else if(user > com) {
				System.out.println("�� ���� ���� �Է��ϼ���.");
				test++;
			}
			else {
				System.out.println("�� ū ���� �Է��ϼ���.");
				test++;
			}
		}
		System.out.println("�õ�Ƚ���� " + test + "���Դϴ�.");
	}
}
