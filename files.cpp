#include "files.h"

//File functions
File::File(std::string new_title, std::string new_absolute_path, std::string new_short_description) : title(new_title), absolute_path(new_absolute_path), short_description(new_short_description) {}
std::string File::get_title() { return title; }
void File::set_title(std::string x) { title = x; }
std::string File::get_absolute_path() { return absolute_path; }
void File::set_short_description(std::string x) { short_description = x; }
std::string File::get_short_description() { return short_description; }
void File::set_absolute_path(std::string x) { absolute_path = x; }

//Book functions
Book::Book(std::string new_title, std::string new_abs_path, std::string new_short_description, std::string new_author, int new_edition) : File(new_title, new_abs_path, new_short_description), author(new_author), edition(new_edition) {}
std::string Book::get_author() { return author; }
// std::string Book::get_title() { return title; }
int Book::get_edition() { return edition; }
void Book::read_book(std::ifstream &in)
{
    std::string title = get_title();
    std::string desc = get_short_description();
    std::string path = get_absolute_path();
    getline(in, title, '\n'); //tva greshno li go polzvam(povtarq se nadolu mnogo)
    getline(in, author, '\n');
    in >> edition;
    getline(in, desc, '\n');
    getline(in, path, '\n');
}
void Book::input_book()
{
    std::string desc;
    std::string path;
    std::string title;
    std::cout << "Title : ";
    getline(std::cin, title, '\n');
    set_title(title);
    std::cout << "Author : ";
    getline(std::cin, author, '\n');
    std::cout << "Edition : ";
    std::cin >> edition;
    std::cout << std::endl;

    std::cout << "Short description : ";
    getline(std::cin, desc, '\n');
    set_short_description(desc);
    std::cout << "Absolute path : ";
    getline(std::cin, path, '\n');
    set_absolute_path(path);
}
void Book::write_book(std::ofstream &out)
{
    out << get_title() << std::endl;
    out << author << std::endl;
    out << edition << std::endl;
    out << get_short_description() << std::endl;
    out << get_absolute_path() << std::endl;
}
void Book::print_book()
{
    std::cout << "==================================================================================" << std::endl;
    std::cout << "Title : " << get_title() << std::endl;
    std::cout << "Author : " << author << std::endl;
    std::cout << "Edtion(number) : " << edition << std::endl;
    std::cout << "Short description : " << get_short_description() << std::endl;
    std::cout << "Path : " << get_absolute_path() << std::endl;
}

//Photo functions
Photo::Photo(std::string new_title, std::string new_abs_path, std::string new_short_description, std::string new_location, std::string new_date) : File(new_title, new_abs_path, new_short_description), location(new_location), date(new_date) {}
std::string Photo::get_location() { return location; }
std::string Photo::get_date() { return date; }
// std::string Photo::get_title() { return title; }
void Photo::read_photo(std::ifstream &in)
{
    std::string title = get_title();
    std::string desc = get_short_description();
    std::string path = get_absolute_path();
    getline(in, title, '\n');
    getline(in, location, '\n');
    getline(in, date, '\n');
    getline(in, desc, '\n');
    getline(in, path, '\n');

}
void Photo::input_photo()
{
    std::string title;
    std::string desc;
    std::string path;
    std::cout << "Title : ";
    getline(std::cin, title, '\n');
    set_title(title);
    std::cout << "Location : ";
    getline(std::cin, location, '\n');
    std::cout << "Date : ";
    getline(std::cin, date, '\n');
    std::cout << "Short description : ";
    getline(std::cin, desc, '\n');
    set_short_description(desc);
    std::cout << "Absolute path : ";
    getline(std::cin, path, '\n');
    set_absolute_path(path);
}
void Photo::write_photo(std::ofstream &out)
{
    out << get_title() << std::endl;
    out << location << std::endl;
    out << date << std::endl;
    out << get_short_description() << std::endl;
    out << get_absolute_path() << std::endl;
}
void Photo::print_photo()
{
    std::cout << "==================================================================================" << std::endl;
    std::cout << "Title : " << get_title() << std::endl;
    std::cout << "Location : " << location << std::endl;
    std::cout << "Date : " << date << std::endl;
    std::cout << "Short description : " << get_short_description() << std::endl;
    std::cout << "Path : " << get_absolute_path() << std::endl;
}

