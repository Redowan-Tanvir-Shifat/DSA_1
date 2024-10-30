#include <iostream>
using namespace std;

class Queue {
    int rear, front, size;
    int *q;

    public:
        Queue() {
            size = 5;
            rear = front = -1;
            q = new int[size];
        }

        Queue(int n) {
            size = n;
            rear = front = -1;
            q = new int[n];
        }

        int isFull() {
            if(rear == size-1) {
                return 1;
            }
            else {
                return 0;
            }
        }

        int isEmpty() {
            if(rear == -1) {
                return 1;
            }
            else{
                return 0;
            } 
        }

        void enEqueue(int x) {
            if(isFull()) {
                cout << "Queue is full" << endl;
            }
            else {
                rear++;
                q[rear] = x;
            }
        }

        int deQueue() {
            if(isEmpty()) {
                cout << "Queue is empty" << endl;
                return INT_MAX;
            }
            else {
                int y = q[0];
                for(int i = 0; i < rear; i++) {
                    q[i] = q[i+1];
                }
                rear--;
                return y;
            }
        }
};

int main() {
    Queue q1;

    q1.enEqueue(1);
    q1.enEqueue(2);
    q1.enEqueue(3);
    q1.enEqueue(4);
    q1.enEqueue(5);

    while(!q1.isEmpty()) {
        cout << q1.deQueue() << endl;
    }

    return 0;
}