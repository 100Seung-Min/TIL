package chap03;

public class test3 {
	public static void main(String[] args) {
		int a = 1;
		while(a <= 4) {
			System.out.print(a);
			a++;
		}
		int b = 1;
		do {
			System.out.print(b);
			b++;
		}while(b <= 4);
		for(int c = 1; c <= 4; c++)
			System.out.print(c);
	}
}
