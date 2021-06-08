#include "files.h"
#include <vector>

class Library
{
private:
    std::vector <File *> files;
public:
    Library::Library(std::vector <File *> _files) : files(_files){}
    void add_book();
    void add_photo();
    void add_movie();
    void add_song(); //done 

    void find_file_path();
    void find_desc();
    void find_book();
    void find_photo();
    void find_movie();
    void find_song();

    void info_books();
    void info_photos();
    void info_movies();
    void info_songs();
    void info_all();

    void remove_file();
    //basic
    void move_file();
    void read_file();
    void close_file();
    void save();
    void save_as();


    void userMenu();
    void run();
};