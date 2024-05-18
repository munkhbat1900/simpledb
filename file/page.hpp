#ifndef PAGE_HPP
#define PAGE_HPP

#include <memory>
#include <optional>
#include <string>
#include <vector>

using namespace std;

class Page {
public:
  Page(int pBlockSize);
  Page(const shared_ptr<vector<char>> &pByteBuffer);

  int getInt(int pOffset);
  void setInt(int pOffset, int n);
  vector<char> getBytes(int pOffset);
  void setBytes(int pOffset, vector<char> &pBytes);
  string getString(int pOffest);
  void setString(int pOffset, const string &pStr);
  int maxLength(int pStrlen);
  shared_ptr<vector<char>> contents();
private:
    shared_ptr<vector<char>> mByteBuffer;
};

#endif