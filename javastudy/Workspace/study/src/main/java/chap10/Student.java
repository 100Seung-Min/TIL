package chap10;

import java.util.Scanner;

public class Student {
	public static void main(String[] args) {
		int numOfStudents = 0;
		int[] scores;
		Scanner in = new Scanner(System.in);
		numOfStudents = in.nextInt();
		scores = new int[numOfStudents];
		
		for(int i = 0; i < scores.length; i++) {
			scores[i] = in.nextInt();
		}
	}
}
