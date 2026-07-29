#pragma once

#include <string>
#include <iostream>

struct Thing {
    std::string data;

    Thing() : data("") {}
    Thing(const std::string& val) : data(val) {}

    // Retorna a string limpa (sem as aspas de literal, se existirem)
    std::string toString() const {
        if (data.size() >= 2 && data.front() == '"' && data.back() == '"') {
            return data.substr(1, data.size() - 2);
        }
        return data;
    }

    // Permite fazer `std::cout << thing_obj;`
    friend std::ostream& operator<<(std::ostream& os, const Thing& t) {
        os << t.toString();
        return os;
    }
};