#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<iomanip>
#include<windows.h>

using namespace std;

#define FILE_HISTORY "history data.csv"
#define FILE_INVOICE "Invoice data.csv"
#define FILE_PRODUCT "product data.csv"
#define FILE_PERSONAL "personal customer.csv"
#define FILE_USER_LOGIN "user login.csv"
#define FILE_SELLER_LOGIN "seller login.csv"
#define FILE_Add_TO_CART "add to cart.csv"


//Note read file for ELITE 
//customer for bro vath
//me tver CRUD

struct Node
{
    Node* left;
    Node* right;
    Node* next;
    // PRODUCT 
    string nameProduct;
    int idPoduct;
    int priceProduct;
    int amount;
    string typeProduct;
    // customer
    int money;
    string cusomterName;
    string gender;
    int age;
    string email;
    string phoneCustomer;
};

struct Date
{
    int year;
    int month;
    int days;
};

struct Login
{
    string usernameCustomer;
    string pwCustomer;
    string emailCustomer;
    string usernameSeller;
    string pwseller;
    string emailSeller;
};

class Customer
{
    int amount_customer; //size
    Node* front;
    Node* rear;
public:
    Customer()
    {
        amount_customer = 0;
        front = NULL;
        rear = NULL;
    }
    void buy_product(int price, string nameOFProduct, int amount, int dateOFbuying){

    }


};

class NST //search function
{
    Node* root;
    int total;
    public:
    NST(){
        root = NULL;
        total = 0;
    }
    void search_product_by_name(){

    }
    void search_product_by_type(){

    }
    void search_product_by_price(){

    }
    void search_product_by_id(){

    }
    void search_product_by_amount(){
        
    }
};

class File_handling
{
    public:
    void readFile_history(){
        fstream file_history(FILE_HISTORY, ios::in);
        //code here
    }
    void writeFile_history(){
        fstream file_history(FILE_HISTORY, ios::out);

    }


    void readFile_invoice(){
        fstream file_invoice(FILE_INVOICE, ios::in);
        //code here
    }
    void writeFile_invoice(){
        fstream file_invoice(FILE_INVOICE, ios::out);

    }

    void readFile_personal(){
        fstream file_persona;(FILE_PERSONAL, ios::in);
        //code here
    }
    void writeFile_personal(){
        fstream file_personal(FILE_PERSONAL, ios::out);

    }

    void readFile_product(){
        fstream file_product(FILE_PRODUCT, ios::in);
        //code here
    }
    void writeFile_product(){
        fstream file_product(FILE_PRODUCT, ios::out);

    }

    void readFile_seller_login(){
        Login read;
        fstream file_seller(FILE_SELLER_LOGIN, ios::in);
        //code here
        if(!file_seller) {
            cout << "can't not read file or file error!" << endl;
            return;
        }
        file_seller >> read.usernameSeller >> read.emailSeller >> read.pwseller;
        file_seller.close();
    }
    void writeFile_seller_login(){
        fstream file_seller(FILE_SELLER_LOGIN, ios::out);
        Login write;
        file_seller << write.usernameSeller << endl;
        file_seller << write.emailSeller << endl;
        file_seller << write.pwseller << endl;
        file_seller.close();

    }

    void readFile_user_login(){
        Login read;
        fstream file_user(FILE_USER_LOGIN, ios::in);
        //code here
        if(!file_user) {
            cout << "can't not read file or file error!" << endl;
            return;
        }
        file_user >> read.usernameCustomer >> read.emailCustomer >> read.pwCustomer;
        file_user.close();
    }
    void writeFile_user_login(){
        fstream file_user(FILE_USER_LOGIN, ios::out);
        Login write;
        file_user << write.usernameCustomer << endl;
        file_user << write.emailCustomer << endl;
        file_user << write.pwCustomer << endl; 
        cout << "your data is successfully saved" << endl;
        file_user.close();
        Sleep (100);

    }

    void readFile_add_to_cart(){
        fstream file_add_to_cart(FILE_Add_TO_CART, ios::in);
        //code here
    }
    void writeFile_add_to_cart(){
        fstream file_add_to_cart(FILE_Add_TO_CART, ios::out);

    }
};

class Seller
{
    int amount_product; //
    Node* head;
    Node* tail;
    Seller(){
        head = NULL;
        tail = NULL;
        amount_product = 0;
    }
};
class CRUD
{
    Node* head;
    Node* tail;
    int quantity;
    CRUD(){
        head = NULL;
        tail = NULL;
        quantity = 0;
    }
};
class AddToCart
{
    Node* top;
    int totalProduct;
    AddToCart(){
        top = NULL;

    }

};

class CustomerLogin
{
    Login customer;
    File_handling file_user;
    public: 
    void lock_program()
    {
        string user_input_password;
        string user_name_input;
        string user_email_input;
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
            cout << "Please enter seller name: ";
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
        file_user.writeFile_user_login();
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
class SellerLogin
{
    Login seller;

};

class Style{
    void display_menu()
    {
        cout << "\n                   \t\t***************************************************************\n";
        cout << "                   \t\t************** Welcome to E-Commerce store *********************\n";
        cout << "                   \t\t***************************************************************\n\n";
        cout << "Please select option\n\n";
        cout << "-------------------------------\n";
        cout << "-  #1. Add Record.            -\n";
        cout << "-------------------------------\n";
        cout << "-  #2. Search Record.         -\n";
        cout << "-------------------------------\n";
        cout << "-  #3. Edit Record.           -\n";
        cout << "-------------------------------\n";
        cout << "-  #4. Delete Record.         -\n";
        cout << "-------------------------------\n";
        cout << "-  #5. Display All Record.    -\n";
        cout << "-------------------------------\n";
        cout << "-  #6. Exit and Save.         -\n";
        cout << "-------------------------------\n";
        cout << "-  #7. Report Record.         -\n";
        cout << "-------------------------------\n";
        cout << "-  #8. Reset Password.        -\n";
        cout << "-------------------------------\n";
        cout << "-  #9. Analyst Your data.     -\n";
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

    void loading_to_file ( )//style loading
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



};


int main ()
{

    return 0;
}
