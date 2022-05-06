package chap11;

import java.util.Scanner;

public class Test07 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int com = (int)(Math.random() * 10) + 1;
		int user;
		int test = 0;
		for(;;) {
			System.out.print("1 과 10사이의 값을 입력하세요 : ");
			user = in.nextInt();
			if(user == com){
				System.out.println("맞췄습니다.");
				test++;
				break;
			}
			else if(user > com) {
				System.out.println("더 작은 수를 입력하세요.");
				test++;
			}
			else {
				System.out.println("더 큰 수를 입력하세요.");
				test++;
			}
		}
		System.out.println("시도횟수는 " + test + "번입니다.");
	}
}
