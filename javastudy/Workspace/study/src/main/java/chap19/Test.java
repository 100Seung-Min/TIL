package chap19;

public class Test {
	public static void main(String[] args) {
		Parent c = new Child();
		
		c.fun();
		System.out.println(c.a);
		String a = "abcd";
		System.out.println(a);
		string(a);
		System.out.println(a);
		
		int[][] b = {{1,2}, {1}, {1,2,3}};
		for(int[]d : b) {
			System.out.println(d.length);
		}
	}
	static void string(String a) {
		a.concat("efgh");
	}
	
	
}

class Parent{
	int a;
	static void fun() {
		System.out.println("±èµ¿Çö");
	}
}

class Child extends Parent{
	int b;
	
	static void fun() {
		System.out.println("±èÇü·Ï");
	}
	
	void fun2() {
		fun();
		super.fun();
	}
	
}