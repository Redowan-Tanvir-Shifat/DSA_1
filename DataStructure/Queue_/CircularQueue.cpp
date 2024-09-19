#include <iostream>
using namespace std;

class Queue{
    int rear, front, size;
    int *q;

    public:
        Queue() {
            size = 4;
            rear = front = -1;
            q = new int[size];
        }
        Queue(int n) {
            size = n;
            rear = front = -1;
            q = new int[n];
        }

        int isFull() {
            if((rear + 1) % size == front) {
                return 1;
            }
            else {
                return 0;
            }
        }

        int isEmpty() {
            if(rear == -1 && front == -1) {
                return 1;
            }
            else{
                return 0;
            } 
        }

        void enqueue(int x) {
            if(isEmpty()) {
                front = rear = 0;
                q[rear] = x;
            } 
            else if(isFull()) {
                cout << "Queue is full" << endl;
            }
            else {
                rear = (rear + 1) % size;
                q[rear] = x;
            }
        }

        int dequeue() {
            if(isEmpty()) {
                cout << "Queue is empty" << endl;
                return INT_MAX;
            }
            else if(front == rear) {
                int y = q[front];
                front = rear = -1;
                return y;
            }
            else {
                int y = q[front];
                front = (front + 1) % size;
                return y;
            }
        }
};

int main() {

    return 0;
}