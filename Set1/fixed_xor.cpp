#include <iostream>
#include "hex_to_64.h"

// Function to convert binary back to hex
// Returns hex string
std::string binaryToHex(std::string binStr) {

	std::string hex_str = "";

	// Iterate through binStr 4 bits at a time
	std::size_t start = 0;

	for (std::size_t end = 3; end < binStr.size(); end += 4) {
		std::string fourBits = "";

		// Add next 4 bits together
		for (start; start <= end; start++) {
			fourBits += binStr[start];
		}

		// Find hex value of these 4 bits and add to final string
		for (HexBin lookup : hex_lookup) {
			if (lookup.binary == fourBits) {
				hex_str += lookup.hex;
			}
		}
	}
	return hex_str;
}

// Function to XOR two EQUAL LENGTH binary strings
// Returns binary string
std::string fixedXOR(std::string binary1, std::string binary2) {

	// Make sure strings are equal length
	if (!(binary1.size() == binary2.size()))

		// If not, return empty string
		return "";

	std::string xor_string = "";

	// Iterate through both strings, XORing each bit
	for (std::size_t x = 0; x < binary1.size(); x++) {
		if (binary1[x] == binary2[x]) {
			xor_string.append("0");
		}

		else {
			xor_string.append("1");
		}
	}

	// Return XOR'd string
	return xor_string;
}

// Main function to run tests
int main() {
	std::string hex1 = "1c0111001f010100061a024b53535009181c";
	std::string hex2 = "686974207468652062756c6c277320657965";
	std::string answer = "746865206b696420646f6e277420706c6179";

	std::string bin1 = hexToBinary(hex1);
	std::string bin2 = hexToBinary(hex2);

	std::string xor_bin = fixedXOR(bin1, bin2);
	std::string my_answer = binaryToHex(xor_bin);

	std::cout << "Real: " << answer << std::endl;
	std::cout << "Mine: " << my_answer << std::endl;
	return 0;
}
