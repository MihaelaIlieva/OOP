#pragma once
#include "Object.hpp"

#include <vector>

class KeyValueDatabase:public Object {
protected:
    vector<pair<string, int>> database;
public:
    KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension);

    void add_entry(const std::pair<std::string, int>& entry);
    int get_value(const std::string& key) const;
    bool operator==(const Comparable* other) const override;
    bool operator!=(const Comparable* other) const override;
    string to_string()const override;
    void from_string(const string& givenString) override;
    string debug_print() const override;

    KeyValueDatabase* clone() const override;

};