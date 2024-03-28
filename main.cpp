#include <iostream>
#include "PGMReader.hpp"
#include "PPMReader.hpp"

int main() {
    PPMReader ppmReader1("x1.ppm");
    PGMReader pgmReader1("PGM.pgm");
    PPMReader ppmReader2("prague.ppm");
    PGMReader pgmReader2("lena.pgm");


    ImageReader* ppmImage1 = &ppmReader1;
    ImageReader* pgmImage1 = &pgmReader1;
    ImageReader* ppmImage2 = &ppmReader2;
    ImageReader* pgmImage2 = &pgmReader2;

    ppmImage1->printImageInfo();
    std::cout << "Liczba unikalnych kolorow w obrazie PPM1: " << ppmImage1->calculateNumberOfUniqueColors() << std::endl;
    ppmImage1->printMostFrequentColor();
    std::cout << std::endl;

    pgmImage1->printImageInfo();
    std::cout << "Liczba unikalnych kolorow w obrazie PGM1: " << pgmImage1->calculateNumberOfUniqueColors() << std::endl;
    pgmImage1->printMostFrequentColor();
    std::cout << std::endl;

    ppmImage2->printImageInfo();
    std::cout << "Liczba unikalnych kolorow w obrazie PPM2: " << ppmImage2->calculateNumberOfUniqueColors() << std::endl;
    ppmImage2->printMostFrequentColor();
    std::cout << std::endl;


    pgmImage2->printImageInfo();
    std::cout << "Liczba unikalnych kolorow w obrazie PGM2: " << pgmImage2->calculateNumberOfUniqueColors() << std::endl;
    pgmImage2->printMostFrequentColor();

    return 0;
}
