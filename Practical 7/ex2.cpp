#include <iostream> 
using namespace std;

// Custom FullStackException that is thrown e.g. if stack is full but user wants to add another element
struct FullStackException : public exception
{
	const char * what () const throw ()
    {
    	return "Stack is already full";
    }
};

// Custom EmptyStackException that is thrown e.g. if stack is empty but user wants to delete an element
struct EmptyStackException : public exception
{
	const char * what () const throw ()
    {
    	return "Stack is already empty";
    }
};

// abstract class (or interface) StackI
template <typename T>
class StackI {
public:
  virtual void push(T t) = 0;
  virtual void pop() = 0;
  virtual T top() =0;
  virtual bool isEmpty() =0;
  virtual void print()=0;
};

template <typename T>
class Stack : public StackI<T> {
  private:
    int size;
    T *arr;
    int i; // to save the first free index

  public: 
    Stack () { // constructor without arguments
      size=20; // default size is 20
      arr = new T [20];
      i = 0;
    }
    Stack (int n) { // constructor with arguments
      size=n;
      arr = new T [n];
      i = 0;
    } 

    ~Stack() { delete[] arr; } // destructor

    void push(T t) {
      if (i<size) {
        arr[i] = t;
        i++; // increasing the pointer for the next free element
      } else {
        throw FullStackException();
      } 
    }

    void pop() {
      if (i != 0) {
        // the element is not actually deleted, the pointer for the next free space is just moved down and the element will eventually be overwritten if a new element is added.
        i--;
      } else {
        throw EmptyStackException();
      }
    }

    T top() {
      if (i != 0) {
        return arr[i-1];
      } else {
        throw EmptyStackException();
      }
    }

    bool isEmpty() {
      return (i==0) ? true : false; // using pointer to check if stack is empty
    }

    void print() {
      cout << "[ ";
      for (int j = 0; j<i; j++) {
        cout << arr[i-j-1] << " ";
      }
      cout << "]" << endl;
    }
};

int main() {
  // Short test program with Stack<int> of size 5.
  Stack<int> stack = Stack<int>(5);
  // Initially stack is empty
  cout << "Is Empty? " << stack.isEmpty() << endl;
  // Adding an element
  stack.push(1);
  stack.print();
  cout << "Is Empty? " << stack.isEmpty() << endl;
  stack.push(2);
  stack.print();
  stack.push(3);
  stack.print();
  // deleting the top element
  stack.pop();
  stack.print();
  stack.push(4);
  stack.print();
  // printing top element of the stack
  cout << stack.top() << endl;
  return 0;
}