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

struct node_invoice
{
    string name;
    int id;
    float price;
    int amount;
    string type;
    node_invoice* next;
    string date;
};

class Invoice
{
    node_invoice* top;
    int totalProduct;
    string invoice_id;
    string invoice_date;
    public:
    string getCurrentTime() {

        // Get the current time
        time_t t = time(nullptr); 
        tm* now = localtime(&t);

        // Format the time into a string
        char buffer[100];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now);

        return string(buffer);
    }
    Invoice()
    {
        top = NULL;
        totalProduct = 0;
        invoice_date = getCurrentTime();
        invoice_id = "Unknow";
    }
    ~Invoice() {
        while (top != nullptr) {
            node_invoice* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void product_add_to_invoice(string name, int id, float price, int amount, string type, string date)
    {
        node_invoice* newProduct = new node_invoice;
        newProduct->name = name;
        newProduct->id = id;
        newProduct->price = price;
        newProduct->amount = amount;
        newProduct->type = type;
        newProduct->date = date;
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
    string getCurrentTime_for_generate_invioce() {

        // Get the current time
        time_t t = time(nullptr); 
        tm* now = localtime(&t);

        // Format the time into a string
        char buffer[100];
        strftime(buffer, 100, "%Y-%m-%d %H:%M:%S", now);
        return string(buffer);
    }
    void delete_product_from_invoice()
    {
        if (totalProduct == 0)
        {
            cout << "No product in history." << endl;
            return;
        }
        node_invoice* toDelete = top;
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
    void display_product_in_invoice()
    {
        if (totalProduct == 0)
        {
            cout << "No product in history." << endl;
            return;
        }
        node_invoice* temp = top;
        int count = 1;
        cout << "\n\t\t\t\t\t================ Invioce ================\n"; 
        cout << "No\tName\t\t\tCategory\t\tID\t\tPrice\t\tQuantity\tDate\n";
        while (temp != nullptr) {
            cout << count << "\t"
                << setw(20) << left << temp->name << "\t"
                << setw(20) << left << temp->type << "\t"
                << setw(10) << left << temp->id << "\t"
                << setw(10) << left << temp->price << "\t"
                << setw(10) << left << temp->amount << "\t"
                << temp->date << "\n";
            temp = temp->next;
            count++;
        }
        cout << "Total product in cart: " << totalProduct << endl;
        cout << "Invoice Date: " << invoice_date << endl;
        cout << "Invoice ID: " << invoice_id << endl;
        cout << "\t\t\t\t\t==========================================\n";
    }
    void save_inovice_to_file(){
        fstream file(FILE_INVOICE, ios::out);
        node_invoice* current = top;
        file << "Name,Type,Date,ID,Price,Quantity" <<endl;
        while(current != nullptr){
            file << current->name <<","
                 << current->type << ","
                 << current->date <<","
                 << current->id << ","
                 << current->price << ","
                 << current->amount << endl;
            current = current->next;
        }
    }
    void load_invoice_from_file(){
        ifstream file;
        file.open(FILE_INVOICE);
        if (!file.is_open()) {
            cerr << "Error: Could not open file.\n";
            return;
        }

        string name, category, date;
        int id, quantity;
        float price;
        string line;
        string skip_line;
        getline(file, skip_line); // Skip the first line
        if (file.is_open()) {
            while (getline(file, line)) {
                stringstream ss(line);
                getline(ss, name, ',');
                getline(ss, category, ',');
                getline(ss, date, ',');
                ss >> id;
                ss.ignore(1, ','); // Ignore the comma
                ss >> price;
                ss.ignore(1, ','); // Ignore the comma
                ss >> quantity;
                product_add_to_invoice(name, id, price, quantity, category, date);
            }
            file.close();
        } else {
            cerr << "Unable to open file for reading.\n";
        }
    }
    int get_total_product(){
        return totalProduct;
    }
    void display_history_of_customer_from_file(){
        fstream file(FILE_HISTORY, ios::in);
        if (!file.is_open()) {
            cerr << "Error: Could not open file.\n";
            return;
        }

        string line;
        while(getline(file, line)){
            cout << line << endl;
        }
    }
    void add_save_history_to_file(){
        fstream file(FILE_HISTORY, ios::app);
        node_invoice* temp = top;
        int count = 1;
        file << "\n\t\t\t\t\t================ Invioce ================\n"; 
        file << "No\tName\t\t\tCategory\t\tID\t\tPrice\t\tQuantity\tDate\n";
        while (temp != nullptr) {
            file << count << "\t"
                << setw(20) << left << temp->name << "\t"
                << setw(20) << left << temp->type << "\t"
                << setw(10) << left << temp->id << "\t"
                << setw(10) << left << temp->price << "\t"
                << setw(10) << left << temp->amount << "\t"
                << temp->date << "\n";
            temp = temp->next;
            count++;
        }
        file << "Total product in cart: " << totalProduct << endl;
        file << "Invoice Date: " << invoice_date << endl;
        file << "Invoice ID: " << invoice_id << endl;
        file << "\t\t\t\t\t==========================================\n";
        file << "Save to file successfully" << endl;
    }
    void displau_menu_invoice(){
        cout << "0. Exit\n"
            << "1. Add product from invoice\n"
            << "2. Remove product from invoice\n"
            << "3. Display invoice\n"
            << "4. Save to history\n"
            << "5. Get Invoice\n"
            << "6. Display history\n"
            << "7. Save to invoice\n"
            << "8. Back to previous\n";
    }

};

// class history_customer
// {
//     history_stack_customer* top;
//     int totalProduct;
//     public:
//     history_customer()
//     {
//         top = NULL;
//         totalProduct = 0;
//     }
//     void product_add_to_invoice(string name, int id, int price, int amount, string type,)
//     {
//         history_stack_customer* newProduct = new history_stack_customer;
//         newProduct->name = name;
//         newProduct->id = id;
//         newProduct->price = price;
//         newProduct->amount = amount;
//         newProduct->type = type;
//         newProduct->date = time(0);
//         if (totalProduct == 0)
//         {
//             top = newProduct;
//         }
//         else
//         {
//             newProduct->next = top;
//             top = newProduct;
//         }
//         totalProduct++;
//     }
//     string getCurrentTime() {

//         // Get the current time
//         time_t t = time(nullptr); 
//         tm* now = localtime(&t);

//         // Format the time into a string
//         char buffer[100];
//         strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now);

//         return string(buffer);
//     }
//     void delete_product_from_history()
//     {
//         if (totalProduct == 0)
//         {
//             cout << "No product in history." << endl;
//             return;
//         }
//         history_stack_customer* toDelete = top;
//         cout<< "are you sure you want to delete the" << toDelete->name << "from history? (Y/N): ";
//         string choice;
//         if (choice == "Y" || choice == "y" || choice == "yes" || choice == "Yes" )
//         {
//             top = top->next;
//             delete toDelete;
//             totalProduct--;
//             cout << "Product " << top->name << " deleted successfully." << endl;
//         }
//         else
//         {
//             cout << "Product " << top->name << " not deleted." << endl;
//         }
//     }
//     void display_history()
//     {
//         if (totalProduct == 0)
//         {
//             cout << "No product in history." << endl;
//             return;
//         }
//         history_stack_customer* current = top;
//         while (current)
//         {
//             cout << current->name << "\t" << current->id << "\t" << current->price << "\t"
//                  << current->amount << "\t" << current->type << "\t" << current->date << endl;
//             current = current->next;
//         }
//     }
//     void save_to_file()
//     {
//         fstream file(FILE_HISTORY, ios::out);
//         if (!file.is_open()) return;
//         history_stack_customer* current = top;
//         while (current)
//         {
//             file << current->name << ","
//                  << current->id << ","
//                  << current->price << ","
//                  << current->amount << ","
//                  << current->type << ","
//                  << current->date << endl;
//             current = current->next;
//         }
//         file.close();
//         cout <<"Saved to file successfully." << endl;
//     }
//     void load_from_file()
//     {
//         fstream file(FILE_HISTORY, ios::in);
//         if (!file.is_open()) return;
//         string name, type;
//         int id, price, amount, date;
//         string skip_line;
//         getline(file, skip_line); // Skip the first line
//         while (getline(file, name, ',')) // read the file until the comma
//         {
//             file >> id >> price >> amount >> date;
//             file.ignore();
//             getline(file, type);
//             product_add_to_history(name, id, price, amount, type);
//         }   
//         file.close();
//     }
//     void load_cart_file() {
//         ifstream file;
//         file.open(FILE_NAME);
//         string name, category, date;
//         int id, quantity;
//         float price;
//         string line;
//         string skip_line;
//         getline(file, skip_line); // Skip the first line
//         if (file.is_open()) {
//             while (getline(file, line)) {
//                 stringstream ss(line);
//                 getline(ss, name, ',');
//                 getline(ss, category, ',');
//                 getline(ss, date, ',');
//                 ss >> id;
//                 ss.ignore(1, ','); // Ignore the comma
//                 ss >> price;
//                 ss.ignore(1, ','); // Ignore the comma
//                 ss >> quantity;
//                 product_add_to_history(name, id, price, quantity, category, date);
//             }
//             file.close();
//         } else {
//             cerr << "Unable to open file for reading.\n";
//         }
//     }
//     ~history_customer()
//     {
//         while (top)
//         {
//             history_stack_customer* toDelete = top;
//             top = top->next;
//             delete toDelete;
//         }
//     }
//     bool check_history_is_empty()
//     {
//         if (totalProduct == 0)
//         {
//             return true;
//         }
//         return false;
//     }
//     void displayMenu()
//     {
//         cout << "0. Exit\n"
//             << "1. Add product to history\n"
//             << "2. Remove product from history\n"
//             << "3. Display history\n"
//             << "4. Save history to file\n";
//     }
//     // void get_invioce(string name_product, int id_product, int price_product, int amount_product, string type_product){
//     //     float total_price = price_product * amount_product;
//     //     cout << "\n================ INVOICE ================\n"; 
//     //     cout << "Name: " << "\tID: " << "\tPrice: " << "\tAmount: " << "\tType: " << endl;
//     //     cout << name_product << "\t" << id_product << "\t" << price_product << "$" << "\t" << amount_product << "\t" << type_product << endl;
//     //     cout << "\t\t\tTotal price: " << total_price << "$" << endl;
//     //     cout << "========================================\n";
//     // }
//     void get_invoice_for_output(){
//         history_stack_customer* temp = top;
//         float total_price = 0;
//         int count = 1;
//         cout << "\n\t\t\t\t\t================ Pre-Pay ================\n"; 
//         cout << "No\tName\t\t\tCategory\t\tID\t\tPrice\t\tQuantity\tDate\n";
//         while (temp != nullptr) {
//             cout << count << "\t"
//                 << setw(20) << left << temp->name << "\t"
//                 << setw(20) << left << temp->type << "\t"
//                 << setw(10) << left << temp->id << "\t"
//                 << setw(10) << left << temp->price << "\t"
//                 << setw(10) << left << temp->amount << "\t"
//                 << temp->date << "\n";
//             temp = temp->next;
//             count++;
//         }
//         cout << "Total product in cart: " << totalProduct << endl;
//         cout << "\t\t\t\t\t==========================================\n";

//     }
//     void display_all_invoice_from_file(){
//         fstream file(FILE_HISTORY, ios::in);
//         if (!file.is_open()) return;
//         string line;
//         while(getline(file, line)){
//             cout << line << endl;
//         }
//     }
//     void add_invoice_to_file_history(){
//         fstream file(FILE_HISTORY, ios::app);
//         if (!file.is_open()) return;

//     }

    

// };


// // int main (){
// //     history_customer* history = new history_customer;
// //     int choice;
// //     while (true)
// //     {
// //         displayMenu();
// //         cout << "Enter your choice: ";
// //         cin >> choice;
// //         switch (choice)
// //         {
// //             case 1:
// //             {
// //                 system("cls");
// //                 string name, type;
// //                 int id, price, amount;
// //                 cin.ignore();
// //                 cout << "Enter Name: ";
// //                 getline(cin, name);
// //                 cout << "Enter ID: ";
// //                 cin >> id;
// //                 cout << "Enter Price: ";
// //                 cin >> price;
// //                 cout << "Enter Amount: ";
// //                 cin >> amount;
// //                 cin.ignore();
// //                 cout << "Enter Type: ";
// //                 getline(cin, type);
// //                 history->product_add_to_history(name, id, price, amount, type);
// //                 break;
// //             }
// //             case 2:
// //                 system("cls");
// //                 history->delete_product_from_history();
// //                 break;
// //             case 3:
// //                 system("cls");
// //                 history->display_history();
// //                 break;
// //             case 4:
// //                 system("cls");
// //                 history->save_to_file();
// //                 break;
// //             case 0:
// //                 system("cls");
// //                 cout << "Exit successfully." << endl;
// //                 return 0;
// //             default:
// //                 system("cls");
// //                 cout << "Invalid choice." << endl;
// //                 break;
// //         }
// //     }
    
// //     return 0;
// // }
