#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

#ifndef BOOK_H
#define BOOK_H
class Book{
    // Hector Dondiego
    // data attributes for Book object
    private:
        std::string Title;
        int bookID;
        bool checkedOut;
    public:
        // prototype getter and setter functions
        std::string getTitle() const;
        int getbookID() const;

        void setTitle(std::string name);
        void setbookID(int id);

        // prototype functions for checkedOut data attribute
        bool isCheckedOut() const;
        void borrowBook();
        void returnBook();

        // default constructor - no parameter
        Book(){
            Title = "No Title";
            srand(time(0));
            bookID = (rand() % 1000) + 1;
            checkedOut = false;
        }

        // 2- or 3- parameter constructor
        Book(std::string name, int id, bool checked=false){
            Title = name;
            bookID = id;
            checkedOut = checked;
        }

        // copy constructor
        Book(const Book &bookObj){
            Title = bookObj.Title;
            bookID = bookObj.bookID;
            checkedOut = bookObj.checkedOut;
        }
};
#endif // BOOK_H
