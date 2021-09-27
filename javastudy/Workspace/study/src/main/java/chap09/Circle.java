package chap09;

public class Circle {
	public static void main(String[] args) {
		Circle_init[] c = new Circle_init[5];
		for(int i = 0; i < c.length; i++) {
			c[i] = new Circle_init(i + 1.0);
			System.out.printf("¹ÝÁö¸§ : %.1f, ³ÐÀÌ : %.2f\n", c[i].radius, c[i].findArea());
		}
	}
}

class Circle_init{
	double radius;

	
	public Circle_init(double radius) {
		this.radius = radius;
	}
	
	double findArea() {
		return 3.14 * radius * radius;
	}
}
