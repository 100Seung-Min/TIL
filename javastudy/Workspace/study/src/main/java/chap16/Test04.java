package chap16;

import java.util.Scanner;

public class Test04 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		char com = (char)((int)(Math.random() * 36 + 65));
		int cnt = 0;
		while(true) {
			cnt++;
			System.out.println("A ���� Z������ ���� �Է��ϼ���:");
			char a = in.next().charAt(0);
			if(a == com) {
				System.out.println("������ϴ�.");
				System.out.println("�õ�Ƚ���� " + cnt + "�� �Դϴ�.");
				break;
			}
			else if(a > com) {
				System.out.println("�� ���� ���ڸ� �Է��ϼ���.");
			}
			else if(a < com) {
				System.out.println("�� ū ���ڸ� �Է��ϼ���.");
			}
		}
	}
}
