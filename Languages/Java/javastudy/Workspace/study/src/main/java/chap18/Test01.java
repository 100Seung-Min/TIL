package chap18;

public class Test01 {

}

class Person{
	String name = "���";
	
	void whoami() {
		System.out.println("���� ����̴�.");
	}
}

class Student extends Person {
	int number = 7;
	
	void work() {
		System.out.println("���� �����Ѵ�.");
	}
}
