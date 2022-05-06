package dao;

import java.util.ArrayList;

import dto.Book;

public class BookRepository {
	private ArrayList<Book> listOfBook = new ArrayList<Book>();
	
	public BookRepository() {
		Book book1 = new Book();
		book1.setDescription("���峪 PPT ������ ���� �� �ֳ���? �׷��� ���� �����ϴ�. ���� �ٷ� �������� ���ۿ� �����غ�����. ���� ���� ��ǻ�Ͱ� ��� �������ϴ�. �ڵ�� ���� ȭ���� �ٷ� ������ ����...");
		book1.setAuthor("Ȳ��ȣ");
		book1.setName("[Hello Coding] HTML5+CSS3");
		book1.setUnitPrice(15000);
		book1.setPublisher("�Ѻ��̵��");
		
		Book book2 = new Book();
		book2.setDescription("��ü ������ �ٽɰ� �ڹ��� ������ ����� ����� �ٷ�鼭�� �ʺ��ڰ� ���� �н��� �� �ְ� �����߽��ϴ�. �ð�ȭ ������ Ȱ���� ���� ����� �������� ���� �ٽ� �ڵ带 ���� ����� ����...");
		book2.setAuthor("������");
		book2.setName("[IT �����] ���� ���� �ڹ� ���α׷���");
		book2.setUnitPrice(27000);
		book2.setPublisher("�Ѻ���ī����");
		
		Book book3 = new Book();
		book3.setDescription("�������� �ܼ��� ��� ����� ������ �ͺ��� ��� �����ϰ� �����ϴ����� �� �߿��մϴ�. ������ ������ �ٿ��ִ� �����δ� ���� ���߿��� �������� ����� Ȱ���� �� �����ϴ�...");
		book3.setAuthor("�ϼ����� ����ġ, ������ ��Ÿ��, ��Ű ������(����ö, ���μ�)");
		book3.setName("[IT �����] ������4 �Թ�");
		book3.setUnitPrice(27000);
		book3.setPublisher("�Ѻ��̵��");
		
		listOfBook.add(book1);
		listOfBook.add(book2);
		listOfBook.add(book3);
	}
	
	public ArrayList<Book> getAllBooks(){
		return listOfBook;
	}
}

