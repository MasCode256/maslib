#ifndef MAS_VEXOR_H
#define MAS_VEXOR_H

#include "../mas.h"

namespace mas0 {
    namespace vex {
        class vexor
        {
            private:
                
            public:
                string str = "\x00";

                // dynamic_content_sizing - 0, endless_max_size - 1

                void parameters_set(const char value) {
                    if (str.length() > 0)
                    {
                        str[0] = value;
                    } else {
                        str.push_back(value);
                    }
                }

                bool is_dynamic_content_sizing() {mas0::qbool::qbool temp(str[0]); return temp.getBit(0);}
                bool is_endless_max_size() {mas0::qbool::qbool temp(str[0]); return temp.getBit(1);}
                string main_argument() { return mas0::parser::after_index_before_delimiter(str, '$', 1); }

                void second_constructing_part(const long int& sector_size) {
                    if(is_dynamic_content_sizing()) {
                        if(!is_endless_max_size()) {
                        }
                    } else {
                        str += mas0::enc::m_int_to_str(sector_size) + "$";
                    }
                }


                void push_back(const string& value) {
                    if(is_dynamic_content_sizing()) {
                        if (is_endless_max_size())
                        {
                            cout << "\nSucessfully adding!";
                            str += mas0::enc::m_int_to_str(value.length()) + ":" + value;
                        }
                        else {
                            str += mas0::enc::size_t_to_bytes(value.length()) + value;
                        }
                    } else {
                        if (value.length() == mas0::enc::m_str_to_int(main_argument()))
                        {
                            cout << "\nSucessfully adding!";
                            str += value;
                        }
                        else {
                            cout << "\n[Vexor error] value length is not equals to sector_size constant.";
                        }
                    }
                }

                vexor() {
                    cout << "\nDefault constructor called!";

                    mas0::qbool::qbool temp;
                    temp.setBit(0, 1);
                    temp.setBit(1, 1);

                    parameters_set(temp.c);
                    second_constructing_part(0);
                }

                vexor(const vector<string>& initial, bool dynamic_content_sizing = true, bool endless_max_size = true
                , size_t sector_size = 0
                )
                {
                    cout << "\nVector size: " << initial.size();
                    cout << "\nIs dynamic content sizing: " << dynamic_content_sizing;
                    cout << "\nIs endless max size: " << endless_max_size;

                    mas0::qbool::qbool temp;
                    temp.setBit(0, dynamic_content_sizing);
                    temp.setBit(1, endless_max_size);

                    parameters_set(temp.c);
                    second_constructing_part(sector_size);

                    for (size_t i = 0; i < initial.size(); i++)
                    {
                        push_back(initial[i]);
                    }
                    
                }

                void print_vexor() {
                    cout << "\nVexor:";
                    for (size_t i = 0; i < str.length(); i++)
                    {
                        cout << " " << int(str[i]);
                    }
                }

                const string operator[](size_t index) {
                    cout << "\nOperator index (const): " << index;
                    const string ret;
                    
                    if (is_dynamic_content_sizing())
                    {
                        cout << "\nContent sizing: dynamic";
                        if (is_endless_max_size())
                        {
                            cout << "\nMax size: none";

                            string full = mas0::parser::index_index(str, 1, str.length() - 1);
                            cout << "\nfull = " << full;

                            string before = mas0::parser::before(full, ':');
                            size_t start_pos = before.length() + 1;

                            if(index == 0) {
                                return mas0::parser::index_index(full, start_pos, mas0::enc::m_str_to_sizet(before) + start_pos);
                            }

                            for (size_t i = 0; i <= index; i++)
                            {
                                size_t pos = before.length() + mas0::enc::m_str_to_sizet(before) + 1;
                                full.erase(0, pos);

                                before = mas0::parser::before(full, ':');
                                start_pos = before.length() + 1;

                                cout << "\npos = " << pos << ", before = " << before << ", start_pos = " << start_pos << ", full = " << full;

                                if (i + 1 >= index)
                                {
                                    return mas0::parser::index_index(full, start_pos, mas0::enc::m_str_to_sizet(before) + start_pos);    
                                }
                                
                            }
                            
                        }
                        else {
                            cout << "\nSizing: size_t";

                            string full = mas0::parser::index_index(str, 1, str.length() - 1);
                            cout << "\nfull = \n"; cout << full;

                            for (size_t i = 0; i <= index; i++)
                            {
                                string slentag = mas0::parser::index_index(full, 0, sizeof(size_t));
                                size_t lentag = mas0::enc::bytes_to_size_t(slentag);

                                cout << "\nlentag = " << lentag << ", slentag = " << slentag << ", full = \n" << full;
                                if (i + 1 >= index)
                                {
                                    return mas0::parser::index_index(full, 0, lentag);
                                }
                                full.erase(0, lentag);
                            }
                            
                        }
                    }
                        
                    
                    

                    return "error";
                }
                
                ~vexor()
                {
                }
        };
    }
}

#endif