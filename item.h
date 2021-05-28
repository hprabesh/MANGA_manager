#ifndef __ITEM_H
#define __ITEM_H
#include "tool.h"
#include "mulch.h"
#include "product.h"
#include "plant.h"
#include <fstream>
class Item{
    private:
        Product* _product;
        int _quantity;
    public:
        double subtotal();
        Item(Product& product, int quantity);
        Item(std::istream& ist);
        void save(std::ostream& ost); 
        int quantity();
        friend std::ostream& operator<<(std::ostream& ost, const Item& item);
};
#endif