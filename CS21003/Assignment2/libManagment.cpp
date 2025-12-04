#include <iostream>
#include <string>

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
        Book(int ID = 0, string Title = "N/A", string Author = "N/A", string Genre = "N/A", int PageCount = 0, bool Available = false){
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
        int memberID;
        string memberName;
        Book memberBooks[];
    
    public:
        //Setters
        void setMemberID(int newMemberID){
            memberID = newMemberID;
        }
        void setMemberName(string newMemberName){
            memberName = newMemberName;
        }
        void addBook(Book newBook){
            int nextID;
            int i = 0;
            while (nextID != 0){
                nextID = memberBooks[i].getID();
                i++;
            }
            memberBooks[i] = newBook;
        }

        //Getters
        int getMemberID(){
            return memberID;
        }
        string getMemberName(){
            return memberName;
        }
        Book getBooks(){
            return *memberBooks;
        }

        //Constructors
        Member(int MemberID = 0, string MemberName = "N/A", Book defaultBook = Book()){
            cout << "Creating object of type Member" << endl;
            setMemberID(MemberID);
            setMemberName(MemberName);
            addBook(defaultBook);
        }
};

class Library {
    private:
        Book Books[300];
        Member Members[100];
    public:
        void addBook(Book newBook){
            int nextID;
            int i = 0;
            while (nextID != 0){
                nextID = Books[i].getID();
                i++;
            }
            Books[i] = newBook;
        }

        void removeBook(Book bookToRemove){
            bool done=false;
            int i = 0;
            while (done==false){
                if (Books[i].getID() == bookToRemove.getID()){
                    Books[i] = Book();
                }
            }
        }

        Book searchByTitle(string titleSearch){
            for (int i=0; i<300; i++){
                if (Books[i].getTitle() == titleSearch){
                    return Books[i];
                }
            }
        }

        Book searchByID(int idSearch){
            for (int i=0; i<300; i++){
                if (Books[i].getID() == idSearch){
                    return Books[i];
                }
            }
        }
        
        void displayAvailableBooks(){
            for (int i=0; i<300; i++){
                if (Books[i].getAvailable()){
                    cout << "ID: " << Books[i].getID() << endl << "Title: " << Books[i].getTitle() << endl << "Author: " << Books[i].getAuthor() << endl << "Genre: " << Books[i].getGenre() << endl << "Page Count: " << Books[i].getPageCount() << endl << endl;
                }
            }
        }

        void addMember(Member newMember){

        }

        void removeMember(Member memberToRemove){

        }

        void displayMembers(){

        }
};
