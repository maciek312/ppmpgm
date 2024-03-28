#include "PPMReader.hpp"

PPMReader::PPMReader(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Blad: Nie mozna otworzyc pliku " << filename << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); 
    if (line != "P3" and line !="P6") {
        std::cerr << "Blad: To nie jest poprawny plik PPM" << std::endl;
        return;
    }

    
    while (getline(file, line) && line[0] == '#');

    std::stringstream ss(line);
    ss >> width >> height;

    pixels.resize(height, std::vector<std::vector<int>>(width, std::vector<int>(3, 0)));

    int maxValue;
    file >> maxValue;

   
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            for (int k = 0; k < 3; ++k) {
                file >> pixels[i][j][k];
            }
        }
    }

    file.close();
}

void PPMReader::printImageInfo() {
    std::cout << "Informacje o obrazie PPM:" << std::endl;
    std::cout << "Szerokosc: " << width << " Wysokosc: " << height << std::endl;
    std::cout << "Liczba pikseli: " << width * height << std::endl;
}

void PPMReader::printMostFrequentColor() {
    std::map<std::vector<int>, int> colorFreq;
    for (const auto& row : pixels) {
        for (const auto& pixel : row) {
            colorFreq[pixel]++;
        }
    }

    int maxFreq = 0;
    std::vector<int> mostFreqColor(3, -1);
    for (const auto& pair : colorFreq) {
        if (pair.second > maxFreq) {
            maxFreq = pair.second;
            mostFreqColor = pair.first;
        }
    }

    std::cout << "Najczesciej wystepujacy kolor: (";
    for (int i = 0; i < 3; ++i) {
        std::cout << mostFreqColor[i];
        if (i < 2) std::cout << ", ";
    }
    std::cout << ") Czestotliwosc: " << maxFreq << std::endl;
}

int PPMReader::calculateNumberOfUniqueColors() {
    std::map<std::vector<int>, bool> uniqueColors;
    for (const auto& row : pixels) {
        for (const auto& pixel : row) {
            uniqueColors[pixel] = true;
        }
    }
    return uniqueColors.size();
}