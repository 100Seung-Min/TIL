package chap16;

public class Test05 {
	public static void main(String[] args) {
		int[][] arr = {
				{2,3,4,5,6},
				{4,6,8,10,12},
				{6,9,12,15,18},
				{8,12,16,20,24}
		};
		int sum = 0;
		int cnt = 0;
		for(int i = 0; i<arr.length;i++) {
			for(int j = 0; j<arr[i].length - 1;j++) {
				if(j == 0) {
					int k = arr[i][j];
					arr[i][j] = arr[i][j + 4];
					arr[i][j + 4] = k;
				}
				else {
					sum += arr[i][j];
					cnt++;
				}
			}
		}
		System.out.println("2-4열의 total = " + sum);
		System.out.println("2-4열의 average = " + (sum / (float)cnt));
		System.out.println();
		for(int i[] : arr) {
			for(int j : i) {
				System.out.printf("%d\t", j);
			}
			System.out.println();
		}
	}
}
