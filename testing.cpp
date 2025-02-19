#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<ctime>
#include"add_to_cart.h"

using namespace std;




#define FILE_PERSONAL "personal customer.csv" // store all the personal information of the customer
#define FILE_USER_LOGIN "user login.csv" // store all the login information of the customer
#define FILE_SELLER_LOGIN "seller login.csv" // store all the login information of the seller
//#define FILE_Add_TO_CART "add to cart.csv" // store all the product that the customer add to cart
//#define FILE_BUY_NOW "buy now.csv" // store all the product that the customer buy now
#define FILE_PERSONAL_SELLER "personal seller.csv" // store all the personal information of the seller





class Style{
    public:
    void display_menu_customer()
    {
        cout << "\n                   \t\t***************************************************************\n";
        cout << "                   \t\t************** Welcome to E-Commerce store *********************\n";
        cout << "                                 \t\t***************************************************************\n\n";
        cout << "Please select option\n\n";
        cout << "-  #0. exit the program       -\n";
        cout << "-------------------------------\n";
        cout << "-  #1. add Product to cart.   -\n";
        cout << "-------------------------------\n";
        cout << "-  #2. Search Product.        -\n";
        cout << "-------------------------------\n";
        cout << "-  #3. Check product in cart. -\n";
        cout << "-------------------------------\n";
        cout << "-  #4. Delete Product in cart -\n";
        cout << "-------------------------------\n";
        cout << "-  #5. check your profile.    -\n";
        cout << "-------------------------------\n";
        cout << "-  #6. Invoice Management.    -\n";
        cout << "-------------------------------\n";
        cout << "-  #7. Back to prevois        -\n";
        cout << "-------------------------------\n";
        cout << "-  #8. buy Product in cart    -\n";
        cout << "-------------------------------\n";
        cout << "-  #9. Save to file           -\n";
        cout << "-------------------------------\n";
        cout << "-  #10. Cart Management       -\n";
        cout << "-------------------------------\n";
        cout << "-  #11. Display product       -\n";
        cout << "-------------------------------\n";

    }
    void display_menu_seller()
    {
        cout << "\n                   \t\t***************************************************************\n";
        cout << "                   \t\t************** Welcome to E-Commerce store *********************\n";
        cout << "                   \t\t***************************************************************\n\n";
        cout << "Please select option\n\n";
        cout << "-  #0. exit the program       -\n";
        cout << "-------------------------------\n";
        cout << "-  #1. Display All Product.   -\n";
        cout << "-------------------------------\n";
        cout << "-  #2. Product Management.    -\n";
        cout << "-------------------------------\n";
        cout << "-  #3. Back to prevois.       -\n";
        cout << "-------------------------------\n";
        cout << "-  #4. Check profile          -\n";
        cout << "-------------------------------\n";
        cout << "-  #5. Get report             -\n";
        cout << "-------------------------------\n";
        
    }
    //loading to data function
    void loading_style ()
    {
        system("color 3");
        for ( int i = 0; i < 4; i ++)
        {

            if ( i == 0)
            {
                Sleep(1000);
                system("color b");
            }
            else if ( i == 1)
            {
                system("cls");
                cout << "\n\n\n\n\t\t\t\t\t\t   Loading ";
                cout << " . ";
                Sleep(1000);
                system("color c");
            }
            else if ( i == 2)
            {
                cout << " . ";
                Sleep(1000);
                system("color d");
            }
            else if ( i == 3)
            {
                cout << " . ";
                Sleep(1000);
                system("color e");
            }
            else
            {
            cout << " . ";
                Sleep(1000);
                system("color f");
            }
        }
        cout << "loading successfully!";
        Sleep(1000);
        system("cls");
    }

    void exit_program_style ()//style loading
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
        //cout << "\n\n\t\t\t\tData saved successfully!\n";

    }
    
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
    // void seller_customer_admin_asking()
    // {
    //     char opt;
    //     cout << "please choose option(only one letter): " << endl;
        // cout << "C. for Customer" << endl;
        // cout << "S. for Seller" << endl;
        // cout << "Enter your role: ";
        // cin >> opt;
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

};



struct Node
{
    Node* left; //for BST
    Node* right;//for BST
    Node* next; //for linked list

    
    //customer personal data & login
    struct Customer
    {
        string name_customer;
        string password_customer;
        string email_customer;
        int id_customer;
        string phone_customer;
        int money_customer;
    } customer;
    
