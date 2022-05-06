package chap05;

public class Test {
	public static void main(String[] args) {
		String s1 = "Hi, Java!";
		String s2 = "Hi, Java!";
		String s3 = new String("Hi, Java!");
		String s4 = new String("Hi, Java!");
		
//		System.out.println(s1 == s2);
//		System.out.println(s1 == s3);
//		System.out.println(s4 == s3);
		
		s1 = s3;
//		System.out.println(s1 == s3);
	}
}
