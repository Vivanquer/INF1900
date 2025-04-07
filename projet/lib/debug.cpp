#include "debug.h"

static RS232 rs232; 

void Debug::init() {
    rs232 = RS232(); 
    }

void Debug::print(const char* msg) {
    while (*msg) {
        rs232.transmissionUART(*msg++);
    }
    rs232.transmissionUART('\n'); 
    }

void Debug::printVar(const char* label, int var) {
    print(label); 
    rs232.transmissionUART(':');
    rs232.transmissionUART(' ');
    
    char buffer[10];
    sprintf(buffer, "%d", var);
    print(buffer);
}