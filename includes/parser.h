#ifndef MAS_PARSER_H
#define MAS_PARSER_H

#include "../mas.h"
using namespace std;

namespace mas0 {
    namespace parser {
        string before(const string& str, char delimiter) {
            size_t delimiterIndex = str.find(delimiter);

            if (delimiterIndex != std::string::npos) {
                return str.substr(0, delimiterIndex);
            } else {
                return "";
            }

            return "";
        }

        string after(const string& str, char delimiter) {
            size_t pos = str.find(delimiter);
            if (pos != std::string::npos) {
                return str.substr(pos + 1);
            }

            return "";
        }

        bool contains_char(const string& str, char c) {
            return str.find(c) != std::string::npos;
        }
    }
}

#endif
