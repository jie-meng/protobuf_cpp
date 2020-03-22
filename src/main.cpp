#include <iostream>
#include "proto/lm.helloworld.pb.h"

using namespace std;
using namespace lm;

int main(int argc, char* argv[])
{
    helloworld hw;
    hw.set_id(1);
    hw.set_str("hello man");
    hw.set_opt(32);

    // fstream output("./log", ios::out | ios::trunc | ios::binary);
    // if (!hw.SerializeToOStream(&output)) {
    //     cerr << "failed to write msg." << endl;
    //     return -1;
    // }

    cout << "helloworld" << endl;
}
