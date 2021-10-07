package chap12;

public class Test03 {
	public static void main(String[] args) {
		int sum = 0;
		int s = 1;
		int num = 0;
		for(;sum < 100;) {
			num++;
			if(s == 1) {
				sum += num;
				s = 0;
			}
			else {
				sum -= num;
				s = 1;
			}
		}
		System.out.println("num = " + num );
		System.out.println("sum = " + sum );
	}
}