    //seller personal data & login
    struct Seller
    {
        string username_seller;
        string password_seller;
        string email_seller;
        int id_seller;
        string phone_seller;
        int money_seller;
    } seller;

};
void main_function();
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

    void add_customer_input_data(){
        string name, email, phone, password;
        int money, id;
        name = "Unknown";
        cout << "Enter your name: ";
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
        insert_customer(name, email, phone, password, id, money);
    }

    void insert_customer(string name, string email, string phone, string password, int id, int money) { 
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

    void load_data_from_file(){
        fstream file(FILE_PERSONAL, ios::in);
        if (!file.is_open()) return;
        string name, email, phone, password;
        int money, id;
        string line;
        getline(file, line); // Skip the header line
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, email, ',');
            getline(ss, phone, ',');
            getline(ss, password, ',');
            ss >> id;
            ss.ignore();
            ss >> money;
            insert_customer(name, email, phone, password, id, money);
        }
        file.close();
    }

    void save_data_to_file(){
        fstream file(FILE_PERSONAL, ios::out);
        if (!file.is_open()) return;
        Node* current = head;
        file << "Name,Email,Phone,Password,Id,Money" << endl; // Write the header line
        while (current)
        {
            file << current->customer.name_customer << ","
                 << current->customer.email_customer << ","
                 << current->customer.phone_customer << ","
                 << current->customer.password_customer << ","
                 << current->customer.id_customer << ","
                 << current->customer.money_customer << endl;
            current = current->next;
        }
        cout << "Data saved to file successfully!" << endl;
        file.close();
    }

    bool check_customer_is_empty(){
        return total_customer == 0;
    }

    void delete_customer(string name, string password) {
        if (check_customer_is_empty()) {
            cout << "There is no customer account" << endl;
            return;
        }
        Node* delete_customer = nullptr;
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->customer.name_customer == name && current->customer.password_customer == password) {
                delete_customer = current;

                // Display customer details
                cout << "Customer details:" << endl;
                cout << "Name: " << current->customer.name_customer << endl
                     << "ID: " << current->customer.id_customer << endl
                     << "Email: " << current->customer.email_customer << endl
                     << "Phone: " << current->customer.phone_customer << endl
                     << "Money: " << current->customer.money_customer << endl
                     << "Password: " << current->customer.password_customer << endl;

                cout << "Please press Enter to delete..." << endl;
                cin.ignore();

                // Adjust pointers to delete the node
                if (current == head) {
                    head = head->next;
                    if (head == nullptr) tail = nullptr; // Handle single-element list
                } else if (current == tail) {
                    tail = previous;
                    tail->next = nullptr;
                } else {
                    previous->next = current->next;
                }

                delete delete_customer;
                total_customer--;
                cout << "Customer deleted successfully!" << endl;
                return;
            }

            previous = current;
            current = current->next;
        }

        cout << "Customer not found!" << endl;
    }

    void update_customer(){
        string name;
        string password;

        if (check_customer_is_empty()) {
            cout << "There is no customer account" << endl;
            return;
        }

        cout << "Enter Customer name you want to update: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Password: ";
        getline(cin, password);
        Node* current = head;
        while (current != nullptr) {
            if (current->customer.name_customer == name && current->customer.password_customer == password) {
                // Display customer details
                cout << "Customer details:" << endl;
                cout << "Name: " << current->customer.name_customer << endl
                     << "ID: " << current->customer.id_customer << endl
                     << "Email: " << current->customer.email_customer << endl
                     << "Phone: " << current->customer.phone_customer << endl
                     << "Money: " << current->customer.money_customer << endl
                     << "Password: " << current->customer.password_customer << endl;
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, current->customer.name_customer);
                cout << "Enter new email: ";
                cin >> current->customer.email_customer;
                cout << "Enter new phone: ";
                cin.ignore();
                getline(cin, current->customer.phone_customer);
                cout << "Enter new money: ";
                cin >> current->customer.money_customer;
                cout << "Enter new Id: ";
                cin >> current->customer.id_customer;
                cout << "Enter new password: ";
                cin.ignore();
                getline(cin, current->customer.password_customer);
                cout << "Customer updated successfully!" << endl;
                return;
            }
            current = current->next;
        }

        cout << "Customer not found!" << endl;
    }

    int get_total_customer(){
        return total_customer;
    }

    void display_customer(){
        if (check_customer_is_empty()) {
            cout << "There is no customer account" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << "Name: " << current->customer.name_customer << " "
                 << "ID: " << current->customer.id_customer << " "
                 << "Email: " << current->customer.email_customer << " "
                 << "Phone: " << current->customer.phone_customer << " "
                 << "Money: " << current->customer.money_customer << " "
                 << "Password: " << current->customer.password_customer << endl;
            current = current->next;
        }
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
    void add_new_seller_input_data(){
        string name_seller, email_seller, pw_seller, phone_seller; 
        int id_seller, seller_money; 
        cout << "Enter seller name: ";
        cin.ignore();
        getline(cin, name_seller);
        cout << "Enter seller email: ";
        cin >> email_seller;
        cout << "Enter seller phone: ";
        cin.ignore();
        getline(cin, phone_seller);
        cout << "Enter seller id: ";
        cin >> id_seller;
        cout << "Enter money: ";
        cin >> seller_money;
        cout << "Enter seller password: ";
        cin.ignore();
        getline(cin, pw_seller);
        insert_new_seller_account(name_seller, email_seller, phone_seller, pw_seller, id_seller, seller_money);
    }
    void insert_new_seller_account(string name_seller, string email_seller, string phone_seller, string pw_seller, int id_seller, int seller_money){
        Node* newSeller = new Node;
        newSeller->seller.username_seller = name_seller;
        newSeller->seller.email_seller = email_seller;
        newSeller->seller.password_seller = pw_seller;
        newSeller->next = NULL;
        if (total_account_seller == 0)
        {
            head = tail = newSeller;
        }
        else
        {
            tail->next = newSeller;
            tail = newSeller;
        }
        total_account_seller++;
    }
    void load_data_seller_from_file(){
        fstream file(FILE_PERSONAL_SELLER, ios::in);
        if (!file.is_open()) return;
        string name, email, phone, password;
        int money, id;
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, email, ',');
            getline(ss, phone, ',');
            getline(ss, password, ',');
            ss >> id;
            ss.ignore();
            ss >> money;
            insert_new_seller_account(name, email, phone, password, id, money);
        }
        file.close();
    }
    void save_data_seller_to_file(){
        fstream file(FILE_PERSONAL_SELLER, ios::out);
        if (!file.is_open()) return;
        Node* current = head;
        while (current)
        {
            file << current->seller.username_seller << ","
                 << current->seller.email_seller << ","
                 << current->seller.phone_seller << ","
                 << current->seller.password_seller << ","
                 << current->seller.id_seller << ","
                 << current->seller.money_seller << endl;
            current = current->next;
        }
        file.close();
    }

    bool check_seller_is_empty(){
        if(total_account_seller == 0){
            return true;
        }
        return false;
    }
    void delete_seller_position(){
        string name_seller;
        string password_seller;
        if (check_seller_is_empty())
        {
            cout << "There is no seller account" << endl;
            return;
        }
        cout << "Enter Seller name you want to delete: ";
        cin.ignore();
        getline(cin, name_seller);
        cout << "Enter Password: ";
        getline(cin, password_seller);
        Node* delete_seller = nullptr;
        Node* current = head;
        Node* previous = nullptr;
        while (current != nullptr)
        {
            if (current->seller.username_seller == name_seller && current->seller.password_seller == password_seller)
            {
                delete_seller = current;
                cout << "Seller details:" << endl;
                cout << "Name: " << current->seller.username_seller << endl
                    << "ID: " << current->seller.id_seller << endl
                    << "Email: " << current->seller.email_seller << endl
                    << "Phone: " << current->seller.phone_seller << endl
                    << "Money: " << current->seller.money_seller << endl
                    << "Password: " << current->seller.password_seller << endl;
                cout << "Please press Enter to delete..." << endl;
                cin.ignore();
                if (current == head)
                {
                    head = head->next;
                    if (head == nullptr) tail = nullptr;
                }
                else if (current == tail)
                {
                    tail = previous;
                    tail->next = nullptr;
                }
                else
                {
                    previous->next = current->next;
                }
                delete delete_seller;
                total_account_seller--;
                cout << "Seller deleted successfully!" << endl;
                return;
            }
            previous = current;
            current = current->next;
        }
        cout << "Seller not found!" << endl;
    }
    void update_seller(){
        string name_seller;
        string password_seller;
        if (check_seller_is_empty())
        {
            cout << "There is no seller account" << endl;
            return;
        }
        cout << "Enter Seller name you want to delete: ";
        cin.ignore();
        getline(cin, name_seller);
        cout << "Enter Password: ";
        getline(cin, password_seller);
        Node* current = head;
        while (current != nullptr)
        {
            if (current->seller.username_seller == name_seller && current->seller.password_seller == password_seller)
            {
                cout << "Seller details:" << endl;
                cout << "Name: " << current->seller.username_seller << endl
                    << "ID: " << current->seller.id_seller << endl
                    << "Email: " << current->seller.email_seller << endl
                    << "Phone: " << current->seller.phone_seller << endl
                    << "Money: " << current->seller.money_seller << endl
                    << "Password: " << current->seller.password_seller << endl;
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, current->seller.username_seller);
                cout << "Enter new email: ";
                cin >> current->seller.email_seller;
                cout << "Enter new phone: ";
                cin.ignore();
                getline(cin, current->seller.phone_seller);
                cout << "Enter new money: ";
                cin >> current->seller.money_seller;
                cout << "Enter new Id:";
                cin >> current->seller.id_seller;
                cout << "Enter new password: ";
                cin.ignore();
                getline(cin, current->seller.password_seller);
                cout << "Seller updated successfully!" << endl;
                break;
            }
            current = current->next;
        }
        cout << "Seller not found!" << endl;
    }
    
    int get_total_seller(){
        return total_account_seller;
    }

    void display_seller(){
        if (check_seller_is_empty())
        {
            cout << "There is no seller account" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr)
        {
            cout << "Name: " << current->seller.username_seller << endl
                << "ID: " << current->seller.id_seller << endl
                << "Email: " << current->seller.email_seller << endl
                << "Phone: " << current->seller.phone_seller << endl
                << "Money: " << current->seller.money_seller << endl
                << "Password: " << current->seller.password_seller << endl;
            current = current->next;
        }
    }

};

