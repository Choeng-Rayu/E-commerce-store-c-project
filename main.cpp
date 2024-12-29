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


class CustomerLogin
{
    public: 
    void lock_program()
    {
        string user_input_password;
        string user_name_input;
        string user_email_input;
        cout << "data in lock program" << customer.usernameCustomer << " " << customer.emailCustomer << " " << customer.pwCustomer  << endl;
        int found = 0;
        bool correct = false;
        file_user.readFile_user_login();
        system("color c");
        for (int j = 0; j < 4; j++)
        {
            found ++;
            if ( found == 4)
            {
                cout << "Access denied. Program will terminate.\n";
                exit(1); // Terminates the program if password is incorrect three times
            }
            cout << "Please enter customer name: ";
        // cin >> user_name_input;
            cin.ignore();
            getline(cin, user_name_input);

            cout << "Please enter email: ";
            cin >> user_email_input;
            cout << "Please enter password: ";
            cin >> user_input_password;
            if ( user_name_input == customer.usernameCustomer  && user_input_password == customer.pwCustomer && user_email_input == customer.emailCustomer )
            {
                correct = true;
                system("cls");
                //cout << "Access granted!\n";
                break;
            }
            if ( !correct )
            {
                system("cls");
                cout << "Invalid  user name or password!\n";
            }
        }
    }

    void reset_pw()
    {
        system ("color d");
        cout << "Enter new user name: ";
        cin.ignore();
        getline(cin, customer.usernameCustomer);
        cout << "Enter new email: ";
        cin >> customer.emailCustomer;
        cout << "Enter new password: ";
        cin.ignore();
        getline(cin, customer.pwCustomer);
        file_user.writeFile_user_login(customer.usernameCustomer, customer.emailCustomer, customer.pwCustomer);

    }

    void lock_reset_pw ()
    {
        int num;
        char login_choice;
        char letter;

        system ("color B");
        cout << "\n                   \t\t***************************************************************\n";
        cout << "                   \t\t************** Welcome to E-Commerce store *********************\n";
        cout << "                   \t\t***************************************************************\n\n";
        cout << " Press Enter to continue...";
        fflush (stdin);
        cin.ignore();
        system("cls");
        system ("color 3");
        cout << "Note" << endl;
        cout << "W. For Enter user name and password" << endl;
        cout << "F. For forget password" << endl;
        cout << "Please your choice: ";
        cin >> login_choice;

        system ("cls");
        switch ( login_choice )
        {
            //choice_convert = atoi (password_choice);
            case 'W':
            case 'w':
                lock_program();
                break;

            case 'F':
            case 'f':
                //int num;
                system ("color 4");
                cout << "Question 1: what number did you like?" << endl;
                cout << "Answer here: ";
                cin >> num;
                system ("cls");
                switch( num )
                {
                case 1:
                    system ("color 5");
                    cout << "Question 2: Which letter you like the most?" << endl;
                    cout << "Answer here: ";
                    cin >> letter;
                    system ("cls");
                    switch( letter )
                    {

                        case 'z':
                        {
                            system ("color 6");
                            float x1,x2;
                            cout << "The last question" << endl;
                            cout << "solve this equation: 2X^2 - 5X + 3 = 0" << endl;
                            cout << "Answer here:" << endl;
                            cout << "X1 = ";
                            cin >> x1;
                            cout << "X2 = ";
                            cin >> x2;
                            system ("cls");
                            if ( (x1 == 1 && x2 == 1.5) || (x2 == 1 && x1 == 1.5 ))
                            {
                                system ("color 7");
                                cout << "You are correct!" << endl;
                                reset_pw();
                            }
                            else
                            {
                                system ("color 7");
                                cout << "You were wrong!" << endl;
                                exit (1);
                            }
                        }
                            break;
                        default:
                            cout << "You're wrong!" <<endl;
                            exit(1); //end the program
                    }

                    break;
                default:
                    cout << "You're wrong!" <<endl;
                    exit(1); //end the program
                }
                break;
            default:
                cout << "Invalid input" << endl;
                exit(1);
        }
    }

};
class SellerLogin
{
    public: 
    void lock_program()
    {
        string seller_input_password;
        string seller_name_input;
        string seller_email_input;
        int found = 0;
        bool correct = false;
        file_user.readFile_seller_login();
        system("color c");
        for (int j = 0; j < 4; j++)
        {
            found ++;
            if ( found == 4)
            {
                cout << "Access denied. Program will terminate.\n";
                exit(1); // Terminates the program if password is incorrect three times
            }
            cout << "Please enter seller name: ";
        // cin >> user_name_input;
            cin.ignore();
            getline(cin, seller_name_input);

            cout << "Please enter email: ";
            cin >> seller_email_input;
            cout << "Please enter password: ";
            cin >> seller_email_input;
            if ( seller_name_input == seller.usernameseller  && seller_input_password == seller.pwseller && seller_email_input == seller.emailseller )
            {
                correct = true;
                system("cls");
                //cout << "Access granted!\n";
                break;
            }
            if ( !correct )
            {
                system("cls");
                cout << "Invalid  user name or password!\n";
            }
        }
    }

