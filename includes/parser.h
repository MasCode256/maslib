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
            string ret;
            for (size_t i = 0; i < str.length(); i++)
            {
                if (str[i] == delimiter)
                {
                    for (size_t j = 0; j < str.length(); j++)
                    {
                        ret += str[j];
                    }
                    return ret;
                } 
            }
            

            return "";
        }

        std::string afterbefore(const std::string& str, char startChar, char endChar) {
            size_t startPos = str.find_first_of(startChar);
            size_t endPos = str.find_last_of(endChar, str.size() - 1);
            
            if (startPos == std::string::npos || endPos == std::string::npos || startPos >= endPos) {
                return ""; 
            }
            
            return str.substr(startPos + 1, endPos - startPos - 1);
        }

        string after_index_before_delimiter(const string& str, char delimiter, size_t index) {
            string ret = "";
            for (size_t i = index; i < str.length() && str[i] != delimiter; i++)
            {
                ret += str[i];
            }
            
            return ret;
        }

        string after_index_before_delimiter_long_unsigned(const string& str, char delimiter, long unsigned int index) {
            string ret = "";
            for (size_t i = index; i < str.length() && str[i] != delimiter; i++)
            {
                ret += str[i];
            }
            
            return ret;
        }

        string after_index(const string& str, size_t index = 1) {
            string ret = "";
            for (size_t i = index; i < str.length(); i++)
            {
                ret += str[i];
            }
            
            return ret;
        }

        string index_index(const string& str, size_t index1, size_t index2) {
            string ret = "";
            for (size_t i = index1; i < index2 && i < str.length(); i++)
            {
                ret += str[i];
            }
            
            return ret;
        }


        bool contains_char(const string& str, char c) {
            return str.find(c) != std::string::npos;
        }


        string in(const string& path) {
            ifstream fin(path.c_str());
            std::string content((std::istreambuf_iterator<char>(fin)), std::istreambuf_iterator<char>());

            return content;
        }
    }
}

#endif
