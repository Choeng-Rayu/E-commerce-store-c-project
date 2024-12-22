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

class date_handling
{
    Node::Date date;
    public:
    void get_date(){
        time_t now = time(0);
        tm* ltm = localtime(&now);
        date.year = 1900 + ltm->tm_year;
        date.month = 1 + ltm->tm_mon;
        date.days = ltm->tm_mday;
    }
};

class Admine
{

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

    void insert_customer() {
        string name, email, phone, password;
        int money, id;

        cout << "Enter your name: ";
        cin.ignore();
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
    bool check_customer_is_empty(){
        if(total_customer == 0){
            return true;
        }
        return false;
    }
    void delete_customer_position(){
        string name;
        string password;
        if(check_customer_is_empty()){
            cout << "There is no customer account" << endl;
            return;
        }
        cout << "Enter Customer name you want to delete: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Password: " ;
        cin.ignore();
        getline(cin, password);
        Node* delete_customer;
        Node* current = head;
        Node* previous = nullptr;
        



        
    }
};


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

};


class BST_for_customer
{
    Node* root;
    BST_for_customer(){
        root = NULL;
    }
    ~BST_for_customer(){

    }
    
};


class product_data
{
    Node* head;
    Node* tail;
    int total_product;
    product_data(){
        head = NULL;
        tail = NULL;
        total_product = 0;
    }
    ~product_data(){

    }
};

class add_to_cart
{
    Node* head;
    Node* tail;
    int total_product_add_to_cart;
    add_to_cart(){
        head = NULL;
        tail = NULL;
        total_product_add_to_cart = 0;

    }

    ~add_to_cart(){


    }

};

class 


int main ()
{

    return 0;
}
