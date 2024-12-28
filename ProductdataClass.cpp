#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

#define FILE_NAME "ProductdataClass.csv"
// PRODUCT 
struct Product
{
    string nameProduct;
    string catagory_product;
    int idPoduct;
    int priceProduct;
    int quantity_product;
};

struct Node {
    Product product;
    Node* next;
};

class ProductManager {
private:
    Node* head;
    Node* tail;

    void displayMenu() {
        cout << "1. Add Product\n";
        cout << "2. Update Product in File\n";
        cout << "3. Delete Product from File\n";
        cout << "4. Display Products from File\n";
        cout << "5. Store All Products to File\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
    }

public:
    ProductManager() : head(nullptr), tail(nullptr) {}

    ~ProductManager() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void addProductToList(const Product& product) {
        Node* newNode = new Node;
        newNode->product = product;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void storeAllProductsToFile() {
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

    void readProducts() {
        ifstream file;
        file.open(FILE_NAME);
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                stringstream ss(line);
                string name, category, id, price, quantity;
                getline(ss, name, ',');
                getline(ss, category, ',');
                getline(ss, id, ',');
                getline(ss, price, ',');
                getline(ss, quantity, ',');
                cout << "Name: " << name << ", Category: " << category << ", ID: " << id
                     << ", Price: " << price << ", Quantity: " << quantity << "\n";
            }
            file.close();
        } else {
            cerr << "Unable to open file for reading.\n";
        }
    }

    void updateProductInFile(int id, const Product& updatedProduct) {
        ifstream file;
        file.open(FILE_NAME);
        ofstream tempFile;
        tempFile.open("temp.csv");
        string line;
        bool found = false;

        if (file.is_open() && tempFile.is_open()) {
            while (getline(file, line)) {
                stringstream ss(line);
                string name, category, idStr, price, quantity;
                getline(ss, name, ',');
                getline(ss, category, ',');
                getline(ss, idStr, ',');
                getline(ss, price, ',');
                getline(ss, quantity, ',');

                if (stoi(idStr) == id) {
                    tempFile << updatedProduct.nameProduct << ","
                             << updatedProduct.catagory_product << ","
                             << updatedProduct.idPoduct << ","
                             << updatedProduct.priceProduct << ","
                             << updatedProduct.quantity_product << "\n";
                    found = true;
                } else {
                    tempFile << line << "\n";
                }
            }
            file.close();
            tempFile.close();
            remove(FILE_NAME);
            rename("temp.csv", FILE_NAME);

            if (!found) {
                cerr << "Product with ID " << id << " not found in the file.\n";
            }
        } else {
            cerr << "Unable to open file for updating.\n";
        }
    }

    void deleteProductFromFile(int id) {
        ifstream file;
        file.open(FILE_NAME);
        ofstream tempFile;
        tempFile.open("temp.csv");
        string line;
        bool found = false;

        if (file.is_open() && tempFile.is_open()) {
            while (getline(file, line)) {
                stringstream ss(line);
                string name, category, idStr, price, quantity;
                getline(ss, name, ',');
                getline(ss, category, ',');
                getline(ss, idStr, ',');
                getline(ss, price, ',');
                getline(ss, quantity, ',');

                if (stoi(idStr) != id) {
                    tempFile << line << "\n";
                } else {
                    found = true;
                }
            }
            file.close();
            tempFile.close();
            remove(FILE_NAME);
            rename("temp.csv", FILE_NAME);

            if (!found) {
                cerr << "Product with ID " << id << " not found in the file.\n";
            }
        } else {
            cerr << "Unable to open file for deleting.\n";
        }
    }

    void run() {
        int choice;
        do {
            displayMenu();
            cin >> choice;
            cin.ignore(); // to ignore the newline character after the choice input

            if (choice == 1) {
                Product product;
                cout << "Enter product name: ";
                getline(cin, product.nameProduct);
                cout << "Enter product category: ";
                getline(cin, product.catagory_product);
                cout << "Enter product ID: ";
                cin >> product.idPoduct;
                cout << "Enter product price: ";
                cin >> product.priceProduct;
                cout << "Enter product quantity: ";
                cin >> product.quantity_product;
                cin.ignore(); // to ignore the newline character after the quantity input
                addProductToList(product);
            } else if (choice == 2) {
                int id;
                Product product;
                cout << "Enter product ID to update: ";
                cin >> id;
                cin.ignore(); // to ignore the newline character after the ID input
                cout << "Enter new product name: ";
                getline(cin, product.nameProduct);
                cout << "Enter new product category: ";
                getline(cin, product.catagory_product);
                cout << "Enter new product ID: ";
                cin >> product.idPoduct;
                cout << "Enter new product price: ";
                cin >> product.priceProduct;
                cout << "Enter new product quantity: ";
                cin >> product.quantity_product;
                cin.ignore(); // to ignore the newline character after the quantity input
                updateProductInFile(id, product);
            } else if (choice == 3) {
                int id;
                cout << "Enter product ID to delete: ";
                cin >> id;
                deleteProductFromFile(id);
            } else if (choice == 4) {
                readProducts();
            } else if (choice == 5) {
                storeAllProductsToFile();
            } else if (choice == 6) {
                cout << "Exiting...\n";
            } else {
                cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 6);
    }
};

int main() {
    ProductManager manager;
    manager.run();
    return 0;
}
