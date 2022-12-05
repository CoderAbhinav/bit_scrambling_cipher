#include <iostream>
#include "StreamingBitCipher/stream_cipher_algorithm.h"
#include "StreamingBitCipher/utils.h"
using namespace std;

int main(int argc, char const *argv[])
{
    string key = "1234";
    StreamCipherAlgorithm s(key);

    string pt = "viit";
    cout << "KEY: " << bitVectorToRepresentionalString(stringToBitVector(key)) << "\n";
    cout << "PT : " << bitVectorToRepresentionalString(stringToBitVector(pt)) << "\n";

    string enc = s.encrypt(pt);
    cout << "ENC: " << bitVectorToRepresentionalString(stringToBitVector(enc)) << "\n";

    string dec = s.decrypt(enc);
    cout << "DEC: " << bitVectorToRepresentionalString(stringToBitVector(dec)) << "\n";

    cout << "\nENC: " << enc;
    cout << "\nDEC: " << dec;
    return 0;
}
