#include "files.h"

//File functions
File::File(std::string new_title, std::string new_absolute_path, std::string new_short_description) : title(new_title), absolute_path(new_absolute_path), short_description(new_short_description) {}
std::string File::get_type() { return type; }
std::string File::get_title() { return title; }
void File::set_title(std::string x) { title = x; }
std::string File::get_absolute_path() { return absolute_path; }
void File::set_short_description(std::string x) { short_description = x; }
std::string File::get_short_description() { return short_description; }
void File::set_absolute_path(std::string x) { absolute_path = x; }

void File::read_file()
{
    std::cout << "gosho";
}
void File::input()
{
    std::cout << "gosho";
}
void File::write_file()
{
    std::cout << "gosho";
}
void File::print()
{
    std::cout << "gosho";
} //teq tuka trq gi opravqm, ma mai ne ni trqbvat

//Book functions
Book::Book(std::string new_title, std::string new_abs_path, std::string new_short_description, std::string new_author, std::string new_edition) : File(new_title, new_abs_path, new_short_description), author(new_author), edition(new_edition) {}
std::string Book::get_author() { return author; }
// std::string Book::get_title() { return title; }
std::string Book::get_edition() { return edition; }
void Book::read(std::ifstream &in)
{
    std::string title;
    std::string desc;
    std::string path;
    getline(in, title, '\n');
    set_title(title);
    getline(in, author, '\n');
    getline(in, edition, '\n');
    getline(in, desc, '\n');
    set_short_description(desc);
    getline(in, path, '\n');
    set_absolute_path(path);
}
void Book::input()
{
    std::string desc;//fix these
    std::string path;
    std::string title;
    std::cout << std::endl
              << "Author : ";
    getline(std::cin, author, '\n');
    std::cout << "Title : ";
    getline(std::cin, title, '\n');
    set_title(title);
    std::cout << "Edition : ";
    std::cin >> edition;
    std::cout << std::endl;
    std::cout << "Short description : ";
    getline(std::cin, desc, '\n');
    set_short_description(desc);
    std::cout << std::endl
              << "Absolute path : ";
    getline(std::cin, path, '\n');
    set_absolute_path(path);
    std::cout << std::endl;
}
void Book::write(std::ofstream &out)
{
    out << get_title() << std::endl;
    out << author << std::endl;
    out << edition << std::endl;
    out << get_short_description() << std::endl;
    out << get_absolute_path() << std::endl;
}
void Book::print()
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
void Photo::read(std::ifstream &in)
{
    std::string title;
    std::string desc;
    std::string path;
    getline(in, title, '\n');
    set_title(title);
    getline(in, location, '\n');
    getline(in, date, '\n');
    getline(in, desc, '\n');
    set_short_description(desc);
    getline(in, path, '\n');
    set_absolute_path(path);
}
void Photo::input()
{
    std::string title;
    std::string desc;
    std::string path;
    std::cout << "Title : ";
    getline(std::cin, title, '\n');
    set_title(title);
    std::cout << std::endl
              << "Location : ";
    getline(std::cin, location, '\n');
    std::cout << "Date : ";
    getline(std::cin, date, '\n');
    std::cout << "Short description : ";
    getline(std::cin, desc, '\n');
    set_short_description(desc);
    std::cout << std::endl
              << "Absolute path : ";
    getline(std::cin, path, '\n');
    set_absolute_path(path);
    std::cout << std::endl;
}
void Photo::write(std::ofstream &out)
{
    out << get_title() << std::endl;
    out << location << std::endl;
    out << date << std::endl;
    out << get_short_description() << std::endl;
    out << get_absolute_path() << std::endl;
}
void Photo::print()
{
    std::cout << "==================================================================================" << std::endl;
    std::cout << "Title : " << get_title() << std::endl;
    std::cout << "Location : " << location << std::endl;
    std::cout << "Date : " << date << std::endl;
    std::cout << "Short description : " << get_short_description() << std::endl;
    std::cout << "Path : " << get_absolute_path() << std::endl;
}

//Movie functions
Movie::Movie(std::string new_title, std::string new_abs_path, std::string new_short_description, std::string new_year_of_release, std::string new_resume, std::string new_duration) : File(new_title, new_abs_path, new_short_description), year_of_release(new_year_of_release), resume(new_resume), duration(new_duration) {}
// std::string Movie::get_title() { return title; }
std::string Movie::get_year_of_release() { return year_of_release; }
std::string Movie::get_resume() { return resume; }
std::string Movie::get_duration() { return duration; }
void Movie::read(std::ifstream &in)
{
    std::string title;
    std::string desc;
    std::string path;
    getline(in, title, '\n');
    set_title(title);
    std::cout << std::endl;

    getline(in, year_of_release, '\n');
    getline(in, resume, '\n');
    getline(in, duration, '\n');
    getline(in, desc, '\n');
    set_short_description(desc);
    std::cout << std::endl;

    getline(in, path, '\n');
    set_absolute_path(path);
    std::cout << std::endl;
}
void Movie::input()
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
void Movie::write(std::ofstream &out)
{
    out << get_title() << std::endl;
    out << year_of_release << std::endl;
    out << resume << std::endl;
    out << duration << std::endl;
    out << get_short_description() << std::endl;
    out << get_absolute_path() << std::endl;
}
void Movie::print()
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
Song::Song(std::string new_title, std::string new_abs_path, std::string new_short_description, std::string new_performer, std::string new_album, std::string new_album_year) : File(new_title, new_abs_path, new_short_description), performer(new_performer), album(new_album), album_year(new_album_year) {}
std::string Song::get_performer() { return performer; }
std::string Song::get_album() { return album; }
// std::string Song::get_title() { return title; }
std::string Song::get_album_year() { return album_year; }
void Song::read(std::ifstream &in)
{
    std::string title;
    std::string desc;
    std::string path;
    getline(in, title, '\n');
    set_title(title);
    std::cout << std::endl;

    getline(in, performer, '\n');
    getline(in, album, '\n');
    getline(in, album_year, '\n');
    getline(in, desc, '\n');
    set_short_description(desc);
    std::cout << std::endl;

    getline(in, path, '\n');
    set_absolute_path(path);
    std::cout << std::endl;
}
void Song::input()
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
void Song::write(std::ofstream &out)
{
    out << get_title() << std::endl;
    out << performer << std::endl;
    out << album << std::endl;
    out << album_year << std::endl;
    out << get_short_description() << std::endl;
    out << get_absolute_path() << std::endl;
}
void Song::print()
{
    std::cout << "==================================================================================" << std::endl;
    std::cout << "Title : " << get_title() << std::endl;
    std::cout << "Singer/Band : " << performer << std::endl;
    std::cout << "Album : " << album << std::endl;
    std::cout << "Year of release : " << album_year << std::endl;
    std::cout << "Short description : " << get_short_description() << std::endl;
    std::cout << "Path : " << get_absolute_path() << std::endl;
}
