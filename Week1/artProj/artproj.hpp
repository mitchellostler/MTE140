#include <iostream>

class Artwork {
    std::string name, title;
    unsigned int year_made;
    public:
    Artwork() : year_made(0) {}
    Artwork(std::string _name, std::string _title, unsigned int _year) :
        name(_name), title(_title), year_made(_year) {}
    bool operator==(const Artwork& art2) const {
        if(name == art2.name && title == art2.title &&
            year_made == art2.year_made) 
                return true;
        return false;
    }
};

class SoldArtwork : public Artwork {
    std::string cust_add, cust_name;
    double sale_amt;
    public:
    SoldArtwork() : sale_amt(0) {}
    SoldArtwork(std::string _add, std::string _name, double _amt) : 
        cust_add(_add), cust_name(_name), sale_amt(_amt) {} 

    bool operator==(const SoldArtwork& art2) const { //const use here ensures that no members are changed in this funtion (read only)
        if(cust_add==art2.cust_add && cust_name == art2.cust_name && 
        sale_amt==art2.sale_amt && static_cast<Artwork>(*this) == static_cast<Artwork>(art2)) 
                return true;
        return false;
    }

};