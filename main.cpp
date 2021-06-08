#include "library.h"

int main(){
    std::vector <File *> files;
    Library library(files);
    library.run();
    return 0;
}