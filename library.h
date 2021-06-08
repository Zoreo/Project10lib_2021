#include "files.h"
#include <typeinfo>
#include <vector>

class Library
{
private:
    std::vector <File *> files;
public:
    Library(std::vector <File *> _files) : files(_files){}
    void add_book();   //done 
    void add_photo();  //done 
    void add_movie();  //done 
    void add_song();  //done 

    void find_file_path();  //done 
    void find_file_title();  //done 
    void find_desc();  //done
    void find_book();  //tf
    void find_photo(); //tf
    void find_movie(); //tf
    void find_song();  //tf

    void info_books();
    void info_photos();
    void info_movies();
    void info_songs();
    void info_all();

    void remove_file(std::string file);  //done
    void move_file();//!!!!!!

    void read_file();   //prolly dont need these
    void close_file();   //prolly dont need these
    void save();   //prolly dont need these  
    void save_as();   //prolly dont need these

    void user_menu();  //done
    void run();        //done
};