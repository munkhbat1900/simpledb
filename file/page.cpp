#include "page.hpp"
#include <cstring>
#include <iterator>
#include <memory>
#include <optional>
#include <stdexcept>
#include <vector>

Page::Page(int pBlockSize) {
  mByteBuffer = make_shared<vector<char>>(pBlockSize);
}
Page::Page(const shared_ptr<vector<char>> &pByteBuffer) : mByteBuffer(pByteBuffer) {}

int Page::getInt(int pOffset) {
    if (pOffset + sizeof(int) > (*mByteBuffer).size()) {
        throw out_of_range("out of range of page: getInt");
    }
    int num;
    memcpy(&num, &(*mByteBuffer)[pOffset], sizeof(int));
    return num;
}

void Page::setInt(int pOffset, int n) {
    if (pOffset + sizeof(int) > (*mByteBuffer).size()) {
        throw out_of_range("out of range of page: setInt");
    }
    memcpy(&(*mByteBuffer)[pOffset], &n, sizeof(int));
}

vector<char> Page::getBytes(int pOffset) {
    int len = getInt(pOffset);
    if (pOffset + sizeof(int) + len > (*mByteBuffer).size()) {
        throw out_of_range("out of range of page: getBytes");
    }
    vector<char> bytes(len);
    memcpy(&bytes[0], &(*mByteBuffer)[pOffset], sizeof(char));
    return bytes;
}

void Page::setBytes(int pOffset, vector<char> &pBytes) {
    if (pOffset + sizeof(int) + pBytes.size() > (*mByteBuffer).size()) {
        throw out_of_range("out of range of page: setBytes");
    }
    setInt(pOffset, pBytes.size());
    memcpy(&(*mByteBuffer)[pOffset], &pBytes[0], pBytes.size());
}

string Page::getString(int pOffest) {
    vector<char> bytes = getBytes(pOffest);
    string s(bytes.begin(), bytes.end());
    return s;
}

void Page::setString(int pOffset, const string &pStr) {
    vector<char> v(pStr.begin(), pStr.end());
    setBytes(pOffset, v);
}

int Page::maxLength(int pStrlen) {
    return sizeof(int) + pStrlen * sizeof(char);
}
shared_ptr<vector<char>> Page::contents() {
    return mByteBuffer;
}