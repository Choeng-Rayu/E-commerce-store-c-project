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
struct Login
{
    string usernameCustomer;
    string pwCustomer;
    string emailCustomer;
    string usernameSeller;
    string pwseller;
    string emailSeller;
};

struct Date
{
    int year;
    int month;
    int days;
};



class Customer_queue
{
    int amount_customer; //size
    Node* front;
    Node* rear;
public:
    Customer_queue()
    {
        amount_customer = 0;
        front = NULL;
        rear = NULL;
    }


};

class File_handling
{
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
    void writeFile_history(){
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
        fstream file_seller(FILE_SELLER_LOGIN, ios::in);
        //code here
    }
    void writeFile_seller_login(){
        fstream file_seller(FILE_SELLER_LOGIN, ios::out);

    }

    void readFile_user_login(){
        fstream file_user(FILE_USER_LOGIN, ios::in);
        //code here
    }
    void writeFile_user_login(){
        fstream file_user(FILE_USER_LOGIN, ios::out);

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
    Login cusotmer;


};
class SellerLogin
{
    Login seller;

};


int main ()
{

    return 0;
}
