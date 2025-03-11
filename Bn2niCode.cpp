#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

struct Grocery 
{
    string name;
    double price;
    string unit;
};

void Addtocart(queue<Grocery>& cart, const vector<pair<string, Grocery>>& groceries);
void RemoveItems(queue<Grocery>& cart);
void CheckCurrentItems(const queue<Grocery>& cart);
void PayCounter(queue<Grocery>& cart);

int main() 
{
    int choice;
    queue<Grocery> cart;
    
    vector<pair<string, Grocery>> groceries = {
        {"F1", {"Apples", 189, "6pcs"}},
        {"f1", {"Apples", 189, "6pcs"}},
        {"F2", {"Bananas", 75, "kg"}},
        {"f2", {"Bananas", 75, "kg"}},
        {"F3", {"Garlic", 220, "kg"}},
        {"f3", {"Garlic", 220, "kg"}},
        {"F4", {"Onion", 120, "kg"}},
        {"f4", {"Onion", 120, "kg"}},
        {"F5", {"Tomatoes", 120, "kg"}},
        {"f5", {"Tomatoes", 120, "kg"}},
        {"G1", {"Brown Rice", 555, "5kg"}},
        {"g1", {"Brown Rice", 555, "5kg"}},
        {"G2", {"White Rice", 744, "10kg"}},
        {"g2", {"White Rice", 744, "10kg"}},
        {"G3", {"Pasta", 112, "90g"}},
        {"g3", {"Pasta", 112, "90g"}},
        {"P1", {"Chicken", 598, "2kg"}},
        {"p1", {"Chicken", 598, "2kg"}},
        {"P2", {"Beef", 840, "2kg"}},
        {"p2", {"Beef", 840, "2kg"}},
        {"P3", {"Eggs", 132, "dozen"}},
        {"p3", {"Eggs", 132, "dozen"}},
        {"D1", {"Butter", 237, "230g"}},
        {"d1", {"Butter", 237, "230g"}},
        {"D2", {"Cheese", 160, "250g"}},
        {"d2", {"Cheese", 160, "250g"}},
        {"D3", {"Milk", 460, "1.5L"}},
        {"d3", {"Milk", 460, "1.5L"}},
        {"B1", {"Baking Powder", 199, "kg"}},
        {"b1", {"Baking Powder", 199, "kg"}},
        {"B2", {"Dry Yeast", 215, "500g"}},
        {"b2", {"Dry Yeast", 215, "500g"}},
        {"B3", {"All-Purpose Flour", 339, "2.2kg"}},
        {"b3", {"All-Purpose Flour", 339, "2.2kg"}},
        {"B4", {"Washed Sugar", 178, "2kg"}},
        {"b4", {"Washed Sugar", 178, "2kg"}},
        {"S1", {"Crackers", 185, "600g"}},
        {"s1", {"Crackers", 185, "600g"}},
        {"S2", {"Popcorn Kernels", 149, "908g"}},
        {"s2", {"Popcorn Kernels", 149, "908g"}},
        {"S3", {"Tortilla Chips", 199, "454g"}},
        {"s3", {"Tortilla Chips", 199, "454g"}},
        {"S4", {"Cereal", 696, "1.36kg"}},
        {"s4", {"Cereal", 696, "1.36kg"}},
        {"C1", {"Black Pepper", 815, "530g"}},
        {"c1", {"Black Pepper", 815, "530g"}},
        {"C2", {"Vinegar", 399, "1.9L"}},
        {"c2", {"Vinegar", 399, "1.9L"}},
        {"C3", {"Ketchup", 675, "3.2kg"}},
        {"c3", {"Ketchup", 675, "3.2kg"}},
        {"C4", {"Mustard", 199, "250g"}},
        {"c4", {"Mustard", 199, "250g"}},
        {"C5", {"Salt", 199, "250g"}},
        {"c5", {"Salt", 199, "250g"}},
        {"C6", {"Soy Sauce", 218, "1L"}},
        {"c6", {"Soy Sauce", 218, "1L"}},
        {"O1", {"Coconut Oil", 395, "2L"}},
        {"o1", {"Coconut Oil", 395, "2L"}},
        {"O2", {"Olive Oil", 2699, "3L"}},
        {"o2", {"Olive Oil", 2699, "3L"}},
        {"O3", {"Vegetable Oil", 1205, "4.7L"}},
        {"o3", {"Vegetable Oil", 1205, "4.7L"}},
        {"CD1", {"Canned Tuna", 596, "1.7kg"}},
        {"cd1", {"Canned Tuna", 596, "1.7kg"}},
        {"CD2", {"Strawberry Jam", 329, "907g"}},
        {"cd2", {"Strawberry Jam", 329, "907g"}},
        {"CD3", {"Pasta Sauce", 244, "907g"}},
        {"cd3", {"Pasta Sauce", 244, "907g"}},
        {"CD4", {"Peanut Butter", 498, "1.3kg"}},
        {"cd4", {"Peanut Butter", 498, "1.3kg"}}
    };

    while (true)
    {
        cout << ".----------------. .-----------------..----------------. .-----------------..----------------.\n";
        cout << "| .--------------. | .--------------. | .--------------. | .--------------. | .--------------. |\n";
        cout << "| |   ______     | | | ____  _____  | | |    _____     | | | ____  _____  | | |     _____    | |\n";
        cout << "| |  |_   _ \\    | | ||_   \\|_   _| | | |   / ___ `.   | | ||_   \\|_   _| | | |    |_   _|   | |\n";
        cout << "| |    | |_) |   | | |  |   \\ | |   | | |  |_/___) |   | | |  |   \\ | |   | | |      | |     | |\n";
        cout << "| |    |  __'.   | | |  | |\\ \\| |   | | |   .'____.'   | | |  | |\\ \\| |   | | |      | |     | |\n";
        cout << "| |   _| |__) |  | | | _| |_\\   |_  | | |  / /____     | | | _| |_\\   |_  | | |     _| |_    | |\n";
        cout << "| |  |_______/   | | ||_____||____| | | |  |_______|   | | ||_____||____| | | |    |_____|   | |\n";
        cout << "| |              | | |              | | |              | | |              | | |              | |\n";
        cout << "| '--------------' | '--------------' | '--------------' | '--------------' | '--------------' |\n";
        cout << " '----------------' '----------------' '----------------' '----------------' '----------------' \n";

        cout << "\t\t\t   __________  ____  __________________  __\n";
        cout << "\t\t\t  / ____/ __ \\/ __ \\/ ____/ ____/ __ \\ \\/ /\n";
        cout << "\t\t\t / / __/ /_/ / / / / /   / __/ / /_/ /\\  / \n";
        cout << "\t\t\t/ /_/ / _, _/ /_/ / /___/ /___/ _, _/ / /  \n";
        cout << "\t\t\t\\____/_/ |_|\\____/\\____/_____/_/ |_| /_/   \n";

        cout << "================================================================================================\n";
        cout << "\t\t\t\t\tGROCERY STORE\n";
        cout << "================================================================================================\n";
        cout << "\t\t\t\t[1] ADD ITEMS TO YOUR CART\n\t\t\t\t[2] REMOVE ITEMS FROM YOUR CART\n\t\t\t\t[3] CHECK CURRENT ITEMS AND TOTAL COST\n\t\t\t\t[4] PAY AT THE COUNTER\n\t\t\t\t[5] EXIT GROCERY STORE\n";
        cout << "================================================================================================\n";

        cout << endl;
		cout << "\t\t\t\t    ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Addtocart(cart, groceries);
            break;

        case 2:
            RemoveItems(cart);
            break;

        case 3:
            CheckCurrentItems(cart);
            break;

        case 4:
            PayCounter(cart);
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice. Exiting..." << endl;
            return 0;
        }
    }
}

