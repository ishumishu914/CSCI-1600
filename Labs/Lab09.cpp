#include <iostream>
#include <string>
using namespace std;

class Bakery
{
    // private member variables
    private:
        string dessertType;
        string pastryName;
        int quantity;
        int price;
        bool soldOut;

    // public member variables & functions
    public:
        Bakery(); // constructor 1
        Bakery(string dT, string pN, int q, int p, bool s); // constructor 2
        ~Bakery(); // destructor
        string toString(); 
        bool available();
        friend bool operator==(Bakery left, Bakery right); // overload function

        // mutator functions
        void setDessertType(string dT)
        {
            dessertType = dT;
        };
        void setPastryName(string pN)
        {
            pastryName = pN;
        };
        bool setQuantity(int q);
        void setPrice(int p)
        {
            price = p;
        };    
        void setSoldOut(int s)
        {
            soldOut = s;
        };

        //accessor functions
        string getDessertType()
        {
            return dessertType;
        };
        string getPastryName()
        {
            return pastryName;
        };
        int getQuantity();
        int getPrice()
        {
            return price;
        };
};

Bakery::Bakery() // constructor
{
    // default state of each variables
    dessertType = "";
    pastryName ="";
    quantity = 5;
    price = 2;
    soldOut = false;
}

Bakery::Bakery(string dT, string pN, int q, int p, bool s) // constructor
{
    dessertType = dT;
    pastryName = pN;
    quantity = q;
    price = p;
    soldOut = s;
}

Bakery::~Bakery()
{
    cout << "Destructor called!" << endl; // delete dynamic arrays and print this sentence
}

bool Bakery::available() // checks if desired dessert item is available in stock or not
{
    if (soldOut == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Bakery::setQuantity(int q) // checks if the quantity of dessert item is present
{
    if (q < 0)
    {
        return false;
    }
    else
    {
        quantity = q;
        return true;
    }
}

int Bakery::getQuantity() // gets the quantity of pastry
{
    return quantity;
}

string Bakery::toString() // function to print output of program
{
    string sentence = "";

    if(available())
    {
        sentence += to_string(quantity) + " of [" + dessertType + "]: " + pastryName + " of unit price $" + to_string(price) + " is ";
    }
    else
    {
        sentence += to_string(quantity) + " of [" + dessertType + "]: " + pastryName + " of unit price $" + to_string(price) + " is ";
    }

    if (soldOut)
    {
        sentence += "available.\n";
    }
    else
    {
        sentence += "unavailable.\n";
    }

    return sentence;  
}

bool operator==(Bakery left, Bakery right) // compares the price & quantity of 2 pastries
{
    return ((left.price == right.price) && (left.quantity == right.quantity));
}

int main()
{
    // create dynamic Bakery variables p1 & p2
    Bakery *p1 = new Bakery();
    p1->setDessertType("Choux Pastry");
    p1->setPastryName("Cream Puff");
    p1->setSoldOut(false);
    cout << p1->toString();

    Bakery *p2 = new Bakery("Sponge Cake", "Opera Cake", 2 , 3, true);
    cout << p2->toString();

    // comparison check & output
    if (*p1 == *p2) 
    {
        cout << p1->getPastryName() << " and " << p2->getPastryName() << " have the same unit price and quantity." << endl;
    } 
    else 
    {
        cout << p1->getPastryName() << " and " << p2->getPastryName() << " don't have the same unit price and quantity." << endl;
    }

    delete p1;
    delete p2;

    return 0;
}