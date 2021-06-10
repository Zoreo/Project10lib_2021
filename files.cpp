#include "files.h"

//File functions
File::File(std::string new_title, std::string new_absolute_path, std::string new_short_description) : title(new_title), absolute_path(new_absolute_path), short_description(new_short_description) {}
std::string File::get_type() { return "File"; }
std::string File::get_title() { return title; }
void File::set_title(std::string x) { title = x; }
std::string File::get_absolute_path() { return absolute_path; }
void File::set_short_description(std::string x) { short_description = x; }
std::string File::get_short_description() { return short_description; }
void File::set_absolute_path(std::string x) { absolute_path = x; }
std::string File::get_total_loc() { return get_absolute_path() + get_title(); }

void File::read_file(std::ifstream &in)
{
    getline(in, title, '\n');
    getline(in, short_description, '\n');
    getline(in, absolute_path, '\n');
    in.ignore();
}
void File::input()
{
    std::cout << "Title : ";
    getline(std::cin, title, '\n');
    std::cout << "Short description : ";
    getline(std::cin, short_description, '\n');
    std::cout << "Path : ";
    getline(std::cin, absolute_path, '\n');
    std::cin.ignore();
}
void File::write_file(std::ofstream &out)
{
    out << title << std::endl;
    out << short_description << std::endl;
    out << absolute_path << std::endl;
}
void File::print()
{
    std::cout << "============== " << get_type() << " ================================================================" << std::endl;
    std::cout << "Title : " << get_title() << std::endl;
    std::cout << "Short description : " << get_short_description() << std::endl;
    std::cout << "Path : " << get_absolute_path()<< std::endl;
} //teq tuka trq gi opravqm, ma mai ne ni trqbvat

//Book functions
Book::Book(std::string new_title, std::string new_abs_path, std::string new_short_description, std::string new_author, std::string new_edition) : File(new_title, new_abs_path, new_short_description), author(new_author), edition(new_edition) {}
std::string Book::get_author() { return author; }
void Book::set_author(std::string x){ author = x;}
std::string Book::get_edition() { return edition; }
void Book::set_edition(std::string x){ author = x;}
std::string Book::get_total_loc() { return get_absolute_path() + get_title() + ".pdf"; }
std::string Book::get_type() { return "Book"; }                                          
void Book::input()
{
    std::string title;
    std::string desc;
    std::string path;
    std::cin.ignore();
    std::cout << "Author : ";
    getline(std::cin, author, '\n');
    std::cout << "Title : ";
    getline(std::cin, title, '\n');
    set_title(title);
    std::cout << "Edition : ";
    getline(std::cin, edition, '\n');
    std::cout << "Short description : ";
    getline(std::cin, desc, '\n');
    set_short_description(desc);
    std::cout << "Absolute path : ";
    getline(std::cin, path, '\n');
    set_absolute_path(path);
    std::cout << std::endl;
}
// std::string Book::get_title() { return title; }
// void Book::read(std::ifstream &in)
// {
//     std::string title;
//     std::string desc;
//     std::string path;
//     getline(in, title, '\n');
//     set_title(title);
//     getline(in, author, '\n');
//     getline(in, edition, '\n');
//     getline(in, desc, '\n');
//     set_short_description(desc);
//     getline(in, path, '\n');
//     set_absolute_path(path);
// }
// void Book::write(std::ofstream &out)
// {
//     out << get_title() << std::endl;
//     out << author << std::endl;
//     out << edition << std::endl;
//     out << get_short_description() << std::endl;
//     out << get_absolute_path() << std::endl;
// }
// void read_file(std::ifstream &in){

void Book::print()
{
    std::cout << "============== " << get_type() << " ================================================================" << std::endl;
    std::cout << "Title : " << get_title() << std::endl;
    std::cout << "Author : " << author << std::endl;
    std::cout << "Edtion : " << edition << std::endl;
    std::cout << "Short description : " << get_short_description() << std::endl;
    std::cout << "Path : " << get_total_loc() << std::endl;
}

//Photo functions
Photo::Photo(std::string new_title, std::string new_abs_path, std::string new_short_description, std::string new_location, std::string new_date) : File(new_title, new_abs_path, new_short_description), location(new_location), date(new_date) {}
std::string Photo::get_location() { return location; }
void Photo::set_location(std::string x) { location = x;}
std::string Photo::get_date() { return date; }
void Photo::set_date(std::string x) { date = x; }
std::string Photo::get_total_loc() { return get_absolute_path() + get_title() + ".png"; } //first change
std::string Photo::get_type() { return "Photo"; }                                         //second change

void Photo::input()
{
    std::string title;
    std::string desc;
    std::string path;
    std::cin.ignore();

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
    std::cout << std::endl;
}
// std::string Photo::get_title() { return title; }
// void Photo::read(std::ifstream &in)
// {
//     std::string title;
//     std::string desc;
//     std::string path;
//     getline(in, title, '\n');
//     set_title(title);
//     getline(in, location, '\n');
//     getline(in, date, '\n');
//     getline(in, desc, '\n');
//     set_short_description(desc);
//     getline(in, path, '\n');
//     set_absolute_path(path);
// }
// void Photo::write(std::ofstream &out)
// {
//     out << get_title() << std::endl;
//     out << location << std::endl;
//     out << date << std::endl;
//     out << get_short_description() << std::endl;
//     out << get_absolute_path() << std::endl;
// }
void Photo::print()
{
    std::cout << "============== " << get_type() << " ================================================================" << std::endl;
    std::cout << "Title : " << get_title() << std::endl;
    std::cout << "Location : " << location << std::endl;
    std::cout << "Date : " << date << std::endl;
    std::cout << "Short description : " << get_short_description() << std::endl;
    std::cout << "Path : " << get_total_loc() << std::endl;
}

