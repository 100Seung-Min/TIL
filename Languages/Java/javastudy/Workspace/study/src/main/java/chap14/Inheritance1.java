package chap14;

public class Inheritance1 {
	public static void main(String[] args) {
		Circle c1 = new Circle();
		Ball c2 = new Ball("������");
		
		System.out.println("�� : ");
//		c1.secret();
		c1.findRadius();
		c1.findArea();
		
		System.out.println("�� : ");
		c2.findRadius();
		c2.findcolor();
		c2.findArea();
		c2.findVolume();
	}
}

class Circle{
	private void secret() {
		System.out.println("���");
	}
	protected void findRadius() {
		System.out.println("������ : 10.0cm");
	}
	
	public void findArea() {
		System.out.println("���� : ������ * ������ * 3.14");
	}
}

class Ball extends Circle{
	private String color;
	
	public Ball(String color) {
		this.color = color;
	}
	
	@Override
	public void findArea() {
		
		findRadius();
		
		super.findArea();
		
		System.out.println("���� : 4 * ������ * ������ * 3.14");
	}
	
	public void findcolor() {
		System.out.println(color + "��");
	}
	
	public void findVolume() {
		System.out.println("���� : 4/3 * ������ * ������ * ������ * 3.14");
	}
}
