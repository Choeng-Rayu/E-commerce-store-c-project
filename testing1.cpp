class CustomerLogin
{
    public: 
    void lock_program()
    {
        string user_input_password;
        string user_name_input;
        string user_email_input;
        int found = 0;
        bool correct = false;
        //file_user.readFile_user_login();
        
        system("color c");
        for (int j = 0; j < 4; j++)
        {
            found ++;
            if ( found == 4)
            {
                cout << "Access denied. Program will terminate.\n";
                exit(1); // Terminates the program if password is incorrect three times
            }
            cout << "Please enter customer name: ";
        // cin >> user_name_input;
            cin.ignore();
            getline(cin, user_name_input);

            cout << "Please enter email: ";
            cin >> user_email_input;
            cout << "Please enter password: ";
            cin >> user_input_password;
            if ( user_name_input == customer.usernameCustomer  && user_input_password == customer.pwCustomer && user_email_input == customer.emailCustomer )
            {
                correct = true;
                system("cls");
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

    void reset_pw()
    {
        system ("color d");
        cout << "Enter new user name: ";
        cin.ignore();
        getline(cin, customer.usernameCustomer);
        cout << "Enter new email: ";
        cin >> customer.emailCustomer;
        cout << "Enter new password: ";
        cin.ignore();
        getline(cin, customer.pwCustomer);
        file_user.writeFile_user_login(customer.usernameCustomer, customer.emailCustomer, customer.pwCustomer);

    }

    void lock_reset_pw ()
    {
        int num;
        char login_choice;
        char letter;

        system ("color B");
        cout << "\n                   \t\t***************************************************************\n";
        cout << "                   \t\t************** Welcome to E-Commerce store *********************\n";
        cout << "                   \t\t***************************************************************\n\n";
        cout << " Press Enter to continue...";
        fflush (stdin);
        cin.ignore();
        system("cls");
        system ("color 3");
        cout << "Note" << endl;
        cout << "W. For Enter user name and password" << endl;
        cout << "F. For forget password" << endl;
        cout << "Please your choice: ";
        cin >> login_choice;

        system ("cls");
        switch ( login_choice )
        {
            //choice_convert = atoi (password_choice);
            case 'W':
            case 'w':
                lock_program();
                break;

            case 'F':
            case 'f':
                //int num;
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
            default:
                cout << "Invalid input" << endl;
                exit(1);
        }
    }

};
class SellerLogin
{
    public: 
    void lock_program()
    {
        string seller_input_password;
        string seller_name_input;
        string seller_email_input;
        int found = 0;
        bool correct = false;
        file_user.readFile_seller_login();
        system("color c");
        for (int j = 0; j < 4; j++)
        {
            found ++;
            if ( found == 4)
            {
                cout << "Access denied. Program will terminate.\n";
                exit(1); // Terminates the program if password is incorrect three times
            }
            cout << "Please enter seller name: ";
        // cin >> user_name_input;
            cin.ignore();
            getline(cin, seller_name_input);

            cout << "Please enter email: ";
            cin >> seller_email_input;
            cout << "Please enter password: ";
            cin >> seller_email_input;
            if ( seller_name_input == seller.usernameseller  && seller_input_password == seller.pwseller && seller_email_input == seller.emailseller )
            {
                correct = true;
                system("cls");
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

    void reset_pw()
    {
        system ("color d");
        cout << "Enter new user name: ";
        cin.ignore();
        getline(cin, seller.usernameseller);
        cout << "Enter new email: ";
        cin >> seller.emailseller;
        cout << "Enter new password: ";
        cin.ignore();
        getline(cin, seller.pwseller);
        file_user.writeFile_seller_login(seller.usernameseller, seller.emailseller, seller.pwseller);
        system("cls");

    }

    void lock_reset_pw ()
    {
        int num;
        char login_choice;
        char letter;

        system ("color B");
        cout << "\n                   \t\t***************************************************************\n";
        cout << "                   \t\t************** Welcome to E-Commerce store *********************\n";
        cout << "                   \t\t***************************************************************\n\n";
        cout << " Press Enter to continue...";
        fflush (stdin);
        cin.ignore();
        system("cls");
        system ("color 3");
        cout << "Note" << endl;
        cout << "W. For Enter user name and password" << endl;
        cout << "F. For forget password" << endl;
        cout << "Please your choice: ";
        cin >> login_choice;

        system ("cls");
        switch ( login_choice )
        {
            //choice_convert = atoi (password_choice);
            case 'W':
            case 'w':
                lock_program();
                break;

            case 'F':
            case 'f':
                //int num;
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
            default:
                cout << "Invalid input" << endl;
                exit(1);
        }
    }
    

};



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















void seller_customer_admin_asking()
    {
        char opt;
        cout << "please choose option(only one letter): " << endl;
        cout << "C. for Customer" << endl;
        cout << "S. for Seller" << endl;
        cout << "Enter your role: ";
        cin >> opt;
        switch (opt)
        {
        case 'c':
        case 'C': 
        system("cls");
            customer.lock_reset_pw();
            break;
        case 'S':
        case 's':
            seller.lock_reset_pw();
            break;
        default:
        cout << "invalid input" << endl;
            break;
        }
    }