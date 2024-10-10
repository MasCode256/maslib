#ifndef MAS_ENCODINGS_H
#define MAS_ENCODINGS_H

#include "../mas.h"

namespace mas0 {
    namespace enc {
        string m_int_to_str(int num) {
            std::stringstream ss;
            ss << num;
            return ss.str();
        }

        int m_str_to_int(string str) {
            std::istringstream iss(str);
            int num;
            iss >> num;

            return num;
        }

        string m_sizet_to_str(size_t num) {
            std::stringstream ss;
            ss << num;
            return ss.str();
        }

        size_t m_str_to_sizet(string str) {
            std::istringstream iss(str);
            size_t num;
            iss >> num;

            return num;
        }

        std::string int_to_bytes(int value) {
            std::string result;
            result.resize(sizeof(int)); // allocate space for sizeof(int) characters

            for (size_t i = 0; i < sizeof(int); i++) {
                unsigned char byte = (value >> (i * 8)) & 0xFF; // extract byte from int
                result[i] = static_cast<char>(byte); // convert byte to char and store in result
            }

            return result;
        }

        int bytes_to_int(const std::string& str) {
            int result = 0;

            for (size_t i = 0; i < str.size(); i++) {
                unsigned char byte = static_cast<unsigned char>(str[i]); // convert char to byte
                result |= byte << (i * 8); // combine byte with result using bitwise OR and shift
            }

            return result;
        }

        std::string size_t_to_bytes(size_t value) {
            std::string result;
            result.resize(sizeof(size_t)); // allocate space for sizeof(size_t) characters

            for (size_t i = 0; i < sizeof(size_t); i++) {
                unsigned char byte = (value >> (i * 8)) & 0xFF; // extract byte from size_t
                result[i] = static_cast<char>(byte); // convert byte to char and store in result
            }

            return result;
        }

        size_t bytes_to_size_t(const std::string& str) {
            size_t result = 0;

            for (size_t i = 0; i < str.size(); i++) {
                unsigned char byte = static_cast<unsigned char>(str[i]); // convert char to byte
                result |= byte << (i * 8); // combine byte with result using bitwise OR and shift
            }

            return result;
        }

        void test_str(string str) {
            cout << "\nString:";
            for (size_t i = 0; i < str.length(); i++)
            {
                cout << " " << int(str[i]);
            }
        }
    }
}

#endif