    void reset_pw()
    {
        system ("color d");
        cout << "Enter new user name: ";
        cin.ignore();
        getline(cin, seller.usernameseller);
        cout << "Enter new email: ";
        cin >> seller.emailseller;
        cout << "Enter new password: ";
        cin.ignore();
        getline(cin, seller.pwseller);
        file_user.writeFile_seller_login(seller.usernameseller, seller.emailseller, seller.pwseller);
        system("cls");

    }

    void lock_reset_pw ()
    {
        int num;
        char login_choice;
        char letter;

        system ("color B");
        cout << "\n                   \t\t***************************************************************\n";
        cout << "                   \t\t************** Welcome to E-Commerce store *********************\n";
        cout << "                   \t\t***************************************************************\n\n";
        cout << " Press Enter to continue...";
        fflush (stdin);
        cin.ignore();
        system("cls");
        system ("color 3");
        cout << "Note" << endl;
        cout << "W. For Enter user name and password" << endl;
        cout << "F. For forget password" << endl;
        cout << "Please your choice: ";
        cin >> login_choice;

        system ("cls");
        switch ( login_choice )
        {
            //choice_convert = atoi (password_choice);
            case 'W':
            case 'w':
                lock_program();
                break;

            case 'F':
            case 'f':
                //int num;
                system ("color 4");
                cout << "Question 1: what number did you like?" << endl;
                cout << "Answer here: ";
                cin >> num;
                system ("cls");
                switch( num )
                {
                case 1:
                    system ("color 5");
                    cout << "Question 2: Which letter you like the most?" << endl;
                    cout << "Answer here: ";
                    cin >> letter;
                    system ("cls");
                    switch( letter )
                    {

                        case 'z':
                        {
                            system ("color 6");
                            float x1,x2;
                            cout << "The last question" << endl;
                            cout << "solve this equation: 2X^2 - 5X + 3 = 0" << endl;
                            cout << "Answer here:" << endl;
                            cout << "X1 = ";
                            cin >> x1;
                            cout << "X2 = ";
                            cin >> x2;
                            system ("cls");
                            if ( (x1 == 1 && x2 == 1.5) || (x2 == 1 && x1 == 1.5 ))
                            {
                                system ("color 7");
                                cout << "You are correct!" << endl;
                                reset_pw();
                            }
                            else
                            {
                                system ("color 7");
                                cout << "You were wrong!" << endl;
                                exit (1);
                            }
                        }
                            break;
                        default:
                            cout << "You're wrong!" <<endl;
                            exit(1); //end the program
                    }

                    break;
                default:
                    cout << "You're wrong!" <<endl;
                    exit(1); //end the program
                }
                break;
            default:
                cout << "Invalid input" << endl;
                exit(1);
        }
    }
    

};

