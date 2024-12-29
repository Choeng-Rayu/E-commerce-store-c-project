#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "invoice.h"
using namespace std;

#define FILE_BUY_NOW "buy_now.csv"  // store all the buy now of the customer
#define FILE_CART "add to cart.csv" // store all the add to cart of the customer
//PRODUCT DATA
#define FILE_PRODUCT_DATA "ProductdataClass.csv"
#define MAX_QUANTITY 1000000 // Define a maximum quantity limit


// cart
struct Product_cart
{
    string nameProduct;
    string catagory_product;
    int idPoduct;
    float priceProduct;
    int quantity_product;
    string date;
};

struct node_cart {
    Product_cart product;
    node_cart* next;
};

//Product
struct Product
{
    string nameProduct;
    string catagory_product;
    int idPoduct;
    float priceProduct;
    int quantity_product;

    bool operator==(const Product &other) const
    {
        return idPoduct == other.idPoduct;
    }
};


struct node_product
{
    Product product;
    node_product *next;
};

class ProductManager
{
    public:
    node_product *head;
    node_product *tail;

    void display_menu()
    {
        cout << "1. Add Product\n";
        cout << "2. Update Product\n";
        cout << "3. Delete Product\n";
        cout << "4. Display Products\n";
        cout << "5. Store All Products to File\n";
        cout << "6. Search Product\n";
        cout << "7. Exit\n";
        cout << "8. Back to Previous\n";
        cout << "Enter your choice: ";
    }

    bool is_valid_category(const string &category)
    {
        for (char c : category)
        {
            if (!isalpha(c))
            {
                return false;
            }
        }
        return true;
    }

    bool is_valid_number(const string &str)
    {
        for (char c : str)
        {
            if (!isdigit(c))
            {
                return false;
            }
        }
        return true;
    }

    void to_upper_case(string &str)
    {
        for (char &c : str)
        {
            c = toupper(c);
        }
    }