void Addtocart(queue<Grocery>& cart, const vector<pair<string, Grocery>>& groceries)
{
    int choice;

    system("cls");
    cout << ".----------------. .-----------------..----------------. .-----------------..----------------.\n";
    cout << "| .--------------. | .--------------. | .--------------. | .--------------. | .--------------. |\n";
    cout << "| |   ______     | | | ____  _____  | | |    _____     | | | ____  _____  | | |     _____    | |\n";
    cout << "| |  |_   _ \\    | | ||_   \\|_   _| | | |   / ___ `.   | | ||_   \\|_   _| | | |    |_   _|   | |\n";
    cout << "| |    | |_) |   | | |  |   \\ | |   | | |  |_/___) |   | | |  |   \\ | |   | | |      | |     | |\n";
    cout << "| |    |  __'.   | | |  | |\\ \\| |   | | |   .'____.'   | | |  | |\\ \\| |   | | |      | |     | |\n";
    cout << "| |   _| |__) |  | | | _| |_\\   |_  | | |  / /____     | | | _| |_\\   |_  | | |     _| |_    | |\n";
    cout << "| |  |_______/   | | ||_____||____| | | |  |_______|   | | ||_____||____| | | |    |_____|   | |\n";
    cout << "| |              | | |              | | |              | | |              | | |              | |\n";
    cout << "| '--------------' | '--------------' | '--------------' | '--------------' | '--------------' |\n";
    cout << " '----------------' '----------------' '----------------' '----------------' '----------------' \n";

    cout << "\t\t\t   __________  ____  __________________  __\n";
    cout << "\t\t\t  / ____/ __ \\/ __ \\/ ____/ ____/ __ \\ \\/ /\n";
    cout << "\t\t\t / / __/ /_/ / / / / /   / __/ / /_/ /\\  / \n";
    cout << "\t\t\t/ /_/ / _, _/ /_/ / /___/ /___/ _, _/ / /  \n";
    cout << "\t\t\t\\____/_/ |_|\\____/\\____/_____/_/ |_| /_/   \n";

    cout << endl;
    cout << endl;
    cout << "====================================================================================================================" << endl;
    cout << "| GROCERY LIST                                                                                                     |" << endl;
    cout << "|==================================================================================================================|" << endl;
    cout << "| FRESH                            |   GRAINS                             |   PROTEIN                              |" << endl;
    cout << "| F1. Apples   ( P189/6pcs )       |   G1. Brown Rice ( P555/5kg )        |   P1. Chicken ( P598/2kg )             |" << endl;
    cout << "| F2. Bananas  ( P75/kg )          |   G2. WHite Rice ( P744/10kg )       |   P2. Beef    ( P840/2kg )             |" << endl;
    cout << "| F3. Garlic   ( P220/kg)          |   G3. Pasta      ( P112/90g )        |   P3. Eggs    ( P132/dozen )           |" << endl;
    cout << "| F4. Onion    ( P120/kg )         |                                      |                                        |" << endl;
    cout << "| F5. Tomatoes ( P120/kg )         |                                      |                                        |" << endl;
    cout << "|----------------------------------|--------------------------------------|----------------------------------------|" << endl;
    cout << "| DAIRY                            |   SNACKS                             |   BAKING GOODS                         |" << endl;
    cout << "| D1. Butter ( P237/230g )         |   S1. Crackers ( P185/600g )         |   B1. Baking Powder     ( P199/kg )    |" << endl;
    cout << "| D2. Cheese ( P160/250g )         |   S2. Popcorn Kernels ( P149/908g )  |   B2. Dry Yeast         ( P215/500g )  |" << endl;
    cout << "| D3. Milk   ( P460/1.5L )         |   S3. Tortilla Chips ( P199/454g )   |   B3. All-Purpose Flour ( P339/2.2kg ) |" << endl;
    cout << "|                                  |   S4. Cereal ( P696/1.36kg)          |   B4. Washed Sugar      ( P178/2kg )   |" << endl;
    cout << "|----------------------------------|--------------------------------------|----------------------------------------|" << endl;
    cout << "| CONDIMENTS/SAUCES                |   OILS                               |   CANNED/DRIED GOODS                   |" << endl;
    cout << "| C1. Black Pepper ( P815/530g )   |   O1. Coconut Oil   ( P395/2L )      |   CD1. Canned Tuna    ( P596/1.7kg )   |" << endl;
    cout << "| C2. Vinegar      ( P399/1.9L )   |   O2. Olive Oil     ( P2699/3L )     |   CD2. Strawberry Jam ( P329/907g )    |" << endl;
    cout << "| C3. Ketchup      ( P675/3.2kg )  |   O3. Vegetable Oil ( P1205/4.7L )   |   CD3. Pasta Sauce    ( P244/907g )    |" << endl; 
    cout << "| C4. Mustard      ( P199/250g )   |                                      |   CD4. Peanut Butter  ( P498/1.3kg )   |" << endl; 
    cout << "| C5. Salt         ( P199/250g )   |                                      |                                        |" << endl; 
    cout << "| C6. Soy Sauce    ( P218/L )      |                                      |                                        |" << endl; 
    cout << "====================================================================================================================" << endl;
    cout << "Enter the LABEL of the items you want to add to your cart (separated by spaces): ";

    vector<string> labels;
    string inputLabel;

    while (cin >> inputLabel) 
    {
        labels.push_back(inputLabel);
        if (cin.peek() == '\n') break;
    }

    for (const auto& label : labels) 
    {
        bool found = false;
        for (const auto& item : groceries) 
        {
            if (item.first == label) 
            {
                cart.push(item.second);
                found = true;
                break;
            }
        }
        if (!found) 
        {
            cout << "Item with label " << label << " not found.\n";
        }
    }

    if (!cart.empty()) 
    {
        cout << "\nItems in your cart are:\n";
        cout << endl;
        queue<Grocery> tempCart = cart; 
        while (!tempCart.empty()) 
        {
            Grocery item = tempCart.front();
            cout << item.name << " (" << item.price << "/" << item.unit << ")\n";
            tempCart.pop();
        }
    } 
    else 
    {
        cout << "\nYour cart is empty.\n";
    }

    system("pause");
    system("cls");
}

