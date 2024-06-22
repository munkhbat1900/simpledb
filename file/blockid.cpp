#include "blockid.hpp"

BlockID::BlockID(const BlockID &pBlck) = default;
BlockID::BlockID(std::string pFileName, int pBlockNum)
    : mFileName(std::move(pFileName)), mBlockNum(pBlockNum) {}

std::string BlockID::fileName() const { return mFileName; }

int BlockID::number() const { return mBlockNum; }

std::string BlockID::toString() const {
    return "[file " + mFileName + ", block " + std::to_string(mBlockNum) + "]";
}

bool BlockID::operator==(const BlockID &other) const {
  return (mFileName == other.fileName()) && (mBlockNum == other.number());
}