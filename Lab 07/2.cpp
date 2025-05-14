#include <iostream>
#include <string>
using namespace std;

class Product{
protected:
    int productID;
    string productName;
    double price;
    int stockQuantity;

public:
    Product(int id,string name,double p,int stock =0)
        :productID(id),productName(name),price(p), stockQuantity(stock) {}

    virtual void applyDiscount(){}

    virtual double calculateTotalPrice(int quantity){
        return price * quantity;
    }

    virtual void displayProductInfo() const {
        cout <<"ID: " << productID << ", Name: " << productName << ", Price: $" << price
             <<", Stock: "<<stockQuantity<<endl;
    }

    double getPrice() const{return price;}

    friend ostream& operator<<(ostream& out,const Product& p){
        p.displayProductInfo();
        return out;
    }

    Product operator+(const Product& other) {
        double totalPrice = this->price + other.price;
        return Product(0, "CombinedProduct", totalPrice);
    }
};

class Electronics : public Product {
    int warrantyPeriod;
    string brand;

public:
    Electronics(int id, string name, double p, int stock, int warranty, string br)
        : Product(id, name, p, stock), warrantyPeriod(warranty), brand(br) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Brand: " << brand << ", Warranty: " << warrantyPeriod << " months" << endl;
    }
};

class Clothing : public Product {
    string size, color, fabricMaterial;

public:
    Clothing(int id, string name, double p, int stock, string sz, string clr, string fabric)
        : Product(id, name, p, stock), size(sz), color(clr), fabricMaterial(fabric) {}

    void applyDiscount() override {
        price *= 0.9;
    }

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Size: " << size << ", Color: " << color << ", Material: " << fabricMaterial << endl;
    }
};

class FoodItem : public Product {
    string expirationDate;
    int calories;

public:
    FoodItem(int id, string name, double p, int stock, string exp, int cal)
        : Product(id, name, p, stock), expirationDate(exp), calories(cal) {}

    double calculateTotalPrice(int quantity) override {
        if (quantity > 10)
            return price * quantity * 0.85;
        return price * quantity;
    }

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Expires: " << expirationDate << ", Calories: " << calories << endl;
    }
};

class Book : public Product {
    string author, genre;

public:
    Book(int id, string name, double p, int stock, string auth, string gen)
        : Product(id, name, p, stock), author(auth), genre(gen) {}

    void displayProductInfo() const override {
        Product::displayProductInfo();
        cout << "Author: " << author << ", Genre: " << genre << endl;
    }
};

int main() {
    Electronics laptop(1, "Laptop", 1200.0, 5, 24, "Dell");
    Clothing shirt(2, "T-Shirt", 25.0, 50, "L", "Red", "Cotton");
    FoodItem rice(3, "Rice Bag", 40.0, 100, "2025-12-01", 1500);
    Book novel(4, "Novel", 15.0, 20, "Author Name", "Fiction");

    laptop.displayProductInfo();
    shirt.applyDiscount();
    shirt.displayProductInfo();
    cout << "Total Price (bulk): $" << rice.calculateTotalPrice(12) << endl;
    rice.displayProductInfo();
    novel.displayProductInfo();

    Product bundle = shirt + rice;
    cout << bundle;

    return 0;
}
