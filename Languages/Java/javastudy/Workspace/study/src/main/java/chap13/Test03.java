package chap13;

public class Test03 {
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

class Account{
	private String ano;
	private String owner;
	private int balance;
	
	Account(String ano, String owner, int balance){
		this.ano = ano;
		this.owner = owner;
		this.balance = balance;
	}

	public String getAno() {
		return ano;
	}

	public void setAno(String ano) {
		this.ano = ano;
	}

	public String getOwner() {
		return owner;
	}

	public void setOwner(String owner) {
		this.owner = owner;
	}

	public int getBalance() {
		return balance;
	}

	public void setBalance(int balance) {
		this.balance = balance;
	}
	
	void transfer(Account target, int amount) {
		if(balance - amount < 0) {
			System.out.println("ÀÜ¾×ÀÌ ¾ø½À´Ï´Ù.");
		}
		else {
			balance -= amount;
			target.balance += amount;
		}
	}
}