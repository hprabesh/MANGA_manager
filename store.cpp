#include "store.h"
#include <typeinfo>
#include <algorithm>
Store::Store(std::string name) : _name{name} { }
Store::Store(std::istream& ist){
    std::getline(ist, _name);
    int size;
    std::string s;
    
    ist >> size; ist.ignore(32767, '\n');
    while(size-- > 0) {
        std::getline(ist, s);
        if(s == "tool") _products.push_back(new Tool(ist));
        else if(s == "plant") _products.push_back(new Plant(ist));
        else if(s == "mulch") _products.push_back(new Mulch(ist));
        else if(s.size()) throw std::runtime_error{"Invalid product type on input: " + s};
    }
    
    ist >> size; ist.ignore(32767, '\n');
    while(size-- > 0) {
        _customers.push_back(new Customer(ist));
    }  
    ist >>size; ist.ignore(32767, '\n');
    while (size-->0){
        _orders.push_back(new Order(ist));
    }    
}
// (new Tool{name, price, description}));

void Store::save(std::ostream& ost){
    ost << _name << '\n';
    ost << _products.size() << '\n';
    for(Product* p : _products) p->save(ost);
    ost << _customers.size() << '\n';
    for(Customer* c : _customers) c->save(ost);
    ost<< _orders.size() <<'\n';
    for(Order* d: _orders) d->save(ost);
}

std::string Store::name(){
    return _name;
}


void Store::add_product(const Tool& product) {_products.push_back(new Tool{product});}
void Store::add_product(const Plant& product) {_products.push_back(new Plant{product});}
void Store::add_product(const Mulch& product) {_products.push_back(new Mulch{product});}
int Store::products() {return _products.size();}
Product& Store::product(int index) {return *_products.at(index);}




int Store::customers(){ return _customers.size();}
const Customer& Store::customer(int index){
    return *_customers.at(index);
}

int Store::add_order(const Customer& customer){
    _orders.push_back(new Order{customer});
    return _orders.size()-1;

}

void Store::add_item(int order_num, Product& product, int quantity){
    _orders[order_num]->add_item(Item{product,quantity});
}
void Store::add_customer(Customer customer){
    _customers.push_back(new Customer{customer});
    std::sort(_customers.begin(),_customers.end(),[](const Customer* lhs, const Customer* rhs){
        int i=0;
        int lstring = std::tolower(lhs->get_name().at(0));
        int rstring = std::tolower(rhs->get_name().at(0));
        while (lstring==rstring){
            i++;
            lstring = std::tolower(lhs->get_name().at(i));
            rstring = std::tolower(rhs->get_name().at(i));
        }
        return lstring < rstring;
    });
}


// const Order& Store::order(int index){
//     return *_orders.at(index);
// }

// int Store::orders() {
//     return _orders.size();
// }





    