void RemoveItems(queue<Grocery>& cart)
{
    if (cart.empty()) 
    {
        cout << "Your cart is empty. Nothing to remove.\n";
        return;
    }

    queue<Grocery> tempCart = cart;

    cout << "Items in your cart:\n";
    cout << endl;
    int itemNumber = 1;

    while (!tempCart.empty()) 
    {
        Grocery item = tempCart.front();
        cout << itemNumber << ". " << item.name << " (" << item.price << "/" << item.unit << ")\n";
        tempCart.pop();
        itemNumber++;
    }

    int choice;
    cout << "Enter the number of the item you want to remove: ";
    cin >> choice;

    if (choice <= 0 || choice > itemNumber - 1) 
    {
        cout << "Invalid choice. No item removed.\n";
        return;
    }

    tempCart = cart;
    cart = queue<Grocery>(); 

    itemNumber = 1;
    while (!tempCart.empty()) 
    {
        Grocery item = tempCart.front();
        tempCart.pop();

        if (itemNumber != choice) 
        {
            cart.push(item); 
        }

        itemNumber++;
    }

    cout << "Item removed from cart.\n";
    
    system("pause");
    system("cls");
}

void CheckCurrentItems(const queue<Grocery>& cart)
{
    double totalcost = 0.0;
        queue<Grocery> tempCart = cart;

    cout << "Items in your cart:\n";
    cout << endl;
    int itemNumber = 1;

    while (!tempCart.empty()) 
    {
        Grocery item = tempCart.front();
        cout << itemNumber << ". " << item.name << " (" << item.price << "/" << item.unit << ")\n";
        tempCart.pop();
        itemNumber++;
        totalcost += item.price;
    }
    
    cout << "-------------------------\n";
    cout << "Total cost: P" << totalcost << endl;
    
    system("pause");
    system("cls");
}

