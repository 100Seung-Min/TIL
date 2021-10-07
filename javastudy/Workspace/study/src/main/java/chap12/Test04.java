package chap12;

public class Test04 {
	public static void main(String[] args) {
		System.out.println("5의 절대값: " + abs(5));
		System.out.println("-10의 절대값: " + abs(-10));
	}
	
	static int abs(int value) {
		if(value < 0)
			value *= -1;
		return value;
	}
}