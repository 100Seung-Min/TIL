package chap04;

class Student_detail {
	String name;
	int kor;
	int eng;
	int math;
	
	int getTotal() {
		return kor + eng + math;
	}
	
	float Average() {
		float avg = getTotal() / 3.0f;
		return Math.round(avg * 100) / 100.0f;
	}
	
	void print() {
		System.out.println("�̸� : " + name);
		System.out.println("�������� : " + kor);
		System.out.println("�������� : " + eng);
		System.out.println("�������� : " + math);
		System.out.println("�հ� : " + getTotal());
		System.out.println("��� : " + Average());
	}
	
	void getScore() {
		switch ((int)(Average() / 10)) {
		case 10, 9 -> System.out.println("���� : A" );
		case 8, 7, 6 -> System.out.println("���� : B");
		default ->{ 
			System.out.println("���� : C");
			System.out.println("���ΰ� �ʿ��մϴ�.");}
		}
	}
}

public class Student {
	public static void main(String[] args) {
		Student_detail s1 = new Student_detail();
		s1.name = "ȫ�浿";
		s1.kor = 70;
		s1.eng = 30;
		s1.math = 75;
		s1.print();
		s1.getScore();
	}
}