void PayCounter(queue<Grocery>& cart)
{
	if (cart.empty())
	{
		cout << "Your cart is empty, nothing to pay for. \n";
		return;
		}	
	
	double totalcost = 0.0;
        cout << "\nItems in your cart are:\n";
        cout << endl;
        queue<Grocery> tempCart = cart; 
        while (!tempCart.empty()) 
        {
            Grocery item = tempCart.front();
            cout << item.name << " (" << item.price << "/" << item.unit << ")\n";
            tempCart.pop();
            totalcost += item.price;
        }
        
        cout << "-------------------------\n";
    	cout << "Total cost: P" << totalcost << endl;\
    	
    	char confirm;
    	cout << endl;
    	cout << "Do you wish to proceed for payment? (Y | N)";
    	cin >> confirm;
    	
    	if (confirm == 'y' || confirm == 'Y')
    	{
    		srand(time(0));
    		int orderNumber = rand() % 10000 + 1;
    		cout << endl;
    		cout << "Order confirmed. Please present order number " << orderNumber << " and pay at the counter. Arigato!" << endl;
    		cout << endl;
    		
    			while(!cart.empty())
			{
				cart.pop();
			}
		}
		else
		{
			cout << "Payment canceled. Returning to main menu. \n";
		}
		
		system("pause");
		system("cls");
}

