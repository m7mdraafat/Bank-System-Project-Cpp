#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
class clsCurrencyCalculatorScreen:protected clsScreen
{
private : 
    static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
    {

        cout << "\n" << Title << "\n";
        cout << "_____________________________\n";
        cout << "\nCountry       : " << Currency.Country();
        cout << "\nCode          : " << Currency.CurrencyCode();
        cout << "\nName          : " << Currency.CurrencyName();
        cout << "\nRate(1$) =    : " << Currency.Rate();
        cout << "\n_____________________________\n\n";

    }
     static clsCurrency _GetCurrency(string Message)
     {

         string CurrencyCode;
         cout << Message << endl;

         CurrencyCode = clsInputValidate<string>::ReadString();

         while (!clsCurrency::IsCurrencyExist(CurrencyCode))
         {
             cout << "\nCurrency is not found, choose another one: ";
             CurrencyCode = clsInputValidate<string>::ReadString();
         }

         clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
         return Currency;
     }
     static float _ReadAmount()
     {
         cout << "\nEnter Amount to Exchange: ";
         float Amount = 0;

         Amount = clsInputValidate<float>::ReadNumber();
         return Amount;
     }

     static void _PrintCalculationsResults(clsCurrency Currency1, clsCurrency Currency2, float amount)
     {
         _PrintCurrencyCard(Currency1, "Convert From: "); 
         float AmountInUSD = Currency1.ConvertToUSD(amount); 

         cout << amount << " " << Currency1.CurrencyCode()
             << " = " << AmountInUSD << " USD\n";

         if (Currency2.CurrencyCode() == "USD") {
             return; 
         }
         cout << "\nConverting from USD to:\n";

         _PrintCurrencyCard(Currency2, "To:");

         float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(amount, Currency2);
         cout << amount << " " << Currency1.CurrencyCode()
             << " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();
     }
public:
    static void ShowCalculatorCurrencyScreen()
    {
        char continu = 'y'; 

        while (continu == 'y' || continu == 'Y')
        {
            system("cls"); 
            _DrawScreenHeader("    Calculator Currency Screen");

            clsCurrency  CurrencyFrom = _GetCurrency("Please Enter Currency1 Code");
            clsCurrency  CurrencyTo = _GetCurrency("Please Enter Currency2 Code");
            float Amount = _ReadAmount(); 

            _PrintCalculationsResults(CurrencyFrom, CurrencyTo, Amount); 

            cout << "\n\n Do you want to perform another calculation[y/n] ? "; 
            cin >> continu; 
        }
       

     }

};

