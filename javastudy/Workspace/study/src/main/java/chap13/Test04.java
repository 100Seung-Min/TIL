package chap13;

public class Test04 {
	public static void main(String[] args) {
		Account a = new Account("123-45", "��ö��", 10000);
		Account b = new Account("567-89", "�ڸ���", 10000);
		
		System.out.println(a.getAno() + " " + a.getOwner() + " " +a.getBalance());
		System.out.println(b.getAno() + " " + b.getOwner() + " " +b.getBalance());
		a.transfer(b, 3000);
		System.out.println("���� �۱� ��");
		System.out.println(a.getAno() + " " + a.getOwner() + " " +a.getBalance());
		System.out.println(b.getAno() + " " + b.getOwner() + " " +b.getBalance());
	}
}
