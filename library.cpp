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

void Library::userMenu()
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
            std::cin >> arg;
            if (arg == "file")
                find_file_path();
            if (arg == "desc")
                find_desc();
            if (arg == "book")
                find_book();
            if (arg == "photo")
                find_photo();
            if (arg == "movie")
                find_movie();
            if (arg == "son")
                find_song(); //can use map to hide some ifs later on
        }
        if (option == "remove")
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
    userMenu();
}
