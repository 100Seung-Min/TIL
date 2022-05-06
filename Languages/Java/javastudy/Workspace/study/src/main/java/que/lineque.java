package que;

public class lineque {
	static int QUEUESIZE = 5;
	static int rear = -1;
	static int front = -1;
	static int[] queue = new int[QUEUESIZE];
	public static void main(String[] args) {
		System.out.println(enqueue(10));
		System.out.println(enqueue(20));
		System.out.println(enqueue(30));
		System.out.println(enqueue(40));
		System.out.println(enqueue(50));
		System.out.println(enqueue(60));
		System.out.println(dequeue());
		System.out.println(dequeue());
	}
	
	public static int enqueue(int data) {
		if (rear == QUEUESIZE - 1) {
			System.out.println("queue is full");
		}
		else return queue[++rear] = data;
		return 0;
	}
	
	public static int dequeue() {
		if (rear == -1 && front == -1) {
			System.out.println("queue is empty");
		}
		else return queue[++front];
		return 0;
	}
}
