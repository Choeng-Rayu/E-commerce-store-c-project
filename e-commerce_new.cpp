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
#define FILE_PRODUCT "product data.csv" // store all the product
#define FILE_PERSONAL "personal customer.csv" // store all the personal information of the customer
#define FILE_USER_LOGIN "user login.csv" // store all the login information of the customer
#define FILE_SELLER_LOGIN "seller login.csv" // store all the login information of the seller
#define FILE_Add_TO_CART "add to cart.csv" // store all the product that the customer add to cart
#define FILE_BUY_NOW "buy now.csv" // store all the product that the customer buy now
#define FILE_PERSONAL_SELLER "personal seller.csv" // store all the personal information of the seller


struct Node
{
    Node* left; //for BST
    Node* right;//for BST
    Node* next; //for linked list

    // PRODUCT 
    struct Product
    {
        string nameProduct;
        int idPoduct;
        int priceProduct;
        int quantity_product;
        string catagory_product;
    };
    
    //customer personal data & login

    struct Customer
    {
        string name_customer;
        string password_customer;
        string email_customer;
        int id_customer;
        string phone_customer;
        int money_customer;
    }customer;
    
    //seller personal data & login
    struct Seller
    {
        string username_seller;
        string password_seller;
        string email_seller;
        int id_seller;
        string phone_seller;
        int money_seller;
    }seller;

    //add to cart
    struct Add_to_cart
    {
        string nameProduct_cart;
        int idPoduct_cart;
        int priceProduct_cart;
        int quantity_product_cart;
        string catagory_product_cart;
        int total_price_cart;
    }add_to_cart;


    //admin personal data & login
    struct Admin
    {
        string username_admin;
        string password_admin;
        string email_admin;
    }addmin;

    //date
    struct Date
    {
        int year;
        int month;
        int days;
    }date;
};

// class date_handling
// {
//     Node::Date date;
//     public:
//     void get_date(){
//         time_t now = time(0);
//         tm* ltm = localtime(&now);
//         date.year = 1900 + ltm->tm_year;
//         date.month = 1 + ltm->tm_mon;
//         date.days = ltm->tm_mday;
//     }

// };

// class Admine
// {

// };

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <ctime>

using namespace std;

//#define FILE_HISTORY "history data.csv" // store all the history of the customer
//#define FILE_INVOICE "Invoice data.csv" // store all the invoice of the customer
//#define FILE_PRODUCT "product data.csv" // store all the product
#define FILE_PERSONAL "personal customer.csv" // store all the personal information of the customer
#define FILE_USER_LOGIN "user login.csv" // store all the login information of the customer
#define FILE_SELLER_LOGIN "seller login.csv" // store all the login information of the seller
//#define FILE_Add_TO_CART "add to cart.csv" // store all the product that the customer add to cart
//#define FILE_BUY_NOW "buy now.csv" // store all the product that the customer buy now
#define FILE_PERSONAL_SELLER "personal seller.csv" // store all the personal information of the seller

struct Node
{
    Node* left; //for BST
    Node* right;//for BST
    Node* next; //for linked list

    
    //customer personal data & login
    struct Customer
    {
        string name_customer;
        string password_customer;
        string email_customer;
        int id_customer;
        string phone_customer;
        int money_customer;
    } customer;
    
    //seller personal data & login
    struct Seller
    {
        string username_seller;
        string password_seller;
        string email_seller;
        int id_seller;
        string phone_seller;
        int money_seller;
    } seller;

};

class customer_account 
{
    int total_customer;
    Node* head;
    Node* tail;

public:
    customer_account() {
        total_customer = 0;
        head = nullptr;
        tail = nullptr;
    }

