#ifndef BLOCKID_HPP
#define BLOCKID_HPP

#include <string>

class BlockID {
public:
  BlockID();
  BlockID(const BlockID &pBlk);
  BlockID(const std::string &pFileName, int pBlockNum);

  std::string fileName() const;
  int number() const;
  std::string toString() const;
  bool operator==(const BlockID &other) const;

private:
  std::string mFileName;
  int mBlockNum;
};

#endif