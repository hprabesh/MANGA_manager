#include "item.h"
Item::Item(Product& product, int quantity):_product{&product}, _quantity{quantity}{};

Item::Item(std::istream& ist){
    if (ist.good()){
        ist>>_quantity;
        ist.ignore(32768,'\n');
    }
    if (ist.good()){
        std::string line;
        getline(ist,line,'\n');
        if (line=="tool"){
            _product = new Tool{ist};
        } else if (line=="plant"){
            _product = new Plant{ist};
        } else if (line =="mulch") {
            _product=new Mulch{ist};
        } else{}
    }
}

void Item::save(std::ostream& ost){
    ost<<_quantity<<std::endl;
    _product->save(ost);

}

double Item::subtotal(){
    int price = _product->price() * _quantity;
    return price;
}

int Item::quantity(){
    return _quantity;
}

std::ostream& operator<<(std::ostream& ost, const Item& item){

    ost<<item._quantity<<' '<<*item._product;
    return ost;
}


