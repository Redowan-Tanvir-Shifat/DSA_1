#include <iostream>
#include<stack>
using namespace std;

class Queue {
    stack<int> s;

    public:
        Queue() {

        }

        void enqueue(int x) {
            s.push(x);
        }

        bool isEmpty() {
            return s.empty();
        }

        int dequeue() {
            if(isEmpty()) {
                cout << "Queue is empty" << endl;
                return INT_MAX;
            }
            
            stack<int> temp;

            while(!s.empty()) {
                int x = s.top();
                temp.push(x);
                s.pop();
            }

            int y = temp.top();
            temp.pop();

            while(!temp.empty()) {
                int z = temp.top();
                s.push(z);
                temp.pop();
            }

            return y;
        }
};


int main() {
    Queue q1;

    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);

    while(!q1.isEmpty()) {
        cout << q1.dequeue() << endl; 
    } 

    return 0;
}