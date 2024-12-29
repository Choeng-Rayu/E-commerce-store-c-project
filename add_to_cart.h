#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

#define FILE_BUY_NOW "buy_now.csv"  // store all the buy now of the customer
#define FILE_NAME "add to cart.csv" // store all the add to cart of the customer
// PRODUCT 
struct Product
{
    string nameProduct;
    string catagory_product;
    int idPoduct;
    float priceProduct;
    int quantity_product;
    string date;
};

struct Node {
    Product product;
    Node* next;
};

class add_to_cart {
private:
    Node* head;
    Node* tail;
    int totalProduct;
    public:
    void displayMenu() {
        cout << "0. Exit\n";
        cout << "1. Shoping\n";
        cout << "2. check out\n";
        cout << "3. cancel Producct\n";
        cout << "4. Display product in cart\n";
        cout << "5. Pay money\n";
        cout << "6. Check Your profile\n";
        cout << "7. Edit Your product in cart\n";
        cout << "8. Save your cart to file\n";
    }
    void shoping_menu(){
        cout << "0. Exit\n";
        cout << "1. Add Product to cart\n";
        cout << "2. Remove Product from cart\n";
        cout << "3. Display Product in cart\n";
        cout << "4. edit Product in cart\n";
        cout << "5. Pay money\n";
        cout << "6. Save cart to file\n";

    }
    string getCurrentTime() {

        // Get the current time
        time_t t = time(nullptr); 
        tm* now = localtime(&t);

        // Format the time into a string
        char buffer[100];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now);

