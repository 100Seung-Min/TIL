package chap05;

class PeopleData{
	String name;
	char gender;
	int age;
	
	PeopleData(){
		this("����", 0, '-');
	}
	
	PeopleData(String name, int age, char gender) {
		this.age = age;
		this.name = name;
		this.gender = gender;
	}
	PeopleData(String name) {
		this(name, 18, '��'); 
	}
}

public class Info1 {
	public static void main(String[] args) {
		PeopleData p1 = new PeopleData();
		PeopleData p2 = new PeopleData("ȫ�浿");
		PeopleData p3 = new PeopleData("��ö��", 15, '��');
		System.out.printf("�̸� : %s, ���� : %d, ���� : %c\n", p1.name, p1.age, p1.gender);
		System.out.printf("�̸� : %s, ���� : %d, ���� : %c\n", p2.name, p2.age, p2.gender);
		System.out.printf("�̸� : %s, ���� : %d, ���� : %c\n", p3.name, p3.age, p3.gender);
	}
}
