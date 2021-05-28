#include "mulch.h"

Mulch::Mulch(std::string name, double price, std::string description, int volume, Material material)
    : Product(name, price, description), _volume{volume}, _material{material} { }
std::string Mulch::to_string() const {
    return Product::to_string() + "\n  Volume: " + std::to_string(_volume) + " ft³\n  Material: " + ::to_string(_material);
}
std::ostream& operator<<(std::ostream& ost, const Material& material) {
    ost << to_string(material);
    return ost;
}
Mulch::Mulch(std::istream& ist):Product{ist}{
    std::string material_string;
    ist>>_volume;
    ist.ignore(3276,'\n');
    std::getline(ist,material_string);
    if (material_string==("rubber")){
        _material=Material::RUBBER;
    } else if (material_string==("pine")){
        _material=Material::PINE;
    } else if (material_string==("cedar")){
        _material=Material::CEDAR;
    } else {
        _material=Material::HARDWOOD;
    } 
}

void Mulch::save(std::ostream& ost) {
    ost<<"mulch"<<'\n';
    Product::save(ost);
    ost<<_volume<<'\n'<<::to_string(_material)<<'\n'<<std::endl;
}
std::string to_string(Material material) {
    if(material == Material::RUBBER) return "rubber";
    else if(material == Material::PINE) return "pine";
    else if(material == Material::CEDAR) return "cedar";
    else if(material == Material::HARDWOOD) return "hardwood";
    else throw std::out_of_range("Invalid Material value");
}
