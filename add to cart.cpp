#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
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
    }
    void shoping_menu(){
        cout << "0. Exit\n";
        cout << "1. Add Product to cart\n";
        cout << "2. Remove Product from cart\n";
        cout << "3. Display Product in cart\n";
        cout << "4. edit Product in cart\n";
        cout << "5. Pay money\n";

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
    void add_product_to_cart(string name_product, int id_product, float price_product, int amount_product, string type_product) {
        Node* new_product;
        Node* newProduct = new Node;
        new_product->product.nameProduct = name_product;
        new_product->product.idPoduct = id_product;
        new_product->product.priceProduct = price_product;
        new_product->product.quantity_product = amount_product;
        new_product->product.catagory_product = type_product;
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

    void load_cart_file() {
        ifstream file;
        file.open(FILE_NAME);
        string name, category;
        int id, quantity;
        float price;
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                stringstream ss(line);
                getline(ss, name, ',');
                getline(ss, category, ',');
                ss >> id >> price >> quantity;
                // getline(ss, id, ',');
                // getline(ss, price, ',');
                // getline(ss, quantity, ',');
                cout << "Name: " << name << ", Category: " << category << ", ID: " << id
                     << ", Price: " << price << ", Quantity: " << quantity << "\n";
                add_product_to_cart(name, id, price, quantity, category);
            }
            file.close();
        } else {
            cerr << "Unable to open file for reading.\n";
        }
    }

    // void updateProductInFile(int id, const Product& updatedProduct) {
    //     ifstream file;
    //     file.open(FILE_NAME);
    //     ofstream tempFile;
    //     tempFile.open("temp.csv");
    //     string line;
    //     bool found = false;

    //     if (file.is_open() && tempFile.is_open()) {
    //         while (getline(file, line)) {
    //             stringstream ss(line);
    //             string name, category, idStr, price, quantity;
    //             getline(ss, name, ',');
    //             getline(ss, category, ',');
    //             getline(ss, idStr, ',');
    //             getline(ss, price, ',');
    //             getline(ss, quantity, ',');

    //             if (stoi(idStr) == id) {
    //                 tempFile << updatedProduct.nameProduct << ","
    //                          << updatedProduct.catagory_product << ","
    //                          << updatedProduct.idPoduct << ","
    //                          << updatedProduct.priceProduct << ","
    //                          << updatedProduct.quantity_product << "\n";
    //                 found = true;
    //             } else {
    //                 tempFile << line << "\n";
    //             }
    //         }
    //         file.close();
    //         tempFile.close();
    //         remove(FILE_NAME);
    //         rename("temp.csv", FILE_NAME);

    //         if (!found) {
    //             cerr << "Product with ID " << id << " not found in the file.\n";
    //         }
    //     } else {
    //         cerr << "Unable to open file for updating.\n";
    //     }
    // }

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

78





int main (){
    add_to_cart* cart = new add_to_cart;
    int choice;
    while (true)
    {
        cart->displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
            case 1:
            {   while(true){
                    int opt;
                    cart->shoping_menu();
                    cout << "Enter your choice: ";
                    cin >> opt;
                    switch (opt)
                    {
                        case 1:
                        {
                            string name, type;
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
                            cart->add_product_to_cart(name, id, price, amount, type);
                            break;
                        }
                        case 2:
                        {
                            cart->delete_product_in_cart();
                            break;
                        }
                        case 3:
                        {
                            cart->load_cart_file();
                            break;
                        }
                        case 4:
                        {
                            //cart->updateProductInFile(1, {"book", "study", 1, 100, 2});
                            break;
                        }
                        case 5:
                        {
                            cart->save_cart_to_file();
                            break;
                        }
                        case 0:
                        {
                            cout << "Exit successfully." << endl;
                            exit(0);
                        }
                        default:
                        {
                            cout << "Invalid choice." << endl;
                            break;
                        }
                    }

                }
                break;
            default:
            {
                cout << "Invalid choice." << endl;
                break;
            }
            }
        }
    }
    return 0;
}
