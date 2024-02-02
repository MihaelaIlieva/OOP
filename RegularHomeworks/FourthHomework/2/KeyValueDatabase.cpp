#include "KeyValueDatabase.hpp"

#include <stdexcept>
#include <exception>
#include <sstream>

KeyValueDatabase::KeyValueDatabase(const std::string& name, const std::string& location, const std::string& extension):Object(name,location,extension)
{
}

void KeyValueDatabase::add_entry(const std::pair<std::string, int>& entry)
{
    for (size_t i = 0; i < database.size(); i++)
    {
        if (database[i].first == entry.first) {
          throw std::invalid_argument("");
        }
        
    }
    this->database.push_back(entry);  
}

int KeyValueDatabase::get_value(const std::string& key) const
{
    bool isThere = false;
    for (size_t i = 0; i < database.size(); i++)
    {
        if (database[i].first == key) {
            isThere = true;
            return database[i].second;
        }        
    }
    if (!isThere) {
       throw std::invalid_argument("");
    }
}

bool KeyValueDatabase::operator==(const Comparable* other) const
{
    const KeyValueDatabase* newOther = dynamic_cast<const KeyValueDatabase*>(other);
    if (this->database.size() == newOther->database.size()) {
        for (size_t i = 0; i < this->database.size(); i++)
        {
            if (this->database[i].first.compare(newOther->database[i].first) != 0 || this->database[i].second!= newOther->database[i].second) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool KeyValueDatabase::operator!=(const Comparable* other) const
{
    const KeyValueDatabase* newOther = dynamic_cast<const KeyValueDatabase*>(other);
    if (this->database.size() == newOther->database.size()) {
        for (size_t i = 0; i < this->database.size(); i++)
        {
            if (this->database[i].first.compare(newOther->database[i].first) != 0 || this->database[i].second != newOther->database[i].second) {
                return true;
            }
        }
        return false;
    }
    return true;
}

string KeyValueDatabase::to_string() const
{
    string databaseGiven = name + '\n';
    databaseGiven += location + '\n';
    databaseGiven += extension + '\n';
    for (size_t i = 0; i < this->database.size(); i++)
    {
        databaseGiven += database[i].first+":"+ std::to_string(database[i].second) + '\n';
    }

    return databaseGiven;
}

void KeyValueDatabase::from_string(const string& givenString)
{
    std::stringstream ss(givenString);

    std::string line;
    if (givenString != "") {
        int lineIndex = 0;
        while (std::getline(ss, line, '\n'))
        {
            if (lineIndex == 0)
            {
                this->name = line;
            }
            else if (lineIndex == 1)
            {
                this->location = line;
            }
            else if (lineIndex == 2)
            {
                this->extension = line;
            }
            else
            {
                std::string key = line.substr(0, line.find(":"));
                int value = std::stoi(line.substr(line.find_last_of(":")+1,'\n'));
                this->database.push_back(std::pair<std::string, int>(key, value));
            }
            lineIndex++;
        }
    }
}

string KeyValueDatabase::debug_print() const
{
    string databasePrint="";
    for (size_t i = 0; i < this->database.size(); i++)
    {
        databasePrint +="{"+ database[i].first + ":" + std::to_string(database[i].second)+"}" + "\n";
    }

    return databasePrint;
}

KeyValueDatabase* KeyValueDatabase::clone() const
{
    return new KeyValueDatabase(*this);
}
