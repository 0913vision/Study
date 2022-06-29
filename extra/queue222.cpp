#include <iostream>
using namespace std;

int n;
int front=0;
int back=0;
int* queue;

void inputQueue(int data);
void deleteQueue();
void printQueue();

bool isFull();
bool isEmpty();


int main() {
    cout << " enter Circle Queue size :";
    cin >> n;
    queue = new int[n+1];

    while (1) {
        int menu, data;
        cout << "1. insert 2. delete"<<endl;
        cin >> menu;

        switch (menu) {
            case 1:
                printf("삽입할 데이터 입력 : ");
                cin>>data;
                inputQueue(data);
                break;
            case 2:
                //input 추가
                deleteQueue();
                break;
            default:
                cout<<"wrong input, try again"<<endl;
                break;
        }
    }
}

void inputQueue(int data){
    int index = 0;
    if(isFull()){
        cout<<"queue full"<<endl;
    }else{ // queue is not full.
        if(back == n) {
            index = back;
            back = 0;
        }
        else index = back++;

        queue[index] = data;
    }
}

void deleteQueue() {
    int index = front;
    if(isEmpty()){
        cout<<"queue is empty"<<endl;
    }else{
        cout << queue[index];
        if(front == n) front = 0;
        else front++;
    }
}

bool isFull(){
    //hard
    if(front < back) {
        return back-front == n;
    }
    else {
        return back+1 == front;
    }
}

bool isEmpty(){
    if(front==back){
        return true;
    }
    else{
        return false;
    }
}