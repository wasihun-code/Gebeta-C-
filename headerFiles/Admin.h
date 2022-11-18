#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include "header.h"
#include "user.h"

/**
 * Class      : Admin.
 * Short Description -  The admin class has privilages like
                - Adding meals
                - Deleting meals
                - Creating Admin account
 * Functions - getDetaislofDish - accepts name, price, description and recipe of a meal.
             - addDishes        - add a dish in any country.
             - deleteDishes     - delete a dish in any country.
             - loginAccount     - logs in to admin account.
             - createAccount    - creates an admin account.
*/
class Admin : public user
{
private:
    char addMealChoice {};
    char countryDelChoice {};
    int  delMealChoice {};    
    std::string name   {};
    std::string price  {};
    std::string details{};
    std::string recipe {};
    std::string list {};
    std::string deletedDish {};
    int i {1};
public:
    Admin() = default;
    bool loginAccount();
    void createAccount();
    void getDetailOfDish();
    void addDishes();
    void deleteDishes();
};
/**
 * Name       : getDetailOfDish
 * Class      : Admin.
 * Parameters : None.
 * Short Description - These function reads name, price, description and recipe
 *                     of a dish so and saves them on name, price, detial and recipe
 *                     strings respectively.
*/
void Admin::getDetailOfDish()
{
    std::cin.ignore();

    system("cls");
    std::cout << lengthManip5;
    std::cout << manipOrder << "\t\t\t ADD A DISH" << twoNew ;

    std::cout << manipOrder << "Dish Name: ";
    getline(std::cin, name);

    std::cout << manipOrder << "Dish Price: ";
    std::cin >> price;

    std::cout << manipOrder;
    details = multiLineInput("Description");

    std::cout << manipOrder;
    recipe = multiLineInput("Recipe");

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
void Admin::addDishes()
{
    // textFiles// - is the directory where all text files
    //             - for this project are located.
    std::string nameOfListFile   {"textFiles//"};
    std::string nameOfTempFile   {"textFiles//"};
    std::string nameOfRecipeFile {"textFiles//"};

    listCountries();
    countryChoice = enforceCountryChoice();
    std::cout << lengthManip5;

    // This function opens a file depending on the userChoice.
    whichFileToOpen(countryChoice, nameOfListFile, 
                  nameOfRecipeFile, nameOfTempFile);

    std::fstream dishListFile;
    std::fstream dishRecipeFile;

    dishListFile.open(nameOfListFile, std::ios::in 
                     |std::ios::out | std::ios::app);
    dishRecipeFile.open(nameOfRecipeFile, std::ios::in
                       |std::ios::out | std::ios::app);

    if (dishListFile.is_open() && dishRecipeFile.is_open())
    {
        getDetailOfDish();

        // Write The name of the dish on the text which contain
        // list of dishes.
        dishListFile   << "\n" <<  name ;
        
        // Write the Name, description, price and recipe of a
        // dish on the file that contain the details of dishes
        // for a specific country.
        dishRecipeFile << "\n" <<  name << std::endl;
        dishRecipeFile << "\t" <<  "Description: " 
                       << "\n\t\t" << details << std::endl;
        dishRecipeFile << "    Price:" << std::endl 
                       << price << std::endl;
        dishRecipeFile << "\tRecipe\n\t\t" << recipe << "\nSTOP!" ;
        system("cls");
        std::cout << lengthManip5 << manipWidth50 << "MEAL added successfully\n";
    }
    else
        NoPermision();

}
/**
 * Name       : deleteDishes
 * Class      : Admin.
 * Parameters : None.
 * Short Description :
            Deletes a dish of a country according to the adminstrator
            Choice. this is done by opening the text file that contains
            the list of dishes of a country. Then every line is copied
            to another temporary file except the line that contains
            the name of the dish to be deleted.
*/
void Admin::deleteDishes()
{
    // textFiles// - is the directory where all text files
    //             - for this project are located.
    std::string nameOfListFile   {"textFiles//"};
    std::string nameOfRecipeFile {"textFiles//"};
    std::string nameOfTempFile   {"textFiles//"};

    listCountries();

    countryChoice = enforceCountryChoice();
    std::cout << lengthManip5;

    // This function opens a file depending on the userChoice.
    whichFileToOpen(countryChoice, nameOfListFile, 
                  nameOfRecipeFile, nameOfTempFile);
    std::fstream dishListFile;
    std::fstream dishListTempfile;

    // List dishes of a country
    if (countryChoice == '1'){
        habesha habeshaobj;
        system("cls");
        std::cout << lengthManip5 << manipOrder << "\t\t Choose an Ethiopian dish to delete.\n";
        habeshaobj.listDishes();
    }
    else if (countryChoice == '2'){
        hindu hinduObj;
        system("cls");
        std::cout << lengthManip5 << manipOrder << "\t\t Choose a hindu dish to delete.\n";
        hinduObj.listDishes();

    }
    else if (countryChoice == '3'){
        mynamar mynamarObj;
        system("cls");
        std::cout << lengthManip5 << manipOrder << "\t\t Choose a Mynamar dish to delete.\n";
        mynamarObj.listDishes();
    }
    else if (countryChoice == '4'){
        syria syriaObj;
        system("cls");
        std::cout << lengthManip5 << manipOrder << "\t\t Choose an Syrian dish to delete.\n";
        syriaObj.listDishes();
    }
    
    std::cout << manipPrompt;
    std::cin >> delMealChoice;
    std::cout << lengthManip5;    

        dishListFile.open(nameOfListFile, std::ios::in);
    dishListTempfile.open(nameOfTempFile, std::ios::out);

    if (dishListFile.is_open() && dishListTempfile.is_open())
    {
        /**
         * Loop (delMealChoice) number of times in the list file so
         * that it stopes when it reaches the line that contains 
         * the specific dish to be deleted. then copy every line
         * except the delmealChoice line eg third line in the file
         * if delMealChoice(user choice to delete a dish) is three.
         */
        while (dishListFile.good())
        {
            getline(dishListFile, list);
            int len = findLineLength(list);

            if (len > 2){
                // Write every line on the temporary file
                if (i != delMealChoice)
                    dishListTempfile << list << std::endl;
                // This is the line that contains the dish to be
                // deleted so it is not witten on the temporary file
                else
                    deletedDish = list;
                i++;
            }
        }
        system("cls");
        std::cout << lengthManip5 << manipWidth50 << deletedDish << " Deleted Successfully.\n";
        dishListFile.close();
        dishListTempfile.close();
    }

       dishListFile.open(nameOfListFile, std::ios::out);
    dishListTempfile.open(nameOfTempFile, std::ios::in);

    if (dishListTempfile.is_open() && dishListFile.is_open())
    {
        dishListFile.seekp(0);
        dishListTempfile.seekg(0);

        // Copy all containts of the temporary file (which has
        // list of dishes except the deleted one) to the original
        // text file that contains list of dishes.
        while (dishListTempfile.good())
        {
            getline(dishListTempfile, list);
            dishListFile << list << std::endl;
        }
        dishListFile.close();
        dishListTempfile.close();
    }
    else
        NoPermision();

}
/**
 * Name       : loginAccount
 * Class      : Admin.
 * Parameters : None.
 * Short Description :
            logs in to administrator account by reading and comparing
            password and id saved in adminAccounts text file and the
            user input.
*/
bool Admin::loginAccount()
{    
    std::fstream adminFile;
    adminFile.open("textFiles//adminAccounts.txt", std::ios::in);

    std::cout << manipWidth50 << "\b\bEnter Details to Login\n";
    if (adminFile.is_open()){

        // Prompt for admin id and password.
        std::cout << manipWidth50 << "Enter Id: ";  
        std::cin >> id;
        std::cout<< manipWidth50 << "PassWord: ";      
        std::cin >> password;

       while(adminFile.good())
        {
            // Change user inputs to strings since the password and id 
            // stored in the file are strings and we need to compare them.
            std::string   adminId = std::to_string(id);
            std::string adminPass = " " + std::to_string(password);

            getline(adminFile, list);

            // if user input of id is found on list of accounts then check
            // for the password if it exists then return true else false.
            if (list == adminId){
                for (int i = 1; i <= 3; i++)
                    getline(adminFile, list);
                if (list == adminPass){
                    adminFile.close();
                    return true;
                }
                adminFile.close();
                return false;
            }
        }
        adminFile.close();
    }
    return false;
}
/**
 * Name       : createAccount
 * Class      : Admin.
 * Parameters : None.
 * Short Description :
            creates administrator account by ensuring the admin knows
            the master password. Then a 4 digit id and a 6 digit
            password is automatically generated and prompted on the
            screen after account is successefully created.
            the admin is prompted to enter name, account and phone
            number only.
*/
void Admin::createAccount()
{
    std::fstream adminFile;
    adminFile.open("textFiles//adminAccounts.txt", 
                   std::ios::out | std::ios::app);

    if (adminFile.is_open())
    {
        getDetailsOf();

        // Write the details of new admin to adminAccounts
        // text file. id and password are randomly generated
        adminFile << id << std::endl;
        adminFile << "\t" << firstName   << " " 
                 << secondName << std::endl;
        adminFile << "\t" << phoneNumber << std::endl;
        adminFile << " "  << password    << std::endl;
        adminFile << "\t" << bankAccount << std::endl;
        adminFile << "  " << randGenerator(1000, 10000000) << std::endl;

        std::cout << lengthManip5 << manipWidth50 << "ACCOUNT DETAILS\n";
        std::cout << manipWidth50 << "    Login Id: " << id << std::endl;
        std::cout << manipWidth50 << "    Password: " << password << "\n\n";
    }
    else{
        std::cout << "Error.";
    }

}

#endif