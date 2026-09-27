#include <iostream>

using namespace std;

class Product {
public:
    int id;
    string name;
    double price;
public:
    Product(int id, string name, double price) {
        this->id = id;
        this->name = name;
        this->price = price;
    }

};

class Node {
public:
    Product data;
public:
    Node(Product data) : data(data), next(nullptr) {}

    Node *next;
};

class LinkedList {
public:
    Node *head;

    LinkedList() : head(nullptr) {}

    void insert(Product data) {
        Node *newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    ~LinkedList(){
        Node *cur = head;
        while(cur!= nullptr){
            Node *next = cur->next;
            delete cur;
            cur = next;
        }
    }
};

class Shoppingcart {
public:
    LinkedList products;
public:
    void addProduct(Product product) {
        products.insert(product);
    }

    Shoppingcart& operator=(Shoppingcart &other) {
        LinkedList thisCart = this->products;
        LinkedList otherCart = other.products;
        Node *cur = otherCart.head;
        while (cur != nullptr) {
            int id = cur->data.id;
            string name = cur->data.name;
            double price = cur->data.price;
            Product newProd{id, name, price};
            thisCart.insert(newProd);
            cur = cur->next;
        }
        this->products = thisCart;
        return *this;
    }


};

ostream& operator<< (ostream& out, Shoppingcart& cart){

    Node *cur = cart.products.head;
    while(cur!= nullptr){
        Product data = cur->data;
        out << data.id <<" "<<data.name<<" "<<data.price<<endl;
        cur = cur->next;
    }
    return out;
}


int main() {

    Shoppingcart chris;
    chris.addProduct(Product(1, "Apple", 1.99));
    chris.addProduct(Product(2, "Orange", 2.99));
    chris.addProduct(Product(3, "Banana", 3.99));
    //print the products in the chris

    cout <<chris;




    return 0;

}