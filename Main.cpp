
#include <random>
#include <iostream>

#include "PPMImage.h"


    
int main(){
    std::default_random_engine rng(1);
    std::uniform_int_distribution<int> rng_dist(0, 255);

    auto image = PPM::PPMImage(512, 512);

    for(int y=512;y--;){
        for(int x=512;x--;) {
            int red = rng_dist(rng);
            int green = rng_dist(rng);
            int blue = rng_dist(rng);
            image.SetPixel(x, y, red, green, blue);
        }
    }

    image.SaveToFile("image.ppm");
    return 0;
}