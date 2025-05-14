#include <iostream>
#include <exception>
using namespace std;

class QueueOverflowException : public exception {};
class QueueUnderflowException : public exception {};

template<typename T>
class Queue {
    T* arr;
    int size, front, rear, count;

public:
    Queue(int cap) : size(cap), front(0), rear(0), count(0) {
        arr = new T[size];
    }

    ~Queue() { delete[] arr; }

    void enqueue(T val) {
        if (count == size)
            throw QueueOverflowException();
        arr[rear] = val;
        rear = (rear + 1) % size;
        count++;
    }

    T dequeue() {
        if (count == 0)
            throw QueueUnderflowException();
        T val = arr[front];
        front = (front + 1) % size;
        count--;
        return val;
    }
};

int main() {
    try {
        Queue<int> q(2);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3); // overflow
    } catch (const exception& e) {
        cout << "Caught QueueOverflowException\nwhat(): " << e.what() << endl;
    }

    try {
        Queue<int> q(2);
        q.dequeue(); // underflow
    } catch (const exception& e) {
        cout << "Caught QueueUnderflowException\nwhat(): " << e.what() << endl;
    }

    return 0;
}
