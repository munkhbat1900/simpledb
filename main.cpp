#include <iostream>
#include <memory>
#include <vector>
#include "file/page.hpp"

using namespace std;

int main() {
    std::unique_ptr<Page> page = std::make_unique<Page>(9);
    page->setInt(3, 123456789);
    shared_ptr<vector<char>> v = page->contents();
    for (auto c : *v) {
        cout<< static_cast<int>(static_cast<unsigned char>(c)) << endl;
    }
    return 1;
}