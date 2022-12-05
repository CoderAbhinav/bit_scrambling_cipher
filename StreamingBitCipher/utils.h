#pragma once
#include <vector>
#include <bitset>
#include <string>
#define bitVector std::vector<bool>

bitVector stringToBitVector(std::string s) {

    int n = s.length();
    bitVector res(8 * n, 0);

    for (int i = 0; i < n; i++) {
        std::bitset<8> curr_char_bs(s[i]);
        for (int j = 0; j < 8; j++) {
            res[i * 8 + j] = curr_char_bs.test(8 - j - 1);
        }
    }

    return res;
}

std::string bitVectorToString(bitVector v) {
    std::string res = "";
    int curr = 0;

    for (int i = 0; i < v.size(); i++) {
        if (i != 0 && i % 8 == 0) {
            res += (char) curr;
            curr = v[i];
        } else {
            curr = curr << 1;
            curr += v[i];
        }
    }

    res += (char) curr;

    return res;
}

std::vector<std::bitset<8> > stringToBitsetVector(std::string s) {
    int n = s.length();
    std::vector<std::bitset<8> > res(n);

    for (int i = 0; i < n; i++) {
        res[i] = std::bitset<8>(s[i]);
    }

    return res;
}

std::string bitsetVectorToString(std::vector<std::bitset<8> > v) {
    int n = v.size();
    std::string res = "";

    for (int i = 0; i < n; i++) {
        res += (char) v[i].to_ullong();
    }

    return res;
}

std::string bitVectorToRepresentionalString(bitVector v) {
    std::string res = "";
    
    for (int i = 0; i < v.size(); i++) {
        res += v[i] == 1 ? "1" : "0";
    }

    return res;
}