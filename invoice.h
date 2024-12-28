#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<ctime>

using namespace std;

#define FILE_HISTORY "history data.csv" // store all the history of the customer
#define FILE_INVOICE "Invoice data.csv" // store all the invoice of the customer

struct history_stack_customer
{
    string name;
    int id;
    int price;
    int amount;
    string type;
    history_stack_customer* next;
    int date;
};

class history_customer
{
    history_stack_customer* top;
    int totalProduct;
    public:
    history_customer()
    {
        top = NULL;
        totalProduct = 0;
    }
    void product_add_to_history(string name, int id, int price, int amount, string type)
    {
        history_stack_customer* newProduct = new history_stack_customer;
        newProduct->name = name;
        newProduct->id = id;
        newProduct->price = price;
        newProduct->amount = amount;
        newProduct->type = type;
        newProduct->date = time(0);
        if (totalProduct == 0)
        {
            top = newProduct;
        }
        else
        {
            newProduct->next = top;
            top = newProduct;
        }
        totalProduct++;
    }
    void delete_product_from_history()
    {
        if (totalProduct == 0)
        {
            cout << "No product in history." << endl;
            return;
        }
        history_stack_customer* toDelete = top;
        cout<< "are you sure you want to delete the" << toDelete->name << "from history? (Y/N): ";
        string choice;
        if (choice == "Y" || choice == "y" || choice == "yes" || choice == "Yes" )
        {
            top = top->next;
            delete toDelete;
            totalProduct--;
            cout << "Product " << top->name << " deleted successfully." << endl;
        }
        else
        {
            cout << "Product " << top->name << " not deleted." << endl;
        }
    }
    void display_history()
    {
        if (totalProduct == 0)
        {
            cout << "No product in history." << endl;
            return;
        }
        history_stack_customer* current = top;
        while (current)
        {
            cout << current->name << "\t" << current->id << "\t" << current->price << "\t"
                 << current->amount << "\t" << current->type << "\t" << current->date << endl;
            current = current->next;
        }
    }
    void save_to_file()
    {
        fstream file(FILE_HISTORY, ios::out);
        if (!file.is_open()) return;
        history_stack_customer* current = top;
        while (current)
        {
            file << current->name << ","
                 << current->id << ","
                 << current->price << ","
                 << current->amount << ","
                 << current->type << ","
                 << current->date << endl;
            current = current->next;
        }
        file.close();
    }
    void load_from_file()
    {
        fstream file(FILE_HISTORY, ios::in);
        if (!file.is_open()) return;
        string name, type;
        int id, price, amount, date;
        while (getline(file, name, ',')) // read the file until the comma
        {
            file >> id >> price >> amount >> date;
            file.ignore();
            getline(file, type);
            product_add_to_history(name, id, price, amount, type);
        }   
        file.close();
    }
    ~history_customer()
    {
        while (top)
        {
            history_stack_customer* toDelete = top;
            top = top->next;
            delete toDelete;
        }
    }
    bool check_history_is_empty()
    {
        if (totalProduct == 0)
        {
            return true;
        }
        return false;
    }
    void displayMenu()
    {
        cout << "0. Exit\n"
            << "1. Add product to history\n"
            << "2. Remove product from history\n"
            << "3. Display history\n"
            << "4. Save history to file\n";
    }
    void get_invioce(string name_product, int id_product, int price_product, int amount_product, string type_product){
        float total_price = price_product * amount_product;
        cout << "\n================ INVOICE ================\n"; 
        cout << "Name: " << "\tID: " << "\tPrice: " << "\tAmount: " << "\tType: " << endl;
        cout << name_product << "\t" << id_product << "\t" << price_product << "$" << "\t" << amount_product << "\t" << type_product << endl;
        cout << "\t\t\tTotal price: " << total_price << "$" << endl;
        cout << "========================================\n";
    }
    

};

void displayMenu()
{
    cout << "0. Exit\n"
         << "1. Add product to history\n"
         << "2. Remove product from history\n"
         << "3. Display history\n"
         << "4. Save history to file\n";
}


// int main (){
//     history_customer* history = new history_customer;
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
//                 system("cls");
//                 string name, type;
//                 int id, price, amount;
//                 cin.ignore();
//                 cout << "Enter Name: ";
//                 getline(cin, name);
//                 cout << "Enter ID: ";
//                 cin >> id;
//                 cout << "Enter Price: ";
//                 cin >> price;
//                 cout << "Enter Amount: ";
//                 cin >> amount;
//                 cin.ignore();
//                 cout << "Enter Type: ";
//                 getline(cin, type);
//                 history->product_add_to_history(name, id, price, amount, type);
//                 break;
//             }
//             case 2:
//                 system("cls");
//                 history->delete_product_from_history();
//                 break;
//             case 3:
//                 system("cls");
//                 history->display_history();
//                 break;
//             case 4:
//                 system("cls");
//                 history->save_to_file();
//                 break;
//             case 0:
//                 system("cls");
//                 cout << "Exit successfully." << endl;
//                 return 0;
//             default:
//                 system("cls");
//                 cout << "Invalid choice." << endl;
//                 break;
//         }
//     }
    
//     return 0;
// }
