#include "blockid.hpp"

namespace simpledb {
    BlockID::BlockID() {}
    BlockID::BlockID(const BlockID &pBlck)
        : mFileName(pBlck.mFileName), mBlockNum(pBlck.mBlockNum) {}
    BlockID::BlockID(const std::string &pFileName, int pBlockNum)
        : mFileName(pFileName), mBlockNum(pBlockNum) {}
    
    std::string BlockID::fileName() const {
        return mFileName;
    }

    int BlockID::number() const {
        return mBlockNum;
    }
    
    std::string BlockID::toString() const {
        return "[file " + mFileName + ", block " + std::to_string(mBlockNum) + "]";
    }
    
    bool BlockID::operator==(const BlockID &other) const {
        return (mFileName == other.fileName()) && (mBlockNum == other.number());
    }
}