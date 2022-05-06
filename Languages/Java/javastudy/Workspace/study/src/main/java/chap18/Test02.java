package chap18;

public class Test02 {
	public static void main(String[] args) {
		Vehicle v = new Car();
		System.out.println(v.name);
		v.whoami();
		v.move();
		
		Car c = new Car();
		System.out.println(c.name);
		c.whoami();
		c.move();
		
		System.out.println(v instanceof Car);
		System.out.println(v instanceof Vehicle);
		System.out.println(c instanceof Car);
		System.out.println(c instanceof Vehicle);
	}
}

class Vehicle{
	String name = "탈 것";
	
	void whoami(){
		System.out.println("나는 탈 것 이다.");
	}
	
	static void move() {
		System.out.println("이동하다.");
	}
}

class Car extends Vehicle{
	String name = "자동차";
	
	void whoami() {
		System.out.println("나는 자동차이다.");
	}
	
	static void move(){
		System.out.println("달리다.");
	}
}