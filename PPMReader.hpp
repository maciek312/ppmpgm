#ifndef _PPM_READER_HPP_
#define _PPM_READER_HPP_

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include "ImageReader.hpp"

class PPMReader : public ImageReader {
private:
    int width;
    int height;
    std::vector<std::vector<std::vector<int>>> pixels;

public:
    PPMReader(const std::string& filename);

    void printImageInfo() override;
    void printMostFrequentColor() override;
    int calculateNumberOfUniqueColors() override;

};

#endif