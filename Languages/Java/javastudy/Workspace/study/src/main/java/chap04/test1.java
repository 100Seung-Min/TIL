package chap04;

import java.util.Scanner;

public class test1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		
		System.out.print("�й� �Է� : ");
		int age = sc.nextInt();
		sc.nextLine();
		System.out.print("�̸� �Է� : ");
		String name = sc.nextLine();
		System.out.print("������ �Է� : ");
		String book = sc.nextLine();
		System.out.println("�й� : "+ age + ", �̸� : " + name + ", ������ : " + book);
	}
}
