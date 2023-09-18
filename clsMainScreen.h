#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include"clsCurrencyExchangeMainScreen.h"
using namespace std;
// Text colors
#define RESET   "\033[0m"


// Bold text colors
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

class clsMainScreen :protected clsScreen
{


private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8,eCurrencyExchange=9 ,eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do?"<< BOLDCYAN<<"[1 to 10] ? "<<RESET;
        short Choice = clsInputValidate<short>::ReadNumberBetween(1, 10, "Enter Number between 1 to 10? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        //  cout << "\nClient List Screen Will be here...\n";
        clsClientListScreen::ShowClientsList();


    }

    static void _ShowAddNewClientsScreen()
    {
        // cout << "\nAdd New Client Screen Will be here...\n";
        clsAddNewClientScreen::ShowAddNewClientScreen();

    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";
        clsDeleteClientScreen::ShowDeleteClientScreen();

    }

    static void _ShowUpdateClientScreen()
    {
        //cout << "\nUpdate Client Screen Will be here...\n";
        clsUpdateClientScreen::ShowUpdateClientScreen();


    }

    static void _ShowFindClientScreen()
    {
        // cout << "\nFind Client Screen Will be here...\n";
        clsFindClientScreen::ShowFindClientScreen();


    }

    static void _ShowTransactionsMenue()
    {
        // cout << "\nTransactions Menue Will be here...\n";
        clsTransactionsScreen::ShowTransactionsMenue();

    }

    static void _ShowManageUsersMenue()
    {
        // cout << "\nUsers Menue Will be here...\n";
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowLoginRegisterScreen()
    {
        // cout << "\nLogin Register Will be here...\n";
        clsLoginRegisterScreen::ShowLoginRegisterScreen();

    }
    static void _ShowCurrencyExhangeScreen()
    {
        clsCurrencyExchangeMainScreen::ShowCurrenciesMenue(); 
    }
    static void _Logout()
    {

        CurrentUser = clsUser::Find("", "");

        //then it will go back to main function.
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eLoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eCurrencyExchange:
            system("cls");
            _ShowCurrencyExhangeScreen(); 
            _GoBackToMainMenue(); 
            break; 
        case enMainMenueOptions::eExit:
            system("cls");
            _Logout();
            break;
        }

    }



public:


    static void ShowMainMenue()
    {

        system("cls");
        _DrawScreenHeader("\t     Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\t"<<BOLDCYAN <<"Main Menue"<< RESET "\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t" << BOLDBLUE "[1]" << RESET << " Show Client List.\n";
        cout << setw(37) << left << "" << "\t" << BOLDBLUE "[2]" << RESET << " Add New Client.\n";
        cout << setw(37) << left << "" << "\t" << BOLDBLUE "[3]" << RESET << " Delete Client.\n";
        cout << setw(37) << left << "" << "\t" << BOLDBLUE "[4]" << RESET << " Update Client Info.\n";
        cout << setw(37) << left << "" << "\t" << BOLDBLUE "[5]" << RESET << " Find Client.\n";
        cout << setw(37) << left << "" << "\t" << BOLDBLUE "[6]" << RESET << " Transactions.\n";
        cout << setw(37) << left << "" << "\t" << BOLDBLUE "[7]" << RESET << " Manage Users.\n";
        cout << setw(37) << left << "" << "\t" << BOLDBLUE "[8]" << RESET << " Login Register.\n";
        cout << setw(37) << left << "" << "\t" << BOLDBLUE "[9]" << RESET << " Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t" << BOLDRED  "[10]" <<" Logout.\n"<<RESET;
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }

};

