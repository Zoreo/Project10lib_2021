#include "library.h"

void Library::add_book()
{
    Book *b = new Book();
    b->input();
    files.push_back(b);
}
void Library::add_photo()
{
    Photo *p = new Photo();
    p->input();
    files.push_back(p);
}
void Library::add_movie()
{
    Movie *m = new Movie();
    m->input();
    files.push_back(m);
}
void Library::add_song()
{
    Song *s = new Song();
    s->input();
    files.push_back(s);
}
//File::print() doesn't really work, how do i get data from child classes using parent elements?????????????
void Library::find_file_path()
{
    std::string path;
    getline(std::cin, path, '\n');
    if (path[0] == ' ')
        path.assign(path.substr(1));
    for (int i = 0; i < files.size(); ++i)
    {
        if (files[i]->get_absolute_path() == path)
            files[i]->print();
    }
}
void Library::find_file_title()
{
    std::string title;
    getline(std::cin, title, '\n');
    if (title[0] == ' ')
        title.assign(title.substr(1));
    for (int i = 0; i < files.size(); ++i)
    {
        if (files[i]->get_title() == title)
            files[i]->print();
    }
}
void Library::find_desc()
{
    std::string desc;
    getline(std::cin, desc, '\n');
    for (int i = 0; i < files.size(); ++i)
    {
        if (files[i]->get_short_description().find(desc)) //std::string::find finds substrings/ matching strings
        {
            files[i]->print();
        }
        else
            std::cout << "none found, try again.";
    }
}

//damn that filetype be useless//fix ones below
//need to know how to create separate vectors of each data type(File ----> Book, Photo, Movie, Song)
void Library::find_book()
{
    std::string search; //edition/author
    std::string option; //1 2 3 4/ terry pratchet etc.
    std::cin >> search >> option;
    std::vector<Book *> books;
    for (int i = 0; i < files.size(); i++)
    {
        if (files[i]->get_type() == "book") //&& search == "edition"
        {
            books.push_back(dynamic_cast<Book *>(files[i])); //tuka programata ne znae koe e. kakvo pravq
            for (int i = 0; i < books.size(); i++)
            {
                if (search == "edition" || books[i]->get_edition() == option)
                {
                    books[i]->print();
                }
                if (search == "author" || books[i]->get_author() == option)
                {
                    books[i]->print();
                }
            }
        }
    }
}
void Library::find_photo()
{
    std::string search; //edition/author
    std::string option; //1 2 3 4/ terry pratchet etc.
    std::cin >> search >> option;
    std::vector<Photo *> photos;
    for (int i = 0; i < files.size(); i++)
    {
        if (files[i]->get_type() == "photo") //&& search == "edition"
        {
            photos.push_back(dynamic_cast<Photo *>(files[i])); //tuka programata ne znae koe e. kakvo pravq
            for (int i = 0; i < photos.size(); i++)
            {
                if (search == "location" || photos[i]->get_location() == option)
                {
                    photos[i]->print();
                }
                if (search == "date" || photos[i]->get_date() == option)
                {
                    photos[i]->print();
                }
            }
        }
    }
}
void Library::find_movie()
{
    std::string search; //edition/author
    std::string option; //1 2 3 4/ terry pratchet etc.
    std::cin >> search >> option;
    std::vector<Movie *> movies;
    for (int i = 0; i < files.size(); i++)
    {
        if (files[i]->get_type() == "movie") //&& search == "edition"
        {
            movies.push_back(dynamic_cast<Movie *>(files[i])); //tuka programata ne znae koe e. kakvo pravq
            for (int i = 0; i < movies.size(); i++)
            {
                if (search == "year" || movies[i]->get_year_of_release() == option)
                {
                    movies[i]->print();
                }
                if (search == "resume" || movies[i]->get_resume() == option)
                {
                    movies[i]->print();
                }
                if (search == "duration" || movies[i]->get_duration() == option)
                {
                    movies[i]->print();
                }
            }
        }
    }
}

void Library::find_song()
{
    std::string search; //edition/author
    std::string option; //1 2 3 4/ terry pratchet etc.
    std::cin >> search >> option;
    std::vector<Song *> songs;
    for (int i = 0; i < files.size(); i++)
    {
        if (files[i]->get_type() == "song") //&& search == "edition"
        {
            songs.push_back(dynamic_cast<Song *>(files[i])); //tuka programata ne znae koe e. kakvo pravq
            for (int i = 0; i < songs.size(); i++)
            {
                if (search == "performer" || songs[i]->get_performer() == option)
                {
                    songs[i]->print();
                }
                if (search == "album" || songs[i]->get_album() == option)
                {
                    songs[i]->print();
                }
                if (search == "year" || songs[i]->get_album_year() == option)
                {
                    songs[i]->print();
                }
            }
        }
    }
}
//File::print() doesn't really work, how do i get data from child classes using parent elements?????????????(same as above)
void Library::info_books()
{
    for (int i = 0; i < files.size(); i++)
    {
        if (files[i]->get_type() == "book")
        {
            files[i]->print();
        }
    }
}

