#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

class customer_account {
private:
    struct Node {
        struct Customer {
            string name_customer;
            string email_customer;
            string phone_customer;
            string password_customer;
            int id_customer;
            int money_customer;
        } customer;
        Node* next;
    };

    Node* head;
    Node* tail;
    int total_customer;

public:
    customer_account() : total_customer(0), head(nullptr), tail(nullptr) {}

    ~customer_account() {
        Node* current = head;
        while (current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
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
        } else {
            tail->next = newCustomer;
            tail = newCustomer;
        }
        total_customer++;
    }

    void display_all_customers() {
        if (head == nullptr) {
            cout << "No customers available." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            display_customer_details(current);
            current = current->next;
        }
    }

    void display_customer_details(Node* current) {
        cout << "Name: " << current->customer.name_customer << ","
             << "ID: " << current->customer.id_customer << ","	
             << "Email: " << current->customer.email_customer << ","
             << "Phone: " << current->customer.phone_customer << ","
             << "Money: " << current->customer.money_customer << ","
             << "Password: " << current->customer.password_customer << endl;
    }

    void delete_customer_position(int position) {
        if (position < 1 || position > total_customer) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        if (position == 1) {
            head = current->next;
            delete current;
        } else {
            for (int i = 1; i < position; i++) {
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
            if (current == tail) tail = previous;
            delete current;
        }

        total_customer--;
        cout << "Customer at position " << position << " deleted successfully." << endl;
    }

    void save_data_to_file(const string& filename) {
        ofstream file(filename);
        if (!file) {
            cout << "Error opening file!" << endl;
            return;
        }

        file << "Name,Email,Phone,Password,ID,Money" << endl;
        Node* current = head;
        while (current != nullptr) {
            file << current->customer.name_customer << ","
                 << current->customer.email_customer << ","
                 << current->customer.phone_customer << ","
                 << current->customer.password_customer << ","
                 << current->customer.id_customer << ","
                 << current->customer.money_customer << endl;
            current = current->next;
        }
        cout << "Customer data saved successfully to " << endl;
    }
};

int main() {
    customer_account ca;

    ca.insert_customer("Alice", "alice@gmail.com", "123456789", "pass123", 1, 1000);
    ca.insert_customer("Bob", "bob@gmail.com", "987654321", "pass456", 2, 2000);

    cout << "All Customers:" << endl;
    ca.display_all_customers();

    ca.delete_customer_position(1);
    cout << "\nAfter Deletion:" << endl;
    ca.display_all_customers();

    ca.save_data_to_file("customers.txt");

    return 0;
}
