package chap12;

public class Test05 {

}

class Dragon{
	int attack = 20;
	int hp = 100;
	
	int attack_power() {
		return attack;
	}
	void status(int n) {
		hp -= n;
		if(hp <= 0)
			System.out.println("ав╬З╫ю╢о╢ы.");
	}
}

class Soldier{
	int attack = 10;
	int hp = 60;
	
	int attack_power() {
		return attack;
	}
	void status(int n) {
		hp -= n;
		if(hp <= 0) {
			System.out.println("ав╬З╫ю╢о╢ы.");
		}
	}
}

