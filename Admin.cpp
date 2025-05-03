#include "Admin.h"

Admin::Admin(const std::string& name, const std::string& id, const std::string& password)
    : Person(name, id, password) {
}

//Print admin info/summary
void Admin::printSummary() const {
    std::cout << "Admin: " << name << " (" << id << ")\n";
}