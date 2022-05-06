package chap09;

public class Inheritance {
	public static void main(String[] args) {
		if(args.length == 2) {
			int i = Integer.parseInt(args[1]);
			print(args[0], i);
		}
		else
			System.out.println("¿¡·¯!");
	}
	
	public static void print(String s, int n) {
		for(int i = 0; i < n; i++) {
			System.out.println(s);
		}
	}
}
