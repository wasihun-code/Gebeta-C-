#include "headerFiles//Admin.h"


int main(void)
{
    home:
        system("color 04");
        system("cls");
        std::cout << lengthManip5;
        std::cout << manipWidth50 << "GEBETA INTERNATIONAL" << twoNew;
        std::cout << manipWidth50 << "1. Login\n";
        std::cout << manipWidth50 << "2. Create Account\n";
        std::cout << manipWidth50 << "\b\b Press Q to Exit\n";

        userChoice = enforceUserChoice();
        system("cls");

        // LOGIN ACCOUNT Interface
        if      (userChoice == '1'){
        login:            
            char loginChoice;
            char homeOrExit;

            std::cout << lengthManip5;
            std::cout << manipWidth50 << "   LOGIN PAGE" << twoNew;
            std::cout << manipWidth50 << "1. User Login\n";
            std::cout << manipWidth50 << "2. Admin Login\n";
            std::cout << manipWidth50 << "\b\b Press Q to Home\n";

            loginChoice = enforceUserChoice();
            system("cls");
            std::cout << lengthManip5;

            if      (loginChoice == '1'){    
            userLogin:    
                std::cout << manipWidth50 << "USER LOGIN PAGE" << twoNew;                       
                user oldUser;
                bool loggedIn;

                loggedIn = oldUser.loginAccount();

                if (loggedIn){
                userLoggedin: 
                        system("cls");
                        std::cout << lengthManip5;
                        std::cout << manipWidth50 << "LOGGED IN SUCCESSEFULLY" << twoNew;

                    countryList:
                        listCountries();
                        std::cout << manipWidth50 << "Press Q to go to home\n";

                        countryChoice = enforceCountryChoice();
                        system("cls");
                        std::cout << lengthManip5;

                        dishList:
                        
                            // Implements countrly wise dish lists and description
                            // according to user choice from list of 4 countries
                            if      (countryChoice == '1'){
                                habesha habesha1;
                                char goback;

                                std::cout << manipWidth50 << "  Choose an Ethopian dish" << twoNew;
                            
                                habesha1.listDishes();
                                std::cout << manipWidth50 << "  (0 to go back)\n";

                                std::cout << manipPrompt;
                                std::cin >> dishChoice;
                                system("cls");
                                std::cout << lengthManip5;  

                                if (dishChoice == 0)
                                    goto countryList;
                                else
                                    habesha1.view_details(dishChoice);
                                
                            }
                            else if (countryChoice == '2'){
                                hindu hindu1;

                                std::cout << manipWidth50 << "Choose an Indian dish" << twoNew;

                                hindu1.listDishes();
                                std::cout << manipWidth50 << "  (0 to go back)\n";

                                std::cout << manipPrompt;
                                std::cin >> dishChoice;
                                system("cls");
                                std::cout << lengthManip5;  

                                if (dishChoice == 0)
                                    goto countryList;
                                else
                                    hindu1.view_details(dishChoice);           
                            }
                            else if (countryChoice == '3'){
                                mynamar mynamarObj;

                                std::cout << manipWidth50 << "Choose a Mynamar dish" << twoNew;

                                mynamarObj.listDishes();
                                std::cout << manipWidth50 << "  (0 to go back)\n";

                                std::cout << manipPrompt;
                                std::cin >> dishChoice;
                                system("cls");
                                std::cout << lengthManip5;  

                                if (dishChoice == 0)
                                    goto countryList;
                                else
                                    mynamarObj.view_details(dishChoice);    
                            }
                            else if (countryChoice == '4'){
                                syria syriaObj;

                                std::cout << manipWidth50 << "Choose a Syrian dish" << twoNew;

                                syriaObj.listDishes();
                                std::cout << manipWidth50 << "  (0 to go back)\n";

                                std::cout << manipPrompt;
                                std::cin >> dishChoice;
                                system("cls");
                                std::cout << lengthManip5;  

                                if (dishChoice == 0)
                                    goto countryList;
                                else
                                    syriaObj.view_details(dishChoice);    
                            }        
                            else if (countryChoice == 'Q' || countryChoice == 'q'){
                                goto home;
                            }
                            
                            std::cout << std::endl;
                            std::cout << manipWidth50 << "1. Order\n";
                            std::cout << manipWidth50 << "2. Countries\n";

                            navChoice = enforceUserChoice();
                            system("cls");
                            std::cout << lengthManip5;
                        
                        if (navChoice == '1'){
                            oldUser.orderMeal();
                            std::cout << manipOrder << "  Press any key to go back: ";

                            std::cin >> navChoice;
                            system("cls");
                            std::cout << lengthManip5;

                            if (navChoice )
                                goto countryList;
                        }
                        else{
                            goto countryList;
                        }
                }
                else{
                    std::cout << manipWidth50 << "Try again with valid credentials.\n";
                    goto home;
                }
            }
            else if (loginChoice == '2'){
            AdminLogin:
                std::cout << manipWidth50 << "  ADMIN LOGIN PAGE" << twoNew;
                Admin oldAdmin;
                bool loggedIn;

                loggedIn = oldAdmin.loginAccount();

                system("cls");
                std::cout << lengthManip5;
                if (loggedIn){
                    adminLoggedIn:
                        Admin admin;

                        std::cout << manipWidth50 << "CHOOSE OPTION" << twoNew;

                        std::cout << manipWidth50 << "1. Add meals\n";
                        std::cout << manipWidth50 << "2. Delete meals\n";
                        std::cout << manipWidth50 << "\b\b Press Q to Home\n";


                        adminOptionChoice = enforceUserChoice();

                        system("cls");
                        std::cout << lengthManip5;

                        if      (adminOptionChoice == '1'){
                            admin.addDishes();

                            std::cout << lengthManip5 << manipOrder << "Press any key to go back: ";

                            std::cin >> loginChoice;
                            system("cls");
                            std::cout << lengthManip5;

                            if (loginChoice)
                                goto adminLoggedIn;
                        }
                        else if (adminOptionChoice == '2'){
                            admin.deleteDishes();
                            
                            std::cout << lengthManip5 << manipOrder << "Press any key to go back: ";

                            std::cin >> loginChoice;
                            system("cls");
                            std::cout << lengthManip5;

                            if (loginChoice)
                                goto adminLoggedIn;
                        }
                        else{
                            goto home;
                        }
                }
                else{
                    std::cout << manipWidth50 << "Try again with valid credential\n";
                }
            }
            else{
                std::cout << manipWidth50 << "Try again with valid credentials.\n";
                goto home;
            }
        }
        
        // CREATE ACCOUNT Interface
        else if (userChoice == '2'){
        createAccount:
            char homeOrExit;
            char createUserAdmin;

            std::cout << lengthManip5 << manipWidth50 << "  ACCOUNT TYPE" << twoNew;

            std::cout << manipWidth50 << "1. User Account\n";
            std::cout << manipWidth50 << "2. Admin Account\n";

            createUserAdmin = enforceUserChoice();
            system("cls");
            std::cout << lengthManip5;

            if      (createUserAdmin == '1'){
                user newUser;

                std::cout << lengthManip5 << manipWidth50 << "CREATE USER ACCOUNT \n";
                newUser.createAccount();
            }
            else if (createUserAdmin == '2'){
                int masterPass;

                std::cout << manipOrder << "MASTER password(to access admin privilages).\n";
                std::cout << manipPrompt;   

                std::cin >> masterPass;
                system("cls");

                if (masterPass == 1234){                                    
                    Admin newAdmin;

                    std::cout << lengthManip5 << manipOrder << "  SUCCESS!" << twoNew;
                    std::cout << manipOrder << "CREATE ADMIN ACCOUNT\n";

                    newAdmin.createAccount();            
                }
                else{
                    goto home;
                }
            }
            std::cout << manipWidth50 << "Account created Successfully\n";
            std::cout << manipWidth50 << "Press any key to go to home: ";

            std::cin >> homeOrExit;
            system("cls");
            std::cout << lengthManip5;

            if (homeOrExit)
                goto home;
        }
}