    ~customer_account() {
        // Destructor to clean up dynamically allocated memory
        Node* current = head;
        while (current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }

    void add_customer_input_data(){
        string name, email, phone, password;
        int money, id;
        name = "Unknown";
        cout << "Enter your name: ";
        getline(cin, name);

        cout << "Enter your email: ";
        cin >> email;

        cout << "Enter your phone: ";
        cin.ignore();
        getline(cin, phone);

        cout << "Enter your money: ";
        cin >> money;

        cout << "Enter your id: ";
        cin >> id;

        cout << "Enter your password: ";
        cin.ignore();
        getline(cin, password);
        insert_customer(name, email, phone, password, id, money);
    }

    void insert_customer(string name, string email, string phone, string password, int id, int money) { 
        Node* newCustomer = new Node;
        newCustomer->customer.name_customer = name;
        newCustomer->customer.email_customer = email;
        newCustomer->customer.phone_customer = phone;
        newCustomer->customer.money_customer = money;
        newCustomer->customer.id_customer = id;
        newCustomer->customer.password_customer = password;
        newCustomer->next = nullptr;
        if (total_customer == 0) {
            head = tail = newCustomer;
        }
        else {
            tail->next = newCustomer;
            tail = newCustomer;
        }
        total_customer++;
    }

    void load_data_from_file(){
        fstream file(FILE_PERSONAL, ios::in);
        if (!file.is_open()) return;
        string name, email, phone, password;
        int money, id;
        string line;
        getline(file, line); // Skip the header line
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, email, ',');
            getline(ss, phone, ',');
            getline(ss, password, ',');
            ss >> id;
            ss.ignore();
            ss >> money;
            insert_customer(name, email, phone, password, id, money);
        }
        file.close();
    }

    void save_data_to_file(){
        fstream file(FILE_PERSONAL, ios::out);
        if (!file.is_open()) return;
        Node* current = head;
        file << "Name,Email,Phone,Password,Id,Money" << endl; // Write the header line
        while (current)
        {
            file << current->customer.name_customer << ","
                 << current->customer.email_customer << ","
                 << current->customer.phone_customer << ","
                 << current->customer.password_customer << ","
                 << current->customer.id_customer << ","
                 << current->customer.money_customer << endl;
            current = current->next;
        }
        cout << "Data saved to file successfully!" << endl;
        file.close();
    }

    bool check_customer_is_empty(){
        return total_customer == 0;
    }

    void delete_customer(string name, string password) {
        if (check_customer_is_empty()) {
            cout << "There is no customer account" << endl;
            return;
        }
        Node* delete_customer = nullptr;
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->customer.name_customer == name && current->customer.password_customer == password) {
                delete_customer = current;

                // Display customer details
                cout << "Customer details:" << endl;
                cout << "Name: " << current->customer.name_customer << endl
                     << "ID: " << current->customer.id_customer << endl
                     << "Email: " << current->customer.email_customer << endl
                     << "Phone: " << current->customer.phone_customer << endl
                     << "Money: " << current->customer.money_customer << endl
                     << "Password: " << current->customer.password_customer << endl;

                cout << "Please press Enter to delete..." << endl;
                cin.ignore();

                // Adjust pointers to delete the node
                if (current == head) {
                    head = head->next;
                    if (head == nullptr) tail = nullptr; // Handle single-element list
                } else if (current == tail) {
                    tail = previous;
                    tail->next = nullptr;
                } else {
                    previous->next = current->next;
                }

                delete delete_customer;
                total_customer--;
                cout << "Customer deleted successfully!" << endl;
                return;
            }

            previous = current;
            current = current->next;
        }

        cout << "Customer not found!" << endl;
    }

    void update_customer(){
        string name;
        string password;

        if (check_customer_is_empty()) {
            cout << "There is no customer account" << endl;
            return;
        }

        cout << "Enter Customer name you want to update: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Password: ";
        getline(cin, password);
        Node* current = head;
        while (current != nullptr) {
            if (current->customer.name_customer == name && current->customer.password_customer == password) {
                // Display customer details
                cout << "Customer details:" << endl;
                cout << "Name: " << current->customer.name_customer << endl
                     << "ID: " << current->customer.id_customer << endl
                     << "Email: " << current->customer.email_customer << endl
                     << "Phone: " << current->customer.phone_customer << endl
                     << "Money: " << current->customer.money_customer << endl
                     << "Password: " << current->customer.password_customer << endl;
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, current->customer.name_customer);
                cout << "Enter new email: ";
                cin >> current->customer.email_customer;
                cout << "Enter new phone: ";
                cin.ignore();
                getline(cin, current->customer.phone_customer);
                cout << "Enter new money: ";
                cin >> current->customer.money_customer;
                cout << "Enter new Id: ";
                cin >> current->customer.id_customer;
                cout << "Enter new password: ";
                cin.ignore();
                getline(cin, current->customer.password_customer);
                cout << "Customer updated successfully!" << endl;
                return;
            }
            current = current->next;
        }

        cout << "Customer not found!" << endl;
    }

    int get_total_customer(){
        return total_customer;
    }

    void display_customer(){
        if (check_customer_is_empty()) {
            cout << "There is no customer account" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << "Name: " << current->customer.name_customer << " "
                 << "ID: " << current->customer.id_customer << " "
                 << "Email: " << current->customer.email_customer << " "
                 << "Phone: " << current->customer.phone_customer << " "
                 << "Money: " << current->customer.money_customer << " "
                 << "Password: " << current->customer.password_customer << endl;
            current = current->next;
        }
    }
};

