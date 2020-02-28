#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "book.h"

int main(){
    // Hector Dondiego
    // creating an array of Book objects called bookLibrary
    const int ARRAY_SIZE = 5;   // defining the size of the array
    Book bookLibrary[ARRAY_SIZE];
    std::string inp;    // inp temporarily holds the title of the book that the user enters
    int tempVal;

    // asking the user to enter five book titles
    // need to generate new bookID since all five Book objects
    // have the same bookID to start with
    for (int i = 0; i < ARRAY_SIZE; i++){
        std::cout << "Enter a book title: ";
        std::getline(std::cin, inp);
        bookLibrary[i].setTitle(inp);
        tempVal = (rand() % 1000) + 1;
        bookLibrary[i].setbookID(tempVal);

    }

    // using the =, +, and - operator overloaded functions to all five book objects
    bookLibrary[0] = bookLibrary[1]; // 0 1
    bookLibrary[1] = bookLibrary[2] + bookLibrary[3]; // 1 2 3
    bookLibrary[2] = bookLibrary[3] - bookLibrary[4]; // 2 3 4

    // printing out each Book object's Title and Book ID
    for (int j = 0; j < 5; j++){
        std::cout << "Book " << j + 1 << std::endl;
        std::cout << "Title: " << bookLibrary[j].getTitle() << std::endl;
        std::cout << "Book ID: " << bookLibrary[j].getbookID() << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
