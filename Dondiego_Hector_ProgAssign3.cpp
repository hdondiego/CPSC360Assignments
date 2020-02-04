#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>

void plotGraph(int seats[15][30]);

void buyTicket(int* totalSales, int seats[15][30]){
    const int FRONT_ROW_COST = 50;          // cost for first 7 rows
    const int BACK_ROW_COST = 40;           // cost for last 8 rows
    const int DIVIDER = 7;                  // the seventh row separating the two sections
    const int NUM_SEATS = 30;               // the number of seats per row

    int numTickets = 0;                     // value user enters to be asked x times for a specific seat to purchase
    std::cout << "Enter number of tickets to purchase: ";
    std::cin >> numTickets;

    int seatAvail = 0;                      // used to keep track of overall available seats
    int count_me = 0;                       // iterating each time a seat is successfully filled
    int ticketPurch = 0;                    // holds the total ticket charge per time that the Buy Ticket option is used
    int row = 0;                            // user-entered row number
    int seat = 0;                           // user-entered seat number
    do {
        std::cout << "Enter row number followed by chosen seat number (separate with space): ";
        std::cin >> row >> seat;
        // counting the number of available seats in the chosen row
        for (int i = 0; i < NUM_SEATS; i++){
            if (!seats[row - 1][i]) {
                seatAvail++;
            }
        }
        // checking to see if there were available seats
        if (seatAvail > 0){
            // checking to see if the seat number is available to purchase
            if (!seats[row - 1][seat - 1]){
                // checking to see if it is a front section or back section seat
                // adding to the current purchasing total (will add to sum ticket purchases)
                // iterating for successful seat purchase
                if (row <= DIVIDER){
                    ticketPurch += FRONT_ROW_COST;
                    count_me++;
                } else {
                    ticketPurch += BACK_ROW_COST;
                    count_me++;
                }
                // make seat filled
                seats[row - 1][seat - 1] = 1;
            } else {
                std::cout << "This seat is not available." << std::endl;
            }
        } else {
            std::cout << "No seats are available in this row." << std::endl;
        }
    } while (count_me < numTickets);
    // adding the sales made from current session to total sum sales made
    *totalSales += ticketPurch;
    std::cout << std::endl;
}

void seatInfo(const int NUM_ROWS, const int NUM_SEATS, int seats[15][30]);

int main()
{
    const int FRONT_ROW_COST = 50;          // cost for first 7 rows
    const int BACK_ROW_COST = 40;           // cost for last 8 rows
    const int NUM_ROWS = 15;                // the number of rows in theater
    const int NUM_SEATS = 30;               // the number of seats per row
    int seats[NUM_ROWS][NUM_SEATS]{0};      // multidimensional array holding all the seats, and value for existing seat-holder
    int totalSales = 0;                     // the sum of all the ticket purchases

    char userChoice;                        // holds the character the user enters for the option of their choice

    do {
        // keep on asking the user for the option of their choice as long as it is not Q - quit
        std::cout << "Options:\n'D' - display seating chart\n'B' - buy tickets" << std::endl;
        std::cout << "'T' - show total sales\n'S' - show seating info\n'Q' - quit" << std::endl;

        std::cout << "Enter option: ";
        std::cin >> userChoice;
        userChoice = std::toupper(userChoice);
        std::cout << std::endl;

        switch(userChoice) {
        case 'D':
            // display seat chart
            plotGraph(seats);
            break;
        case 'B':
            // buy tickets
            buyTicket(&totalSales, seats);
            break;
        case 'T':
            // show ticket sales
            std::cout << "Total Sales: " << totalSales << "\n" << std::endl;
            break;
        case 'S':
            // show seating info
            seatInfo(NUM_ROWS, NUM_SEATS, seats);
            break;
        case 'Q':
            // quitting application
            std::cout << "Thank you for using Seat Charter" << std::endl;
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
        }
    } while (userChoice != 'Q');
    return 0;
}

void plotGraph(int seats[15][30])
{
    // uses multidimensional array to help plot the seating chart
    char row[30];
    std::cout << "          123456789012345678901234567890" << std::endl;
    for (int i = 0; i < 15; i++){
        // adjusting the width of spacing between Row # and the seats
        if (i < 9) {
            std::cout << "Row " << i + 1 << std::setw(6);
        } else {
            std::cout << "Row " << i + 1 << std::setw(5);
        }
        /*
        Reading through multidimensional array to see if
        a specific row and column location has a 0 or 1
        0 - empty seat
        1 - seat taken
        The if-statement below sees if it is 0 -> if so, # for empty
        */
        for (int j = 0; j < 30; j++){
            if (!seats[i][j]){
                std::cout << "#";
            } else {
                std::cout << "*";
            }

            // implemented at 29 because it will end the seat count
            // creates a new row for the next one
            if (j == 29){
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::endl;
}

void seatInfo(const int NUM_ROWS, const int NUM_SEATS, int seats[15][30]){
    int seatAvail = 0;  // used to keep track of overall available seats
    int seatCount = 0;  // keeps track of available seats per row and is used to add to seatAvail for total available seats
    std::cout << "Available Seats:" << std::endl;
    // iterating through each row
    for (int i = 0; i < NUM_ROWS; i++){
        std::cout << "Row " << i + 1 << ": ";
        seatCount = 0;
        // checking each seat in a row to see if it has a 0 - is empty
        for (int j = 0; j < NUM_SEATS; j++){
            if (!seats[i][j]){
                seatCount++;
            }
            // print out the row's count and create new line
            if (j == 29){
                std::cout << seatCount << std::endl;
                seatAvail += seatCount;
            }
        }
    }
    // print out the overall seats available and the seats sold
    std::cout << "There are " << seatAvail << " seat(s) available." << std::endl;
    std::cout << (NUM_ROWS * NUM_SEATS) - seatAvail << " seat(s) sold.\n" << std::endl;
}
