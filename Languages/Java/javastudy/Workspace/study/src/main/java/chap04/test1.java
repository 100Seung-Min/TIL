package chap04;

import java.util.Scanner;

public class test1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		
		System.out.print("학번 입력 : ");
		int age = sc.nextInt();
		sc.nextLine();
		System.out.print("이름 입력 : ");
		String name = sc.nextLine();
		System.out.print("도서명 입력 : ");
		String book = sc.nextLine();
		System.out.println("학번 : "+ age + ", 이름 : " + name + ", 도서명 : " + book);
	}
}
