package chap15;

import java.util.*;
import chap15.pack.Pack01;
import chap15.pack.subpack.Pack2;

public class Test02 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt();
		System.out.println("Ãâ·Â : " + a);
		Pack01 pp = new Pack01();
		pp.x = a;
		pp.print();
		
		Pack2 p1 = new Pack2();
		p1.subprint();
	}
}
