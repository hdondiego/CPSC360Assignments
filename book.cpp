#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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

// default constructor - no parameter
Book::Book(){
    Title = "No Title";
    srand(time(0));
    bookID = (rand() % 1000) + 1;
    checkedOut = false;
}

// 2- or 3- parameter constructor
Book::Book(std::string name, int id, bool checked){
    Title = name;
    bookID = id;
    checkedOut = checked;
}

// copy constructor
Book::Book(const Book &bookObj){
    Title = bookObj.Title;
    bookID = bookObj.bookID;
    checkedOut = bookObj.checkedOut;
}

/*
 uses another Book object's pointer address
 to set this Book objects attributes to the
 the addressed values

 this is different from the copy constructor
 as the copy constructor uses a Book's pointer
 address to instantiate another Book object
 and copy its values to the new object
*/
void Book::operator=(const Book &right){
    Title = right.Title;
    bookID = right.bookID;
    checkedOut = right.checkedOut;
}

/*
 creating a new Book object for the = operator
 to use to copy the concatenated Book object's Titles
 and bookID changes

 appends this Book object's Title and another Book
 object's Title together with a comma separated by
 a space

 newly generated bookID cannot be either this Book's bookID
 or the right Book's bookID
*/
Book Book::operator+(const Book &right){
    Book temp;
    std::string tempTitle = Title + ", " + right.Title;
    temp.setTitle(tempTitle);
    int val = 0;
    srand(time(0));
    while (true){
        val = (rand() % 1000) + 1;
        if ((val != bookID) && (val != right.bookID)){
            bookID = val;
            break;
        }
    }
    temp.setbookID(val);
    return temp;
}

/*
 copying the right Book's variable data
 to this Book's variables

 erasing the right Book by setting
 Title to "No Title" and changing
 bookID to 0

 returning this Book object, with
 the changes made to it
*/
Book Book::operator-(Book &right){
    Title = right.Title;
    bookID = right.bookID;
    checkedOut = right.checkedOut;

    right.Title = "No Title";
    right.bookID = 0;
    right.checkedOut = false;

    return *this;
}
