// A double-ended queue (deque) is a linear list in which additions and deletions may be made at either end. Obtain a data representation mapping a deque into a onedimensional array. Write C++ program to simulate deque with functions to add and delete elements from either end of the deque.


#include <iostream>
#include <deque>

using namespace std;

void addToFront(deque<int> &dq, int element) {
    dq.push_front(element);
}

void addToBack(deque<int> &dq, int element) {
    dq.push_back(element);
}

void deleteFromFront(deque<int> &dq) {
    if (!dq.empty()) {
        cout << "Deleted element from front: " << dq.front() << endl;
        dq.pop_front();
    } else {
        cout << "Deque is empty." << endl;
    }
}

void deleteFromBack(deque<int> &dq) {
    if (!dq.empty()) {
        cout << "Deleted element from back: " << dq.back() << endl;
        dq.pop_back();
    } else {
        cout << "Deque is empty." << endl;
    }
}

int main() {
    deque<int> dq;

    addToFront(dq, 10);
    addToBack(dq, 20);
    addToFront(dq, 5);
    addToBack(dq, 30);

    deleteFromFront(dq);
    deleteFromBack(dq);

    addToFront(dq, 40);

    deleteFromFront(dq);
    deleteFromBack(dq);

    return 0;
}
