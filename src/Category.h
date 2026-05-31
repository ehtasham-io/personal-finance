#ifndef CATEGORY_H
#define CATEGORY_H
#include <string>

class Category {
    std::string name;
    std::string type;
public:
    Category(const std::string& n = "", const std::string& t = "");
    std::string getName() const;
    std::string getType() const;
    void setName(const std::string&);
    void setType(const std::string&);
};

#endif