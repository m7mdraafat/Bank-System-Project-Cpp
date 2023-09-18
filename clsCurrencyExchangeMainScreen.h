#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrecnyScreen.h"
#include"clsUpdateCurrecnyRateScreen.h"
#include"clsCurrencyCalculatorScreen.h"
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
class clsCurrencyExchangeMainScreen:protected clsScreen
{
private: 
	 
	enum enCurrencyExchangeMenueOption {eListCurrencies =1, eFindCurrencies = 2 , eUpdateRate = 3 , eCurrencyCalculator=4,eMainMenue=5};
	
	static short _ReadCurrenciesMainMenueOptions()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? "<< BOLDMAGENTA << "[1 to 5] ? "<<RESET;
		short Choice = clsInputValidate<short>::ReadNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}
	static void _GoBackToCurrenciesMenue()
	{
		cout << "\n\nPress any key to go back to Currencies Menue...";
		system("pause>0");
		ShowCurrenciesMenue();
	}
	static void _ShowCurrenciesListScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();  
	}
	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrecnyScreen::ShowFindCurrencyScreen(); 
	}
	static void _ShowUpdateRateScreen()
	{
		clsUpdateCurrecnyRateScreen::ShowUpdateCurrencyRateScreen();  
	}
	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCalculatorCurrencyScreen(); 
	}
	static void _PerformCurrencyMainMenueOptions(enCurrencyExchangeMenueOption CurrencyMainMenueOption)
	{
		switch (CurrencyMainMenueOption)
		{
		case clsCurrencyExchangeMainScreen::eListCurrencies:
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrenciesMenue();
			break;
		case clsCurrencyExchangeMainScreen::eFindCurrencies:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrenciesMenue();
			break;
		case clsCurrencyExchangeMainScreen::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrenciesMenue();

			break;
		case clsCurrencyExchangeMainScreen::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrenciesMenue();

			break;
		case clsCurrencyExchangeMainScreen::eMainMenue:
		{
			//do nothing here the main screen will handle it :-) ;
		}
	}
    }
public:
	 
	static void ShowCurrenciesMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
		{
			return;// this will exit the function and it will not continue
		}
		system("cls");
		_DrawScreenHeader("    Currency Exchange Main Screen"); 
		 
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t"<<BOLDCYAN<< "Currency Exhange Menue\n"<<RESET ;
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t" << BOLDMAGENTA << "[1]" << RESET << " List Currencies.\n";
		cout << setw(37) << left << "" << "\t" << BOLDMAGENTA << "[2]" << RESET << " Find Currency.\n";
		cout << setw(37) << left << "" << "\t" << BOLDMAGENTA << "[3]" << RESET << " Update Rate.\n";
		cout << setw(37) << left << "" << "\t" << BOLDMAGENTA << "[4]" << RESET << " Currency Calculator.\n";
		cout << setw(37) << left << "" << BOLDBLUE << "\t[5] Main Menue.\n"<<RESET; 
		cout << setw(37) << left << "" << "===========================================\n";
		_PerformCurrencyMainMenueOptions((enCurrencyExchangeMenueOption)_ReadCurrenciesMainMenueOptions()); 
	}
};

