#ifndef HINDU_H
#define HINDU_H

#include "header.h"

class hindu
{
protected:
    std::string line;
public:
    hindu() = default;
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
void hindu::view_details(int dishChoice)
{
    std::fstream hinduList;
    std::fstream hinduRecipe;

    hinduRecipe.open("textFiles//hinduRecipe.txt", 
                        std::ios::out | std::ios::in);
    hinduList.open("textFiles//hindu.txt", 
                std::ios::out | std::ios::in);

    if (hinduList.is_open() && hinduRecipe.is_open())
    {
        std::string list {}, name {}, recipe {};
        int j {1} ;

        while (hinduList.good() && j <= dishChoice)
        {
            getline(hinduList, list); // Tibs in hindu.txt
            int len = findLineLength(list);
            if (len > 1)
                j++;
        }    
        while (hinduRecipe.good())
        {
            getline(hinduRecipe, name); // Tibs in hinduRecipe.txt
            if (list == name)
            {
                dishName = list;
                std::cout << manipOrder << "\t" <<  list << std::endl;                    
                while (hinduRecipe.good())
                {
                    getline(hinduRecipe, recipe);
                    if (recipe == "STOP!"){
                        break;
                    }
                    else if (recipe == "    Price:")
                        findPriceOfDish(hinduRecipe, recipe, priceOfDish);
                    else{
                        std::cout << manipOrder << recipe << std::endl;
                    }
                }

            }
    }
        std::cout << manipWidth50 << "PRICE: " << priceOfDish << std::endl;
        hinduList.close();
        hinduRecipe.close();
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
void hindu::listDishes()
{
    std::fstream file("textFiles//hindu.txt", std::ios::in | std::ios::out);

    if (file.is_open()){
        int i {1}; 
        std::string line {};

        // file.good?
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