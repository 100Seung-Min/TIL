package chap16;

import java.util.Scanner;

public class Test01 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String a1 = in.nextLine();
		String a2 = in.nextLine();
		String a3 = a1 + a2;
		System.out.println("°á°ú: " + a3);
	}
}
