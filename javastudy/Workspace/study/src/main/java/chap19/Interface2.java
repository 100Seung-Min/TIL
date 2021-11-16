package chap19;

public class Interface2 {
	public static void main(String[] args) {
		RealCal c = new RealCal();
		System.out.println(c.sum(2, 1));
		c.print();
		System.out.println(c.PI);
		Student s = new  Student();
		s.number = "한글입니다";
		System.out.println(s.number);
	}
}

interface Calculable{
	double PI = 3.14;
	int sum(int v1, int v2);
}

interface Printable{
	void print();
}

class AdvancedPrint implements Printable{
	public void print() {
		System.out.println("This is RealCal!");
	}
}

class RealCal implements Calculable, Printable{
	public int sum(int v1, int v2) {
		return v1 + v2;
	}
	
	public void print() {
		System.out.println("This is RealCal!");
	}
}

class Student<N>{
	N number;
	
	public static <N> N[] hello(N[] in) {
		return in;
	}
}