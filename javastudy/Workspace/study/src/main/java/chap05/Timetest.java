package chap05;

public class Timetest {
	public static void main(String[] args) {
		Time t1 = new Time();
		t1.setHour(9);
		t1.setMinute(14);
		t1.setSecond(30);
		System.out.println(t1.getHour()+ "Ω√" + t1.getMinute()+ "∫–" + t1.getSecond() + "√ ");
	}
}

class Time{
	private int hour;
	private int minute;
	private float second;
	void setHour(int hour) {
		if(hour<0||hour>23)
			return;
		this.hour = hour;
	}
	int getHour() {
		return hour;
	}
	void setMinute(int minute) {
		if(minute<0||minute>59)
			return;
		this.minute = minute;
	}
	int getMinute() {
		return minute;
	}
	void setSecond(float second) {
		if(second<0||second>59)
			return;
		this.second = second;
	}
	float getSecond() {
		return second;
	}
}
