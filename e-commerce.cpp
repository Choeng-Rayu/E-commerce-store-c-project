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
    string cusomterName;
    string gender;
    int age;
    string email;
    string phoneCustomer;
    int money;
    
    //seller
    string usernameCustomer;
    string pwCustomer;
    string emailCustomer;
    string usernameseller;
    string pwseller;
    string emailseller;

    //date
    struct Date
    {
        int year;
        int month;
        int days;
    };
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
    void display_date(){
        cout << "Date: " << date.days << "/" << date.month << "/" << date.year << endl;
    }
};

class Customer_account
{
    int total_customer;
    Node* head;
    Node* tail;
    public:
    Customer_account(){
        total_customer = 0;
        head = NULL;
        tail = NULL;
    }
    void add_customer(string name, string email, string phone, int money){
        Node* newCustomer = new Node;
        newCustomer->cusomterName = name;
        newCustomer->email = email;
        newCustomer->phoneCustomer = phone;
        newCustomer->money = money;
        if (total_customer == 0)
        {
            head = tail = newCustomer;
        }
        else
        {
            tail->next = newCustomer;
            tail = newCustomer;
        }
        total_customer++;
    }
    void delete_customer(int position)
    {
        if (position < 0 || position >= total_customer)
        {
            cout << "Invalid position." << endl;
            return;
        }
        Node* toDelete;
        string removedName;
        if (position == 0)
        {
            toDelete = head;
            head = head->next;
            removedName = toDelete->cusomterName;
        }
        else
        {
            Node* current = head;
            for (int i = 1; i < position; i++)
            {
                current = current->next;
            }
            toDelete = current->next;
            current->next = toDelete->next;
            removedName = toDelete->cusomterName;
            if (position == total_customer - 1) tail = current;
        }
        delete toDelete;
        total_customer--;
        cout << "Customer " << removedName << " deleted successfully." << endl;
    }
    void load_customer(){
        fstream file_customer(FILE_PERSONAL, ios::in);
        if (!file_customer)
        {
            cout << "Unable to open file for loading." << endl;
            return;
        }
        string name, email, phone;
        int money;
        while (file_customer >> name >> email >> phone >> money)
        {
            add_customer(name, email, phone, money);
        }
        file_customer.close();
    }
    void save_customer(){
        fstream file_customer(FILE_PERSONAL, ios::out);
        if (!file_customer)
        {
            cout << "Unable to open file for saving." << endl;
            return;
        }
        Node* current = head;
        while (current)
        {
            file_customer << current->cusomterName << "\t" << current->email << "\t" << current->phoneCustomer << "\t" << current->money << endl;
            current = current->next;
        }
        file_customer.close();
        cout << "Data saved to file successfully." << endl;
    }
    void update_account_customer(int position, int money){
        if (position < 0 || position >= total_customer)
        {
            cout << "Invalid position." << endl;
            return;
        }
        Node* current = head;
        for (int i = 0; i < position; i++)
        {
            current = current->next;
        }
        current->money = money;
        cout << "Account updated successfully." << endl;
    }
};
class Product
{
    int size;
    Node* head;
    Node* tail;
    public:
    Product(){
        size = 0;
        head = NULL;
        tail = NULL;
    }
    void add_product(string name, int id, int price, int amount, string type){
        Node* newProduct = new Node;
        newProduct->nameProduct = name;
        newProduct->idPoduct = id;
        newProduct->priceProduct = price;
        newProduct->amount = amount;
        newProduct->typeProduct = type;
        if (size == 0)
        {
            head = tail = newProduct;
        }
        else
        {
            tail->next = newProduct;
            tail = newProduct;
        }
        size++;
    }
    void display_product(){
        if (size == 0)
        {
            cout << "No product available." << endl;
            return;
        }
        Node* current = head;
        while (current)
        {
            cout << current->nameProduct << "\t" << current->idPoduct << "\t" << current->priceProduct << "\t"
                 << current->amount << "\t" << current->typeProduct << endl;
            current = current->next;
        }
    }
    void delete_product(int position)
    {
        if (position < 0 || position >= size)
        {
            cout << "Invalid position." << endl;
            return;
        }
        Node* toDelete;
        string removedName;
        if (position == 0)
        {
            toDelete = head;
            head = head->next;
            removedName = toDelete->nameProduct;
        }
        else
        {
            Node* current = head;
            for (int i = 1; i < position; i++)
            {
                current = current->next;
            }
            toDelete = current->next;
            current->next = toDelete->next;
            removedName = toDelete->nameProduct;
            if (position == size - 1) tail = current;
        }
        delete toDelete;
        size--;
        cout << "Product " << removedName << " deleted successfully." << endl;
    void buy_product(int price, string nameOFProduct, int amount, int dateOFbuying){
        Node* temp = new Node;
        temp->priceProduct = price;
        temp->nameProduct  =nameOFProduct;
        temp->amount = amount;
        temp->idPoduct = amount_customer + 1;
        temp->next = NULL;
        if (front == NULL)
        {
            front = temp;
            rear = temp;

        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
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
    void insert(int id){
        root = insert_(root, id);
    }
    void insert(int id){
        root = insert_(root, id);
    }
    void readFile(){
        fstream file(FILE_PRODUCT, ios::in);
        if (!file) {
            cerr << "Error: Unable to open file " << FILE_PRODUCT << endl;
            return;
        }
        int readIDFile;
        while (file >> readIDFile) {
            root = insert_(root, readIDFile);
        }
    void search_product_by_name(){
        string SearchName;
        cout<<"Enter the name of product that you want to search:"; cin>>SearchName;
        Node* temp = root;
        while (temp != NULL)
        {
            if (temp->nameProduct==SearchName)
            {
                cout<<"Product Name: "<<temp->nameProduct<<endl;
                cout<<"Pruduct ID: "<<temp->idPoduct<<endl;
                cout<<"Price of product: "<<temp->priceProduct<<endl;
                cout<<"Type of product: "<<temp->typeProduct<<endl;
                cout<<"Amount: "<<temp->amount<<endl;
                return;  
            }
            temp = temp->next;
        }
        cout<<"Product not found!"<<endl;
    }
    void search_product_by_type(){
        string SearchType;
        cout<<"Enter the type of product that you want to search: ";cin>>SearchType;
        Node* temp = root;
        while (temp != NULL)
        {
            if (temp->typeProduct == SearchType)
            {
                cout<<"Product found: "<<temp->nameProduct<<endl;
                cout<<"Type: "<<temp->typeProduct<<endl;
                cout<<"Price of product: "<<temp->priceProduct<<endl;
            }
            temp = temp->next;
        }
        
    }
    void search_product_by_price(){
        int SearchPrice;
        cout<<"Enter the price of product that you want to search: ";cin>>SearchPrice;
        Node* temp = root;
        while(temp != NULL)
        {
            if (temp->priceProduct == SearchPrice)
            {
                cout<<"Product Name: "<<temp->nameProduct<<endl;
                cout<<"Price of product: "<<temp->priceProduct<<endl;
            }
            temp = temp->next;
        }
    }
    void search_product_by_id(){
        int SearchId;
        cout<<"Enter the id of product that you want to search: ";cin>>SearchId;
        Node* temp = root;
        while (temp != NULL)
        {
            if (temp-> idPoduct==SearchId)
            {
                cout<<"Product Name: "<<temp->nameProduct<<endl;
                cout<<"Price of product: "<<temp->priceProduct<<endl;
                cout<<"ID of product: "<<temp->idPoduct<<endl;
            }
            temp= temp->next;   
        }
        
    }
    void search_product_by_amount(){
        int SearchAmount;
        cout<<"Enter the Amount of product that you want to search: ";cin>>SearchAmount;
        Node* temp = root;
        while (temp != NULL)
        {
            if (temp->amount == SearchAmount)
            {
                cout<<"Product Name: "<<temp->nameProduct<<endl;
                cout<<"Price of product: "<<temp->priceProduct<<endl;
                cout<<"ID of product: "<<temp->idPoduct<<endl;
                cout<<"Quantity of product: "<<temp->amount<<endl;
            }
            temp = temp->next;   
        }
        
    }
};

class File_handling
{
    Node read;
    Node write;
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
        fstream file_seller(FILE_SELLER_LOGIN, ios::in);
        //code here
        if(!file_seller) {
            cout << "can't not read file or file error!" << endl;
            return;
        }
        file_seller >> read.usernameseller >> read.emailseller >> read.pwseller;
        cout << read.usernameseller << " " << read.emailseller << " " << read.pwseller;
        file_seller.close(); 
    }
    void writeFile_seller_login(string name, string email, string pw){
        fstream file_seller(FILE_SELLER_LOGIN, ios::out);
        file_seller << name << endl;
        file_seller << email << endl;
        file_seller << pw << endl; 
        cout << "your data is successfully saved" << endl;
        file_seller.close();
        Sleep (100);
    }

    void readFile_user_login(){
        fstream file_user(FILE_USER_LOGIN, ios::in);
        //code here
        if(!file_user) {
            cout << "can't not read file or file error!" << endl;
            return;
        }
        file_user >> read.usernameCustomer >> read.emailCustomer >> read.pwCustomer;
        cout << "data in read file function" << read.usernameCustomer << " " << read.emailCustomer << " " << read.pwCustomer  << endl;
        file_user.close();
    }
    void writeFile_user_login(string name, string email, string pw){
        fstream file_user(FILE_USER_LOGIN, ios::out);
        file_user << name << endl;
        file_user << email << endl;
        file_user << pw << endl; 
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

class seller_account
{
    int amount_seller; //
    Node* head;
    Node* tail;
    seller_account(){
        head = NULL;
        tail = NULL;
        amount_seller = 0;
    }
    void new_seller_account(string name_seller, string email_seller, string pw_seller){
        Node* newSeller = new Node;
        newSeller->cusomterName = name_seller;
        newSeller->email = email_seller;
        newSeller->pwseller = pw_seller;
        if (amount_seller == 0)
        {
            head = tail = newSeller;
        }
        else
        {
            tail->next = newSeller;
            tail = newSeller;
        }
        amount_seller++;
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
    void add_product(string name, int id, int price, int amount, string type){
        Node* newProduct = new Node;
        newProduct->nameProduct = name;
        newProduct->idPoduct = id;
        newProduct->priceProduct = price;
        newProduct->amount = amount;
        newProduct->typeProduct = type;
        if (quantity == 0)
        {
            head = tail = newProduct;
        }
        else
        {
            tail->next = newProduct;
            tail = newProduct;
        }
        quantity++;
    }
    void delete_product(int position)
    {
        if (position < 0 || position >= quantity)
        {
            cout << "Invalid position." << endl;
            return;
        }
        Node* toDelete;
        string removedName;
        if (position == 0)
        {
            toDelete = head;
            head = head->next;
            removedName = toDelete->nameProduct;
        }
        else
        {
            Node* current = head;
            for (int i = 1; i < position; i++)
            {
                current = current->next;
            }
            toDelete = current->next;
            current->next = toDelete->next;
            removedName = toDelete->nameProduct;
            if (position == quantity - 1) tail = current;
        }
        delete toDelete;
        quantity--;
        cout << "Product " << removedName << " deleted successfully." << endl;
    }
    void update_product(int position, string name, int id, int price, int amount, string type){
        if (position < 0 || position >= quantity)
        {
            cout << "Invalid position." << endl;
            return;
        }
        Node* current = head;
        for (int i = 0; i < position; i++)
        {
            current = current->next;
        }
        current->nameProduct = name;
        current->idPoduct = id;
        current->priceProduct = price;
        current->amount = amount;
        current->typeProduct = type;
        cout << "Product " << name << " updated successfully." << endl;
    }
    void load_from_file(){
        ifstream file(FILE_PRODUCT);
        if (!file.is_open()) return;
        string name, type;
        int id, price, amount;
        while (getline(file, name, ','))
        {
            file >> id >> price >> amount;
            file.ignore();
            getline(file, type);
            add_product(name, id, price, amount, type);
        }
        file.close();
    }
    void save_to_file(){
        fstream file(FILE_PRODUCT, ios::out);
        if (!file.is_open()) return;
        Node* current = head;
        while (current)
        {
            file << current->nameProduct << ","
                 << current->idPoduct << ","
                 << current->priceProduct << ","
                 << current->amount << ","
                 << current->typeProduct << endl;
            current = current->next;
        }
        file.close();
    }

};
class AddToCart
{
    Node* top;
    int totalProduct;
    AddToCart(){
        top = NULL;
        totalProduct = 0;
    }
    void add_product_to_cart(string name, int id, int price, int amount, string type){
        Node* newProduct = new Node;
        newProduct->nameProduct = name;
        newProduct->idPoduct = id;
        newProduct->priceProduct = price;
        newProduct->amount = amount;
        newProduct->typeProduct = type;
        if (totalProduct == 0)
        {
            top = newProduct;
        }
        else
        {
            newProduct->next = top;
            top = newProduct;
        }
        totalProduct++;
    }
    void delete_product_from_cart(){
        if (totalProduct == 0)
        {
            cout << "No product in cart." << endl;
            return;
        }
        Node* toDelete = top;
        top = top->next;
        delete toDelete;
        totalProduct--;
        cout << "Product deleted from cart successfully." << endl;
    }
    void display_product_in_cart(){
        if (totalProduct == 0)
        {
            cout << "No product in cart." << endl;
            return;
        }
        Node* current = top;
        while (current)
        {
            cout << current->nameProduct << "\t" << current->idPoduct << "\t" << current->priceProduct << "\t"
                 << current->amount << "\t" << current->typeProduct << endl;
            current = current->next;
        }
    }
    void update_product_in_cart(int position, string name, int id, int price, int amount, string type){
        if (position < 0 || position >= totalProduct)
        {
            cout << "Invalid position." << endl;
            return;
        }
        Node* current = top;
        for (int i = 0; i < position; i++)
        {
            current = current->next;
        }
        current->nameProduct = name;
        current->idPoduct = id;
        current->priceProduct = price;
        current->amount = amount;
        current->typeProduct = type;
        cout << "Product " << name << " updated successfully." << endl;
    }
    void checkout(){
        if (totalProduct == 0)
        {
            cout << "No product in cart." << endl;
            return;
        }
        Node* current = top;
        while (current)
        {
            cout << current->nameProduct << "\t" << current->idPoduct << "\t" << current->priceProduct << "\t"
                 << current->amount << "\t" << current->typeProduct << endl;
            current = current->next;
        }
        cout << "Total product: " << totalProduct << endl;
        cout << "Checkout successfully." << endl;
    }
    void clear_cart(){
        while (top)
        {
            Node* toDelete = top;
            top = top->next;
            delete toDelete;
        }
        totalProduct = 0;
        cout << "Cart cleared successfully." << endl;
    }
    void save_to_file(){
        fstream file(FILE_Add_TO_CART, ios::out);
        if (!file.is_open()) return;
        Node* current = top;
        while (current)
        {
            file << current->nameProduct << ","
                 << current->idPoduct << ","
                 << current->priceProduct << ","
                 << current->amount << ","
                 << current->typeProduct << endl;
            current = current->next;
        }
        file.close();
    }
    void load_from_file(){
        ifstream file(FILE_Add_TO_CART);
        if (!file.is_open()) return;
        string name, type;
        int id, price, amount;
        while (getline(file, name, ','))
        {
            file >> id >> price >> amount;
            file.ignore();
            getline(file, type);
            add_product_to_cart(name, id, price, amount, type);
        }
        file.close();
    }
    void display_cart(){
        if (totalProduct == 0)
        {
            cout << "No product in cart." << endl;
            return;
        }
        Node* current = top;
        while (current)
        {
            cout << current->nameProduct << "\t" << current->idPoduct << "\t" << current->priceProduct << "\t"
                 << current->amount << "\t" << current->typeProduct << endl;
            current = current->next;
        }
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
    Login seller;
    File_handling file_user;
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

class Style{
    public:
    CustomerLogin customer;
    SellerLogin seller;
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




int main ()
{
    Style style;
    style.loading();
    char opt;
        cout << "please choose option(only one letter): " << endl;
        cout << "C. for Customer" << endl;
        cout << "S. for Seller" << endl;
        cout << "A. for Admin" << endl;
        cout << "Enter your role: ";
        cin >> opt;
    char opt;
    if( opt == 'c' || opt == 'C')
    {
        int opt;
        while (true)
        {
            style.display_menu_customer();
            cout << "Enter your option: ";
            cin >> opt;
            switch (opt)
            {
                case 1:
                    //add product to cart
                    break;
                case 2:
                    {
                        int opt_type;
                        style.display_menu_at_search_production_by_type();
                        cout << "Enter your option: ";  
                        cin >> opt_type;
                        switch (opt_type)
                        {
                            case 1:
                                //search product by type
                                break;
                            case 2:
                                //search product by id
                                break;
                            case 3:
                                //search product by price
                                break;
                            case 4:
                                //exit program
                                break;
                            case 5:
                                //back to previous
                                break;
                            default:
                                cout << "invalid input" << endl;
                                break;
                        }

                    }
                case 3:
                    //display product in cart
                    break;
                case 4:
                    //delete product in cart
                    break;
                case 5:
                    //check profile
                    break;
                case 6:
                    //get invoice
                    break;
                case 7:
                    //back to previous
                    break;
                case 8:
                    //buy product in cart
                    break;
                case 9:
                    //exit program
                    break;
                default:
                    cout << "invalid input" << endl;
                    break;
            }
        }
        
    }
    else if ( opt == 's' || opt == 'S')
    {
        int opt;
        while (true)
        {
            style.display_menu_seller();
            cout << "Enter your option: ";
            cin >> opt;
            switch (opt)
            {
                case 1:
                    //add product
                    break;
                case 2:
                    //search product
                    style.display_menu_at_search_production_by_type();
                    break;
                case 3:
                    //edit product
                    break;
                case 4:
                    //delete product
                    break;
                case 5:
                    //display all product
                    break;
                case 6:
                    //save product
                    break;
                case 7:
                    //exit program
                    break;
                case 8:
                    //back to previous
                    break;
                case 9:
                    //check profile
                    break;
                default:
                    cout << "invalid input" << endl;
                    break;
            }
        }
    }
    else if ( opt == 'A' || opt == 'a')
    {
        int opt;
        while (true)
        {
            style.display_menu_admin();
            cout << "Enter your option: ";
            cin >> opt;
            switch (opt)
            {
                case 1:
                    //display all customer
                    break;
                case 2:
                    //display all seller
                    break;
                case 3:
                    //search customer
                    break;  
                case 4:
                    //search seller
                    break;
                case 5:
                    //delete seller
                    break;  
                case 6:
                    //delete customer
                    break;  
                case 7:
                    exit(1);
                    break;
                case 8: 
                    //display product
                    break; 
                    default:
                    cout << "invalid input" << endl;     
            }
        
        }
    }
    else
    {
        cout << "invalid input" << endl;
    }
    return 0;
}