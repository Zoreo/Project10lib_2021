#include <iostream>
#include <string>
#include <fstream>

class File
{
private:
    // std::string type = "File";
    std::string title;
    std::string absolute_path;
    std::string short_description;

public:
    File(){};
    File(std::string title, std::string absolute_path, std::string short_description);
    virtual void read_file(std::ifstream &in);
    virtual void input();
    virtual void write_file(std::ofstream &out);
    virtual void print();
    virtual std::string get_type();
    virtual std::string get_title();
    void set_title(std::string x);
    virtual std::string get_absolute_path();
    void set_absolute_path(std::string x);
    virtual std::string get_short_description();
    void set_short_description(std::string x);
    virtual std::string get_total_loc();
};

class Book : public File
{
private:
    std::string author;
    std::string edition;
    // std::string type = "Book";
    // std::string title;
    // std::string total_loc = get_absolute_path() + get_title() + ".pdf";

public:
    Book(){};
    Book(std::string title, std::string abs_path, std::string short_description, std::string author, std::string edition);
    void input();
    void print();
    std::string get_author();
    void set_author(std::string x);
    std::string get_edition();
    void set_edition(std::string x);
    std::string get_type();
    void set_type();
    std::string get_total_loc();
    // void read(std::ifstream &in);
    // void write(std::ofstream &out);
    // std::string get_title();
};

class Photo : public File
{
private:
    // std::string type = "Photo";
    // std::string title;
    std::string location;
    std::string date;
    std::string total_loc = get_absolute_path() + get_title() + ".png";

public:
    Photo(){};
    Photo(std::string title, std::string location, std::string date, std::string abs_path, std::string short_description);
    void input();
    void print();
    // virtual void read_file(std::ifstream &in);
    // virtual void write_file(std::ofstream &out);
    std::string get_location();
    void set_location(std::string x);
    std::string get_date();
    void set_date(std::string x);
    std::string get_type();
    void set_type();
    std::string get_total_loc();

    // std::string get_title();
    // void write(std::ofstream &out);
    // void read(std::ifstream &in);
};

class Movie : public File
{
private:
    // std::string type = "Movie";
    // std::string title;
    std::string year_of_release;
    std::string resume;
    std::string duration; //change duration to int if needed
    std::string total_loc = get_absolute_path() + get_title() + ".mp4";

public:
    Movie(){};
    Movie(std::string title, std::string abs_path, std::string short_description, std::string year_of_release, std::string resume, std::string duration);
    void input();
    void print();
    std::string get_year_of_release();
    void set_year_of_release(std::string x);
    std::string get_resume();
    void set_resume(std::string x);
    std::string get_duration();
    void set_duration(std::string x);
    std::string get_type();
    std::string get_total_loc();
    // std::string get_title();
    // void read(std::ifstream &in);
    // void write(std::ofstream &out);
};

class Song : public File
{
private:
    // std::string type = "Song";
    std::string performer;
    std::string album;
    // std::string title;
    std::string album_year;
    std::string total_loc = get_absolute_path() + get_title() + ".mp3";

public:
    Song(){};
    Song(std::string title, std::string new_abs_path, std::string new_short_description, std::string performer, std::string album, std::string album_year);
    void input();
    void print();
    std::string get_performer();
    void set_performer(std::string x);
    std::string get_album();
    void set_album(std::string x);
    std::string get_album_year();
    void set_album_year(std::string x);
    std::string get_total_loc();
    std::string get_type();
    // std::string get_title();
    // void read(std::ifstream &in);
    // void write(std::ofstream &out);
};