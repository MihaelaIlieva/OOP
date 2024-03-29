#pragma once
#include "Comparable.hpp"
#include "Debug.hpp"
#include "Serializable.hpp"

#include <string>

using namespace std;

class Object:public Comparable,public Debug, public Serializable {
protected:
    string name;
    string location;
    string extension;
public:

    Object(const std::string& name, const std::string& location, const std::string& extension);

    std::string get_name() const;
    std::string get_location() const;
    std::string get_extension() const;
    std::string get_fullpath() const;

    virtual Object* clone() const=0;

    virtual bool operator==(const Comparable* other) const override;
    virtual bool operator!=(const Comparable* other) const override;
    
};