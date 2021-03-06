#include <iostream>
#include <string>

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

        /*
        In-line constructor functions were removed and replaced with
        prototype constructor functions. Constructor functions
        were added to book.cpp file.
        This, in a way, does not follow good practice.
        In bookmain.cpp, each time a variable is instantiated,
        imagine copying and pasting the content in the constructors
        to the location in bookmain.cpp where the Book object
        is instantiated. In the end, it makes the compiled code
        size larger than having the constructor prototype
        functions here and defining what the functions should
        do in the book.cpp file.
        */

        Book(); // default constructor - no parameter
        Book(std::string name, int id, bool checked=false); // 2- or 3- parameter constructor
        Book(const Book &bookObj);  // copy constructor

        // prototype functions for the =, +, and - operator overloads
        void operator=(const Book &right);
        Book operator+(const Book &right);
        Book operator-(Book &right);
};
#endif // BOOK_H
