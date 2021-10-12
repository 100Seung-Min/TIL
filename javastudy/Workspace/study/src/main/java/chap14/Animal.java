package chap14;

public class Animal {
	String eye;
	String mouth;
	
	void eat() {};
	void sleep() {};
}

class Eagle extends Animal{
	String wing;
	
	void fly() {};
}

class Tiger extends Animal{
	String leg;
	
	void run() {};
}

class Goldfish extends Animal{
	String fin;
	
	void swim() {};
}
