#include <iostream>
#include <string>
#include <fstream>

class File
{
private:
    std::string title;
    std::string absolute_path;
    std::string short_description;

public:
    File(){};
    File(std::string title, std::string absolute_path, std::string short_description);
    virtual void read_file();
    virtual void input();
    virtual void write_file();
    virtual void print();
    std::string get_title();
    void set_title(std::string x);
    std::string get_absolute_path();
    void set_absolute_path(std::string x);
    std::string get_short_description();
    void set_short_description(std::string x);
};

class Book : public File
{
private:
    std::string author;
    // std::string title;
    int edition;

public:
    Book(){};
    Book(std::string title, std::string abs_path, std::string short_description, std::string author, int edition);
    void read_book(std::ifstream &in);
    void input_book();
    void write_book(std::ofstream &out);
    void print_book();
    std::string get_author();
    // std::string get_title();
    int get_edition();
};

class Photo : public File
{
private:
    // std::string title;
    std::string location;
    std::string date;

public:
    Photo(){};
    Photo(std::string title, std::string location, std::string date, std::string abs_path, std::string short_description);
    void read_photo(std::ifstream &in);
    void input_photo();
    void write_photo(std::ofstream &out);
    void print_photo();
    // std::string get_title();
    std::string get_location();
    std::string get_date();
};

class Movie : public File
{
private:
    // std::string title;
    int year_of_release;
    std::string resume;
    std::string duration; //change duration to int if needed

public:
    Movie(){};
    Movie(std::string title, std::string abs_path, std::string short_description, int year_of_release, std::string resume, std::string duration);
    void read_movie(std::ifstream &in);
    void input_movie();
    void write_movie(std::ofstream &out);
    void print_movie();
    // std::string get_title();
    int get_year_of_release();
    std::string get_resume();
    std::string get_duration();
};

class Song : public File
{
private:
    std::string performer;
    std::string album;
    // std::string title;
    int album_year;

public:
    Song(){};
    Song(std::string title, std::string new_abs_path, std::string new_short_description, std::string performer, std::string album, int album_year);
    void read_song(std::ifstream &in);
    void input_song();
    void write_song(std::ofstream &out);
    void print_song();
    std::string get_performer();
    std::string get_album();
    // std::string get_title();
    int get_album_year();
};