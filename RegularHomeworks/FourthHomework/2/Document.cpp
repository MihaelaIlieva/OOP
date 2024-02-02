#include "Document.hpp"

#include <stdexcept>
#include <sstream>

Document::Document(const std::string& name, const std::string& location, const std::string& extension):Object(name,location,extension)
{

}

void Document::write_line(const std::string& line)
{
    linesOfText.push_back(line);
}

int lineToBeRead=-1;

std::string Document::read_line()
{    
    lineToBeRead++;
    if (lineToBeRead<0|| lineToBeRead >=linesOfText.size()) { 
        throw std::out_of_range("");
    }
    else {
        return linesOfText[lineToBeRead];
    }
}

std::string Document::read_line(const unsigned line)
{
    lineToBeRead = line - 1;
    if (lineToBeRead < 0 || lineToBeRead >= linesOfText.size()) {
        throw std::out_of_range("");
    }
    else {
        return linesOfText[lineToBeRead];     
    }    
}

bool Document::operator==(const Comparable* other) const
{
    const Document* newOther = dynamic_cast<const Document*>(other);
    if (this->linesOfText.size() == newOther->linesOfText.size()) {
        for (size_t i = 0; i < this->linesOfText.size(); i++)
        {
            if (this->linesOfText[i].compare(newOther->linesOfText[i]) != 0) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Document::operator!=(const Comparable* other) const
{
    const Document* newOther = dynamic_cast<const Document*>(other);
    if (this->linesOfText.size() == newOther->linesOfText.size()) {
        for (size_t i = 0; i < this->linesOfText.size(); i++)
        {
            if (this->linesOfText[i].compare(newOther->linesOfText[i]) != 0) {
                return true;
            }
        }
        return false;
    }
    return true;
}

string Document::to_string() const
{
    string documentGiven = name + '\n';
    documentGiven += location + '\n';
    documentGiven += extension + '\n';
    for (size_t i = 0; i < this->linesOfText.size(); i++)
    {
        documentGiven += linesOfText[i] + '\n';
    }

    return documentGiven;
}

void Document::from_string(const string& givenString)
{

    std::stringstream ss(givenString);
    string line;
    if (givenString != "") {
        int lineIndex = 0;
        while (getline(ss, line, '\n')) {
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
                this->linesOfText.push_back(line);
            }
            lineIndex++;
        }
    }
}

string Document::debug_print() const
{
    int line = 1;
    string documentPrint = "";
    for (size_t i = 0; i < this->linesOfText.size(); i++)
    {
        documentPrint += "Line "+std::to_string(i + 1) + ":" + linesOfText[i] + "\n";
    }
    
    return documentPrint;
}

Document* Document::clone() const
{
    return new Document(*this);
}
