package chap16;

import java.util.Scanner;

public class Test04 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		char com = (char)((int)(Math.random() * 36 + 65));
		int cnt = 0;
		while(true) {
			cnt++;
			System.out.println("A 부터 Z사이의 값을 입력하세요:");
			char a = in.next().charAt(0);
			if(a == com) {
				System.out.println("맞췄습니다.");
				System.out.println("시도횟수는 " + cnt + "번 입니다.");
				break;
			}
			else if(a > com) {
				System.out.println("더 작은 문자를 입력하세요.");
			}
			else if(a < com) {
				System.out.println("더 큰 문자를 입력하세요.");
			}
		}
	}
}
