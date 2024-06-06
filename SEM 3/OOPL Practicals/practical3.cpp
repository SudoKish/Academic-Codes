#include <iostream>
#include <string>

using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0f) {}

    void getData() {
        cout << "Enter the title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter the price: ";
        cin >> price;
        if (cin.fail()) {
            throw runtime_error("Invalid input for price. Price must be a float.");
        }
    }

    void putData() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    Book() : pageCount(0) {}

    void getData() {
        Publication::getData();
        cout << "Enter the page count: ";
        cin >> pageCount;
        if (cin.fail()) {
            throw runtime_error("Invalid input for page count. Page count must be an integer.");
        }
    }

    void putData() const {
        Publication::putData();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;

public:
    Tape() : playingTime(0.0f) {}

    void getData() {
        Publication::getData();
        cout << "Enter the playing time in minutes: ";
        cin >> playingTime;
        if (cin.fail()) {
            throw runtime_error("Invalid input for playing time. Playing time must be a float.");
        }
    }

    void putData() const {
        Publication::putData();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    try {
        // Create instances of Book and Tape
        Book book;
        Tape tape;

        // Get data for the book
        cout << "\nEnter details for the book:" << endl;
        book.getData();

        // Get data for the tape
        cout << "\nEnter details for the tape:" << endl;
        tape.getData();

        // Display the data for the book
        cout << "\nDetails of the book:" << endl;
        book.putData();

        // Display the data for the tape
        cout << "\nDetails of the tape:" << endl;
        tape.putData();

    } catch (const runtime_error &e) {
        cout << "\nException caught: " << e.what() << endl;

        // Reset all data members to zero values
        Book book;
        Tape tape;

        // Display the reset data for the book
        cout << "\nDetails of the book:" << endl;
        book.putData();

        // Display the reset data for the tape
        cout << "\nDetails of the tape:" << endl;
        tape.putData();
    }

    return 0;
}
