#include"add_to_cart.h"





int main() {
    add_to_cart* cart = new add_to_cart;
    int choice;
    cart->load_cart_file();
    while (true) {
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
                        case 0: {
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
    return 0;
}