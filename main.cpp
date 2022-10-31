#include <iostream>
#include <string>

using namespace std;
void login (string password,string user, std::string info);
void UI(std::string password, std :: string user, std :: string info);

void Change_info (std::string password,std::string user,std::string info)
{
    std :: cout << "Current info: ";
    std :: cout << info;
    std :: cout << "\n use _ as spaces \n";
    std :: cout << "New info: ";
    std :: cin >> info;
    UI(password,user,info);
}

void read_info(std::string info)
{
    std::string usless;
    std::cout << info;
    std::cout << "\n\n";
    std :: cout << "Enter anything to continue \n";
    std::cin >> usless;
}

std :: string changeuser(std::string user)
{
    std :: string user_check;
    std :: string user_new;
    std :: cout << "Enter old username \n";
    std :: cin >> user_check;
    if (user_check == user)
    {
        std :: cout << "Enter new username \n";
        std :: cin >> user_new;
    }
    else
    {
        std :: cout << "Try again \n";
        changeuser(user);
    }
    return user_new;
}

std :: string changepass(std::string password)
{
    std :: string password_check;
    std :: string password_new;
    std :: cout << "Enter old password \n";
    std :: cin >> password_check;
    if (password_check == password)
    {
        std :: cout << "Enter new password \n";
        std :: cin >> password_new;
    }
    else
    {
        std :: cout << "Try again \n";
        changepass(password);
    }
    return password_new;
}

void UI(std::string password, std :: string user, std :: string info)
{
    std :: string choice;
    std :: cout << "What do you what to do? \n";
    std :: cout << "1) change password \n";
    std :: cout << "2) change username \n";
    std :: cout << "3) Change storaged info \n";
    std :: cout << "4) Read storaged info \n";
    std :: cout << "5) exit \n";
    std :: cout << "6) shut down \n";
    std :: cin >> choice;
    if (choice == "6")
    {
        exit(0);
    }
    else if (choice == "1")
    {
        password = changepass(password);
        UI(password, user, info);
    }
    else if (choice == "2")
    {
        user = changeuser(user);
        UI(password, user, info);
    }
    else if (choice == "3")
    {
        Change_info(password,user,info);
    }
    else if (choice == "4")
    {
        read_info(info);
        UI(password,user,info);
    }
    else if (choice == "5");
    {
        login(password, user, info);
    }
}

void login (string password,string user, std :: string info)
{
std :: string password_enter;
std :: string user_enter;
//std :: cout << user;
//std :: cout << password;
std :: cout << "Enter username \n";
std :: cin >> user_enter;
std :: cout << "Enter password \n";
std :: cin >> password_enter;
if (user_enter == user and password_enter == password)
{
    std :: cout << "Acess granted \n";
    UI(password, user, info);
}
else
{
    std :: cout << "Wrong username or password, try again \n \n";
    login(password, user,info);
}
}

int main ()
{
std :: string password = "00000000";
std :: string user = "admin";
std :: string info = "No storaged info";
int choice = 0;
std::cout << "What do you want to do?";
std::cout << "\n1) login";
std::cout << "\n2) exit \n";
std::cin >> choice;
if (choice == 2)
{
    exit;
}
if (choice == 1)
{
    login(password, user, info);
}
}