#pragma once
#include "Object.hpp"

#include <vector>

class Document:public Object {
protected:
    vector<string> linesOfText;

public:
    Document(const std::string& name, const std::string& location, const std::string& extension);

    void write_line(const std::string& line);

    std::string read_line();
    std::string read_line(const unsigned line);

    bool operator==(const Comparable* other)const override;
    bool operator!=(const Comparable* other)const override;
    string to_string()const override;
    void from_string(const string& givenString) override;
    string debug_print() const override;

    Document* clone() const override;

};