class Login_customer
{
    public:
    bool correct_c = true;
    void lock_program()
    {
        string input_password;
        string password_file [ 10 ];
        string user_name_input;
        int line = 0;
        int found = 0;
        bool correct = false;
        ifstream read_file(FILE_USER_LOGIN);
        if ( read_file.fail() )
        {
            cout << "Unable to open file "<< endl;
            return;
        }

        while ( getline ( read_file , password_file [ line ] ) )
        {
            line++;
        }
        read_file.close();
        system("color c");
        for (int j = 0; j < 4; j++)
        {
            found ++;
            if ( found == 4)
            {
                cout << "Access denied. Program will terminate.\n";
                exit(1); // Terminates the program if password is incorrect three times
            }
            cout << "Please enter user name: ";
        // cin >> user_name_input;
            cin.ignore();
            getline(cin, user_name_input);

            cout << "Please enter password: ";
            cin >> input_password;

            if ( password_file [ 0 ] == user_name_input && password_file [ 1 ]  == input_password )
            {
                correct = true;
                system("cls");
                correct_c = false;
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



    //reset pw
    void reset_pw()
    {
        string reset_username;
        string reset_pw;
        ofstream file_write(FILE_USER_LOGIN);
        system ("color d");
        cout << "Enter new user name: ";
        cin >> reset_username;
        cout << "Enter new password: ";
        cin >> reset_pw;
        file_write << reset_username << endl;
        file_write << reset_pw;
        system("cls");
        cout << "Your user name and password has been changed. Successfully!" << endl;
        Sleep (100);


    }


    void lock_reset_pw ()
    {
        int num;
        char password_choice;
        char letter;

        system ("color B");
        cout << "\n                   \t\t***************************************************************\n";
        cout << "                   \t\t************** Welcome to E-commerce Store **********************\n";
        cout << "                   \t\t***************************************************************\n\n";
        cout << " Press Enter to continue...";
        fflush ( stdin);
        cin.ignore();
        system("cls");
        system ("color 3");
        
        system ("cls");
        while(correct_c)
        {
            cout << "Note" << endl;
            cout << "W. For Enter user name and password" << endl;
            cout << "F. For forget password" << endl;
            cout << "x. back to previouse" << endl;
            cout << "Please your choice: ";
            cin >> password_choice;
            switch ( password_choice )
                {
                    //choice_convert = atoi (password_choice);
                    case 'W':
                    case 'w':
                        system ("cls");
                        lock_program();
                        break;

                    case 'F':
                    case 'f':
                        //int num;
                        system ("cls");
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
                case 'X':
                case 'x':
                    main_function();
                    break;
                default:
                    cout << "Invalid input" << endl;
                    exit(1);
            }
        }
    }

};

class Login_seller
{
    public:
    bool correct = true;
    void lock_program()
    {
        string input_password;
        string password_file [ 10 ];
        string user_name_input;
        int line = 0;
        int found = 0;
        bool correct = false;
        ifstream read_file(FILE_SELLER_LOGIN);
        if ( read_file.fail() )
        {
            cout << "Unable to open file "<< endl;
            return;
        }

        while ( getline ( read_file , password_file [ line ] ) )
        {
            line++;
        }
        read_file.close();
        system("color c");
        for (int j = 0; j < 4; j++)
        {
            found ++;
            if ( found == 4)
            {
                cout << "Access denied. Program will terminate.\n";
                exit(1); // Terminates the program if password is incorrect three times
            }
            cout << "Please enter user name: ";
        // cin >> user_name_input;
            cin.ignore();
            getline(cin, user_name_input);

            cout << "Please enter password: ";
            cin >> input_password;

            if ( password_file [ 0 ] == user_name_input && password_file [ 1 ]  == input_password )
            {
                correct = true;
                system("cls");
                //cout << "Access granted!\n";
                correct = false;
                break;
            }
            if ( !correct )
            {
                system("cls");
                cout << "Invalid  user name or password!\n";
            }
        }
    }



    //reset pw
    void reset_pw()
    {
        string reset_username;
        string reset_pw;
        ofstream file_write(FILE_SELLER_LOGIN);
        system ("color d");
        cout << "Enter new user name: ";
        cin >> reset_username;
        cout << "Enter new password: ";
        cin >> reset_pw;
        file_write << reset_username << endl;
        file_write << reset_pw;
        system("cls");
        cout << "Your user name and password has been changed. Successfully!" << endl;
        Sleep (100);


    }


    void lock_reset_pw ()
    {
        int num;
        char password_choice;
        char letter;

        system ("color B");
        cout << "\n                   \t\t***************************************************************\n";
        cout << "                   \t\t************** Welcome to E-commerce Store **********************\n";
        cout << "                   \t\t***************************************************************\n\n";
        cout << " Press Enter to continue...";
        fflush ( stdin);
        cin.ignore();
        system("cls");
        system ("color 3");
        
        system ("cls");
        while(correct)
        {
            cout << "Note" << endl;
            cout << "W. For Enter user name and password" << endl;
            cout << "F. For forget password" << endl;
            cout << "x. back to previouse" << endl;
            cout << "Please your choice: ";
            cin >> password_choice;
            switch ( password_choice )
                {
                    //choice_convert = atoi (password_choice);
                    case 'W':
                    case 'w':
                        system ("cls");
                        lock_program();
                        break;

                    case 'F':
                    case 'f':
                        //int num;
                        system ("cls");
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
                case 'X':
                case 'x':
                    main_function();
                    break;
                default:
                    cout << "Invalid input" << endl;
                    exit(1);
            }
        }
    }
    

};

void main_function(){
        Style style;
        ProductManager* product = new ProductManager;
        add_to_cart* cart = new add_to_cart;
        Invoice* invoice = new Invoice;
        Login_customer c;
        Login_seller s;
        invoice->load_invoice_from_file();
        cart->load_cart_file();
        product->read_products();
        int opt;
        bool back = true;
        //design
        style.loading_style();
        bool back_seller_customer = true;
        while (back_seller_customer)
        {

            //ask for seller or customer
            cout << "please choose option(only one letter): " << endl;
            cout << "0. Exit the program" << endl;
            cout << "1. for Customer" << endl;
            cout << "2. for Seller" << endl;
            cout << "Enter your role: ";
            cin >> opt;
            if(opt == 1)
            {
                system("cls");
                system("color 0b");
                bool back1 = true;
                c.lock_reset_pw();
                while(back1)
                {
                    
                    style.display_menu_customer();
                    int opt_customer;
                    cout << "Enter your option: ";
                    cin >> opt_customer;
                    switch (opt_customer)
                    {
                        case 1:
                            system("cls");
                            system("color 0A");
                            {
                                product->display_products();
                                int id_product, quantity;
                                cout << "Enter ID for add product to cart: " ;
                                cin >> id_product;
                                cout << "Enter Amount for add to cart: ";
                                cin >> quantity;
                                cart->add_to_cart_data_transfer( product, id_product, quantity);

                            }
                            break;
                        case 0:
                            cout << "You are exited the program" << endl;
                            style.exit_program_style ();
                            exit(0);
                            break;
                        case 2:
                        {
                            system("cls");
                            system("color 0A");
                            product->search_product();
                        }
                            break;
                        case 3:
                            system("cls");
                            system("color 0A");
                            cart->display_product_in_cart();
                            break;
                        case 4:
                            system("cls");
                            system("color 0A");
                                cart->delete_product_in_cart();
                            break;
                        case 5:
                            system("cls");
                            system("color 0A");
                            //check profile
                            break;
                        case 6:
                            system("cls");
                            system("color 0A");
                            {
                                int choice;
                                bool back_customer = true;
                                while(back_customer)
                                {
                                    invoice->displau_menu_invoice();
                                    cout << "Enter your choice: ";
                                    cin >> choice;
                                    switch (choice)
                                    {
                                        case 1:
                                        {
                                            system("cls");
                                            system("color 3A");
                                            system("color 0A");
                                            {
                                                int id_product, quantity;
                                                cout << "Enter ID for add product to cart: " ;
                                                cin >> id_product;
                                                cout << "Enter Amount for add to cart: ";
                                                cin >> quantity;
                                                cart->add_to_cart_data_transfer( product, id_product, quantity);
                                                
                                            }
                                            break;
                                        }
                                        case 2:
                                        {
                                            system("cls");
                                            system("color 1a");
                                            invoice->delete_product_from_invoice();
                                            break;
                                        }
                                        case 3:
                                        {
                                            system("cls");
                                            system("color 0A");
                                            invoice->display_product_in_invoice();
                                            break;
                                        }
                                        case 4:
                                        {
                                            system("cls");
                                            system("color 2A");
                                            invoice->add_save_history_to_file();
                                            break;
                                        }
                                        case 5:
                                        {
                                            system("cls");
                                            system("color 6A");
                                            invoice->display_product_in_invoice();
                                            break;
                                        }   
                                        case 0:
                                        {
                                            system("cls");
                                            system("color 4A");
                                            style.exit_program_style ();
                                            cout << "Exit successfully." << endl;
                                            exit(0);
                                        }
                                        case 6:
                                            system("cls");
                                            system("color 5A");
                                            invoice->display_history_of_customer_from_file();
                                        break;
                                        case 7:
                                            system("cls");
                                            system("color 4A");
                                            invoice->save_inovice_to_file();
                                        break;
                                        case 8:
                                            back_customer = false;
                                            cout << "you are backed to previouse!" << endl;
                                        break;
                                        default:
                                        {
                                            system("cls");
                                            system("color 5A");
                                            cout << "Invalid choice." << endl;
                                            break;
                                        }

                                    }
                                }


                            }

                            break;
                        case 7:
                            system("cls");
                            system("color 0A");
                            back1 = false;
                            break;
                        case 8:
                            system("cls");
                            system("color 0A");
                            break;
                        case 9:
                            system("cls");
                            system("color 0A");
                            cart->save_cart_to_file();
                        break;
                        case 11:
                            system("cls");
                            system("color 0c");
                            product->display_products();
                        break;
                        case 10:
                            {
                                bool back_cart_management = true;
                                system("cls");
                                system("color 0c");
                                int choice;
                                while (back_cart_management) 
                                {
                                    cart->displayMenu();
                                    cout << "Enter your choice: ";
                                    cin >> choice;
                                    bool back_invoice = true;
                                    switch (choice) {
                                        case 1: {
                                            while (back_invoice) {
                                                int opt;
                                                cart->shoping_menu();
                                                cout << "Enter your choice: ";
                                                cin >> opt;
                                                switch (opt) {
                                                    case 1: {
                                                        system("cls");                                               
                                                        system("color 0A");
                                                    {
                                                        int id_product, quantity;
                                                        cout << "Enter ID for add product to cart: " ;
                                                        cin >> id_product;
                                                        cout << "Enter Amount for add to cart: ";
                                                        cin >> quantity;
                                                        cart->add_to_cart_data_transfer( product, id_product, quantity);
                        
                                                    }
                                                        break;
                                                    }
                                                    case 2: {
                                                        system("cls");
                                                        system("color 4");  
                                                        cart->delete_product_in_cart();
                                                        break;
                                                    }
                                                    case 3: {
                                                        system("cls");
                                                        system("color 3");
                                                        cart->display_product_in_cart();
                                                        break;
                                                    }
                                                    case 4: {
                                                        system("cls");
                                                        system("color 5");
                                                        cart->update_product_in_cart();
                                                        break;
                                                    }
                                                    case 5: {
                                                        system("cls");
                                                        system("color 6");
                                                        cart->pay_money();
                                                        invoice->getCurrentTime_for_generate_invioce();
                                                        invoice->add_save_history_to_file();
                                                        break;
                                                    }
                                                    case 6: {
                                                        system("cls");
                                                        system("color 7");
                                                        cart->save_cart_to_file();
                                                        break;
                                                    }
                                                    case 7:
                                                        system("cls");
                                                        system("color 7");
                                                        invoice->save_inovice_to_file();
                                                        cout << " Your are backed to previouse!" << endl;
                                                        break;
                                                    case 8:
                                                        system("cls");
                                                        system("color 4");
                                                        back_invoice = false;
                                                        cout << " Your are backed to previouse!" << endl;
                                                    break;
                                                    case 0: {
                                                        style.exit_program_style ();
                                                        cout << "Exit successfully." << endl;
                                                        exit(0);
                                                    }
                                                    default: {
                                                        cout << "Invalid choice." << endl;
                                                        break;
                                                    }
                                                }
                                            }
                                            break; // Add break here
                                        }
                                        case 0: {
                                            style.exit_program_style ();
                                            cout << "Exiting the program.\n";
                                            exit(0);
                                        }
                                        case 2: {
                                            system("cls");
                                            system("color 2");
                                            cart->display_product_in_cart();
                                            break;
                                        }
                                        case 3: {
                                            system("cls");
                                            system("color 1");
                                            cart->update_product_in_cart();
                                            break;
                                        }
                                        case 4: {
                                            system("cls");
                                            system("color e");
                                            cart->display_product_in_cart();
                                            break;
                                        }
                                        case 5: {
                                            system("cls");
                                            system("color d");
                                            cart->pay_money();
                                            break;
                                        }
                                        case 6: {
                                            system("cls");
                                            system("color c");
                                            //check your profile
                                            cout << "Your profile\n";
                                            break;
                                        }
                                        case 7: {
                                            system("cls");
                                            system("color b");
                                            cart->update_product_in_cart();
                                            break;
                                        }
                                        case 8: {
                                            system("cls");
                                            system("color a");
                                            cart->save_cart_to_file();
                                            break;
                                        }
                                        case 9:
                                            system("cls");
                                            system("color a");
                                            back_cart_management = false;
                                            break;
                                        default: {
                                            cout << "Invalid choice." << endl;
                                            break;
                                        }
                                    }
                                }
                            }
                        break;
                        default:
                            cout << "invaid input!" << endl;
                            break;
                    }
                }
            }
            else if (opt == 2)
            {
                s.lock_reset_pw();
                bool back2=true;
                while (back2)
                {
                    style.display_menu_seller();
                    int opt_seller;
                    cout << "Enter Your option: ";
                    cin >> opt_seller;
                    switch (opt_seller)
                    {
                        case 0:
                        {
                            style.exit_program_style ();
                            cout << "You are exited the program" << endl;
                            exit(0);
                        }         
                        break;
                        case 1:
                            system("cls");
                            system("color 0A");
                            product->display_products();
                        break;
                        case 2:
                            system("cls");
                            system("color 0A");
                            product->run();
                                
                        break;
                        case 3:
                            system("cls");
                            system("color 0A");  
                            back2 = false;  
                        break;
                        case 4:
                            system("cls");
                            system("color 0A");  
                            //report
                        break;
                        case 5:
                            system("cls");
                            system("color 0A");  
                            //report
                            product->generate_report();
                        break;
                        default:
                        cout << "Invalid input" << endl;
                    }
                    
                }
                
            }
            else if(opt == 0){
                cout << "You are exited the program " << endl;
                exit(0);
            }
            else{
                cout << "invalid input" << endl;
            }
        }
    }


int main ()
{
    main_function();
    
    return 0;
}

