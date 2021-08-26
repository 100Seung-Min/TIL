package chap02;

import java.util.Scanner;

public class test11 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		System.out.println("È­¾¾¿Âµµ ÀÔ·Â : ");
		double f = in.nextDouble();
		double c = 5.0 / 9.0 * (f - 32);
		System.out.println("¼·¾¾¿Âµµ´Â : " + c);
	}
}