//Movie functions
Movie::Movie(std::string new_title, std::string new_abs_path, std::string new_short_description, int new_year_of_release, std::string new_resume, std::string new_duration) : File(new_title, new_abs_path, new_short_description), year_of_release(new_year_of_release), resume(new_resume), duration(new_duration) {}
// std::string Movie::get_title() { return title; }
int Movie::get_year_of_release() { return year_of_release; }
std::string Movie::get_resume() { return resume; }
std::string Movie::get_duration() { return duration; }
void Movie::read_movie(std::ifstream &in)
{
    std::string title = get_title();
    std::string desc = get_short_description();
    std::string path = get_absolute_path();
    getline(in, title, '\n');
    in >> year_of_release;
    getline(in, resume, '\n');
    getline(in, duration, '\n');
    getline(in, desc, '\n');
    getline(in, path, '\n');
}
void Movie::input_movie()
{
    std::string desc;
    std::string path;
    std::string title;
    std::cout << "Title : ";
    getline(std::cin, title, '\n');
    set_title(title);
    std::cout << "Year of release : ";
    std::cin >> year_of_release;
    std::cout << std::endl;
    std::cout << "Resume : ";
    getline(std::cin, resume, '\n');
    std::cout << "Duration : ";
    getline(std::cin, duration, '\n');
    std::cout << "Short description : ";
    getline(std::cin, desc, '\n');
    set_short_description(desc);
    std::cout << "Absolute path : ";
    getline(std::cin, path, '\n');
    set_absolute_path(path);
}
void Movie::write_movie(std::ofstream &out)
{
    out << get_title() << std::endl;
    out << year_of_release << std::endl;
    out << resume << std::endl;
    out << duration << std::endl;
    out << get_short_description() << std::endl;
    out << get_absolute_path() << std::endl;
}
void Movie::print_movie()
{
    std::cout << "==================================================================================" << std::endl;
    std::cout << "Title : " << get_title() << std::endl;
    std::cout << "Year of release : " << year_of_release << std::endl;
    std::cout << "Resume : " << resume << std::endl;
    std::cout << "Duration : " << duration << std::endl;
    std::cout << "Short description : " << get_short_description() << std::endl;
    std::cout << "Path : " << get_absolute_path() << std::endl;
}

//Song functions
Song::Song(std::string new_title, std::string new_abs_path, std::string new_short_description, std::string new_performer, std::string new_album, int new_album_year) : File(new_title, new_abs_path, new_short_description), performer(new_performer), album(new_album), album_year(new_album_year) {}
std::string Song::get_performer() { return performer; }
std::string Song::get_album() { return album; }
// std::string Song::get_title() { return title; }
int Song::get_album_year() { return album_year; }
void Song::read_song(std::ifstream &in)
{
    std::string title = get_title();
    std::string desc = get_short_description();
    std::string path = get_absolute_path();
    getline(in, title, '\n');
    getline(in, performer, '\n');
    getline(in, album, '\n');
    in >> album_year;
    getline(in, path, '\n');
    getline(in, desc, '\n');
}
void Song::input_song()
{
    std::string desc;
    std::string path;
    std::string title;
    std::cout << "Title : ";
    getline(std::cin, title, '\n');
    set_title(title);
    std::cout << "Singer/Band : ";
    getline(std::cin, performer, '\n');
    std::cout << "Album : ";
    getline(std::cin, album, '\n');
    std::cout << "Album's release year : ";
    std::cin >> album_year;
    std::cout << std::endl;
    std::cout << "Short description : ";
    getline(std::cin, desc, '\n');
    set_short_description(desc);
    std::cout << "Absolute path : ";
    getline(std::cin, path, '\n');
    set_absolute_path(path);
}
void Song::write_song(std::ofstream &out)
{
    out << performer << std::endl;
    out << album << std::endl;
    out << get_title() << std::endl;
    out << album_year << std::endl;
    out << get_short_description() << std::endl;
    out << get_absolute_path() << std::endl;
}
void Song::print_song()
{
    std::cout << "==================================================================================" << std::endl;
    std::cout << "Singer/Band : " << performer << std::endl;
    std::cout << "Album : " << album << std::endl;
    std::cout << "Title : " << get_title() << std::endl;
    std::cout << "Year of release : " << album_year << std::endl;
    std::cout << "Short description : " << get_short_description() << std::endl;
    std::cout << "Path : " << get_absolute_path() << std::endl;
}
