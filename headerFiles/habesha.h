#ifndef HABESHA_H
#define HABESHA_h

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
class habesha
{
protected:
    std::string line;

public:
    habesha() = default;
    void view_details(int);
    void listDishes();
};
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
void habesha::view_details(int dishChoice)
{
    std::fstream habeshaList;
    std::fstream habeshaRecipe;

    habeshaRecipe.open("textFiles//habeshaRecipe.txt",
                       std::ios::out | std::ios::in);
    habeshaList.open("textFiles//habesha.txt",
                     std::ios::out | std::ios::in);

    if (habeshaList.is_open() && habeshaRecipe.is_open())
    {
        std::string list{}, name{}, recipe{};
        int j{1};

        while (habeshaList.good() && j <= dishChoice)
        {
            getline(habeshaList, list); // Tibs in habesha.txt
            int len = findLineLength(list);
            if (len > 1)
                j++;
        }
        while (habeshaRecipe.good())
        {
            getline(habeshaRecipe, name); // Tibs in habeshaRecipe.txt
            if (list == name)
            {
                dishName = list;
                std::cout << manipOrder << "\t" << list << std::endl;
                while (habeshaRecipe.good())
                {
                    getline(habeshaRecipe, recipe);
                    if (recipe == "STOP!")
                    {
                        break;
                    }
                    else if (recipe == "    Price:")
                        findPriceOfDish(habeshaRecipe, recipe, priceOfDish);
                    else
                    {
                        std::cout << manipOrder << recipe << std::endl;
                    }
                }
            }
        }
        std::cout << manipWidth50 << "PRICE: " << priceOfDish << std::endl;
        habeshaList.close();
        habeshaRecipe.close();
    }
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
void habesha::listDishes()
{
    std::fstream file("textFiles//habesha.txt", std::ios::in | std::ios::out);

    if (file.is_open())
    {
        int i{1};
        std::string line{};

        while (file.good())
        {
            getline(file, line);
            int len = findLineLength(line);

            if (len > 2)
            {
                std::cout << manipWidth50 << i << ". " << line << std::endl;
                i++;
            }
        }
        file.close();
    }
    else
        std::cout << "\n\t Dish not ready!\n";
}

#endif