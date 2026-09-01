#pragma once
#include <array>

class RegisterFile {

    std::array<int, 32>mem;

public:

    RegisterFile();

    int getRegister(int address);

    void setRegister(int address, int data);

    void dispData();
};
