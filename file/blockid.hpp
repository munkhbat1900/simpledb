#ifndef BLOCKID_HPP
#define BLOCKID_HPP

#include <string>

class BlockID {
public:
  BlockID(const BlockID &pBlk);
  BlockID(std::string pFileName, int pBlockNum);

  [[nodiscard]] std::string fileName() const;
  [[nodiscard]] int number() const;
  [[nodiscard]] std::string toString() const;
  bool operator==(const BlockID &other) const;

private:
  std::string mFileName;
  int mBlockNum{};
};

#endif