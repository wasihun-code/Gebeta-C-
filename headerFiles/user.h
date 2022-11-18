#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "habesha.h"
#include "hindu.h"
#include "mynamar.h"
#include "syria.h"
#include "header.h"

/**
 * Class      : Admin.
 * Short Description -  The asmin class has privilages like
                - Adding meals
                - Deleting meals
                - Creating Admin account
 * Functions - whichFiletoOpen  - dictates which country's file to open
             - getDetaislofDish - accepts name, price, description and recipe of a meal.
             - addDishes        - add a dish in any country.
             - deleteDishes     - delete a dish in any country.
             - loginAccount     - logs in to admin account.
             - createAccount    - creates an admin account.
*/
class user :
     public habesha,
     public hindu,
     public mynamar,
     public syria
{
protected:
    int id = 1;
    int password;
    std::string   firstName;
    std::string  secondName;
    std::string phoneNumber;
    std::string bankAccount;
public:
    user() = default;
    void orderMeal();
    void getDetailsOf();
    void createAccount();
    bool loginAccount();
};
/**
 * Name       : addDishes
 * Class      : Admin.
 * Parameters : None.
 * Short Description :
            Adds dishes to a country upon administrator choice.
            This is done by opening each countries text file
            containing list of dishes and adding only the name
            of the dish on a new line. And also opening each
            countries text file that contain details of the dish
            and appending name, price, description and recipe of file.
*/
void user::getDetailsOf(){
    id = randGenerator(1000, 9999);
    password = randGenerator(1000000, 100000000);
    
    std::cout << manipOrder << "   First Name: "; std::cin >> firstName;
    std::cout << manipOrder << "  Second Name: "; std::cin >> secondName;
    std::cout << manipOrder << " Phone Number: "; std::cin >> phoneNumber;
    std::cout << manipOrder << " Bank Account: "; std::cin >> bankAccount;
    system("cls");

}
/**
 * Name       : addDishes
 * Class      : Admin.
 * Parameters : None.
 * Short Description :
            Adds dishes to a country upon administrator choice.
            This is done by opening each countries text file
            containing list of dishes and adding only the name
            of the dish on a new line. And also opening each
            countries text file that contain details of the dish
            and appending name, price, description and recipe of file.
*/
void user::createAccount()
{
    std::fstream userFile;
    userFile.open("textFiles//userAccounts.txt", 
                 std::ios::out | std::ios::app);

    if (userFile.is_open())
    {
        getDetailsOf();

        bankAmmount = randGenerator(1000, 1000000);
        userFile << std::endl;

        userFile << id << std::endl;
        userFile << "\t" << firstName   << " " << secondName << std::endl;
        userFile << "\t" << phoneNumber << std::endl;
        userFile << " "  << password    << std::endl;
        userFile << "\t" << bankAccount << std::endl;
        userFile << bankAmmount << std::endl;
        userFile << std::endl;

        std::cout << lengthManip5 << manipWidth50 << "ACCOUNT DETAILS\n";
        std::cout << manipWidth50 << "    Login Id: " << id << std::endl;
        std::cout << manipWidth50 << "    Password: " << password << "\n\n";

        userFile.close();
    }
    else
        std::cout << "System Erorr. Please Try again.\n";
}
/**
 * Name       : addDishes
 * Class      : Admin.
 * Parameters : None.
 * Short Description :
            Adds dishes to a country upon administrator choice.
            This is done by opening each countries text file
            containing list of dishes and adding only the name
            of the dish on a new line. And also opening each
            countries text file that contain details of the dish
            and appending name, price, description and recipe of file.
*/
bool user::loginAccount()
{
    std::cout << manipWidth50 << "Enter Details to Login\n";

    std::fstream userFile;
    std::string  passInFile;
    userFile.open("textFiles//userAccounts.txt", std::ios::in);

    if (userFile.is_open()){
        std::cout << manipWidth50 << "\t Enter Id: ";      std::cin >> id;
        std::cout << manipWidth50 << "\t PassWord: ";      std::cin >> password;
        system("cls");

       while(userFile.good())
        {
            std::string list {};
            std::string   userId = std::to_string(id);
            std::string userPass = " " + std::to_string(password);

            getline(userFile, list);
            if (list == userId){
                for (int i = 1; i <= 5; i++){ 
                    getline(userFile, list);
                    if     (i == 1)
                        userName = list;
                    else if (i == 2)
                        userPhone = list;
                    else if (i == 3)
                        passInFile = list;
                    else if (i == 4)
                        bankAccount = list;
                    else if (i == 5)
                        bankAmmount = stoi(list);
                }
                if (passInFile == userPass){
                    userFile.close();
                    return true;
                }
                userFile.close();
                return false;
            }
        }
    }
    return false;
}
/**
 * Name       : addDishes
 * Class      : Admin.
 * Parameters : None.
 * Short Description :
            Adds dishes to a country upon administrator choice.
            This is done by opening each countries text file
            containing list of dishes and adding only the name
            of the dish on a new line. And also opening each
            countries text file that contain details of the dish
            and appending name, price, description and recipe of file.
*/
void user::orderMeal()
{ 
    int newbankAmmount = bankAmmount - priceOfDish - 50;

    std::cout << manipOrder << "\t"                     << "ORDER DETAILS"  << twoNew;
    std::cout << manipOrder << "Name"                   <<"\b\b\b\b"        << userName << std::endl;
    std::cout << manipOrder << "Ordered Dish"           << dishName         << std::endl;
    std::cout << manipOrder << "Bank Account"           <<"\b\b\b\b"        << bankAccount << std::endl;
    std::cout << manipOrder << "Price of dish"          << priceOfDish      << std::endl;
    std::cout << manipOrder << "Delivery  Fee"          << 49 << " Rs. "    << std::endl;
    std::cout << manipOrder << "Amount before Order"    << bankAmmount      << std::endl;
    std::cout << manipOrder << "Amount after Order"     << newbankAmmount   << std::endl;

    printTime();

}


#endif