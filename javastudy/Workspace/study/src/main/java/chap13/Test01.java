package chap13;

public class Test01 {
	public static void main(String[] args) {
		Miner m1 = new Miner("����");
		Miner m2 = new Miner("�۷θ���");
		m1.mine(3);
		m2.mine(2);
		m1.print();
		m2.print();
	}
}

class Miner{
	String name;
	int coins;
	
	Miner(String name){
		this.name = name;
	}
	
	public void mine(int n) {
		this.coins += n;
	}
	
	public void print() {
		System.out.println("name : " + name + ", coins : " + coins);
	}
}