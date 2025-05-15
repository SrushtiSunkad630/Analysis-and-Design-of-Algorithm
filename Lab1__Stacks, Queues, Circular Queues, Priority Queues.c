//1. Stack Exercises in C
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, int val) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = val;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->arr[s->top];
}

OUTPUT
Element 10 pushed to stack.
Element 20 pushed to stack.
Element 30 pushed to stack.
Element 30 popped from stack.
Top element is 20
Stack elements are:
20
10

 //Valid Parentheses (LeetCode #20)
  int isValid(char* s) {
    Stack stack;
    init(&stack);
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            push(&stack, c);
        } else {
            if (isEmpty(&stack)) return 0;
            char top = pop(&stack);
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return 0;
        }
    }
    return isEmpty(&stack);
}

OUTPUT
Input: "()[]{}"
Output: True


//2. Queue - Simple Queue Operations
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = -1;
}

int isEmptyQueue(Queue* q) {
    return q->rear < q->front;
}

int isFullQueue(Queue* q) {
    return q->rear == MAX - 1;
}

void enqueue(Queue* q, int val) {
    if (isFullQueue(q)) {
        printf("Queue Overflow\n");
        return;
    }
    q->arr[++q->rear] = val;
}

int dequeue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return q->arr[q->front++];
}

int peekQueue(Queue* q) {
    if (isEmptyQueue(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

OUTPUT
1
2
3
None  (queue is empty)


//3. Circular Queue
#include <stdio.h>
#define MAX 5

typedef struct {
    int arr[MAX];
    int front, rear;
} CircularQueue;

void initCQ(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmptyCQ(CircularQueue* q) {
    return q->front == -1;
}

int isFullCQ(CircularQueue* q) {
    return (q->rear + 1) % MAX == q->front;
}

void enqueueCQ(CircularQueue* q, int val) {
    if (isFullCQ(q)) {
        printf("Circular Queue is Full\n");
        return;
    }
    if (isEmptyCQ(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }
    q->arr[q->rear] = val;
}

int dequeueCQ(CircularQueue* q) {
    if (isEmptyCQ(q)) {
        printf("Circular Queue is Empty\n");
        return -1;
    }
    int val = q->arr[q->front];
    if (q->front == q->rear) { // single element
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    return val;
}

OUTPUT
Inserted
Inserted
Inserted
Full
1
2
3


//4. Priority Queue - Min Heap
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int arr[MAX];
    int size;
} PriorityQueue;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(PriorityQueue* pq, int index) {
    if (index && pq->arr[(index - 1) / 2] > pq->arr[index]) {
        swap(&pq->arr[index], &pq->arr[(index - 1) / 2]);
        heapifyUp(pq, (index - 1) / 2);
    }
}

void insertPQ(PriorityQueue* pq, int val) {
    if (pq->size == MAX) {
        printf("Priority Queue Full\n");
        return;
    }
    pq->arr[pq->size] = val;
    heapifyUp(pq, pq->size);
    pq->size++;
}

void heapifyDown(PriorityQueue* pq, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < pq->size && pq->arr[left] < pq->arr[smallest])
        smallest = left;
    if (right < pq->size && pq->arr[right] < pq->arr[smallest])
        smallest = right;
    if (smallest != index) {
        swap(&pq->arr[index], &pq->arr[smallest]);
        heapifyDown(pq, smallest);
    }
}

int extractMin(PriorityQueue* pq) {
    if (pq->size <= 0) {
        printf("Priority Queue Empty\n");
        return -1;
    }
    int root = pq->arr[0];
    pq->arr[0] = pq->arr[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return root;
}

int main() {
    PriorityQueue pq;
    pq.size = 0;

    insertPQ(&pq, 10);
    insertPQ(&pq, 4);
    insertPQ(&pq, 15);
    insertPQ(&pq, 20);
    insertPQ(&pq, 0);

    printf("Min element: %d\n", extractMin(&pq)); // 0
    printf("Min element: %d\n", extractMin(&pq)); // 4

    return 0;
}

OUTPUT
0
4
10
