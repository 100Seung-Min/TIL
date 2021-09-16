package chap08;

public class Array3 {
	public static void main(String[] args) {
		int[] one2five = {0,1,2,3,4};
		int sum = 0;
		for(int x = 0; x < one2five.length; x++) {
			one2five[x]++;
		}
		for(int x : one2five) {
			sum += x;
		}
		System.out.println("ЦђБе" + sum / 5.0);
	}
}
