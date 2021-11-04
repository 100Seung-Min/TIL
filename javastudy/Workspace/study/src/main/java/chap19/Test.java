package chap19;

public class Test {
	static int d;
	public static void main(String[] args) {
		byte a = 0b1111;
		System.out.println((int)a);
		int b = 0xF;
		System.out.println(b);
		int c = 017;
		System.out.println(c);
		System.out.println(d);
		String abcd = "abcd";
		System.out.println(abcd);
		a(abcd);
		System.out.println(abcd);
	}
	
	static void a(String a) {
		a.concat("efgh");
	}
}