package chap16;

public class prob8 {
	public static void main(String[] args) {
		String str1 = "Hello world";
		String str2 =  new String("Hello world");
		if(str1 == str2) {
			System.out.println("���� �ν��Ͻ�");
		}
		else {
			System.out.println("�ٸ� �ν��Ͻ�");
		}
		if(str1.equals(str2)) {
			System.out.println("���� ���ڿ�");
		}
	}
}
