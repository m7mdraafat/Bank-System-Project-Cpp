#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsDate.h"
// Text colors
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

// Bold text colors
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

// Background colors
#define BACKBLACK   "\033[40m"      /* Black */
#define BACKRED     "\033[41m"      /* Red */
#define BACKGREEN   "\033[42m"      /* Green */
#define BACKYELLOW  "\033[43m"      /* Yellow */
#define BACKBLUE    "\033[44m"      /* Blue */
#define BACKMAGENTA "\033[45m"      /* Magenta */
#define BACKCYAN    "\033[46m"      /* Cyan */
#define BACKWHITE   "\033[47m"      /* White */

// Reset all attributes
#define RESETATTR   "\033[0m"
using namespace std;

class clsScreen
{
protected:


    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        std::cout << "\t\t\t\t\t______________________________________";
        std::cout << "\n\n\t\t\t\t\t  " << BOLDBLUE << Title << RESET; // Bold Blue color for the title
        if (SubTitle != "")
        {
            std::cout << "\n\t\t\t\t\t  " << CYAN << SubTitle << RESET; // Cyan color for the subtitle
        }
        std::cout << "\n\t\t\t\t\t______________________________________\n";
        std::cout << "\n\t\t\t\t\tUser: " << BOLDGREEN << CurrentUser.UserName << RESET << "\n"; // Bold Magenta color for the username
        std::cout << "\t\t\t\t\tDate: " << BOLDYELLOW << clsDate::DateToString(clsDate()) << RESET << "\n"; // Bold Red color for the date
        std::cout << "\n";
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << BOLDRED<< "\n\n\t\t\t\t\t  Access Denied! Contact your Admin."<<RESET;
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }

};
