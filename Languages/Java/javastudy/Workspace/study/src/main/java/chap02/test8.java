package chap02;

import java.util.Scanner;

public class test8 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.print("원기둥의 밑면의 반지름은 ? ");
		int a = in.nextInt();		
		System.out.print("원기둥의 높이는 ? ");
		int b = in.nextInt();
		double c = a * a * 3.14 * b;
		System.out.println("원기둥의 부피는 " + c);
	}
}
