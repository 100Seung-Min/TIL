package chap13;

public class Test04 {
	public static void main(String[] args) {
		Account a = new Account("123-45", "±èÃ¶¼ö", 10000);
		Account b = new Account("567-89", "¹Ú¸íÈñ", 10000);
		
		System.out.println(a.getAno() + " " + a.getOwner() + " " +a.getBalance());
		System.out.println(b.getAno() + " " + b.getOwner() + " " +b.getBalance());
		a.transfer(b, 3000);
		System.out.println("°èÁÂ ¼Û±Ý ÈÄ");
		System.out.println(a.getAno() + " " + a.getOwner() + " " +a.getBalance());
		System.out.println(b.getAno() + " " + b.getOwner() + " " +b.getBalance());
	}
}
