#include <iostream>
#include <vector>
using namespace std;

struct Seat {
    bool isBooked;
    int row;
    int seat;
    Seat *next;
    Seat *prev;
    // Define a destructor for the Seat class
    ~Seat() {
        delete next;
        delete prev;
    }
};

void addSeat(Seat *&head, int row, int seat) {
    Seat *newSeat = new Seat;
    newSeat->isBooked = false;
    newSeat->row = row;
    newSeat->seat = seat;
    newSeat->next = head;
    newSeat->prev = head->prev;
    head->prev->next = newSeat;
    head->prev = newSeat;
}

void displaySeats(Seat *&head) {
    Seat *curr = head;
    cout << "Row: " << curr->row << ", Seat: " << curr->seat << endl;
    do {
        curr = curr->next;
        if (curr == head) break;
        cout << "Row: " << curr->row << ", Seat: " << curr->seat << endl;
    } while (true);
}

void bookSeat(Seat *&head, int row, int seat) {
    Seat *curr = head;
    do {
        if (curr->row == row && curr->seat == seat) {
            curr->isBooked = true;
            return;
        }
        curr = curr->next;
    } while (curr != head);
    cout << "No seat available at row: " << row << ", seat: " << seat << endl;
}

void cancelBooking(Seat *&head, int row, int seat) {
    Seat *curr = head;
    do {
        if (curr->row == row && curr->seat == seat) {
            curr->isBooked = false;
            return;
        }
        curr = curr->next;
    } while (curr != head);
    cout << "No booking available at row: " << row << ", seat: " << seat << endl;
}

// Define a function to initialize the seatArray
void initialize(Seat *seatArray[], int n) {
    for (int i = 0; i < n; i++) {
        seatArray[i] = new Seat;
        seatArray[i]->isBooked = false;
        seatArray[i]->row = i;
        seatArray[i]->seat = 0;
        seatArray[i]->next = seatArray[i];
        seatArray[i]->prev = seatArray[i];
    }
}

// Define a function to delete the seatArray
void deleteArray(Seat *seatArray[], int n) {
    for (int i = 0; i < n; i++) {
        delete seatArray[i];
    }
    delete[] seatArray;
}

int main() {
    Seat *seatArray[10];
    initialize(seatArray, 10);

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 7; j++) {
            addSeat(seatArray[i], i, j);
        }
    }

    bookSeat(seatArray[1], 1, 2);
    bookSeat(seatArray[1], 1, 3);

    displaySeats(seatArray[1]);

    cancelBooking(seatArray[1], 1, 2);

    displaySeats(seatArray[1]);

    // Delete the seatArray
    deleteArray(seatArray, 10);

    return 0;
}
