#include <iostream>
#include "book.h"

int main(){
    // Hector Dondiego
    // instantiating Book object with no parameters
    Book b1;
    // using setters to set values in Book b1 object
    b1.setTitle("If You Give a Mouse a Cookie");
    b1.setbookID(65);

    // printing out Book b1's attributes
    std::cout << "Title: " << b1.getTitle() << std::endl;
    std::cout << "Book ID: " << b1.getbookID() << std::endl;
    if (b1.isCheckedOut()){
        std::cout << "Status: This book is currently checked out." << std::endl;
    } else {
        std::cout << "Status: This book is currently available." << std::endl;
    }
    std::cout << std::endl;

    // checking out Book b1 - setting checkedOut to True
    b1.borrowBook();

    // printing out Book b1's changed attributes
    std::cout << "Title: " << b1.getTitle() << std::endl;
    std::cout << "Book ID: " << b1.getbookID() << std::endl;
    if (b1.isCheckedOut()){
        std::cout << "Status: This book is currently checked out." << std::endl;
    } else {
        std::cout << "Status: This book is currently available." << std::endl;
    }
    std::cout << std::endl;

    /*--------------------------------------------------------------------------*/

    // instantiating Book object with three parameters
    Book b2("Strange Case of Dr Jekyll and Mr Hyde", 23, true);

    // printing out Book b2's attributes
    std::cout << "Title: " << b2.getTitle() << std::endl;
    std::cout << "Book ID: " << b2.getbookID() << std::endl;
    if (b2.isCheckedOut()){
        std::cout << "Status: This book is currently checked out." << std::endl;
    } else {
        std::cout << "Status: This book is currently available." << std::endl;
    }
    std::cout << std::endl;

    // returning Book b2 object - setting checkedOut to False
    b2.returnBook();

    // printing out Book b2's changed attributes
    std::cout << "Title: " << b2.getTitle() << std::endl;
    std::cout << "Book ID: " << b2.getbookID() << std::endl;
    if (b2.isCheckedOut()){
        std::cout << "Status: This book is currently checked out." << std::endl;
    } else {
        std::cout << "Status: This book is currently available." << std::endl;
    }
    std::cout << std::endl;

    /*--------------------------------------------------------------------------*/

    // instantiating Book object with copy constructor, passing in Book b1 object
    Book b3(b1);

    // printing out Book b3's attributes
    std::cout << "Title: " << b3.getTitle() << std::endl;
    std::cout << "Book ID: " << b3.getbookID() << std::endl;
    if (b3.isCheckedOut()){
        std::cout << "Status: This book is currently checked out." << std::endl;
    } else {
        std::cout << "Status: This book is currently available." << std::endl;
    }
    return 0;
}
