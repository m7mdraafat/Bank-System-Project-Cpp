//ProgrammingAdivces.com
//Mohammed Abu-Hadhoud

#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"
template <class T> 
class clsInputValidate
{

public:

	

	static T IsNumberBetween(T Number, T From, T To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static T IsDateBetween(T Date, T From, T To)
	{
		//Date>=From && Date<=To
		if ((T::IsDate1AfterDate2(Date, From) || T::IsDate1EqualDate2(Date, From))
			&&
			(T::IsDate1BeforeDate2(Date, To) || T::IsDate1EqualDate2(Date, To))
			)
		{
			return true;
		}

		//Date>=To && Date<=From
		if ((T::IsDate1AfterDate2(Date, To) || T::IsDate1EqualDate2(Date, To))
			&&
			(T::IsDate1BeforeDate2(Date, From) || T::IsDate1EqualDate2(Date, From))
			)
		{
			return true;
		}

		return false;
	}


	static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		T Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	

	static T ReadNumberBetween(T From, T To,  string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		T Number = ReadNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadNumber();
		}
		return Number;
	}

	
	static T IsValideDate(T Date)
	{
		return	T::IsValidDate(Date);
	}

	static T ReadString()
	{
		T  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}


};

