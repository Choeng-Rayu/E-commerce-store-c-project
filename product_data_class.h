#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

#define FILE_PRODUCT_DATA "ProductdataClass.csv"
#define MAX_QUANTITY 1000000 // Define a maximum quantity limit
// PRODUCT
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
    void generate_report()
    {
        // Check if there are any products
        if (!head)
        {
            cout << "No products available in the inventory.\n";
            return;
        }

        // Generate the report heading
        cout << "Product Inventory Report\n";
        cout << "---------------------------------------------------------\n";
        cout << "ID   | Name                       | Category     | Price   | Quantity\n";
        cout << "---------------------------------------------------------\n";

        // Loop through the linked list to display each product
        node_product *temp = head;
        while (temp != nullptr)
        {
            cout << temp->product.idPoduct << "   | "
                << temp->product.nameProduct << "   | "
                << temp->product.catagory_product << "   | $"
                << temp->product.priceProduct << "   | "
                << temp->product.quantity_product << "\n";
            temp = temp->next;
        }

        cout << "---------------------------------------------------------\n";
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
};
