package chap13;

public class Test02 {
	public static void main(String[] args) {
		Food chicken = new Food("ġŲ", 18000);
		Food pizza = new Food("����", 28000);
		Food sushi = new Food("�ʹ似Ʈ", 22000);
		
		Food[] foods = { chicken, pizza, sushi };
		
		for(int i = 0; i < foods.length; i++) {
			foods[i].print();
		}
	}
}

class Food{
	String name;
	int price;
	
	Food(String name, int price){
		this.name = name;
		this.price = price;
	}
	
	void print() {
		System.out.println("name : " + name + ", price : " + price);
	}
}