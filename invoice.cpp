#include"invoice.h"


int main()
{
    Invoice* invoice = new Invoice;
    int choice;
    invoice->load_invoice_from_file();
    while(true)
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
            default:
            {
                system("cls");
                system("color 5A");
                cout << "Invalid choice." << endl;
                break;
            }

        }
    }
    return 0;
}
