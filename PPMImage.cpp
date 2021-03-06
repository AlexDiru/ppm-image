#include "PPMImage.h"

namespace PPM {
    PPMImage::PPMImage(int width, int height) : PPMImage::PPMImage(width, height, 0, 0, 0) {

    }

    PPMImage::PPMImage(int width, int height, unsigned char red, unsigned char green, unsigned char blue) {
        Width = width;
        Height = height;
        PixelsR.resize(Width * Height, red);
        PixelsG.resize(Width * Height, green);
        PixelsB.resize(Width * Height, blue);
    }

    void PPMImage::SetPixel(unsigned int x, unsigned int y, unsigned char red, unsigned char green, unsigned char blue) {
        PixelsR[y * Width + x] = red;
        PixelsG[y * Width + x] = green;
        PixelsB[y * Width + x] = blue;
    }

    std::string PPMImage::ToString() const {
        std::stringstream ss;
        ss << "P6 " << Width << " " << Height << " 255 ";

        for (size_t i = 0; i < PixelsR.size(); i++) {
            ss << PixelsR[i] << PixelsG[i] << PixelsB[i];
        }

        return ss.str();
    }

    void PPMImage::SaveToFile(const std::string& file) const {
        std::ofstream f;
        f.open(file);
        f << ToString();
        f.close();
    }
}