        return string(buffer);
    }
    add_to_cart(){
        head = nullptr;
        tail = nullptr;
        totalProduct = 0;
    }

    ~add_to_cart() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    void add_product_to_cart(string name_product, int id_product, float price_product, int amount_product, string type_product, string date) {
        Node* new_product = new Node;
        new_product->product.nameProduct = name_product;
        new_product->product.idPoduct = id_product;
        new_product->product.priceProduct = price_product;
        new_product->product.quantity_product = amount_product;
        new_product->product.catagory_product = type_product;
        new_product->product.date = date;
        new_product->next = nullptr;
        if (head == nullptr) {
            head = new_product;
            tail = new_product;
        } else {
            tail->next = new_product;
            tail = new_product;
        }
        totalProduct++;

    }

    void save_cart_to_file() {
        ofstream file;
        file.open(FILE_NAME);
        if (file.is_open()) {
            Node* temp = head;
            while (temp != nullptr) {
                file << temp->product.nameProduct << ","
                     << temp->product.catagory_product << ","
                     << temp->product.date << ","
                     << temp->product.idPoduct << ","
                     << temp->product.priceProduct << ","
                     << temp->product.quantity_product << "\n";
                temp = temp->next;
            }
            file.close();
            cout << "All products stored in the file successfully.\n";
        } else {
            cerr << "Unable to open file for writing.\n";
        }
    }
    void display_product_in_cart() {
        Node* temp = head;
        int count = 1;
        cout << "\n\t\t\t\t\t================ Pre-Pay ================\n"; 
        cout << "No\tName\t\t\tCategory\t\tID\t\tPrice\t\tQuantity\tDate\n";
        while (temp != nullptr) {
            cout << count << "\t"
                << setw(20) << left << temp->product.nameProduct << "\t"
                << setw(20) << left << temp->product.catagory_product << "\t"
                << setw(10) << left << temp->product.idPoduct << "\t"
                << setw(10) << left << temp->product.priceProduct << "\t"
                << setw(10) << left << temp->product.quantity_product << "\t"
                << temp->product.date << "\n";
            temp = temp->next;
            count++;
        }
        cout << "Total product in cart: " << totalProduct << endl;
        cout << "\t\t\t\t\t==========================================\n";
    }
    void load_cart_file() {
        ifstream file;
        file.open(FILE_NAME);
        string name, category, date;
        int id, quantity;
        float price;
        string line;
        string skip_line;
        getline(file, skip_line); // Skip the first line
        if (file.is_open()) {
            while (getline(file, line)) {
                stringstream ss(line);
                getline(ss, name, ',');
                getline(ss, category, ',');
                getline(ss, date, ',');
                ss >> id;
                ss.ignore(1, ','); // Ignore the comma
                ss >> price;
                ss.ignore(1, ','); // Ignore the comma
                ss >> quantity;
                add_product_to_cart(name, id, price, quantity, category, date);
            }
            file.close();
        } else {
            cerr << "Unable to open file for reading.\n";
        }
    }
    void delete_product_in_cart() {
        int product_id;
        cout << "Enter list in your cart to delete that product: ";
        cin >> product_id;
        string name_remove;
        if(head == nullptr){
            cout << "Cart is empty\n";
            return;
        }
        Node* current = head;
        Node* previous = nullptr;
        bool found = false;
        while(current != nullptr){
            if(current->product.idPoduct == product_id){
                found = true;
                name_remove = current->product.nameProduct;
                if(previous == nullptr){
                    head = current->next;
                    delete current;
                    totalProduct--;
                    break;
                }else{
                    previous->next = current->next;
                    delete current;
                    totalProduct--;
                    break;
                }
                
            }
        }
        if(!found){
            cout << "Product not found in cart\n";
        }else{
            cout << "Product " << name_remove << " removed from cart\n";
        }

    }
    void pay_money(){
        Node* current = head;
        float total = 0;
        cout << "\n================ INVOICE ================\n"; 
        cout << "Name\t\t\tCategory\tID\t\tPrice\tQuantity\t\t\tDate\n";
        while(current != nullptr){
            cout << current->product.nameProduct << "\t\t\t" << current->product.catagory_product << "\t\t" << current->product.idPoduct << "\t\t" << current->product.priceProduct << "\t\t" << current->product.quantity_product << "\t" << current->product.date <<  "\n";
            total += current->product.priceProduct * current->product.quantity_product;
            current = current->next;
        }
        cout << "\n\t\tTotal money: " << total << "$" << endl;
        cout << "Please Enter your money: ";
        float money;
        cin >> money;
        if(money < total){
            cout << "Not enough money\n";
        }else if(money == total){
            cout << "Pay successfully at" << getCurrentTime() << endl;
            cout << "====================================Thank you for shopping with us==========================================\n";
            head = nullptr;
            tail = nullptr;
            totalProduct = 0;
        }else{
            cout << "Your product did not pay: " << endl;
        }

    }
    void update_product_in_cart() {
        int product_id;
        cout << "Enter id product to update: ";
        cin >> product_id;
        string name_update;
        if (head == nullptr) {
            cout << "Cart is empty\n";
            return;
        }
        Node* current = head;
        bool found = false;
        while (current != nullptr) {
            if (current->product.idPoduct == product_id) {
                found = true;
                cout << "Product found in cart\n";
                cout << "Product name: " << current->product.nameProduct << endl;
                cout << "Product ID: " << current->product.idPoduct << endl;
                cout << "Product Price: " << current->product.priceProduct << endl;
                cout << "Product Amount: " << current->product.quantity_product << endl;
                cout << "Product Type: " << current->product.catagory_product << endl;
                cout << "Product Date: " << current->product.date << endl;
                name_update = current->product.nameProduct;
                cout << "Enter new Amount product: ";
                cin >> current->product.quantity_product;
                cout << "Product updated successfully\n";
                break;
            }
            current = current->next; // Move to the next node
        }
        if (!found) {
            cout << "Product not found in cart\n";
        } else {
            cout << "Product " << name_update << " updated in cart\n";
        }
    }

    

    // void run() {
    //     int choice;
    //     do {
    //         displayMenu();
    //         cin >> choice;
    //         cin.ignore(); // to ignore the newline character after the choice input

    //         if (choice == 1) {
    //             Product product;
    //             cout << "Enter product name: ";
    //             getline(cin, product.nameProduct);
    //             cout << "Enter product category: ";
    //             getline(cin, product.catagory_product);
    //             cout << "Enter product ID: ";
    //             cin >> product.idPoduct;
    //             cout << "Enter product price: ";
    //             cin >> product.priceProduct;
    //             cout << "Enter product quantity: ";
    //             cin >> product.quantity_product;
    //             cin.ignore(); // to ignore the newline character after the quantity input
    //             add_product_to_cart(product.nameProduct, product.idPoduct, product.priceProduct, product.quantity_product, product.catagory_product);
    //         } else if (choice == 2) {
    //             int id;
    //             Product product;
    //             cout << "Enter product ID to update: ";
    //             cin >> id;
    //             cin.ignore(); // to ignore the newline character after the ID input
    //             cout << "Enter new product name: ";
    //             getline(cin, product.nameProduct);
    //             cout << "Enter new product category: ";
    //             getline(cin, product.catagory_product);
    //             cout << "Enter new product ID: ";
    //             cin >> product.idPoduct;
    //             cout << "Enter new product price: ";
    //             cin >> product.priceProduct;
    //             cout << "Enter new product quantity: ";
    //             cin >> product.quantity_product;
    //             cin.ignore(); // to ignore the newline character after the quantity input
    //             updateProductInFile(id, product);
    //         } else if (choice == 3) {
    //             int id;
    //             cout << "Enter product ID to delete: ";
    //             cin >> id;
    //             deleteProductFromFile(id);
    //         } else if (choice == 4) {
    //             readProducts();
    //         } else if (choice == 5) {
    //             storeAllProductsToFile();
    //         } else if (choice == 6) {
    //             cout << "Exiting...\n";
    //         } else {
    //             cout << "Invalid choice. Please try again.\n";
    //         }
    //     } while (choice != 6);
    // }
};