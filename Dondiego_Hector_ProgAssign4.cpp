#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


int main(){


    // User enters a string to analyze
    std::string wordLine;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, wordLine);

    bool contains_E = false;        // used to help identify while in the for-loop if E was detected
    int numWordsE = 0;              // used to help keep count of the number of words with the letter E
    int longestWordE = 0;           // number of characters in the longest word containing E
    int longestWordEStart = 0;      // starting position of the longest word containing E
    int wordStart = 0;              // keeps track of the starting index of the first letter to a word
    int wordLength = 0;             // holds the length of the word from the empty space to the start of the word
    std::string tempLongestWordE;   // used to store the current word being analyzed
    std::string longWordContE;      // holds the longest word containing E from tempLongestWordE

    // iterating through each character in the string the user enters
    for (int i = 0; i < wordLine.length(); i++){
        // appending the current character to a temp string variable
        tempLongestWordE += wordLine[i];

        // analyzes each character to see if it is the letter E
        if (tolower(wordLine[i]) == 'e'){
            contains_E = true;
        }

        // checks to see if conclusion of word was reached.
        if (wordLine[i] == ' '){
            // if word contained E, go ahead and analyze the word
            if (contains_E){
                numWordsE++; // increase number of E words
                wordLength = i - wordStart; // length of current E word
                // now keep track of longest E word so far
                if (wordLength >= longestWordE) {
                    // if current E word length is greater than longestWordE we saw so far
                    // replace old longestEWord with new longestEWord
                    longestWordE = wordLength;
                    longestWordEStart = wordStart;
                    longWordContE = tempLongestWordE;   // copying the temp long word to the long word string
                    tempLongestWordE.clear();   // setting temp long word to empty
                } else {
                    // the current E word wasn't the longest
                    tempLongestWordE.clear();   // set temp long word to empty
                }
                wordStart = i+1;    // making new starting word mark for the next work
                contains_E = false; // setting the boolean back to false for next word
                tempLongestWordE.clear();   // set temp long word to empty
            } else {
                wordStart = i + 1;  // moving on to the next word because it didn't contain the letter E
                tempLongestWordE.clear();   // set temp long word to empty
            }
        }
    }

    // analyzing the last word
    if (contains_E){
        numWordsE++; // increase number of words
        wordLength = wordLine.length() - wordStart; // length of current word
        if (wordLength >= longestWordE) {
            // if current word length is greater than longestWord we saw so far
            longestWordE = wordLength;
            longestWordEStart = wordStart;
            longWordContE = tempLongestWordE;
        }
    }

    std::fstream outputFile("filestats.txt",std::ios::out);
    outputFile << numWordsE << " word(s) contained the letter E." << std::endl;
    outputFile << "The longest E word is: " << longWordContE << std::endl;
    outputFile << "The longest E word has " << longestWordE << " character(s)." << std::endl;
    outputFile.close();

    return 0;
}
