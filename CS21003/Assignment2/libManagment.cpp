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
        Book memberBooks[30];
    
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

        //Methods
        void removeBook(Book bookToRemove){
            for (int i=0; i<30; i++){
                if (memberBooks[i].getID() == bookToRemove.getID()){
                    memberBooks[i] = Book();
                }
            }
        }
};

class Library {
    private:
        Book Books[300];
        Member Members[100];
    public:
        void addBook(Book newBook){
            for (int i=0; i<300; i++){
                if (Books[i].getID() == 0){
                    Books[i] = newBook;
                    return;
                }
            }
        }

        void removeBook(Book bookToRemove){
            for (int i=0; i<300; i++){
                if (Books[i].getID() == bookToRemove.getID()){
                    Books[i] = Book();
                    return;
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
            for (int i=0; i<100; i++){
                if (Members[i].getMemberID() == 0){
                    Members[i] = newMember;
                    return;
                }
            }
        }

        void removeMember(Member memberToRemove){
            for (int i=0; i<100; i++){
                if (Members[i].getMemberID() == memberToRemove.getMemberID()){
                    Members[i] = Member();
                    return;
                }
            }
        }

        void displayMembers(){
            for (int i=0; i<100; i++){
                if (Members[i].getMemberID() != 0){
                    cout << "Member ID: " << Members[i].getMemberID() << endl << "Name: " << Members[i].getMemberName() << endl;
                }
            }
        }

        //Borrowing and Returning

        void borrowBook(Book bookToBorrow, Member borrowingMember) {
            if (bookToBorrow.getTitle() != searchByID(bookToBorrow.getID()).getTitle()){
                cout << "Invalid book ID... returning..." << endl;
                return;
            }
            if (borrowingMember.getMemberID() == 0){
                cout << "Invalid member ID... returning..." << endl;
                return;
            }
            if (bookToBorrow.getAvailable()){
                borrowingMember.addBook(bookToBorrow);
                bookToBorrow.setAvailable(false);
                return;
            }
            else {
                cout << "Book unavailable... returning..." << endl;
                return; 
            }
        }

        void returnBook(Book bookToReturn, Member returningMember){
            if (bookToReturn.getTitle() != searchByID(bookToReturn.getID()).getTitle()){
                cout << "Invalid book ID... returning..." << endl;
                return;
            }
            if (returningMember.getMemberID() == 0){
                cout << "Invalid member ID... returning..." << endl;
                return;
            }
            if (bookToReturn.getAvailable()){
                cout << "Book not borrowed... returning..." << endl;
                return;
            }
            else{
                returningMember.removeBook(bookToReturn);
            }
        }

        //File I/O

        
};
