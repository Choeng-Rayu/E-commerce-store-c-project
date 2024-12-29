#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<ctime>
#include"invoice.h"
#include"add_to_cart.h"
#include"product_data_class.h"

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

class Style{
    public:
    void display_menu_seller()
    {
        cout << "\n                   \t\t***************************************************************\n";
        cout << "                   \t\t************** Welcome to E-Commerce store *********************\n";
        cout << "                   \t\t***************************************************************\n\n";
        cout << "Please select option\n\n";
        cout << "-------------------------------\n";
        cout << "-  #1. Add Product.            -\n";
        cout << "-------------------------------\n";
        cout << "-  #2. Search Product.         -\n";
        cout << "-------------------------------\n";
        cout << "-  #3. Edit Product.           -\n";
        cout << "-------------------------------\n";
        cout << "-  #4. Delete Product.         -\n";
        cout << "-------------------------------\n";
        cout << "-  #5. Display All Product.    -\n";
        cout << "-------------------------------\n";
        cout << "-  #6. Save Your product.      -\n";
        cout << "-------------------------------\n";
        cout << "-  #7. Exit program.      -\n";
        cout << "-------------------------------\n";
        cout << "-  #8. Back to prevois.      -\n";
        cout << "-------------------------------\n";
        cout << "-  #9. Check profile      -\n";
        cout << "-------------------------------\n";
        
    }
    void display_menu_customer()
    {
        cout << "\n                   \t\t***************************************************************\n";
        cout << "                   \t\t************** Welcome to E-Commerce store *********************\n";
        cout << "                   \t\t***************************************************************\n\n";
        cout << "Please select option\n\n";
        cout << "-------------------------------\n";
        cout << "-  #1. add Product to cart.            -\n";
        cout << "-------------------------------\n";
        cout << "-  #2. Search Product.         -\n";
        cout << "-------------------------------\n";
        cout << "-  #3. Display product you added to cart. -\n";
        cout << "-------------------------------\n";
        cout << "-  #4. Delete Product you add to cart -\n";
        cout << "-------------------------------\n";
        cout << "-  #5. check your profile.    -\n";
        cout << "-------------------------------\n";
        cout << "-  #6. Get Invoice.         -\n";
        cout << "-------------------------------\n";
        cout << "-  #7. Back to prevois        -\n";
        cout << "-------------------------------\n";
        cout << "-  #8. buy Product in cart    -\n";
        cout << "-------------------------------\n";
        cout << "-  #9. exit the program    -\n";
        cout << "-------------------------------\n";

    }
    void display_menu_at_search_product()
    {
        cout << "Please select option\n\n";
        cout << "-------------------------------\n";
        cout << "-  #1. search product by type.-\n";
        cout << "-------------------------------\n";
        cout << "-  #2. search product by ID.  -\n";
        cout << "-------------------------------\n";
        cout << "-  #3. Search Product by price. -\n";
        cout << "-------------------------------\n";
        cout << "-  #4. Exit program.      -\n";
        cout << "-------------------------------\n";
        cout << "-  #4. Back to preavois.      -\n";
        cout << "-------------------------------\n";
    }
    void display_menu_at_search_production_by_type()
    {
        cout << "Please select option\n\n";
        cout << "-------------------------------\n";
        cout << "-  #1. Shoes.                 -\n";
        cout << "-------------------------------\n";
        cout << "-  #2. Food.  -\n";
        cout << "-------------------------------\n";
        cout << "-  #3. closthes. -\n";
        cout << "-------------------------------\n";
        cout << "-  #4. vehicle.      -\n";
        cout << "-------------------------------\n";
        cout << "-  #5. Back to preavois.      -\n";
        cout << "-------------------------------\n";
        cout << "-  #6. Exit Program.      -\n";
        cout << "-------------------------------\n";

    }
    void display_menu_customer()
    {
        cout << "\n                   \t\t***************************************************************\n";
        cout << "                   \t\t************** Welcome to E-Commerce store *********************\n";
        cout << "                   \t\t***************************************************************\n\n";
        cout << "Please select option\n\n";
        cout << "-------------------------------\n";
        cout << "-  #1. add Product to cart.            -\n";
        cout << "-------------------------------\n";
        cout << "-  #2. Search Product.         -\n";
        cout << "-------------------------------\n";
        cout << "-  #3. Display product you added to cart. -\n";
        cout << "-------------------------------\n";
        cout << "-  #4. Delete Product you add to cart -\n";
        cout << "-------------------------------\n";
        cout << "-  #5. check your profile.    -\n";
        cout << "-------------------------------\n";
        cout << "-  #6. Get Invoice.         -\n";
        cout << "-------------------------------\n";
        cout << "-  #7. Back to prevois        -\n";
        cout << "-------------------------------\n";
        cout << "-  #8. buy Product in cart    -\n";
        cout << "-------------------------------\n";
        cout << "-  #9. exit the program    -\n";
        cout << "-------------------------------\n";

    }

