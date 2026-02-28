#include "Serializer.hpp"
#include "Data.hpp"

#include <iostream>

int main()
{
	Data data(42, 84, 168);
	std::cout << "Data ptr: " << &data << "\n";
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized as uintptr_t value: " << raw << "\n";
	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized as ptr: " << deserializedData << "\n";
	return 0;
}