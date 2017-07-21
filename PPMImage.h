#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

namespace PPM {
    class PPMImage {

        unsigned int Width;
        unsigned int Height;
        std::vector<unsigned char> PixelsR;
        std::vector<unsigned char> PixelsG;
        std::vector<unsigned char> PixelsB;
    public:
        PPMImage() = delete;
        PPMImage(int width, int height);
        void SetPixel(unsigned int x, unsigned int y, unsigned char red, unsigned char green, unsigned char blue);
        std::string ToString() const;
        void SaveToFile(const std::string& file) const;
    };
}