    //loading to data function
    void loading ( )
    {
        system("color 3");
        for ( int i = 0; i < 4; i ++)
        {

            if ( i == 0)
            {
                cout << "You login successfully!";
                Sleep(1000);
                system("color b");
            }
            else if ( i == 1)
            {
                system("cls");
                cout << "\n\n\n\n\t\t\t\t\t\t   Loading ";
                cout << " . ";
                Sleep(500);
                system("color c");
            }
            else if ( i == 2)
            {
                cout << " . ";
                Sleep(500);
                system("color d");
            }
            else if ( i == 3)
            {
                cout << " . ";
                Sleep(500);
                system("color e");
            }
            else
            {
            cout << " . ";
                Sleep(500);
                system("color f");
            }
        }
        system("cls");
    }

    void exit_program ( )//style loading
    {
        system ("cls");
        system("color 8");
        cout << "\n\n\n\t\t\t\t\t\tSaving Data . ";

        for ( int i = 0; i < 4; i ++)
        {
            if ( i == 0)
            {
                cout << " . ";
                Sleep(500);
                system("color 4");
            }
            else if ( i == 1)
            {
                cout << " . ";
                Sleep(500);
                system("color 3");
            }
            else if ( i == 2)
            {
                cout << " . ";
                Sleep(500);
                system("color 2");
            }
            else if ( i == 3)
            {
                cout << " . ";
                Sleep(500);
                system("color 0");
            }
            else
            {
            cout << " . ";
                Sleep(500);
                system("color 7");
            }
        }
        system ("cls");
        cout << "\n\n\t\t\t\tData saved successfully!\n";

    }
    // void seller_customer_admin_asking()
    // {
    //     char opt;
    //     cout << "please choose option(only one letter): " << endl;
    //     cout << "C. for Customer" << endl;
    //     cout << "S. for Seller" << endl;
    //     cout << "Enter your role: ";
    //     cin >> opt;
    //     switch (opt)
    //     {
    //     case 'c':
    //     case 'C': 
    //     system("cls");
    //         customer.lock_reset_pw();
    //         break;
    //     case 'S':
    //     case 's':
    //         seller.lock_reset_pw();
    //         break;
    //     default:
    //     cout << "invalid input" << endl;
    //         break;
    //     }
    // }
    void display_menu_admin(){
        cout << "\n                   \t\t***************************************************************\n";
        cout << "                   \t\t************** Welcome to E-Commerce store *********************\n";
        cout << "                   \t\t***************************************************************\n\n";
        cout << "Please select option\n\n";
        cout << "-------------------------------\n";
        cout << "-  #1. display all customer.   -\n";
        cout << "-------------------------------\n";
        cout << "-  #2. display all Seller      -\n";
        cout << "-------------------------------\n";
        cout << "-  #3. search customer.           -\n";
        cout << "-------------------------------\n";
        cout << "-  #4. searach seller         -\n";
        cout << "-------------------------------\n";
        cout << "-  #5. delete seller    -\n";
        cout << "-------------------------------\n";
        cout << "-  #6. delete customer      -\n";
        cout << "-------------------------------\n";
        cout << "-  #7. Exit program.      -\n";
        cout << "-------------------------------\n";
        cout << "-  #8. Display Product.      -\n";
        cout << "-------------------------------\n";
        cout << "-  #9. Exit Program     -\n";
        cout << "-------------------------------\n";

    }

};

