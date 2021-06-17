#ifndef ___IntQueue
#define ___IntQueue

typedef struct {
    int max;
    int num;
    int front;
    int rear;
    int* que;
}IntQueue;

//큐를 초기화
int Initialize(IntQueue* q, int max);

//큐에 데이터를 인큐
int Enque(IntQueue* q, int x);

//큐에서 데이터를 디큐
int Deque(IntQueue* q, int* x);

//큐에서 데이터를 피크
int Peek(const IntQueue* q, int* x);

//모든 데이터 삭제
void Clear(IntQueue* q);

//큐의 최대용량
int Capacity(const IntQueue* q);

//큐에 저장된 데이터 개수
int Size(const IntQueue* q);

//큐가 비어있는지 확인
int IsEmpty(const IntQueue* q);

//큐가 가득 찼는지 확인
int IsFull(const IntQueue* q);

//큐에서 검색
int Search(const IntQueue* q, int x);

//모든데이터를 출력
void Print(const IntQueue* q);

//큐 종료
void Terminate(IntQueue* q);
#endif // !___IntQueue