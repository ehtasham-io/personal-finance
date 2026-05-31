#ifndef CREDENTIAL_H
#define CREDENTIAL_H
#include <string>

class Credential {
    std::string username;
    std::string passwordHash;
public:
    Credential(const std::string& user = "", const std::string& hash = "");
    void setPassword(const std::string& password);
    bool authenticate(const std::string& password) const;
    std::string getUsername() const;
    std::string getPasswordHash() const;
    bool saveToFile() const;
    static bool authenticateFromFile(const std::string& username, const std::string& password);
};

#endif