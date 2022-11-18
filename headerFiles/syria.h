#ifndef SYRIA_H
#define SYRIA_H

#include "header.h"

class syria
{
protected:
    std::string line;
public:
    syria() = default;
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
void syria::view_details(int dishChoice)
{
    std::fstream syriaList;
    std::fstream syriaRecipe;

    syriaRecipe.open("textFiles//syriaRecipe.txt", 
                        std::ios::out | std::ios::in);
    syriaList.open("textFiles//syria.txt", 
                std::ios::out | std::ios::in);

    if (syriaList.is_open() && syriaRecipe.is_open())
    {
        std::string list {}, name {}, recipe {};
        int j {1} ;

        while (syriaList.good() && j <= dishChoice)
        {
            getline(syriaList, list); // Tibs in syria.txt
            int len = findLineLength(list);
            if (len > 1)
                j++;
        }    
        while (syriaRecipe.good())
        {
            getline(syriaRecipe, name); // Tibs in syriaRecipe.txt
            if (list == name)
            {
                dishName = list;
                std::cout << manipOrder << "\t" <<  list << std::endl;                    
                while (syriaRecipe.good())
                {
                    getline(syriaRecipe, recipe);
                    if (recipe == "STOP!"){
                        break;
                    }
                    else if (recipe == "    Price:")
                        findPriceOfDish(syriaRecipe, recipe, priceOfDish);
                    else{
                        std::cout << manipOrder << recipe << std::endl;
                    }
                }

            }
    }
        std::cout << manipWidth50 << "PRICE: " << priceOfDish << std::endl;
        syriaList.close();
        syriaRecipe.close();
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
void syria::listDishes()
{
    std::fstream file("textFiles//syria.txt", std::ios::in | std::ios::out);

    if (file.is_open()){
        int i {1};
        std::string line {};

        while(file.good())
        {
            getline(file, line);
            int len = findLineLength(line);

            if (len > 1){
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