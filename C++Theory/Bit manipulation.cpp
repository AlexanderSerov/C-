#include <iostream>
#include <bitset>
#include <cstddef>

using namespace std;

int main() {

    std::bitset<8> bits;
    std::cout << bits << std::endl;
    std::bitset<8> bits1("00000010");
    std::cout << bits1 << std::endl;
    cout << bits1[1] << endl;
    cout << bits1.to_ulong() << endl;
    cout << 0b0101 << endl;                     // Bit literals. Since C++14


    // Printing unsigned char as bits
    unsigned char var = 56;
    for (short bit(CHAR_BIT-1); bit >= 0 ; bit--) 
        std::cout << ((var >> bit) & 1);

    // Bit flags make the most sense when you have many identical flag variables.For example, 
    // in the example above, imagine that instead of having one person(me), you had 100.
    // If you used 8 Booleans per person(one for each possible state), you’d use 800 bytes of memory.
    // With bit flags, you’d use 8 bytes for the bit masks, and 100 bytes for the bit flag variables, 
    // for a total of 108 bytes of memory -- approximately 8 times less memory.

    // Modern way to represent bit masks
    enum masks : unsigned char
    {
        mask1 = 0b00000001,
        mask2 = 0b00000010,
        mask3 = 0b00000100,
        mask4 = 0b00001000,
        mask5 = 0b00010000,
        mask6 = 0b00100000,
        mask7 = 0b01000000,
        mask8 = 0b10000000,
    };

    // Create a new integral type using scoped enum
    enum class MyByte : unsigned char {};

    std::byte b{ 66 };
    cout << (unsigned char)b << endl;


    std::cin.get();
    return 0;
}