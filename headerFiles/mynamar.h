#ifndef MYNAMAR_H
#define MYNAMAR_H
class mynamar
{
protected:
    std::string line;
public:
    mynamar() = default;
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
void mynamar::view_details(int dishChoice)
{
    std::fstream mynamarList;
    std::fstream mynamarRecipe;

    mynamarRecipe.open("textFiles//mynamarRecipe.txt", 
                        std::ios::out | std::ios::in);
    mynamarList.open("textFiles//mynamar.txt", 
                std::ios::out | std::ios::in);

    if (mynamarList.is_open() && mynamarRecipe.is_open())
    {
        std::string list {}, name {}, recipe {};
        int j {1} ;

        while (mynamarList.good() && j <= dishChoice)
        {
            getline(mynamarList, list); // Tibs in mynamar.txt
            int len = findLineLength(list);
            if (len > 1)
                j++;
        }    
        while (mynamarRecipe.good())
        {
            getline(mynamarRecipe, name); // Tibs in mynamarRecipe.txt
            if (list == name)
            {
                dishName = list;
                std::cout << manipOrder << "\t" <<  list << std::endl;                    
                while (mynamarRecipe.good())
                {
                    getline(mynamarRecipe, recipe);
                    if (recipe == "STOP!"){
                        break;
                    }
                    else if (recipe == "    Price:")
                        findPriceOfDish(mynamarRecipe, recipe, priceOfDish);
                    else{
                        std::cout << manipOrder << recipe << std::endl;
                    }
                }

            }
    }
        std::cout << manipWidth50 << "PRICE: " << priceOfDish << std::endl;
        mynamarList.close();
        mynamarRecipe.close();
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
void mynamar::listDishes()
{
    std::fstream file("textFiles//mynamar.txt", std::ios::in | std::ios::out);

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