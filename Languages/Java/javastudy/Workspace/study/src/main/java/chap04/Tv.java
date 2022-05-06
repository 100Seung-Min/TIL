package chap04;

class Channel{
	boolean power = false;
	int volume;
	int channel;
	final int MAX_VOLUME = 100;
	final int MIN_VOLUME = 0;
	
	void turnOnOff() {
//		power = power? false : true;
		power = !power;
	}
	
	void channelDown() {
		channel++;
	}
	
	void channelUp() {
		channel--;
	}
	
	void volumeUp() {
		if (volume < MAX_VOLUME) volume++;
		else System.out.println("�� �̻� ������ ���� �� �����ϴ�.");
	}
	void volumeDown() {
		if (volume > MIN_VOLUME) volume--;
		else System.out.println("�� �̻� ������ ���� �� �����ϴ�.");
	}
}

public class Tv {
	public static void main(String[] args) {
		Channel tv1 = new Channel();
		tv1.turnOnOff();
		tv1.channel = 10;
		tv1.volume = 99;
		tv1.channelDown();
		tv1.volumeUp();
		tv1.volumeUp();
		System.out.println("���� ä����" + tv1.volume);
		System.out.println("���� ������" + tv1.channel);
	}
}
