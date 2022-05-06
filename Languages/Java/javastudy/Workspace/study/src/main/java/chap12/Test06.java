package chap12;

public class Test06 {
	public static void main(String[] args) {
		Dragon d1 = new Dragon();
		Soldier[] soldier = new Soldier[10];
		
		for(int i = 0; i < soldier.length; i++) {
			soldier[i] = new Soldier();
			d1.status(soldier[i].attack);
		}
		System.out.println("µå·¡°ï hp : " + d1.hp);
	}
}
