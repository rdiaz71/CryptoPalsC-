#include<iostream>
#include<string>

// Struct for looking up hex to binary conversions
struct HexBin {
	char hex;
	std::string binary;
};


// Hex to binary conversion lookup table
const HexBin hex_lookup[16] = { {'0',"0000"},
								{'1',"0001"},
								{'2',"0010"},
								{'3',"0011"},
								{'4',"0100"},
								{'5',"0101"},
								{'6',"0110"},
								{'7',"0111"},
								{'8',"1000"},
								{'9',"1001"},
								{'A',"1010"},
								{'B',"1011"},
								{'C',"1100"},
								{'D',"1101"},
								{'E',"1110"},
								{'F',"1111"},
};

// Struct for looking up binary to Base64 conversions
struct Bin64 {
	std::string binary;
	char base64;
};

// Binary to Base64 conversion lookup table
const Bin64 b64_lookup[64] = { {"000000", 'A'},
							   {"000001", 'B'},
							   {"000010", 'C'},
							   {"000011", 'D'},
							   {"000100", 'E'},
							   {"000101", 'F'},
							   {"000110", 'G'},
							   {"000111", 'H'},
							   {"001000", 'I'},
							   {"001001", 'J'},
							   {"001010", 'K'},
							   {"001011", 'L'},
							   {"001100", 'M'},
							   {"001101", 'N'},
							   {"001110", 'O'},
							   {"001111", 'P'},
							   {"010000", 'Q'},
							   {"010001", 'R'},
							   {"010010", 'S'},
							   {"010011", 'T'},
							   {"010100", 'U'},
							   {"010101", 'V'},
							   {"010110", 'W'},
							   {"010111", 'X'},
							   {"011000", 'Y'},
							   {"011001", 'Z'},
							   {"011010", 'a'},
							   {"011011", 'b'},
							   {"011100", 'c'},
							   {"011101", 'd'},
							   {"011110", 'e'},
							   {"011111", 'f'},
							   {"100000", 'g'},
							   {"100001", 'h'},
							   {"100010", 'i'},
							   {"100011", 'j'},
							   {"100100", 'k'},
							   {"100101", 'l'},
							   {"100110", 'm'},
							   {"100111", 'n'},
							   {"101000", 'o'},
							   {"101001", 'p'},
							   {"101010", 'q'},
							   {"101011", 'r'},
							   {"101100", 's'},
							   {"101101", 't'},
							   {"101110", 'u'},
							   {"101111", 'v'},
							   {"110000", 'w'},
							   {"110001", 'x'},
							   {"110010", 'y'},
							   {"110011", 'z'},
							   {"110100", '0'},
							   {"110101", '1'},
							   {"110110", '2'},
							   {"110111", '3'},
							   {"111000", '4'},
							   {"111001", '5'},
							   {"111010", '6'},
							   {"111011", '7'},
							   {"111100", '8'},
							   {"111101", '9'},
							   {"111110", '+'},
							   {"111111", '/'},
};
// Function to convert hex string to binary
// Returns binary string
std::string hexToBinary(std::string hexStr) {

	std::string binary = "";

	// Iterate through the hex input string
	for (int x = 0; x < hexStr.length(); x++) {

		// Ensure all letters are uppercase
		hexStr[x] = toupper(hexStr[x]);

		// Look for the corresponding binary value and add to the final binary string
		for (HexBin lookup : hex_lookup) {
			if (lookup.hex == hexStr[x]) {
				binary += lookup.binary;
			}
		}
	}
	return binary;
}

// Function to convert binary string to base64 string
// Returns base64 string
std::string binaryToBase64(std::string binStr) {
	
	// Check if binStr needs padding
	int padding = binStr.length() % 3;
	if (padding) {
		// Add padding
		binStr += std::string(padding*2, '0');
	}

	// Iterate through binStr 6 bits at a time
	std::string base64 = "";
	int start = 0;

	for (int end = 5; end < binStr.length(); end += 6) {
		std::string sixBits = "";

		// Add next 6 bits together
		for (start; start <= end; start++) {
			sixBits += binStr[start];
		}

		// Find base64 value of these 6 bits and add to final string
		for (Bin64 lookup : b64_lookup) {
			if (lookup.binary == sixBits) {
				base64 += lookup.base64;
			}
		}
	}

	// Add padding if needed
	if (padding) {
		base64 += std::string(padding, '=');
	}

	return base64;
}

// Function to convert hex string to base64 string using previous functions
std::string hexToBase64(std::string hex) {
	return binaryToBase64(hexToBinary(hex));
}

int main(){
	// Challenge 1 hex string to test, and the Base64 answer
	std::string testHex = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	std::string ans64 = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

	std::cout << "Answ: " << ans64 << std::endl;
	std::cout << "Mine: " << hexToBase64(testHex) << std::endl;
}