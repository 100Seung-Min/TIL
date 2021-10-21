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
	String name = "Ż ��";
	
	void whoami(){
		System.out.println("���� Ż �� �̴�.");
	}
	
	static void move() {
		System.out.println("�̵��ϴ�.");
	}
}

class Car extends Vehicle{
	String name = "�ڵ���";
	
	void whoami() {
		System.out.println("���� �ڵ����̴�.");
	}
	
	static void move(){
		System.out.println("�޸���.");
	}
}