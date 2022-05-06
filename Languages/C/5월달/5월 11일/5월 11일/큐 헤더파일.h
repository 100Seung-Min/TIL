#ifndef ___IntQueue
#define ___IntQueue

typedef struct {
    int max;
    int num;
    int front;
    int rear;
    int* que;
}IntQueue;

//ť�� �ʱ�ȭ
int Initialize(IntQueue* q, int max);

//ť�� �����͸� ��ť
int Enque(IntQueue* q, int x);

//ť���� �����͸� ��ť
int Deque(IntQueue* q, int* x);

//ť���� �����͸� ��ũ
int Peek(const IntQueue* q, int* x);

//��� ������ ����
void Clear(IntQueue* q);

//ť�� �ִ�뷮
int Capacity(const IntQueue* q);

//ť�� ����� ������ ����
int Size(const IntQueue* q);

//ť�� ����ִ��� Ȯ��
int IsEmpty(const IntQueue* q);

//ť�� ���� á���� Ȯ��
int IsFull(const IntQueue* q);

//ť���� �˻�
int Search(const IntQueue* q, int x);

//��絥���͸� ���
void Print(const IntQueue* q);

//ť ����
void Terminate(IntQueue* q);
#endif // !___IntQueue