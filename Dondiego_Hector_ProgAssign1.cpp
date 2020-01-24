#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <ctype.h>

int main()
{
    int pOneScore, pTwoScore, dice, turnTotal;
    char response;

    pOneScore = 0;
    pTwoScore = 0;

    turnTotal = 0;

    srand(time(0));

    int playerVal = rand() % 2 + 1;
    std::cout << "You will be player " << playerVal << std::endl;
    std::cout << "R to roll; enter any other characters to hold." << std::endl;

    while(true) {
        std::cout << "Player 1 score: " << pOneScore << std::endl;
        std::cout << "Player 2 score: " << pTwoScore << std::endl;

        if (playerVal == 1){
            std::cout << "It is player 1's turn." << std::endl;
            response = 'R';
            while (response == 'R') {
                dice = rand() % 6 + 1;
                std::cout << "Roll: " << dice << std::endl;
                if (dice != 1){
                    turnTotal += dice;
                    std::cout << "Turn total: " << turnTotal << " Roll/Hold "<< std::endl;
                    std::cin >> response;
                    response = toupper(response);
                } else {
                    turnTotal = 0;
                    break;
                }
            }

            pOneScore += turnTotal;
            std::cout << "Turn total: " << turnTotal << std::endl;
            std::cout << "New score: " << pOneScore << std::endl;

            if (pOneScore >= 100) {
                break;
            }

            turnTotal = 0;

            /*-------------------------------------------------------------------*/

            std::cout << "Player 1 score: " << pOneScore << std::endl;
            std::cout << "Player 2 score: " << pTwoScore << std::endl;

            std::cout << "It is player 2's turn." << std::endl;
            while (turnTotal <= 20) {
                dice = rand() % 6 + 1;
                std::cout << "Roll: " << dice << std::endl;
                if (dice != 1) {
                    turnTotal += dice;
                } else {
                    turnTotal = 0;
                    break;
                }
            }

            pTwoScore += turnTotal;
            std::cout << "Turn total: " << turnTotal << std::endl;
            std::cout << "New score: " << pTwoScore << std::endl;

            if (pTwoScore >= 100) {
                break;
            }

            turnTotal = 0;
        } else {
            std::cout << "It is player 1's turn." << std::endl;

            while (turnTotal <= 20) {
                dice = rand() % 6 + 1;
                std::cout << "Roll: " << dice << std::endl;
                if (dice != 1) {
                    turnTotal += dice;
                } else {
                    turnTotal = 0;
                    break;
                }
            }

            pOneScore += turnTotal;
            std::cout << "Turn total: " << turnTotal << std::endl;
            std::cout << "New score: " << pOneScore << std::endl;

            if (pOneScore >= 100) {
                break;
            }

            turnTotal = 0;

            /*-------------------------------------------------------------------*/

            std::cout << "Player 1 score: " << pOneScore << std::endl;
            std::cout << "Player 2 score: " << pTwoScore << std::endl;

            std::cout << "It is player 2's turn." << std::endl;
            response = 'R';
            while (response == 'R') {
                dice = rand() % 6 + 1;
                std::cout << "Roll: " << dice << std::endl;
                if (dice != 1){
                    turnTotal += dice;
                    std::cout << "Turn total: " << turnTotal << " Roll/Hold "<< std::endl;
                    std::cin >> response;
                    response = toupper(response);
                } else {
                    turnTotal = 0;
                    break;
                }
            }

            pTwoScore += turnTotal;
            std::cout << "Turn total: " << turnTotal << std::endl;
            std::cout << "New score: " << pTwoScore << std::endl;

            if (pTwoScore >= 100) {
                break;
            }

            turnTotal = 0;
        }
    }

    return 0;
}
