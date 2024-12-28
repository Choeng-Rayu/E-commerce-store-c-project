#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<ctime>
#include "invoice.h"
#include <memory> // For std::unique_ptr  //include <memory> in C++ when you want to use smart pointers such as std::unique_ptr, std::shared_ptr, or std::weak_ptr. These smart pointers are part of the C++ Standard Library and were introduced in C++11 to simplify memory management and prevent common issues like memory leaks and dangling pointers.


using namespace std;

#define FILE_HISTORY "history data.csv" // store all the history of the customer
#define FILE_INVOICE "Invoice data.csv" // store all the invoice of the customer


void display_menu()
{
    cout << "0. Exit\n"
         << "1. Add product to history\n"
         << "2. Remove product from history\n"
         << "3. Display history\n"
         << "4. Save history to file\n"
         << "5. Get invoice\n";
}


// int main()
// {
//     history_customer* history = new history_customer(); // Dynamically allocated
//     int choice;

//     while (true)
//     {
//         displayMenu();
//         cout << "Enter your choice: ";
//         cin >> choice;
//         switch (choice)
//         {
//             case 1:
//             {
//                 string name, type;
//                 int id, price, amount;
//                 cout << "Enter Name: ";
//                 cin.ignore();
//                 getline(cin, name);
//                 cout << "Enter ID: ";
//                 cin >> id;
//                 cout << "Enter Price: ";
//                 cin >> price;
//                 cout << "Enter Amount: ";
//                 cin >> amount;
//                 cout << "Enter Type: ";
//                 cin >> type;
//                 history->product_add_to_history(name, id, price, amount, type);
//                 break;
//             }
//             case 2:
//                 history->delete_product_from_history();
//                 break;
//             case 3:
//                 history->display_history();
//                 break;
//             case 4:
//                 history->save_to_file();
//                 break;
//             case 0:
//                 cout << "Exiting the program.\n";
//                 delete history; // Deallocate memory before exiting
//                 return 0;
//             default:
//                 cout << "Invalid choice. Please try again.\n";
//                 break;
//         }
//     }
//     return 0;
// }

int main()
{
    unique_ptr<history_customer> history(new history_customer()); // Dynamically allocated
    int choice;
    while(1)
    {
        display_menu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                system("cls");
                system("color 3A");
                string name, type;
                int id, price, amount;
                cout << "Enter Name product:";
                cin.ignore();
                getline(cin, name);
                cout << "Enter ID product:";
                cin >> id;
                cout << "Enter Price product:";
                cin >> price;
                cout << "Enter Amount product:";
                cin >> amount;
                cout << "Enter Type product:";
                cin >> type;
                history->product_add_to_history(name, id, price, amount, type);
                break;
            }
            case 2:
            {
                system("cls");
                system("color 1a");
                history->delete_product_from_history();
                break;
            }
            case 3:
            {
                system("cls");
                system("color 0A");
                history->display_history();
                break;
            }
            case 4:
            {
                system("cls");
                system("color 2A");
                history->save_to_file();
                break;
            }
            case 5:
            {
                system("cls");
                system("color 6A");
                history->get_invioce("book", 1, 100, 2, "study");
                break;
            }   
            case 0:
            {
                system("cls");
                system("color 4A");
                cout << "Exit successfully." << endl;
                exit(0);
            }
            default:
            {
                system("cls");
                system("color 5A");
                cout << "Invalid choice." << endl;
                break;
            }

        }
    }
    return 0;
}
