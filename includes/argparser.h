#ifndef MAS_ARGPARSER_H
#define MAS_ARGPARSER_H

#include "../mas.h"
using namespace std;

namespace mas0 {
    namespace argParser {
        string get_primary_argument(int argc, char** argv) {
            if(argc > 1) {
                if(argc >= 2) {
                    if(string(argv[1]).length() > 0 && string(argv[1])[0] != '-') {
                        return string(argv[1]);
                    } 
                }
                if(argc > 2) {
                    for (size_t i = 2; i < argc; i++)
                    {
                        if (string(argv[i - 1]).length() > 1 && string(argv[i - 1])[0] == '-')
                        {
                            if(string(argv[i - 1])[1] == '-' && string(argv[i])[0] != '-') {
                                return string(argv[i]);
                            }
                        } else {
                            return string(argv[i]);
                        }
                    }
                    
                }
            }
            return "";
        }

        string get_argument_by_name(int argc, char** argv, const string& name) {
            for (size_t i = 1; i < argc; i++)
            {
                if (string(argv[i - 1]).length() > 1 && string(argv[i - 1])[0] == '-' && string(argv[i - 1])[1] != '-' && (string(argv[i - 1])) == ("-" + name))
                {
                    return string(argv[i]);
                }
                else if (string(argv[i]).length() > 2 && string(argv[i])[0] == '-' && string(argv[i])[1] == '-' && mas0::parser::contains_char(string(argv[i]), '=') && "--" + name == mas0::parser::before(string(argv[i]), '=')) {
                    return mas0::parser::after(string(argv[i]), '=');
                }
            }

            return "";
        }

        bool contains_tag(int argc, char** argv, string& tag) {
            if (argc >= 2)
            {
                for (size_t i = 1; i < argc; i++)
                {
                    if(string(argv[i]).length() > 2 && string(argv[i])[0] == '-' && string(argv[i])[1] == '-' && "--" + tag == string(argv[i])) {
                        return true;
                    }
                }
            }
            return false;
        }
    }
}

#endif
