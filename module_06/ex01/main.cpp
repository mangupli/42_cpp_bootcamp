#include "Data.class.hpp"
#include <iostream>

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

int main()
{
    Data *oldData = new Data();

    std::cout << std::endl << "-----------------Data created---------------------------" << std::endl;
    oldData->setImportantData("I'm original important data");
    std::cout << "Data before: " << oldData->getImportantData() << std::endl;
    std::cout << "-------------------------------------------------------" << std::endl << std::endl;

    std::cout << "original pointer: " << oldData << std::endl;

    uintptr_t tmp = serialize(oldData);

    std::cout << "serialized pointer: " << tmp << std::endl;

    Data *newData = deserialize(tmp);

     std::cout << "serialized pointer: " << newData << std::endl;

    std::cout << std::endl << "-----------------------------------------------------" << std::endl;
    std::cout << "Data after: " << newData->getImportantData() << std::endl;     //notice here I'm calling newData pointer, but recieve oldData information
    std::cout << "-----------------------------------------------------" << std::endl << std::endl;

    return 0;
}

uintptr_t serialize(Data* ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}