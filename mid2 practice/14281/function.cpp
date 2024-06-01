#include "function.h"
#include <string>
#include <iostream>
#include <sstream>
using namespace std;


class DummyCodec : public Codec {
    public:
        DummyCodec(string s): Codec(s) {}
        void encode() override{
            if(!encoded){
                encoded = true;
            }
        }

        void decode() override{
            if(encoded){
                encoded = false;
            }
        }

};

class RLECodec : public Codec {
    public:
        RLECodec(string s): Codec(s) {}
        void encode() override{
            if(!encoded){
                stringstream result;
                char lastChar = '\0';
                int count = 0;

                for (char ch : code_str) {
                    if (ch == lastChar) {
                        count++;
                    } else {
                        if (lastChar != '\0') {
                            if (count > 2) {
                                result << count << lastChar;
                            } else {
                                result << string(count, lastChar);
                            }
                        }
                        lastChar = ch;
                        count = 1;
                    }
                }

                if (count > 2) {
                    result << count << lastChar;
                } else {
                    result << string(count, lastChar);
                }

                code_str = result.str();
                encoded = true;
            }
        }

        void decode() override{
            if(encoded){
                stringstream result;
                int count = 0;

                 for(char lastChar : code_str) {
                    if (isdigit(lastChar)) {
                        count = count * 10 + (lastChar - '0');
                    } else {
                        count = count == 0 ? 1 : count;
                        result << string(count, lastChar);
                        count = 0;
                    }
                }
                code_str = result.str();
                encoded = false;
            }
        }
};


Codec* getCodec(const string& type, const string& is){
    if(type == "Dummy"){
        return new DummyCodec(is);
    }
    else if(type == "RLE"){
        return new RLECodec(is);
    }
    else{
        return nullptr;
    }
};