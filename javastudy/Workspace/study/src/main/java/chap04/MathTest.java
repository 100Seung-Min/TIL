package chap04;

class MyMath {
	float a,b;
	float add() {return a+b;};
	float subtract() {return a-b;};
	float multiply() {return a*b;};
	float divide() {return a/b;};
	
	static float add(float a, float b) {return a+b;};
	static float subtract(float a, float b) {return a-b;};
	static float multiply(float a, float b) {return a*b;};
	static float divide(float a, float b) {return a/b;};
}

public class MathTest {
	public static void main(String[] args) {
		System.out.println(MyMath.add(200f, 100f));
		System.out.println(MyMath.subtract(200f, 100f));
		System.out.println(MyMath.multiply(200f, 100f));
		System.out.println(MyMath.divide(200f, 100f));
		
		MyMath m = new MyMath();
		m.a = 200f;
		m.b = 100f;
		System.out.println(m.add());
		System.out.println(m.subtract());
		System.out.println(m.multiply());
		System.out.println(m.divide());
	}
}