void Library::info_photos()
{
    for (int i = 0; i < files.size(); i++)
    {
        if (files[i]->get_type() == "photo")
        {
            files[i]->print();
        }
    }
}
void Library::info_movies()
{
    for (int i = 0; i < files.size(); i++)
    {
        if (files[i]->get_type() == "movie")
        {
            files[i]->print();
        }
    }
}
void Library::info_songs()
{
    for (int i = 0; i < files.size(); i++)
    {
        if (files[i]->get_type() == "song")
        {
            files[i]->print();
        }
    }
}
void Library::info_all()
{
    for (int i = 0; i < files.size(); i++)
    {
        files[i]->print();
    }
}

void Library::remove_file(){ //idk if we need the string to be in here
    std::string file;
    getline(std::cin, file, '\n');
    for (int i = 0; i < files.size(); i++)
    {
        if (file == files[i]->get_title() || file == files[i]->get_absolute_path())
        {
            files.erase(files.begin() + i - 1);
        }
    }
    files.resize(files.size() - 1); //might not need this
}

void Library::move_file(){
    std::string old_file;
    std::string new_file;
    getline(std::cin, old_file, '\n');
    std::cout << "Where do you want to move that file to: ";
    getline(std::cin, new_file, '\n');
    //need to copy each component first and then remove_file()
}

void Library::read_file(){
    std::cout << "gosho";
}
void Library::save(){
    std::cout << "gosho";
}

void Library::save_as(){
    std::cout << "gosho";
}

void Library::user_menu()
{
    std::string option;
    while (true)
    {
        std::cout << "> ";
        std::cin >> option;
        if (option == "add")
        {
            std::string arg1;
            std::cin >> arg1;
            if (arg1 == "book")
            {
                add_book();
                std::cout << "Book added.\n";
            }
            if (arg1 == "photo")
            {
                add_photo();
                std::cout << "Photo added.\n";
            }
            if (arg1 == "movie")
            {
                add_movie();
                std::cout << "Movie added.\n";
            }
            if (arg1 == "song")
            {
                add_song();
                std::cout << "Song added.";
            }
        }
        if (option == "find")
        {
            std::string arg;
            std::string arg2;
            std::cin >> arg;
            if (arg == "file")
                std::cin >> arg2;
            if (arg2 == "path")
            {
                find_file_path();
            }
            if (arg2 == "title")
            {
                find_file_title();
            }
            if (arg == "desc")
                find_desc();
            if (arg == "book")
                find_book();
            if (arg == "photo")
                find_photo();
            if (arg == "movie")
                find_movie();
            if (arg == "song")
                find_song(); //can use map to hide some ifs later on
        }
        if (option == "remove") // remove ivan.txt
        {
            remove_file();
        }
        if (option == "info")
        {
            std::string arg;
            std::cin >> arg;
            if (arg == "books")
                info_books();
            if (arg == "photos")
                info_photos();
            if (arg == "movies")
                info_movies();
            if (arg == "songs")
                info_songs();
            if (arg == "")
                info_all();
            else
                std::cout << "Wrong input, enter h for help\n";
        }
        if (option == "move")
        {
            move_file();
        }
        else if (option == "open")
        {
            read_file();
        }
        else if (option == "close")
        {
            files.clear();
            std::cout << "Successfully closed "; // << session.getBookFile() << std::endl; //tf is that
        }
        else if (option == "save")
        {
            save();
        }
        else if (option == "saveas")
        {
            save_as();
        }
        else if (option == "h")
        {
            std::cout << "The following commands are supported:\n";
            std::cout << "--------------------------------------General options------------------------------------------\n";
            std::cout << "open <file>:                              opens <file>\n";
            std::cout << "close:                                    closes currently opened file\n";
            std::cout << "save:                                     saves the currently open file\n";
            std::cout << "saveas <file>:                            saves the currently open file in <file>\n";
            std::cout << "help:                                     prints this information\n";
            std::cout << "exit:                                     exits the program\n";
            std::cout << "--------------------------------------Program options------------------------------------------\n";
            std::cout << "add <option>:                             adds a book/song/movie/photo\n";
            std::cout << "find file <option>:                       finds and prints a file (path/abs_path)\n";
            std::cout << "find <option> <option_string>:            finds and prints all files of specified type(book/song/movie/photo) and selected option";
            std::cout << "find description <string>:                finds files with descriptions that the <string> partially matches at least";
            std::cout << "remove <path>:                            removes a file by path";
            std::cout << "info <option>:                            shows info on wanted type of files(all/books/songs/movies)\n";
            std::cout << "books all:                                shows all the books available\n";
            std::cout << "files sort <option> [asc | desc]:         sorts listed files(books/photos/songs/movies) by a criteria in ascending or descending order\n";
            std::cout << "move file:                                moves a chosen file to a chosen location";
        }
    }
}
void Library::run()
{
    user_menu();
}
