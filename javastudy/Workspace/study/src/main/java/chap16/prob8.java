package chap16;

public class prob8 {
	public static void main(String[] args) {
		String str1 = "Hello world";
		String str2 =  new String("Hello world");
		if(str1 == str2) {
			System.out.println("같은 인스턴스");
		}
		else {
			System.out.println("다른 인스턴스");
		}
		if(str1.equals(str2)) {
			System.out.println("같은 문자열");
		}
	}
}
