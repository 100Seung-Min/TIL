package que;

public class cycleque {
	static int MAX_SIZE = 5;
	static class Queuetype{
		static int[] queue = new int[MAX_SIZE];
		static int front, rear;
	}
	
	static void init(Queuetype q) {
		q.front = q.rear = 0;
	}
	
	static int enqueue(Queuetype q, int item) {
		if((q.rear+1)%MAX_SIZE == q.front) {
			System.out.println("큐가 포화 상태입니다");
			System.exit(1);
		}
		q.rear = (q.rear+1)%MAX_SIZE;
		q.queue[q.rear] = item;
		return q.queue[q.rear];
	}
	
	static int dequeue(Queuetype q) {
		if(q.front == q.rear) {
			System.out.println("큐가 공백상태입니다");
			System.exit(1);
		}
		q.front = (q.front+1)%MAX_SIZE;
		return q.queue[q.front];
	}
	
	public static void main(String[] args) {
		Queuetype q1 = new Queuetype();
		init(q1);
		System.out.println(enqueue(q1, 5));
		System.out.println(enqueue(q1, 10));
		System.out.println(enqueue(q1, 4));
		System.out.println(enqueue(q1, 7));
		System.out.println(dequeue(q1));
		System.out.println(dequeue(q1));
		System.out.println(dequeue(q1));
		System.out.println(dequeue(q1));
	}
}
