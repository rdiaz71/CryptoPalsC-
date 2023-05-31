#pragma once

// Struct declarations
struct HexBin {
	char hex;
	std::string binary;
};

struct Bin64 {
	std::string binary;
	char base64;
};

// Lookup tables
extern const HexBin hex_lookup[16];

// Function declarations
std::string hexToBinary(std::string);
std::string binaryToBase64(std::string);
std::string hexToBase64(std::string);
