#include <iostream>

using namespace std;

class Queue
{
private:
    int queue[10];
    int n = 10;
    int front;
    int rear;
    int val;

public:
    Queue()
    {
        front = 0;
        rear = -1;
    }
    void enqueue(int val)
    {
        if (rear == n - 1)
        {
            cout << "Queue is full" << endl;
            return;
        }
        rear++;
        queue[rear] = val;
    }
    void dequeue()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        front++;
    }
    void display()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main(void)
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8);
    q.enqueue(9);
    q.enqueue(10);
    //////
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    ////
    q.display();
}