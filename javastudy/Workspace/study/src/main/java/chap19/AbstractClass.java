package chap19;

public class AbstractClass {
	public static void main(String[] args) {
		Circle c = new Circle(3);
		c.draw();
		System.out.printf("���� ���̴� %.1f\n", c.findArea());
		
		Rectangle r = new Rectangle(3, 4);
		r.draw();
		System.out.printf("�簢���� ���̴� %.1f\n", r.findArea());		
	}
}


abstract class Shape{
	double pi = 3.14;
	
	abstract void draw();
	
	public double findArea() {
		return 0.0;
	}
}

class Circle extends Shape{
	int radius;
	
	public Circle(int radius) {
		this.radius = radius;
	}
	
	public void draw() {
		System.out.println("���� �׸���.");
	}
	
	public double findArea() {
		return pi * radius * radius;
	}
}

class Rectangle extends Shape{
	int horizontal;
	int vertical;
	
	public Rectangle(int horizontal, int vertical){
		this.horizontal = horizontal;
		this.vertical = vertical;
	}
	
	public void draw() {
		System.out.println("�簢���� �׸���.");
	}
	
	public double findArea() {
		return horizontal * vertical;
	}
}