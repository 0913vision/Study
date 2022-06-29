#include <iostream>
using namespace std;

typedef struct {
    int data;
} Node;

typedef struct _CircularQueue {
    Node* nodes;
    unsigned int capacity;
    unsigned int front;
    unsigned int rear;
} CircularQueue;

bool isEmpty(CircularQueue *q) {
    return (q->front) == (q->rear);
}

bool isFull(CircularQueue *q) {
    if(q->front < q->rear)
        return q->rear - q->front == q->capacity;
    else
        return q->rear+1 == q->front;
}

void dequeue(CircularQueue *q) {
    int pop = q->front;
    if(isEmpty(q)) {
        cout << "Queue is Empty.\n";
        return;
    }


    if(q->front == q->capacity) q->front = 0;
    else q->front++;

    cout << "The pop element is " << q->nodes[pop].data << "\n";
    return;
}

void enqueue(CircularQueue *q, int data) {
    int push = 0;

    if(isFull(q)) {
        cout << "Queue is Full.\n";
        return;
    }

    if(q->rear == q->capacity) {
        push = q->rear;
        q->rear = 0; // 1칸 키운것
    }
    else {
        push = q->rear++;
    }
    q->nodes[push].data = data;
    return;
}

void print(CircularQueue* q) {
    int index = q->front;
    cout << "Queue elements\n";

    while(index != q->rear) {
        // index는 내가 출력할 원소의 인덱스.
        if(index == q->capacity+1) {
            index = 0;
        }
        cout << q->nodes[index].data << " ";
        index++;
    }
    cout << "\n";
    return;
}

void freeQueue(CircularQueue* q) {
    delete q->nodes;
    delete q;
}

int main() {
    int menu, data;

    CircularQueue *q;
    unsigned int size;

    cout << "Enter the queue size : ";
    cin >> size;

    q = new CircularQueue[1];
    q->nodes = new Node[size+1];
    q->capacity = size;
    q->front = 0;
    q->rear = 0;

    bool flag = true;
    while(flag) {
        cout << "1. Push\n2. Pop\n3. Print\n4. Exit\n=================\nEnter the number : ";
        cin >> menu;
        switch(menu) {
            case 1:
                cout << "Enter the element number : ";
                cin >> data;
                enqueue(q, data);
                break;
            case 2:
                dequeue(q);
                break;
            case 3:
                print(q);
                break;
            case 4:
                flag = false;
                break;
            default:
                cout << "Error. Enter the element number : ";
        }
    }
    freeQueue(q);

    return 0;
}