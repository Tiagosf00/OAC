#include <iostream>
#include "globals.h"


int main() {

    init();

    load_mem("testeASM/code.bin", 0);
    load_mem("testeASM/data.bin", DATA_SEGMENT_START);

    run();

    return 0;
}