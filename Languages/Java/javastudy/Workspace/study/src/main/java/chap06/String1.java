package chap06;

public class String1 {

	public static void main(String[] args) {
		String s1 = "pizza";
        String s2 = new String("pizza");
        String s3 = "chicken";
        String s4 = "Pizza";
        
        
        //문자열 s1과 s2가 가리키는 내용이 같으면 true, 다르면 false 를 반환 
        // s1은 원본 s2는 비교 문자열
        System.out.println(s1 == s2);
        System.out.println(s1.equals(s2)); // s1이랑 s2 비교 T
        System.out.println(s1.equals(s3)); // s1 이랑 s3 비교 F
        System.out.println(s1.equals(s4)); // F
        System.out.println(s1.equalsIgnoreCase(s4)); // T
        
        //문자열 s1과 s2가 가리키는 내용이 같으면 0 , 다르면 0 이아닌 정수
        System.out.println(s1.compareTo(s2));
        System.out.println(s1.compareTo(s3));
        System.out.println(s1.compareTo(s4));
        System.out.println(s1.compareToIgnoreCase(s4));
		
	}

}
