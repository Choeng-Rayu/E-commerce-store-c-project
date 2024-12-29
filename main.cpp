#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<ctime>
#include"add_to_cart.h"
#include"invoice.h"

using namespace std;







class Style{
    public:
    void display_menu_customer()
    {
        cout << "\n                   \t\t***************************************************************\n";
        cout << "                   \t\t************** Welcome to E-Commerce store *********************\n";
        cout << "                   \t\t***************************************************************\n\n";
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
        cout << "You login successfully!";
        Sleep(3000);
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

int main ()
{
    Style style;
    ProductManager* product = new ProductManager;
    add_to_cart* cart = new add_to_cart;
    Invoice* invoice = new Invoice;
    invoice->load_invoice_from_file();
    cart->load_cart_file();
    product->read_products();
    int opt;
    bool back = true;
    //design
    style.loading_style();
    while (true)
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
            while(back)
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
                            int id_product, quantity;
                            cout << "Enter ID for add product to cart: " ;
                            cin >> id_product;
                            cout << "Enter Amount for add to cart: ";
                            cin >> quantity;
                            cart->add_to_cart_data_transfer(id_product, quantity);
                            cout << "hi";
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
                                        string name, type,date;
                                        int id, amount;
                                        float price;
                                        cout << "Enter Name product:";
                                        cin.ignore();
                                        getline(cin, name);
                                        cout << "Enter ID product:";
                                        cin >> id;
                                        cout << "Enter Price product:";
                                        cin >> price;
                                        cout << "Enter Amount product:";
                                        cin >> amount;
                                        cout << "Enter Type product:";
                                        cin >> type;
                                        invoice->product_add_to_invoice(name, id, price, amount, type, date = invoice->getCurrentTime());
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
                        back = false;
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
                                switch (choice) {
                                    case 1: {
                                        while (true) {
                                            int opt;
                                            cart->shoping_menu();
                                            cout << "Enter your choice: ";
                                            cin >> opt;
                                            switch (opt) {
                                                case 1: {
                                                    system("cls");
                                                    string name, type;
                                                    int id, amount;
                                                    float price;
                                                    cout << "Enter Name product: ";
                                                    cin.ignore();
                                                    getline(cin, name);
                                                    cout << "Enter ID product: ";
                                                    cin >> id;
                                                    cout << "Enter Price product: ";
                                                    cin >> price;
                                                    cout << "Enter Amount product: ";
                                                    cin >> amount;
                                                    cout << "Enter Type product: ";
                                                    cin.ignore();
                                                    getline(cin, type);
                                                    cart->add_product_to_cart(name, id, price, amount, type, cart->getCurrentTime());
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
                                                    back_cart_management = false;
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
                                        delete cart; // Deallocate memory before exiting
                                        return 0;
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
            while (back)
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
                        back = false;  
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
    

    return 0;
}

