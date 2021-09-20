#include <iostream>

struct	Data { std::string importantString; };

uintptr_t serialize(Data * ptr);
Data* deserialize(uintptr_t raw);

int main()
{
    Data *oldData = new Data;

    std::cout << std::endl << "----------------Data Structure created---------------" << std::endl;
	oldData->importantString = ("I'm original important data");
    std::cout << "Data before: " << oldData->importantString << std::endl;
    std::cout << "------------------------------------------------------" << std::endl << std::endl;

    std::cout << "original pointer: " << oldData << std::endl;

    uintptr_t tmp = serialize(oldData);

    std::cout << "serialized pointer: " << tmp << std::endl;

    Data *newData = deserialize(tmp);

    std::cout << "deserialized pointer: " << newData << std::endl;

    std::cout << std::endl << "-----------------------------------------------------" << std::endl;
    std::cout << "Data after: " << newData->importantString << std::endl;     //notice here I'm calling newData pointer, but recieve oldData1 information
    std::cout << "-----------------------------------------------------" << std::endl << std::endl;

    return 0;
}

uintptr_t serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}