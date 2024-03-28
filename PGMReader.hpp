#ifndef _PGM_READER_HPP_
#define _PGM_READER_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include "ImageReader.hpp"

class PGMReader : public ImageReader {
private:
    int width;
    int height;
    std::vector<std::vector<int>> pixels;

public:
    PGMReader(const std::string& filename);

    void printImageInfo() override;
    void printMostFrequentColor() override;
    int calculateNumberOfUniqueColors() override;

};

#endif
