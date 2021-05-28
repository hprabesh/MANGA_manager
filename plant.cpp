#include "plant.h"

Plant::Plant(std::string name, double price, std::string description, std::string species, Exposure exposure)
    : Product(name, price, description), _species{species}, _exposure{exposure} { }
std::string Plant::to_string() const {
    return Product::to_string() + "\n  Species: " + _species + "\n  Exposure: " + ::to_string(_exposure);
}
std::ostream& operator<<(std::ostream& ost, const Exposure& exposure) {
    ost << to_string(exposure);
    return ost;
}
std::string to_string(Exposure exposure) {
    if(exposure == Exposure::SHADE) return "shade";
    else if(exposure == Exposure::PARTSUN) return "part sun";
    else if(exposure == Exposure::SUN) return "full sun";
    else throw std::out_of_range("Invalid Exposure value");
}

Plant::Plant(std::istream& ist):Product{ist}{
    std::string exposure_string;
    std::getline(ist,_species);
    std::getline(ist,exposure_string);
    // ist.ignore(32767,'\n');
    
    // ist>>_species>>exposure_string;
    if (exposure_string.compare("shade")){
        _exposure=Exposure::SHADE;
    } else if (exposure_string.compare("part sun")){
        _exposure=Exposure::PARTSUN;
    } else if (exposure_string.compare("full sun")){
        _exposure=Exposure::SUN;
    } else {
        throw std::out_of_range("Invalid Exposure value");
    }
}

void Plant::save(std::ostream& ost) {
    ost<<"plant"<<'\n';
    Product::save(ost);
    ost<<_species<<'\n'<<_exposure<<std::endl;
}
