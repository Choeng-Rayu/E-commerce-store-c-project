#include<iostream>

using namespace std;

#define FILE_HISTORY "history data.csv"
#define FILE_INVOICE "Invoice data.csv"
#define FILE_PRODUCT "product data.csv"

//Note read file for ELITE 
//customer for bro vath
//me tver CRUD

struct Node
{
    Node* left;
    Node* right;
    Node* next;
    string name;
    int id;
    string gender;
    int amount;
    int age;
    int money;

};
class Customer_queue
{
    int amount_customer; //size
    Node* front;
    Node* reare;
public:
    Customer_queue()
    {
        amount_customer = 0;
        front = NULL;
        reare = NULL;
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

int main ()
{

    return 0;
}
