#pragma once
#include <vector>
#include <cstdint>
using namespace std;

/*
	memory class where memory locations is defined as elements of vector each element is an integer represinting the value in the location
	-- this file includes only the data memory
*/


class Memory {

private: 
	uint32_t size;
	vector<uint8_t> mem;

public:
	// Constructor
	Memory(uint32_t size);

	// default memory to be 16KB
	Memory();


	// set size of the data memort
	void setSize(uint32_t size);


	// get size of the data memory
	uint32_t getSize();

	// insert element to the memory
	void storeWord(uint32_t address,uint32_t word);

	// read element from the memory
	uint32_t readWord(uint32_t address);

	// read byte from the memory
	uint8_t readByte(uint32_t address);

	


};