#include <string>
#include "lib/id3v2parser.h"

int main(int argc, char **argv) {
    std::string filename;
    bool all_frames = false;
    std::vector<std::string> frames;
    for (size_t i = 1; i < argc; ++i) {
        char *term = argv[i];
        if (strcmp(term, "--file=") == 0) {
            filename = argv[++i];
        } else if (strcmp(term, "--all") == 0) {
            all_frames = true;
        } else {
            frames.emplace_back(term);
        }
    }

    Id3v2Parser parser(filename);
    Id3v2 tag = parser.Parse();
    if (all_frames) {
        tag.PrintAllFrames();
    } else {
        for (size_t i = 0; i < frames.size(); ++i) {
            tag.PrintFrame(frames[i]);
        }
    }
}