#pragma once
#include <exception>
#include <string>

class OutOfBoard : public std::exception {
    public:
        OutOfBoard(int x, int y);
        virtual const char* what() const throw() {
            return "";
        }
    private:
        std::string error;
};
