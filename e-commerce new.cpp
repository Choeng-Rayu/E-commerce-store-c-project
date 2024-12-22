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
    string nameProduct;
    int idPoduct;
    int priceProduct;
    int quantity_product;
    string catagory_product;
    
    //customer personal data & login
    struct cuustomer
    {
        string name_customer;
        string password_customer;
        string email_customer;
        int id_customer;
        string phone_customer;
        int money_customer;
    };
    
    //seller personal data & login
    struct Seller
    {
        string username_seller;
        string password_seller;
        string email_seller;
        int id_seller;
        string phone_seller;
        int money_seller;
    };

    //add to cart
    struct Add_to_cart
    {
        string nameProduct_cart;
        int idPoduct_cart;
        int priceProduct_cart;
        int quantity_product_cart;
        string catagory_product_cart;
        int total_price_cart;
    };


    //admin personal data & login
    struct Admin
    {
        string username_admin;
        string password_admin;
        string email_admin;
    };

    //date
    struct Date
    {
        int year;
        int month;
        int days;
    };
};

