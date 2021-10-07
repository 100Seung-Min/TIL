package chap12;

public class Test01 {
	public static void main(String[] args) {
		int x = 1;
		int y = 2;
		int z = 3;
		int temp;
		System.out.printf("x = %d, y = %d, z = %d\nº¯°æÈÄ\n", x, y, z);
		temp = x;
		x = y;
		y = z;
		z = temp;
		System.out.printf("x = %d, y = %d, z = %d", x, y, z);		
	}
}
