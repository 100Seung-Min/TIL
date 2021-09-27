package chap09;

public class Sum {
	public static void main(String[] args) {
		Sum(1,2,3,4,5);
		Sum(10, 20, 30);
	}
	
	static void Sum(int...x) {
		int sum = 0;
		for(int i : x) {
			sum += i;
		}
		System.out.println(sum);
	}
}
