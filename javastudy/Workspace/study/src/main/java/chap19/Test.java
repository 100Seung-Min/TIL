package chap19;

public class Test {
	static double radious;
	static double findArea() {
		return 3.14*radious*radious;
	}
	static void show(double x, double y) {
		System.out.printf("반지름 = %.1f, 넓이 = %.1f\n",x,y );
	}
	public static void main(String[] args) {
		radious = 10;
		double area = findArea();
		show(radious, area);
	}
}
