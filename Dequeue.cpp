#include <iostream>
#include <string>
using namespace std;

class Deque {
private:
    string* array;
    int size;
    int front;
    int back;

    bool is_full() const {
        return (back + 1) % size == front;
    }

    bool is_empty() const {
        return front == -1;
    }
public:
    Deque(int size) : size(size), front(-1), back(-1) {
        array = new string[size];
    }

    ~Deque() {
        delete[] array;
    }

    void push_front(const string& value) {
        if (is_full()) {
            cout << "overflow" << endl;
            return;
        }
        if (is_empty()) {
            front = back = 0;
        }
        else {
            front = (front - 1 + size) % size;
        }
        array[front] = value;
    }

    void push_back(const string& value) {
        if (is_full()) {
            cout << "overflow" << endl;
            return;
        }
        if (is_empty()) {
            front = back = 0;
        }
        else {
            back = (back + 1) % size;
        }
        array[back] = value;
    }

    void pop_front() {
        if (is_empty()) {
            cout << "underflow" << endl;
            return;
        }
        cout << array[front] << endl; 
        if (front == back) {
            front = back = -1; 
        }
        else {
            front = (front + 1) % size;
        }
    }

    void pop_back() {
        if (is_empty()) {
            cout << "underflow" << endl;
            return;
        }
        cout << array[back] << endl; 
        if (front == back) {
            front = back = -1; 
        }
        else {
            back = (back - 1 + size) % size;
        }
    }

    void print() const {
        if (is_empty()) {
            cout << "error" << endl; 
            return;
        }
        int i = front;
        while (true) {
            cout << array[i];
            if (i == back) break;
            cout << " ";
            i = (i + 1) % size;
        }
        cout << endl; 
    }
};

int main() {
    string command;
    Deque* deque = nullptr;

    while (getline(cin, command)) {
        if (command.empty()) {
            continue; 
        }
        if (command.substr(0, 8) == "set_size") {
            if (deque != nullptr) {
                cout << "error" << endl;
                continue; 
            }
            try {
                int size = stoi(command.substr(9)); 
                if (size <= 0) {
                    cout << "error" << endl;
                    continue;
                }
                deque = new Deque(size);
            }
            catch (...) {
                cout << "error" << endl; 
            }
            continue;
        }
        if (deque == nullptr) {
            cout << "error" << endl; 
            continue;
        }
        if (command.substr(0, 6) == "pushf ") {
            deque->push_front(command.substr(6));
        }
        else if (command.substr(0, 6) == "pushb ") {
            deque->push_back(command.substr(6));
        }
        else if (command == "popf") {
            deque->pop_front(); 

        }
        else if (command == "popb") {
            deque->pop_back(); 
        }
        else if (command == "print") {
            deque->print(); 
        }
        else {
            cout << "error" << endl; 
        }
    }

    delete deque; 
    return 0;
}
