package chap04;

class car_detail {
	int speed;
	boolean power = false;
	float gas_mileage;
	float car_fuel;
	float distance;
	void power() {
		power = !power;
		if (power) System.out.println("자동차 시동을 켭니다.");
		else System.out.println("자동차 시동을 끕니다.");
	}
	
	int speedUp() {
		return speed+=10;
	}
	
	int speedDown() {
		return speed-=10;
	}
	
	void carPrint() {
		System.out.println("현재 주행 속도 : " + speed);
	}
	
	void fuel_calculation() {
		float num = car_fuel - distance / gas_mileage;
		if (distance / gas_mileage <= car_fuel) {
			System.out.print("운행 가능 합니다.");
			car_fuel = Math.round(num * 100) / 100.0f;
			System.out.println(" 남은 연료는 " + car_fuel + "L입니다.");
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
