#include <iostream>
#include <string>
#include "book.h"

// Hector Dondiego
// getters
std::string Book::getTitle() const{
    return Title;
}

int Book::getbookID() const{
    return bookID;
}

// setters
void Book::setTitle(std::string name){
    Title = name;
}

void Book::setbookID(int id){
    bookID = id;
}

// methods for checkedOut boolean
bool Book::isCheckedOut() const{
    // checks to see if a Book object was checked out
    return checkedOut;
}

void Book::borrowBook(){
    // this function checks out a book
    // if-statement determines whether or not the book was already checked out
    if (isCheckedOut()){
        std::cout << "This book has been checked out and is not available." << std::endl;
    } else {
        checkedOut = true;
    }
}

// returning the checked out book
void Book::returnBook(){
    checkedOut = false;
}