    void sort_linked_list()
    {
        if (!head || !head->next)
            return;

        node_product *sorted = nullptr;

        while (head)
        {
            node_product *current = head;
            head = head->next;

            if (!sorted || sorted->product.catagory_product > current->product.catagory_product ||
                (sorted->product.catagory_product == current->product.catagory_product && sorted->product.idPoduct > current->product.idPoduct))
            {
                current->next = sorted;
                sorted = current;
            }
            else
            {
                node_product *temp = sorted;
                while (temp->next && (temp->next->product.catagory_product < current->product.catagory_product ||
                                      (temp->next->product.catagory_product == current->product.catagory_product && temp->next->product.idPoduct < current->product.idPoduct)))
                {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
        }

        head = sorted;
    }

    void clear_list()
    {
        node_product *current = head;
        while (current != nullptr)
        {
            node_product *next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        tail = nullptr;
    }

public:
    ProductManager() : head(nullptr), tail(nullptr)
    {
        read_products(); // Read products from the file when the program starts
    }

    ~ProductManager()
    {
        clear_list();
    }

    void add_product_to_list(const Product &product)
    {
        node_product *newnode_product = new node_product;
        newnode_product->product = product;
        newnode_product->next = nullptr;
        if (head == nullptr)
        {
            head = newnode_product;
            tail = newnode_product;
        }
        else
        {
            tail->next = newnode_product;
            tail = newnode_product;
        }
    }

    void store_all_products_to_file()
    {
        sort_linked_list(); // Sort the linked list by category and ID

        ofstream outFile;
        outFile.open(FILE_PRODUCT_DATA, ios::trunc); // Open file in truncate mode to clear it first
        if (outFile.is_open())
        {
            node_product *temp = head;
            while (temp != nullptr)
            {
                to_upper_case(temp->product.nameProduct);
                to_upper_case(temp->product.catagory_product);
                outFile << temp->product.nameProduct << ","
                        << temp->product.catagory_product << ","
                        << temp->product.idPoduct << ","
                        << temp->product.priceProduct << ","
                        << temp->product.quantity_product << "\n";
                temp = temp->next;
            }
            outFile.close();
            cout << "All products stored in the file successfully.\n";
        }
        else
        {
            cerr << "Unable to open file for writing.\n";
        }
    }

    void read_products()
    {
        ifstream file;
        file.open(FILE_PRODUCT_DATA);
        string line;
        if (file.is_open())
        {
            while (getline(file, line))
            {
                stringstream ss(line);
                Product product;
                getline(ss, product.nameProduct, ',');
                getline(ss, product.catagory_product, ',');
                if (!(ss >> product.idPoduct))
                    continue;
                ss.ignore();
                if (!(ss >> product.priceProduct))
                    continue;
                ss.ignore();
                if (!(ss >> product.quantity_product))
                    continue;
                to_upper_case(product.nameProduct);
                to_upper_case(product.catagory_product);
                add_product_to_list(product);
            }
            file.close();
        }
        else
        {
            cerr << "Unable to open file for reading.\n";
        }
    }

    void update_product_in_list(int id, const Product &updatedProduct)
    {
        node_product *temp = head;
        bool found = false;
        while (temp != nullptr)
        {
            if (temp->product.idPoduct == id)
            {
                temp->product = updatedProduct;
                found = true;
                break;
            }
            temp = temp->next;
        }
        if (!found)
        {
            cerr << "Product with ID " << id << " not found in the list.\n";
        }
    }

    void delete_product_from_list(int id)
    {
        node_product *temp = head;
        node_product *prev = nullptr;
        bool found = false;

        while (temp != nullptr)
        {
            if (temp->product.idPoduct == id)
            {
                if (prev == nullptr)
                {
                    head = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                if (temp == tail)
                {
                    tail = prev;
                }
                delete temp;
                found = true;
                break;
            }
            prev = temp;
            temp = temp->next;
        }

        if (!found)
        {
            cerr << "Product with ID " << id << " not found in the list.\n";
        }
    }

    void delete_product_from_file(int id)
    {
        ifstream file;
        file.open(FILE_PRODUCT_DATA);
        ofstream tempFile;
        tempFile.open("temp.csv");
        string line;
        bool found = false;

        if (file.is_open() && tempFile.is_open())
        {
            while (getline(file, line))
            {
                stringstream ss(line);
                string name, category, idStr, price, quantity;
                getline(ss, name, ',');
                getline(ss, category, ',');
                getline(ss, idStr, ',');
                getline(ss, price, ',');
                getline(ss, quantity, ',');

                if (stoi(idStr) != id)
                {
                    tempFile << line << "\n";
                }
                else
                {
                    found = true;
                }
            }
            file.close();
            tempFile.close();
            remove(FILE_PRODUCT_DATA);
            rename("temp.csv", FILE_PRODUCT_DATA);

            if (!found)
            {
                cerr << "Product with ID " << id << " not found in the file.\n";
            }
        }
        else
        {
            cerr << "Unable to open file for deleting.\n";
        }
    }

    void display_products()
    {
        cout << "Products in list:\n";
        node_product *temp = head;
        while (temp != nullptr)
        {
            cout << "Name: " << temp->product.nameProduct << ", Category: " << temp->product.catagory_product
                 << ", ID: " << temp->product.idPoduct << ", Price: " << temp->product.priceProduct
                 << ", Quantity: " << temp->product.quantity_product << "\n";
            temp = temp->next;
        }
    }
    void sell_product_by_ID(int id){
            node_product *temp = head;
            while (temp != nullptr)
            {
                if (temp->product.idPoduct == id)
                {
                    cout << "Name: " << temp->product.nameProduct << ", Category: " << temp->product.catagory_product
                         << ", ID: " << temp->product.idPoduct << ", Price: " << temp->product.priceProduct
                         << ", Quantity: " << temp->product.quantity_product << "\n";
                        temp->product.quantity_product--;
                    return;
                }
                temp = temp->next;
            }
            cout << "Product with ID " << id << " not found.\n";
    }
    void search_product()
    {
        int choice;
        cout << "Search by:\n";
        cout << "1. ID\n";
        cout << "2. Name\n";
        cout << "3. Category\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // to ignore the newline character after the choice input

        if (choice == 1)
        {
            int id;
            cout << "Enter product ID: ";
            cin >> id;
            node_product *temp = head;
            while (temp != nullptr)
            {
                if (temp->product.idPoduct == id)
                {
                    cout << "Name: " << temp->product.nameProduct << ", Category: " << temp->product.catagory_product
                         << ", ID: " << temp->product.idPoduct << ", Price: " << temp->product.priceProduct
                         << ", Quantity: " << temp->product.quantity_product << "\n";
                    return;
                }
                temp = temp->next;
            }
            cout << "Product with ID " << id << " not found.\n";
        }
        else if (choice == 2)
        {
            string name;
            cout << "Enter product name: ";
            getline(cin, name);
            to_upper_case(name);
            node_product *temp = head;
            while (temp != nullptr)
            {
                if (temp->product.nameProduct == name)
                {
                    cout << "Name: " << temp->product.nameProduct << ", Category: " << temp->product.catagory_product
                         << ", ID: " << temp->product.idPoduct << ", Price: " << temp->product.priceProduct
                         << ", Quantity: " << temp->product.quantity_product << "\n";
                    return;
                }
                temp = temp->next;
            }
            cout << "Product with name " << name << " not found.\n";
        }
        else if (choice == 3)
        {
            string category;
            cout << "Enter product category: ";
            getline(cin, category);
            to_upper_case(category);
            node_product *temp = head;
            while (temp != nullptr)
            {
                if (temp->product.catagory_product == category)
                {
                    cout << "Name: " << temp->product.nameProduct << ", Category: " << temp->product.catagory_product
                         << ", ID: " << temp->product.idPoduct << ", Price: " << temp->product.priceProduct
                         << ", Quantity: " << temp->product.quantity_product << "\n";
                }
                temp = temp->next;
            }
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }

    void run()
    {
        int choice;
        bool back = true;
        do
        {
            display_menu();
            cin >> choice;
            cin.ignore(); // to ignore the newline character after the choice input

            if (choice == 1)
            {
                Product product;
                cout << "Enter product name: ";
                getline(cin, product.nameProduct);
                do
                {
                    cout << "Enter product category: ";
                    getline(cin, product.catagory_product);
                    if (!is_valid_category(product.catagory_product))
                    {
                        cerr << "Invalid category. Please enter alphabetic characters only.\n";
                    }
                } while (!is_valid_category(product.catagory_product));
                do
                {
                    cout << "Enter product ID: ";
                    string idStr;
                    getline(cin, idStr);
                    if (is_valid_number(idStr))
                    {
                        product.idPoduct = stoi(idStr);
                    }
                    else
                    {
                        cerr << "Invalid ID. Please enter numeric characters only.\n";
                    }
                } while (!is_valid_number(to_string(product.idPoduct)));
                while (true)
                {
                    cout << "Enter product price: ";
                    string priceStr;
                    getline(cin, priceStr);
                    try
                    {
                        product.priceProduct = stof(priceStr);
                        break;
                    }
                    catch (...)
                    {
                        cerr << "Invalid price. Please enter a valid number.\n";
                    }
                }
                do
                {
                    cout << "Enter product quantity: ";
                    string quantityStr;
                    getline(cin, quantityStr);
                    if (is_valid_number(quantityStr))
                    {
                        int quantity = stoi(quantityStr);
                        if (quantity > 0 && quantity <= MAX_QUANTITY)
                        {
                            product.quantity_product = quantity;
                        }
                        else
                        {
                            cerr << "Invalid quantity. Please enter a number between 1 and " << MAX_QUANTITY << ".\n";
                        }
                    }
                    else
                    {
                        cerr << "Invalid quantity. Please enter numeric characters only.\n";
                    }
                } while (product.quantity_product <= 0 || product.quantity_product > MAX_QUANTITY);
                to_upper_case(product.nameProduct);
                to_upper_case(product.catagory_product);
                add_product_to_list(product);
            }
            else if (choice == 2)
            {
                int id;
                Product product;
                cout << "Enter product ID to update: ";
                cin >> id;
                cin.ignore(); // to ignore the newline character after the ID input
                cout << "Enter new product name: ";
                getline(cin, product.nameProduct);
                do
                {
                    cout << "Enter new product category: ";
                    getline(cin, product.catagory_product);
                    if (!is_valid_category(product.catagory_product))
                    {
                        cerr << "Invalid category. Please enter alphabetic characters only.\n";
                    }
                } while (!is_valid_category(product.catagory_product));
                do
                {
                    cout << "Enter new product ID: ";
                    string idStr;
                    getline(cin, idStr);
                    if (is_valid_number(idStr))
                    {
                        product.idPoduct = stoi(idStr);
                    }
                    else
                    {
                        cerr << "Invalid ID. Please enter numeric characters only.\n";
                    }
                } while (!is_valid_number(to_string(product.idPoduct)));
                while (true)
                {
                    cout << "Enter new product price: ";
                    string priceStr;
                    getline(cin, priceStr);
                    try
                    {
                        product.priceProduct = stof(priceStr);
                        break;
                    }
                    catch (...)
                    {
                        cerr << "Invalid price. Please enter a valid number.\n";
                    }
                }
                do
                {
                    cout << "Enter new product quantity: ";
                    string quantityStr;
                    getline(cin, quantityStr);
                    if (is_valid_number(quantityStr))
                    {
                        int quantity = stoi(quantityStr);
                        if (quantity > 0 && quantity <= MAX_QUANTITY)
                        {
                            product.quantity_product = quantity;
                        }
                        else
                        {
                            cerr << "Invalid quantity. Please enter a number between 1 and " << MAX_QUANTITY << ".\n";
                        }
                    }
                    else
                    {
                        cerr << "Invalid quantity. Please enter numeric characters only.\n";
                    }
                } while (product.quantity_product <= 0 || product.quantity_product > MAX_QUANTITY);
                to_upper_case(product.nameProduct);
                to_upper_case(product.catagory_product);
                update_product_in_list(id, product);
            }
            else if (choice == 3)
            {
                int id;
                cout << "Enter product ID to delete: ";
                cin >> id;
                cout << "Are you sure you want to delete this product? (y/n): ";
                char confirm;
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y')
                {
                    delete_product_from_list(id);
                    delete_product_from_file(id);
                    cout << "Product deleted successfully.\n";
                }
                else
                {
                    cout << "Product deletion canceled.\n";
                }
            }
            else if (choice == 4)
            {
                display_products();
            }
            else if (choice == 5)
            {
                store_all_products_to_file();
            }
            else if (choice == 6)
            {
                search_product();
            }
            else if (choice == 7)
            {
                cout << "Have you saved the products to the file yet? (y/n): ";
                char confirm;
                cin >> confirm;
                if (confirm == 'y' || confirm == 'Y')
                {
                    cout << "Successfully exited.\n";
                    break;
                }
                else
                {
                    cout << "Please save the products to the file before exiting.\n";
                }
            }
            else if(choice == 8)
            {
                back = false;
                break;
            }
            else
            {
                cout << "Invalid choice. Please try again.\n";
            }
        } while (back);
    }
    void generate_report()
    {
        int total_quantity = 0;
        float total_money = 0.0;
        node_product *temp = head;

        // Iterate through the list and calculate totals
        while (temp != nullptr)
        {
            total_quantity += temp->product.quantity_product;
            total_money += temp->product.priceProduct * temp->product.quantity_product;
            temp = temp->next;
        }

        // Display the report
        cout << "------ Product Report ------\n";
        cout << "Total Number of Products: " << total_quantity << "\n";
        cout << "Total Money (Value of All Products in Stock): " << total_money << " USD\n";
        cout << "----------------------------\n";
    }


};

class add_to_cart {
private:
    node_cart* head_cart;
    node_cart* tail;
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
        head_cart = nullptr;
        tail = nullptr;
        totalProduct = 0;
    }

    ~add_to_cart() {
        node_cart* current = head_cart;
        while (current != nullptr) {
            node_cart* next = current->next;
            delete current;
            current = next;
        }
    }
    // void add_to_cart_data_transfer(int id,int quantity){

    //     string name,type,date;
    //     date = getCurrentTime();
    //     int id;
    //     float price;
    //     //Node* ProductManager::head
    //     Node* temp = ProductManager::head;
    //         while (temp != nullptr)
    //         {
    //             if (temp->product.idPoduct == id)
    //             {
    //                 name =  temp->product.nameProduct;
    //                 type = temp->product.catagory_product;
    //                 id = temp->product.idPoduct;
    //                 price = temp->product.priceProduct;
    //                 temp->product.quantity_product = temp->product.quantity_product - quantity;
    //                 return add_product_to_cart(name, id, price, quantity, type, date);
    //                 return;
    //             }
    //             temp = temp->next;
    //         }
    //         cout << "Product with ID " << id << " not found.\n";
        
    // }

    void add_product_to_cart(string name_product, int id_product, float price_product, int amount_product, string type_product, string date) {
        node_cart* new_product = new node_cart;
        new_product->product.nameProduct = name_product;
        new_product->product.idPoduct = id_product;
        new_product->product.priceProduct = price_product;
        new_product->product.quantity_product = amount_product;
        new_product->product.catagory_product = type_product;
        new_product->product.date = date;
        new_product->next = nullptr;
        if (head_cart == nullptr) {
            head_cart = new_product;
            tail = new_product;
        } else {
            tail->next = new_product;
            tail = new_product;
        }
        totalProduct++;

    }
    void add_to_cart_data_transfer(ProductManager* p, int id, int quantity) {
        if (!p) {
            cout << "Error: ProductManager instance not available.\n";
            return;
        }

        node_product* temp = p->head; // Start at the head of the linked list
        Invoice* invoice = new Invoice;
        while (temp != nullptr) {
            if (temp->product.idPoduct == id) { // Match found
                if (temp->product.quantity_product >= quantity) { // Sufficient stock
                    string name = temp->product.nameProduct;
                    string type = temp->product.catagory_product;
                    float price = temp->product.priceProduct;

                    temp->product.quantity_product -= quantity; // Decrement the stock

                    string date = getCurrentTime(); // Get the current date
                    add_product_to_cart(name, id, price, quantity, type, date); // Add product to cart
                    invoice->product_add_to_invoice(name, id, price, quantity, type, date);
                    cout << "Product " << name << " added to cart.\n";
                    return; // Exit after adding to the cart
                } else {
                    cout << "Insufficient stock for Product ID " << id << ". Available: " 
                        << temp->product.quantity_product << "\n";
                    return;
                }
            }
            temp = temp->next; // Move to the next node
        }

        // If no product matches the ID
        cout << "Product with ID " << id << " not found.\n";
    }


    void save_cart_to_file() {
        ofstream file;
        file.open(FILE_CART);
        if (file.is_open()) {
            node_cart* temp = head_cart;
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
        node_cart* temp = head_cart;
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
        file.open(FILE_CART);
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
        if(head_cart == nullptr){
            cout << "Cart is empty\n";
            return;
        }
        node_cart* current = head_cart;
        node_cart* previous = nullptr;
        bool found = false;
        while(current != nullptr){
            if(current->product.idPoduct == product_id){
                found = true;
                name_remove = current->product.nameProduct;
                if(previous == nullptr){
                    head_cart = current->next;
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
        node_cart* current = head_cart;
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
            head_cart = nullptr;
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
        if (head_cart == nullptr) {
            cout << "Cart is empty\n";
            return;
        }
        node_cart* current = head_cart;
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
            current = current->next; // Move to the next node_cart
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