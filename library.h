#include "files.h"
#include <typeinfo>
#include <vector>

class Library
{
private:
    std::vector <File *> files;
    std::string file_name = "files.txt";
public:
    Library(std::vector <File *> _files) : files(_files){}
    void add_book();   //done 
    void add_photo();  //done 
    void add_movie();  //done 
    void add_song();  //done 

    std::string get_file_name();
    void copy_files_to_file(std::string file_name);//praim na .txt da pazi veche dobavenite
    void read_files_from_file(std::ifstream& file_name);//chete ot tuka i gi dobavq v nachaloto za da ne trqbwa da dobavqme edin fail 48 pyti    

    void find_file_path();  //done 
    void find_file_title();  //done 
    void find_desc();  //done
    void find_book();  //done
    void find_photo(); //done
    void find_movie(); //done
    void find_song();  //donenew_file_name

    void info();
    void info_books(); //done
    void info_photos();//done
    void info_movies();//done
    void info_songs(); //done
    void info_all();   //done

    void remove_file();  //done
    void move_file();    //done

    void read_file();    //prolly dont need these
    void close_file();   //prolly dont need these
    void save();         //prolly dont need these  
    void save_as();      //prolly dont need these

    void user_menu();  //done
    void run();        //done
};