// GifUnfolder.cpp : This function takes a specified animated gif as an argument and splits it into
//                      each of its component frames. It then outputs these frames into the folder
//                      that it's placed in, in png format.
//

#include <iostream>
#include <string>
#include <sstream>
#include <Magick++.h>
#include <iostream>
#include "GifUnfolder.h"

using namespace Magick; 

int main(int argc, char* argv[])
{
    InitializeMagick(*argv);

    std::vector<Magick::Image> frames;
    std::string filename = argv[1];

    readImages(&frames, filename);

    coalesceImages(&frames, frames.begin(), frames.end());

    std::string rawname = filename.substr(0, filename.size()-4);

    for (unsigned int i = 0; i < frames.size(); i++) {
        std::stringstream ss;
        ss << rawname << "_frame" << i << ".png";
        frames[i].write(ss.str());
    }

    return 0;
}