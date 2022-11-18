#ifndef HEADER_H
#define HEADER_H


#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <random>
#include <string>
#include <cstring>
#include <iomanip>
#include <stdlib.h>

// Declarations: to take input from user
char       orderChoice {'1'};
char        userChoice  {'1'};
char   interfaceChoice {'1'};
char     countryChoice {'1'};
char adminOptionChoice {'1'};
char         navChoice {'1'};
int          dishChoice {1};
// Declaration to store account information
// Mostly used to print stuff on the output
int priceOfDish {1};
int bankAmmount {1};
std::string userName;
std::string userId;
std::string userPhone;
std::string dishName;

// This two functions are manipulators 
std::ostream& manipWidth50(std::ostream& output)
{
    output << std::setw(50) << " " << std::left;
    return output;
}

std::ostream& lengthManip5(std::ostream& output)
{
    for (int i = 0; i < 3; i++)
        output << std::endl;
    return output;
}

std::ostream& twoNew(std::ostream& output)
{
    output << std::endl << std::endl ;
    return output;
}

std::ostream& manipOrder(std::ostream& output)
{
    output << std::setw(30) << " " << std::left << std::setw(22);
    return output;
}

std::ostream& manipPrompt(std::ostream& output)
{
    output << std::setw(25) << " " << std::left << ">> ";
    return output;
}

// Strlen implementation for a line from file
int findLineLength(std::string line)
{
    int len {0};

    for ( ; line[len] != '\0'; len++);

    return len;
}

// Takes mulit-line Input from user.
std::string multiLineInput(std::string prompt)
{
    std::string s {' '};
    std::string result;

    std::cout << prompt << "(press 1 and enter to stop!)\n";;

    while (getline(std::cin, s)){
        std::cout << std::setw(53) << " " << std::left;
        if (s == "1")
            break;
        result += s;
    }
    std::cout << std::endl;
    return result;
}

// Lists available countries
void listCountries()
{
    std::cout << manipWidth50 << "Choose country" << twoNew;
    std::cout << manipWidth50 << " 1. Ethiopia"   << std::endl;
    std::cout << manipWidth50 << " 2. Hindu"      << std::endl;
    std::cout << manipWidth50 << " 3. Mynamar"    << std::endl;
    std::cout << manipWidth50 << " 4. Syria"      << std::endl;
}

// Enforces user to choose only between four countries
char enforceCountryChoice()
{
    char enforcedChoice;
    do
    {
        std::cout << manipPrompt;
        std::cin >> enforcedChoice;
    }while ( !(enforcedChoice == '1' || enforcedChoice == '2'
            || enforcedChoice == '3' || enforcedChoice == '4' 
            || enforcedChoice == 'Q' || enforcedChoice == 'q'));

    return enforcedChoice;
}

// Enforces user to insert only 1 and 2 as input.
char enforceUserChoice()
{
    char enforceUser;
    do
    {
        std::cout << manipPrompt;
        std::cin >> enforceUser;
    }while ( !(enforceUser == '1' || enforceUser == '2' || 
               enforceUser == 'Q' || enforceUser == 'q'));

    return enforceUser;
}


// Prints Information when file open fails for admins.
void NoPermision()
{
    std::cout << manipWidth50 << "It seems like you don't have permission to edit.";
    std::cout << manipWidth50 << "Please ask the administrator for privilages.\n";   
}

// Generates random number between start - end
// Used for generating password, id and bank amount.
int randGenerator(int start, int end){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(start, end); // define the range

    int rand =  distr(gen) ; // generate numbers
    return rand;
}

// Finds a price of dish by opening the file that contains
// Details of a specific countries dishes.
void findPriceOfDish
    (std::fstream& recipeFile, std::string recipe, int& price)
{
    getline(recipeFile, recipe);
    price = stoi(recipe);
}

/**
 * Name       : whichFileToOpen
 * Class      : None
 * Parameters : Four.
    @countryChoice    - user choice of countries
    @nameOfListFile   - name of the file to be opened that has
                        list of dishes for each country.
    @nameOfRecipeFile - name of the file to be opened that has
                        details of every dish for each country.
    @nameofTempFile   - name of the temporary file to be opened that has list of 
                        dishes for each country after a specific dish is deleted.
 * Short Description :
            These function takes input countryChoice to decide which 
            countries file to open and does that by storing and modifying
            the other three parameters by reference. 
 */
void whichFileToOpen(char& countryChoice, std::string& nameOfListFile,
                     std::string& nameOfRecipeFile, std::string& nameOfTempFile)
{
    /**
     * This conditional modifies the last three arguments depending on
     * the users preference of country choice. it  modifies the last 
     * three arguments so that the specific text file is opened.
     */
    if      (countryChoice == '1'){
        nameOfListFile += "habesha.txt";
        nameOfRecipeFile += "habeshaRecipe.txt";
        nameOfTempFile += "habeshatemplist.txt";
    }
    else if (countryChoice == '2'){
        nameOfListFile += "hindu.txt";
        nameOfRecipeFile += "hinduRecipe.txt";
        nameOfTempFile += "hindutemplist.txt";
    }
    else if (countryChoice == '3'){
        nameOfListFile += "mynamar.txt";
        nameOfRecipeFile += "mynamarRecipe.txt";
        nameOfTempFile += "mynamartemplist.txt";
    }
    else if (countryChoice == '4'){
        nameOfListFile += "syria.txt";
        nameOfRecipeFile += "syriaRecipe.txt";
        nameOfTempFile += "syriatemplist.txt";
    }
}

// This prints delivery and order time.
void printTime(){

    // current date/time based on current system
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int day = ltm->tm_mday;
    int mon = 1 + ltm->tm_mon;
    int year = 1900 + ltm->tm_year;
    int hour = 5+ltm->tm_hour;
    int min = 30+ltm->tm_min;
    int sec = ltm->tm_sec;
    int time = randGenerator(30, 60);


    std::cout << manipOrder << "Order date: "   << day  << " " << mon << " " << year << std::endl;
    std::cout << manipOrder << "Order Time "    << hour << ":" << min << ":" << sec   << std::endl;
    std::cout << manipOrder << "Estimated Time" << time << " Minutes " << std::endl;
    std::cout << manipOrder << "Delivery Time"  << hour << ":" << time + min << ":" << sec << std::endl;    

}

#endif