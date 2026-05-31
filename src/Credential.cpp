#include "Credential.h"
#include <fstream>
#include <sstream>
#include <functional>

Credential::Credential(const std::string& user, const std::string& hash)
    : username(user), passwordHash(hash) {}

void Credential::setPassword(const std::string& password) {
    std::hash<std::string> hasher;
    passwordHash = std::to_string(hasher(password));
}

bool Credential::authenticate(const std::string& password) const {
    std::hash<std::string> hasher;
    return passwordHash == std::to_string(hasher(password));
}

std::string Credential::getUsername() const { return username; }
std::string Credential::getPasswordHash() const { return passwordHash; }

bool Credential::saveToFile() const {
    std::ofstream file("users.csv", std::ios::app);
    if (!file) return false;
    file << username << "," << passwordHash << "\n";
    file.close();
    return true;
}

bool Credential::authenticateFromFile(const std::string& username, const std::string& password) {
    std::ifstream file("users.csv");
    if (!file) return false;
    std::string line;
    std::hash<std::string> hasher;
    std::string passwordHash = std::to_string(hasher(password));
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string user, hash;
        getline(ss, user, ',');
        getline(ss, hash, ',');
        if (user == username && hash == passwordHash) {
            return true;
        }
    }
    return false;
}