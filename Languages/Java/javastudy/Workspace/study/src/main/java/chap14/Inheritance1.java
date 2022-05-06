package chap14;

public class Inheritance1 {
	public static void main(String[] args) {
		Circle c1 = new Circle();
		Ball c2 = new Ball("빨강색");
		
		System.out.println("원 : ");
//		c1.secret();
		c1.findRadius();
		c1.findArea();
		
		System.out.println("공 : ");
		c2.findRadius();
		c2.findcolor();
		c2.findArea();
		c2.findVolume();
	}
}

class Circle{
	private void secret() {
		System.out.println("비밀");
	}
	protected void findRadius() {
		System.out.println("반지름 : 10.0cm");
	}
	
	public void findArea() {
		System.out.println("넓이 : 반지름 * 반지름 * 3.14");
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
		
		System.out.println("넓이 : 4 * 반지름 * 반지름 * 3.14");
	}
	
	public void findcolor() {
		System.out.println(color + "공");
	}
	
	public void findVolume() {
		System.out.println("부피 : 4/3 * 반지름 * 반지름 * 반지름 * 3.14");
	}
}
