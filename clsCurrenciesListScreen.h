#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
class clsCurrenciesListScreen : protected clsScreen
{
private : 
	 
	static void PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8)  << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate(); 
	}
public:
	static void ShowCurrenciesListScreen()
	{
		vector<clsCurrency>vCurrencies = clsCurrency::GetCurrenciesList(); 
		string Title = "\n Currencies List Screen"; 
		string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency.";
		_DrawScreenHeader(Title, SubTitle); 

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8)  << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)"; 
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;

		if (vCurrencies.size() == 0)
			cout << "\n No Currencies avilable in the system!"; 
		else 
			for (clsCurrency C : vCurrencies)
			{
				PrintCurrencyRecordLine(C);
				cout << endl; 
			}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_______________________________________________\n" << endl;
 	}
};

