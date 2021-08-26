package chap02;

public class test3 {
	public static void main(String[] args) {
		int a = 10;
		int b = 20;
		int r1 = ++a + ++b;
		int r2 = a++ + b++;
		int r3 = b++ + --a;
		int r4 = --a + a--;
		int r5 = b += ++a;
		
		System.out.println(r1);
		System.out.println(r2);
		System.out.println(r3);
		System.out.println(r4);
		System.out.println(r5);
	}
}