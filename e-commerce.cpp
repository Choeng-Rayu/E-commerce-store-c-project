#include<iostream>

using namespace std;

#define FILE_HISTORY "history data.csv"
#define FILE_INVOICE "Invoice data.csv"
#define FILE_PRODUCT "product data.csv"
#define FILE_PERSONAL "personal customer.csv"

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
    // SELLER
    int money;
    string cusomterName;
    string gender;
    int 
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
class AddToCard
{
    Node* top;
    int totalProduct;
    AddToCard(){
        top = NULL;

    }

};

int main ()
{

    return 0;
}
