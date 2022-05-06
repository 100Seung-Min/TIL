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
		System.out.println("이름 : " + name);
		System.out.println("국어점수 : " + kor);
		System.out.println("영어점수 : " + eng);
		System.out.println("수학점수 : " + math);
		System.out.println("합계 : " + getTotal());
		System.out.println("평균 : " + Average());
	}
	
	void getScore() {
		switch ((int)(Average() / 10)) {
		case 10, 9 -> System.out.println("학점 : A" );
		case 8, 7, 6 -> System.out.println("학점 : B");
		default ->{ 
			System.out.println("학점 : C");
			System.out.println("공부가 필요합니다.");}
		}
	}
}

public class Student {
	public static void main(String[] args) {
		Student_detail s1 = new Student_detail();
		s1.name = "홍길동";
		s1.kor = 70;
		s1.eng = 30;
		s1.math = 75;
		s1.print();
		s1.getScore();
	}
}