int main() {
    customer_account customer;
    customer.load_data_from_file();
    customer.display_customer();
    customer.add_customer_input_data();
    customer.save_data_to_file();
    customer.display_customer();
    return 0;
}


class seller_account
{
    Node* head;
    Node* tail;
    int total_account_seller;
    public:
    seller_account(){
        head = NULL;
        tail = NULL;
        total_account_seller = 0;
    }
    ~seller_account(){

        //code here

    }
    void add_new_seller_input_data(){
        string name_seller, email_seller, pw_seller, phone_seller; 
        int id_seller, seller_money; 
        cout << "Enter seller name: ";
        cin.ignore();
        getline(cin, name_seller);
        cout << "Enter seller email: ";
        cin >> email_seller;
        cout << "Enter seller phone: ";
        cin.ignore();
        getline(cin, phone_seller);
        cout << "Enter seller id: ";
        cin >> id_seller;
        cout << "Enter money: ";
        cin >> seller_money;
        cout << "Enter seller password: ";
        cin.ignore();
        getline(cin, pw_seller);
        insert_new_seller_account(name_seller, email_seller, phone_seller, pw_seller, id_seller, seller_money);
    }
    void insert_new_seller_account(string name_seller, string email_seller, string phone_seller, string pw_seller, int id_seller, int seller_money){
        Node* newSeller = new Node;
        newSeller->seller.username_seller = name_seller;
        newSeller->seller.email_seller = email_seller;
        newSeller->seller.password_seller = pw_seller;
        newSeller->next = NULL;
        if (total_account_seller == 0)
        {
            head = tail = newSeller;
        }
        else
        {
            tail->next = newSeller;
            tail = newSeller;
        }
        total_account_seller++;
    }
    void load_data_seller_from_file(){
        fstream file(FILE_PERSONAL_SELLER, ios::in);
        if (!file.is_open()) return;
        string name, email, phone, password;
        int money, id;
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, email, ',');
            getline(ss, phone, ',');
            getline(ss, password, ',');
            ss >> id;
            ss.ignore();
            ss >> money;
            insert_new_seller_account(name, email, phone, password, id, money);
        }
        file.close();
    }
    void save_data_seller_to_file(){
        fstream file(FILE_PERSONAL_SELLER, ios::out);
        if (!file.is_open()) return;
        Node* current = head;
        while (current)
        {
            file << current->seller.username_seller << ","
                 << current->seller.email_seller << ","
                 << current->seller.phone_seller << ","
                 << current->seller.password_seller << ","
                 << current->seller.id_seller << ","
                 << current->seller.money_seller << endl;
            current = current->next;
        }
        file.close();
    }

    bool check_seller_is_empty(){
        if(total_account_seller == 0){
            return true;
        }
        return false;
    }
    void delete_seller_position(){
        string name_seller;
        string password_seller;
        if (check_seller_is_empty())
        {
            cout << "There is no seller account" << endl;
            return;
        }
        cout << "Enter Seller name you want to delete: ";
        cin.ignore();
        getline(cin, name_seller);
        cout << "Enter Password: ";
        getline(cin, password_seller);
        Node* delete_seller = nullptr;
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr)
        {
            if (current->seller.username_seller == name_seller && current->seller.password_seller == password_seller)
            {
                delete_seller = current;
                cout << "Seller details:" << endl;
                cout << "Name: " << current->seller.username_seller << endl
                    << "ID: " << current->seller.id_seller << endl
                    << "Email: " << current->seller.email_seller << endl
                    << "Phone: " << current->seller.phone_seller << endl
                    << "Money: " << current->seller.money_seller << endl
                    << "Password: " << current->seller.password_seller << endl;
                cout << "Please press Enter to delete..." << endl;
                cin.ignore();
                if (current == head)
                {
                    head = head->next;
                    if (head == nullptr) tail = nullptr;
                }
                else if (current == tail)
                {
                    tail = previous;
                    tail->next = nullptr;
                }
                else
                {
                    previous->next = current->next;
                }
                delete delete_seller;
                total_account_seller--;
                cout << "Seller deleted successfully!" << endl;
                return;
            }
            previous = current;
            current = current->next;
        }
        cout << "Seller not found!" << endl;
    }
    void update_seller(){
        string name_seller;
        string password_seller;
        if (check_seller_is_empty())
        {
            cout << "There is no seller account" << endl;
            return;
        }
        cout << "Enter Seller name you want to delete: ";
        cin.ignore();
        getline(cin, name_seller);
        cout << "Enter Password: ";
        getline(cin, password_seller);
        Node* current = head;
        while (current != nullptr)
        {
            if (current->seller.username_seller == name_seller && current->seller.password_seller == password_seller)
            {
                cout << "Seller details:" << endl;
                cout << "Name: " << current->seller.username_seller << endl
                    << "ID: " << current->seller.id_seller << endl
                    << "Email: " << current->seller.email_seller << endl
                    << "Phone: " << current->seller.phone_seller << endl
                    << "Money: " << current->seller.money_seller << endl
                    << "Password: " << current->seller.password_seller << endl;
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, current->seller.username_seller);
                cout << "Enter new email: ";
                cin >> current->seller.email_seller;
                cout << "Enter new phone: ";
                cin.ignore();
                getline(cin, current->seller.phone_seller);
                cout << "Enter new money: ";
                cin >> current->seller.money_seller;
                cout << "Enter new Id:";
                cin >> current->seller.id_seller;
                cout << "Enter new password: ";
                cin.ignore();
                getline(cin, current->seller.password_seller);
                cout << "Seller updated successfully!" << endl;
                break;
            }
            current = current->next;
        }
        cout << "Seller not found!" << endl;
    }
    
    int get_total_seller(){
        return total_account_seller;
    }

    void display_seller(){
        if (check_seller_is_empty())
        {
            cout << "There is no seller account" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr)
        {
            cout << "Name: " << current->seller.username_seller << endl
                << "ID: " << current->seller.id_seller << endl
                << "Email: " << current->seller.email_seller << endl
                << "Phone: " << current->seller.phone_seller << endl
                << "Money: " << current->seller.money_seller << endl
                << "Password: " << current->seller.password_seller << endl;
            current = current->next;
        }
    }

};


// class BST_for_customer
// {
//     Node* root;
//     BST_for_customer(){
//         root = NULL;
//     }
//     ~BST_for_customer(){

//     }
    
// };
// class BST_for_seller
// {
//     Node* root;
//     BST_for_customer(){
//         root = NULL;
//     }
//     ~BST_for_customer(){

//     }
    
// };
// class BST_for_product
// {
//     Node* root;
//     BST_for_customer(){
//         root = NULL;
//     }
//     ~BST_for_customer(){
x
//     }
    
// };


// class product_data
// {
//     Node* head;
//     Node* tail;
//     int total_product;
//     product_data(){
//         head = NULL;
//         tail = NULL;
//         total_product = 0;
//     }
//     ~product_data(){

//     }
// };

// class add_to_cart
// {
//     Node* head;
//     Node* tail;
//     int total_product_add_to_cart;
//     add_to_cart(){
//         head = NULL;
//         tail = NULL;
//         total_product_add_to_cart = 0;

//     }

//     ~add_to_cart(){


//     }

// };


 main ()
{
    customer_account customer;
    seller_account seller;
    customer.load_data_from_file();
    customer.display_customer();
    customer.add_customer_input_data();
    customer.save_data_to_file();
    customer.display_customer();
    return 0;
}