//Movie functions
Movie::Movie(std::string new_title, std::string new_abs_path, std::string new_short_description, std::string new_year_of_release, std::string new_resume, std::string new_duration) : File(new_title, new_abs_path, new_short_description), year_of_release(new_year_of_release), resume(new_resume), duration(new_duration) {}
std::string Movie::get_year_of_release() { return year_of_release; }
void Movie::set_year_of_release(std::string x){ year_of_release = x; }
std::string Movie::get_resume() { return resume; }
void Movie::set_resume(std::string x) { resume = x; }
std::string Movie::get_duration() { return duration; }
void Movie::set_duration(std::string x) { duration = x; }
std::string Movie::get_total_loc() { return get_absolute_path() + get_title() + ".mp4"; } //first change
std::string Movie::get_type() { return "Movie"; }                                         //second change
void Movie::input()
{
    std::string desc;
    std::string path;
    std::string title;
    std::cin.ignore();

    std::cout << "Title : ";
    getline(std::cin, title, '\n');
    set_title(title);
    std::cout << "Year of release : ";
    getline(std::cin, year_of_release, '\n');
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
    std::cout << std::endl;
}
// std::string Movie::get_title() { return title; }
// void Movie::read(std::ifstream &in)
// {
//     std::string title;
//     std::string desc;
//     std::string path;
//     getline(in, title, '\n');
//     set_title(title);
//     std::cout << std::endl;
//     getline(in, year_of_release, '\n');
//     getline(in, resume, '\n');
//     getline(in, duration, '\n');
//     getline(in, desc, '\n');
//     set_short_description(desc);
//     std::cout << std::endl;
//     getline(in, path, '\n');
//     set_absolute_path(path);
//     std::cout << std::endl;
// }
// void Movie::write(std::ofstream &out)
// {
//     out << get_title() << std::endl;
//     out << year_of_release << std::endl;
//     out << resume << std::endl;
//     out << duration << std::endl;
//     out << get_short_description() << std::endl;
//     out << get_absolute_path() << std::endl;
// }
void Movie::print()
{
    std::cout << "============== " << get_type() << " ================================================================" << std::endl;
    std::cout << "Title : " << get_title() << std::endl;
    std::cout << "Year of release : " << year_of_release << std::endl;
    std::cout << "Resume : " << resume << std::endl;
    std::cout << "Duration : " << duration << std::endl;
    std::cout << "Short description : " << get_short_description() << std::endl;
    std::cout << "Path : " << get_total_loc() << std::endl;
}

//Song functions
Song::Song(std::string new_title, std::string new_abs_path, std::string new_short_description, std::string new_performer, std::string new_album, std::string new_album_year) : File(new_title, new_abs_path, new_short_description), performer(new_performer), album(new_album), album_year(new_album_year) {}
std::string Song::get_performer() { return performer; }
void Song::set_performer(std::string x) { performer = x;}
std::string Song::get_album() { return album; }
void Song::set_album(std::string x) { album = x;}
std::string Song::get_album_year() { return album_year; }
void Song::set_album_year(std::string x) { album_year = x;}
std::string Song::get_total_loc() { return get_absolute_path() + get_title() + ".mp3"; } //first change
std::string Song::get_type() { return "Song"; }                                          //second change

void Song::input()
{
    std::string desc;
    std::string path;
    std::string title;
    std::cin.ignore();

    std::cout << "Title : ";
    getline(std::cin, title, '\n');
    set_title(title);
    std::cout << "Singer/Band : ";
    getline(std::cin, performer, '\n');
    std::cout << "Album : ";
    getline(std::cin, album, '\n');
    std::cout << "Album's release year : ";
    getline(std::cin, album_year, '\n');
    std::cout << "Short description : ";
    getline(std::cin, desc, '\n');
    set_short_description(desc);
    std::cout << "Absolute path : ";
    getline(std::cin, path, '\n');
    set_absolute_path(path);
    std::cout << std::endl;
}
// std::string Song::get_title() { return title; }
// void Song::read(std::ifstream &in)
// {
//     std::string title;
//     std::string desc;
//     std::string path;
//     getline(in, title, '\n');
//     set_title(title);
//     std::cout << std::endl;
//     getline(in, performer, '\n');
//     getline(in, album, '\n');
//     getline(in, album_year, '\n');
//     getline(in, desc, '\n');
//     set_short_description(desc);
//     std::cout << std::endl;
//     getline(in, path, '\n');
//     set_absolute_path(path);
//     std::cout << std::endl;
// }
// void Song::write(std::ofstream &out)
// {
//     out << get_title() << std::endl;
//     out << performer << std::endl;
//     out << album << std::endl;
//     out << album_year << std::endl;
//     out << get_short_description() << std::endl;
//     out << get_absolute_path() << std::endl;
// }
void Song::print()
{
    std::cout << "============== " << get_type() << " ================================================================" << std::endl;
    std::cout << "Title : " << get_title() << std::endl;
    std::cout << "Singer/Band : " << performer << std::endl;
    std::cout << "Album : " << album << std::endl;
    std::cout << "Year of release : " << album_year << std::endl;
    std::cout << "Short description : " << get_short_description() << std::endl;
    std::cout << "Path : " << get_total_loc() << std::endl;
}
