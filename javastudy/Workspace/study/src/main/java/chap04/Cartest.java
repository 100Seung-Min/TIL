package chap04;

class car_detail {
	int speed;
	boolean power = false;
	float gas_mileage;
	float car_fuel;
	float distance;
	void power() {
		power = !power;
		if (power) System.out.println("�ڵ��� �õ��� �մϴ�.");
		else System.out.println("�ڵ��� �õ��� ���ϴ�.");
	}
	
	int speedUp() {
		return speed+=10;
	}
	
	int speedDown() {
		return speed-=10;
	}
	
	void carPrint() {
		System.out.println("���� ���� �ӵ� : " + speed);
	}
	
	void fuel_calculation() {
		float num = car_fuel - distance / gas_mileage;
		if (distance / gas_mileage <= car_fuel) {
			System.out.print("���� ���� �մϴ�.");
			car_fuel = Math.round(num * 100) / 100.0f;
			System.out.println(" ���� ����� " + car_fuel + "L�Դϴ�.");
		}
	}
}

public class Cartest {
	public static void main(String[] args) {
		car_detail car1 = new car_detail();
		car1.gas_mileage = 14.3f;
		car1.car_fuel = 9.2f;
		car1.distance = 90.5f;
		car1.fuel_calculation();
		
		car1.power();
		car1.speed = 50;
		car1.speedDown();
		car1.carPrint();
		car1.power();
	}
}
