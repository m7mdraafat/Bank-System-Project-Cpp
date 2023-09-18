#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include"clsString.h"
class clsFindCurrecnyScreen : protected clsScreen
{
private: 
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card: \n";  
		cout << "\n______________________\n";
		cout << "\n Country    : " << Currency.Country();
		cout << "\n Code       : " << Currency.CurrencyCode();
		cout << "\n Name       : " << Currency.CurrencyName();
		cout << "\n Rate(1$) = : " << Currency.Rate(); 
		cout << "\n______________________\n";


	}
	static void _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\n Currency Found :-)\n"; 
			_PrintCurrency(Currency); 
		 }
		else {
			cout << "\n Currency was not found:-(\n"; 
		}
	}
public: 
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen"); 
		
		cout << "\nFind By: [1] Code or [2] Country ? "; 
		short answer = 1; 
		cin >> answer;

		if (answer == 1)
		{
			string CurrencyCode; 
			cout << "\n Please Enter CurrencyCode: "; 
			CurrencyCode = clsInputValidate<string>::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResult(Currency); 
		}
		else if (answer == 2)
		{
			string Country;
			cout << "\n Please Enter CountryName: "; 
			Country = clsInputValidate<string>::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country); 
			_ShowResult(Currency); 
		}
		
	}
};

