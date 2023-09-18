#pragma once
#include<iostream>
#include<string>
using namespace std;
class clsPreson
{
private:
	string _FirstName;
	string _LastName;
	string _Emal;
	string _Phone;

public:
	clsPreson(string FirstName, string LastName, string Email, string Phone) {
		_FirstName = FirstName;
		_LastName = LastName;
		_Emal = Email;
		_Phone = Phone;
	}

	// Properties set & get 

	void SetFirstName(string FirstName) {
		_FirstName = FirstName;
	}

	string GetFirstName() {
		return _FirstName;
	}
	__declspec(property(get = GetFirstName, put = SetFirstName))string FirstName;

	void SetLastName(string LastName) {
		_LastName = LastName;
	}
	string GetLastName() {
		return _LastName;
	}
	__declspec(property(get = GetLastName, put = SetLastName))string LastName;
	string FullName()
	{
		return _FirstName + " " + _LastName;
	}
	void SetEmail(string Email) {
		_Emal = Email;
	}
	string GetEmail() {
		return _Emal;
	}
	__declspec(property(get = GetEmail, put = SetEmail))string Email;

	void SetPhone(string Phone) {
		_Phone = Phone;
	}
	string GetPhone() {
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone))string Phone;

};

