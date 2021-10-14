package chap15;

public class Test01 {
	public static void main(String[] args) {
		Point3D p1 = new Point3D();
		p1.getLocation();
		Point3D p2 = new Point3D(1,2,3);
		p2.getLocation();
	}
}

class Point{
	int x,y;
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
	void getLocation() {
		System.out.println("x : " + x + ", y : " + y);
	}
}

class Point3D extends Point{
	int z;
	
	Point3D(){
		this(10,20,30);
	}
	
	Point3D(int x, int y, int z){
		super(x, y);
		this.z = z;
	}
	void getLocation() {
		System.out.println("x : " + x + ", y : " + y + ", z : " + z);
	}
}