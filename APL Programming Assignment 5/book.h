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

        // these constructors are in-line functions
        /*
        This, in a way, does not follow good practice.
        In bookmain.cpp, each time a variable is instantiated,
        imagine copying and pasting the content in the constructors
        to the location in bookmain.cpp where the Book object
        is instantiated. In the end, it makes the compiled code
        size larger than having the constructor prototype
        functions here and defining what the functions should
        do in the book.cpp file.
        */
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
