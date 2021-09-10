package chap05;

class PeopleData{
	String name;
	char gender;
	int age;
	
	PeopleData(){
		this("없음", 0, '-');
	}
	
	PeopleData(String name, int age, char gender) {
		this.age = age;
		this.name = name;
		this.gender = gender;
	}
	PeopleData(String name) {
		this(name, 18, '남'); 
	}
}

public class Info1 {
	public static void main(String[] args) {
		PeopleData p1 = new PeopleData();
		PeopleData p2 = new PeopleData("홍길동");
		PeopleData p3 = new PeopleData("김철수", 15, '남');
		System.out.printf("이름 : %s, 나이 : %d, 성별 : %c\n", p1.name, p1.age, p1.gender);
		System.out.printf("이름 : %s, 나이 : %d, 성별 : %c\n", p2.name, p2.age, p2.gender);
		System.out.printf("이름 : %s, 나이 : %d, 성별 : %c\n", p3.name, p3.age, p3.gender);
	}
}
