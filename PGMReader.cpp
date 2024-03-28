#include "PGMReader.hpp"

PGMReader::PGMReader(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Blad: Nie mozna otworzyc pliku " << filename << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    if (line != "P2" && line != "P5") {
        std::cerr << "Blad: To nie jest poprawny plik PGM" << std::endl;
        return;
    }

    while (std::getline(file, line) && line[0] == '#');

    std::stringstream ss(line);
    ss >> width >> height; 

    pixels.resize(height, std::vector<int>(width, 0)); 

    int maxValue;
    file >> maxValue;

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            file >> pixels[i][j];
        }
    }

    file.close();
}

void PGMReader::printImageInfo() {
    std::cout << "Informacje o obrazie PGM:" << std::endl;
    std::cout << "Szerokosc: " << width << " Wysokosc: " << height << std::endl;
    std::cout << "Liczba pikseli: " << width * height << std::endl;
}

void PGMReader::printMostFrequentColor() {
    std::map<int, int> colorFreq;
    for (const auto& row : pixels) {
        for (int pixel : row) {
            colorFreq[pixel]++;
        }
    }

    int maxFreq = 0;
    int mostFreqColor = -1;
    for (const auto& pair : colorFreq) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            mostFreqColor = pair.first;
        }
    }

    std::cout << "Najczesciej wystepujacy kolor: " << mostFreqColor << " Czestotliwosc: " << maxFreq << std::endl;
}

int PGMReader::calculateNumberOfUniqueColors() {
    std::map<int, bool> uniqueColors;
    for (const auto& row : pixels) {
        for (int pixel : row) {
            uniqueColors[pixel] = true;
        }
    }
    return uniqueColors.size();
}