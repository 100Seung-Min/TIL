package chap06;

public class String1 {

	public static void main(String[] args) {
		String s1 = "pizza";
        String s2 = new String("pizza");
        String s3 = "chicken";
        String s4 = "Pizza";
        
        
        //���ڿ� s1�� s2�� ����Ű�� ������ ������ true, �ٸ��� false �� ��ȯ 
        // s1�� ���� s2�� �� ���ڿ�
        System.out.println(s1 == s2);
        System.out.println(s1.equals(s2)); // s1�̶� s2 �� T
        System.out.println(s1.equals(s3)); // s1 �̶� s3 �� F
        System.out.println(s1.equals(s4)); // F
        System.out.println(s1.equalsIgnoreCase(s4)); // T
        
        //���ڿ� s1�� s2�� ����Ű�� ������ ������ 0 , �ٸ��� 0 �̾ƴ� ����
        System.out.println(s1.compareTo(s2));
        System.out.println(s1.compareTo(s3));
        System.out.println(s1.compareTo(s4));
        System.out.println(s1.compareToIgnoreCase(s4));
		
	}

}
