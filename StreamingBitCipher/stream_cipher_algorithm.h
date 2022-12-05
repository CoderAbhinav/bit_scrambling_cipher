#pragma once
#include <bitset>
#include <vector>
#include <string>
#include "utils.h"
#define bitVector std::vector<bool>

class StreamCipherAlgorithm{
    std::string key;
    std::vector<bool> key_in_bit_vector;
public:
    StreamCipherAlgorithm(std::string);
    std::string encrypt(std::string);
    std::string decrypt(std::string);
};

StreamCipherAlgorithm::StreamCipherAlgorithm(std::string key) {
    this->key = key;
    this->key_in_bit_vector = stringToBitVector(key);
}

std::string StreamCipherAlgorithm::encrypt(std::string msg) {
    // create bit vectors for each
    bitVector msg_in_bit_vector = stringToBitVector(msg);
    bitVector cipher_in_bit_vector = bitVector(msg.size() * 8, 0);

    // create pointers
    bitVector::iterator p, q, r, s;

    p = msg_in_bit_vector.begin();
    q = key_in_bit_vector.begin();
    r = cipher_in_bit_vector.begin();
    s = cipher_in_bit_vector.begin(); s--;

    // create loop
    while (p != msg_in_bit_vector.end()) {
        if (*q == 1) {
            *r = *p;
            r++;
        } else {
            *s = !(*p);
            s--;
        }

        p++;
        q++;
        if (q == key_in_bit_vector.end()) {

            q = key_in_bit_vector.begin();
        }

    }

    // return formatted results
    return bitVectorToString(cipher_in_bit_vector);
}

std::string StreamCipherAlgorithm::decrypt(std::string cipher_text) {
    // create bit vectors for each
    bitVector msg_in_bit_vector = bitVector(cipher_text.size() * 8, 0);
    bitVector cipher_in_bit_vector = stringToBitVector(cipher_text);

    // create pointers
    bitVector::iterator p, q, r, s;

    p = msg_in_bit_vector.begin();
    q = key_in_bit_vector.begin();
    r = cipher_in_bit_vector.begin();
    s = cipher_in_bit_vector.begin(); s--;

    while (p != msg_in_bit_vector.end()) {
        if (*q == 1) {
            *p = *r;
            r++;
        } else {
            *p = !(*s);
            s--;
        }

        p++;
        q++;
        if (q == key_in_bit_vector.end()) {
            q = key_in_bit_vector.begin();
        }
    }

    return bitVectorToString(msg_in_bit_vector);
}