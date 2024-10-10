#ifndef MAS_QASM_H
#define MAS_QASM_H

#include "../mas.h"

namespace mas1 {
    namespace qori {
        class qscript {
            private:
                class stream {
                    public:
                        vector<string> script_argv;
                        string script = "undef";

                        size_t pos = 0;
                };
            public:
                vector<stream> streams;
                bool debug = true;

                string exe() {

                }

                string exe(const vector<string>& argv, size_t pos = 0) {
                    streams[0].pos = pos;
                }

                string exe(const string& exe_script, size_t pos = 0) {
                    streams[0].pos = pos;
                    streams[0].script = exe_script;
                }

                string exe(const string& exe_script, const vector<string>& argv, size_t pos = 0) {
                    streams[0].pos = pos;
                    streams[0].script = exe_script;
                    streams[0].script_argv = argv;
                }

                void construct() {
                    stream temp;
                    streams.push_back(temp);
                }

                qscript() {
                    construct();
                }

                qscript(bool debug_mode) {
                    construct();

                    debug = debug_mode;
                }

                qscript(const string& path, bool debug_mode = false) {
                    construct();

                    debug = debug_mode;
                    streams[0].script = mas0::parser::in(path);
                }

                ~qscript() {
                }
        };
    }
}

#endif