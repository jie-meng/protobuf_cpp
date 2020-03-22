#include <iostream>
#include <fstream>
#include "proto/tutorial.addressbook.pb.h"

using namespace std;
using namespace tutorial;

const char* OUTPUT_FILE = "./output";

void writeToDisk() {
    AddressBook address_book;
    auto ppeople = address_book.add_people();
    ppeople->set_id(1);
    ppeople->set_name("John");
    ppeople->set_email("example@gmail.com");

    auto pphone_number = ppeople->add_phones();
    pphone_number->set_type(tutorial::Person::MOBILE);
    pphone_number->set_number("139000000000");

    pphone_number = ppeople->add_phones();
    pphone_number->set_type(tutorial::Person::HOME);
    pphone_number->set_number("12345678");

    // Write to disk.
    fstream output(OUTPUT_FILE, ios::out | ios::trunc | ios::binary);
    if (!address_book.SerializeToOstream(&output)) {
        cerr << "failed to write msg." << endl;
        return;
    }

    output.close();
}

void readFromDisk() {
    AddressBook address_book;

    // Read from disk
    fstream input(OUTPUT_FILE, ios::in | ios::binary);
    if (!input) {
        cout << OUTPUT_FILE << ": File not found." << endl;
        return;
    } else if (!address_book.ParseFromIstream(&input)) {
        cerr << "Failed to parse from disk." << endl;
        return;
    }

    input.close();

    for (int i = 0; i < address_book.people_size(); ++i) {
        cout << "id: " << address_book.people(i).id() << endl;
        cout << "name: " << address_book.people(i).name() << endl;
        cout << "email: " << address_book.people(i).email() << endl;

        for (int j = 0; j < address_book.people(i).phones_size(); ++j) {
            cout << "type: " << address_book.people(i).phones(j).type() << endl;
            cout << "number: " << address_book.people(i).phones(j).number() << endl;
        }
    }
}

int main(int argc, char* argv[]) {
    writeToDisk();
    readFromDisk();

    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}
