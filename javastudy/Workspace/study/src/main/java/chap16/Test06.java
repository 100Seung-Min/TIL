package chap16;

public class Test06 {
	public static void main(String[] args) {
		int sum = 0;
		int num = 0;
		int sw = 0;
		while(sum < 100) {
			num++;
			if(sw == 0) {
				sum -= num;
				sw = 1;
			}
			else {
				sum += num;
				sw = 0;
			}
		}
		System.out.println("num = " + num);
		System.out.println("sum = " + sum);
	}
}
