#include <iostream>

using namespace std;
class Book {
    private:
        int bookID;
        string title;
        string author;
        string genre;
        int pageCount;
        bool available;

    public:
        //Setters
        void setID(int newID){
            bookID = newID;
        }
        void setTitle(string newTitle){
            title = newTitle;
        }
        void setAuthor(string newAuthor){
            author = newAuthor;
        }
        void setGenre(string newGenre){
            genre = newGenre;
        }
        void setPageCount(int newPageCount){
            pageCount = newPageCount;
        }
        void setAvailable(bool newAvailable){
            available = newAvailable;
        }

        //Getters
        int getID(){
            return bookID;
        }
        string getTitle(){
            return title;
        }
        string getAuthor(){
            return author;
        }
        string getGenre(){
            return genre;
        }
        int getPageCount(){
            return pageCount;
        }
        bool getAvailable(){
            return available;
        }

        //Constructors
        Book(int ID = 0, string Title = "N/A", string Author = "N/A", string Genre = "N/A", int PageCount = 0, bool Available = 0){
            cout << "Creating object of type Book" << endl;
            setID(ID);
            setTitle(Title);
            setAuthor(Author);
            setGenre(Genre);
            setPageCount(PageCount);
            setAvailable(Available);
        }
};

class Member {
    private:
};
