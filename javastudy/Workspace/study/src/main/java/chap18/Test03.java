package chap18;

public class Test03 {
	public static void main(String[] args) {
		MyAnimal a1;
		Dog d1 = new Dog();
		Dog d2;
		
		a1 = (MyAnimal)d1;
		a1.sleep();
		a1.sound();
		
		d2 = (Dog)a1;
		d2.sleep();
		d2.sound();
		d2.like();
	}
}

class MyAnimal{
	String name;
	int leg;
	
	void sleep() {
		System.out.println("ÄðÄð");
	}
	
	void sound() {
		System.out.println("--");
	}
}

class Dog extends MyAnimal{
	void like() {
		System.out.println("»êÃ¥");
	}
	
	void sound() {
		System.out.println("¸Û¸Û");
	}
}