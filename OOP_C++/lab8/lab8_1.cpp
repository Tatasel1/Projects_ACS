#include <iostream>
using namespace std;

template <class T>
class stack{
    T *arr;
    int top;
    int capacity;
public:
    stack(int size) {
        arr = new T[size];
        capacity = size;
        top = -1;
    }

    void getArr() {
        for (int i = 0; i <= top; i++) {
            cout<<arr[i]<<" ";
        }
    }

    T push(T x) {
        try {
            if (top < capacity - 1) {
                arr[++top] = x;
            }
            else throw overflow_error("Stack Overflow" );
        }
        catch (...) {
            cout<<"Stack Overflow"<<endl;
        }
        return x;

    }

    T pop() {
        T x;
        try {
           if (top>=0) {
                x =arr[top--];
            }
            else throw underflow_error("Stack Underflow");
        }
        catch (...) {
           cout<<"Stack Underflow"<<endl;
        }
       return x;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack empty" << endl;
            return;
        }
        cout<<arr[top];
    }

    ~stack() {
        delete [] arr;
    }
  };


template <class Q>
class queue {
    Q *arr;
    int front, rear, capacity;
public:
    queue(int size) {
        arr = new Q[size];
        capacity = size;
        front = -1;
        rear = -1;
    }

    void getArr() {
        for (int i = front; i <= rear; i++) {
            cout<<arr[i]<<" ";
        }
    }

    Q enqueue(Q x) {
        try {
            if (rear == capacity - 1) {
                throw overflow_error("Queue Overflow");
            }

           if (front == -1) {
                front = 0;
            }

            arr[++rear] = x;
        }
        catch (...) {
            cout << "Queue Overflow" << endl;
        }
        return x;
    }

    Q dequeue() {
        Q x= Q();
        try {
            if (front == -1 || front > rear) {
                throw underflow_error("Queue Underflow");
            }
            x=arr[front++];
            if (front > rear) {
                front = -1;
                rear = -1;
            }
        }
        catch (...) {
            throw underflow_error("Queue Underflow");
        }
        return x;
    }

    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return rear == capacity - 1;
    }

    void peek() {

        if (isEmpty()) {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        cout<<arr[front];
    }

    ~queue() {
        delete [] arr;
    }

};
  int main() {
      cout<<"Stivele cu numere si char uri:\n";
      stack<int> s(5);
      s.push(10);
      s.push(20);
      s.push(30);
      s.getArr();
      cout<<"\nPeek:\n";
      s.peek();
      cout<<endl;

      s.pop();
      s.getArr();
      cout << "\nIs empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

      cout<<endl;

      stack<char> s2(5);
      cout << "\nIs empty? " << (s2.isEmpty() ? "Yes" : "No") << endl;
      s2.push('X');
      s2.push('Y');
      s2.push('Z');
      s2.getArr();

      cout<<endl;

      s2.pop();
      s2.getArr();
      cout<<"\nPeek:\n";
      s2.peek();

      cout<<endl;
      cout<<"Cozile cu numere si char uri:\n";
      queue<char> q(5);
      cout << "\nIs empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
      q.enqueue('A');
      q.enqueue('b');
      q.enqueue('C');
      q.getArr();

      cout<<"\nPeek:\n";
      q.peek();

      cout<<endl;

      q.dequeue();
      q.getArr();

      cout<<endl;

      queue<int> q2(5);
      q2.enqueue(100);
      q2.enqueue(200);
      q2.enqueue(300);
      q2.getArr();

      cout<<endl;

      q2.dequeue();
      q2.getArr();

      cout<<"\nPeek:\n";
      q2.peek();
      cout << "\nIs empty? " << (q2.isEmpty() ? "Yes" : "No") << endl;

      return 0;
  }