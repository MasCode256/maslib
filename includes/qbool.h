#ifndef MAS_QBOOL_H
#define MAS_QBOOL_H

#include "../mas.h"

namespace mas0 {
    namespace qbool{
        class qbool {
            public:
                char c;

                qbool() {
                    this->c = 0;
                }

                qbool(const char initial) {
                    this->c = initial;
                }

                char setBit(char index, bool value) {
                    char mask = 1 << index;

                    if (value) {
                        c |= mask;
                    }
                    else {
                        c &= ~mask;
                    }

                    return c;
                }

                bool getBit(char index) {
                    char mask = 1 << index;

                    return (c & mask) != 0;
                }

                uint8_t value() {
                    return uint8_t(c);
                }

                string bites() {
                    std::bitset<8> binaryRepresentation(c);
                    return binaryRepresentation.to_string();
                }
        };
    }
}

#endif