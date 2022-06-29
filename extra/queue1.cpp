#include <iostream>
using namespace std;

typedef struct _item {
    int key;
    _item* next;
} item;

int main() {
    item *front, *rear, *temp;
    front = rear = temp = 0; // null pointer
    int key;
    while(1) {
        cin >> key;
        if(key == -1) {
            if(front==0) {
                cout << "empty queue!\n";
            }
            else {
                temp = front;
                cout << front->key << " ";
                front = front->next;
                delete temp;
            }
        }
        else {
            temp = new item;
            temp->key = key;
            temp->next = 0;
            if(front == 0) {
                front = rear = temp;
            }
            else {
                rear->next = temp;
                rear = temp;
            }
        }
    }
    return 0;
}