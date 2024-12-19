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
    string name;
    string gender;
    int id;
    int amount;
    int age;
    int money;

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
