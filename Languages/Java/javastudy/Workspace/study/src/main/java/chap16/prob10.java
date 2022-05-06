package chap16;

public class prob10 {
	public static void main(String[] args) {
		Student s = new Student("ȫ�浿", 1, 1, 100, 60, 76);
		System.out.println("�̸� :" + s.name);
		System.out.println("���� :" + s.getTotal());
		System.out.println("��� :" + s.getAverage());
	}
}

class Student{
	String name;
	int ban;
	int no;
	int kor;
	int eng;
	int math;
	
	Student(String name,int ban,int no,int kor,int eng,int math){
		this.name = name;
		this.ban = ban;
		this.no = no;
		this.kor = kor;
		this.eng = eng;
		this.math = math;
	}
	String info() {
		int sum = kor+eng+math;
		return name + "," + ban + "," + no + "," + kor + "," + eng + "," + math + "," + sum + "," + (Math.round(sum/3f * 10) / 10f);
	}
	int getTotal() {
		return kor+eng+math;
	}
	
	float getAverage() {
		return (Math.round(getTotal()/3f * 10) / 10f);
	}
}
