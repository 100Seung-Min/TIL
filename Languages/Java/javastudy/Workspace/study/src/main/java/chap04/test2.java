package chap04;

import java.util.Scanner;

class Car{
	String name;
	String color;
	int seat;
	float gas_mileage;
	
	String carEnrollment() {
		System.out.print("�̸��Է� : ");
		Scanner in = new Scanner(System.in);
		name = in.nextLine();
		return name;
	}
	
	void carPrint() {
		System.out.println("������ȣ : " + name);
		System.out.println("���� : " + color);
		System.out.println("�¼� : " + seat + "�ν�");
		System.out.println("���� : " + gas_mileage);
		System.out.println();
	}
}

public class test2 {
	
	public static void main(String[] args) {
		Car car1 = new Car();
		car1.name = car1.carEnrollment();
		car1.color = "black";
		car1.seat = 5;
		
		Car car2 = new Car();
		car2.name = car2.carEnrollment();
		car2.color = "white";
		car2.seat = 4;
		
		car1.carPrint();
		car2.carPrint();
	}
}
