#include <iostream>
#include <string>
#include <fstream>

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
        int memberBooks[30] = {0};  //set here to avoid errors
    
    public:
        //Setters
        void setMemberID(int newMemberID){
            memberID = newMemberID;
        }
        void setMemberName(string newMemberName){
            memberName = newMemberName;
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
        Member(int MemberID = 0, string MemberName = "N/A"){

            cout << "Creating object of type Member" << endl;
            setMemberID(MemberID);
            setMemberName(MemberName);
        }

        //Methods
        void removeBook(Book bookToRemove){
            for (int i=0; i<30; i++){
                if (memberBooks[i] == bookToRemove.getID()){
                    memberBooks[i] = 0;
                }
            }
        }

        void addBook(Book newBook){
            int nextID;
            int i = 0;
            while (nextID != 0){
                nextID = memberBooks[i];
                i++;
            }
            memberBooks[i] = newBook.getID();
        }

        void addBookByID(int newBookID){
            for (int i=0; i<30; i++){
                if (memberBooks[i] == 0){
                    memberBooks[i] = newBookID;
                }
            }
        }
};

class Library {
    private:
        Book Books[300];
        Member Members[100];
    public:
        //Setters
        void setBooks(Book newBooks[]){
            for (int i=0; i<300; i++){
                Books[i] = newBooks[i];
            }
        }
        void setMembers(Member newMembers[]){
            for (int i=0; i<100; i++){
                Members[i] = newMembers[i];
            }
        }

        //methods
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
        ////
        //Method which takes a book object and member object, adds the book to the members books list, and changes the books availability to false
        void borrowBook(Book bookToBorrow, Member borrowingMember) {
            //Check if title of book inputted has a valid and matching ID in the libraries system
            if (bookToBorrow.getTitle() != searchByID(bookToBorrow.getID()).getTitle()){
                cout << "Invalid book ID... returning..." << endl;
                return;
            }
            //Check if the member attempting to borrow the book has a valid Member ID
            if (borrowingMember.getMemberID() == 0){
                cout << "Invalid member ID... returning..." << endl;
                return;
            }
            //If the book is available, add the book the the members list of books and set the books availability to false
            if (bookToBorrow.getAvailable()){
                borrowingMember.addBook(bookToBorrow);
                bookToBorrow.setAvailable(false);
                return;
            }
            //If book isn't available, output message to user
            else {
                cout << "Book unavailable... returning..." << endl;
                return; 
            }
        }

        ////
        //Takes a book object and member object and removes the book from the members book list, then sets the books availabiity to true
        void returnBook(Book bookToReturn, Member returningMember){
            //Check if book title matches that of the book with the same id in the system
            if (bookToReturn.getTitle() != searchByID(bookToReturn.getID()).getTitle()){
                cout << "Invalid book ID... returning..." << endl;
                return;
            }
            //Check if the member has a valid ID
            if (returningMember.getMemberID() == 0){
                cout << "Invalid member ID... returning..." << endl;
                return;
            }
            //Check if book being returned has been marked has been withdrawn from the library
            if (bookToReturn.getAvailable()){
                cout << "Book not borrowed... returning..." << endl;
                return;
            }
            //If book has been withdrawn, remove the book from the members book list and set its availability to true
            else{
                returningMember.removeBook(bookToReturn);
                bookToReturn.setAvailable(true);
            }
        }

        //File I/O
        ////
        //Takes a file name as an input, then iterates through each character, dividing each line into
        //seperate words to be assigned to an appropriate variable depending on its position in the
        //file. These variables are then used to initialise a new Member object for each line in the file
        void loadMembers(string fileName){
            //Create an input stream
            ifstream txtFile(fileName);
            string currentLine;
            string currentWord;
            int wordNumber = 0;

            //While there EOF has not been reached
            while (getline(txtFile, currentLine)){
                //reset word counter to 0
                wordNumber = 0;
                //reset variables to default values
                int newMemberID = 0;
                string newMemberName = "0";
                int newMemberBookID[10] = {0};
                //clear the current word
                currentWord.clear();
                //for each character in the current line
                for (int i=0; i<currentLine.length(); i++){
                    //if the current character isn't whitespace, append it to the current word
                    if (currentLine[i] != ' '){
                        currentWord = currentWord + currentLine[i];
                    }
                    //otherwise, move on
                    else {
                        //increment word counter
                        wordNumber++;
                        //if it is the first word in the line, it should be the member ID, so remove the 'M' character from the start and then parse it as an integer
                        if (wordNumber == 1){
                            currentWord.erase(0, 1);
                            newMemberID = stoi(currentWord);
                        }
                        //if it is the second word in the line, it should be the member Name, so just copy the word to the name variable
                        else if (wordNumber == 2){
                            newMemberName = currentWord;
                        }
                        //if it is after the second word, it is one of the book ids to be assigned to the member
                        else if (wordNumber > 2){
                            //for each space in the book id array
                            for (int u=0; u<10; u++){
                                //if the current space is empty, remove the 'B' character and parse the word as an integer
                                if (newMemberBookID[u] == 0){
                                    currentWord.erase(0, 1);
                                    newMemberBookID[u] = stoi(currentWord);
                                    currentWord.clear();
                                    break;
                                }
                            }
                        }
                        currentWord.clear();
                    }
                    
                }
                //Create a new member object, initialised with the id and name variables
                Member newMember = Member(newMemberID, newMemberName);
                //Add the new member to the library system
                addMember(newMember);
                //Add each book ID found to the member's book list
                for (int i=0; i<10; i++){
                    if (newMemberBookID[i] != 0){
                        newMember.addBookByID(newMemberBookID[i]);
                    }
                }
            }
            //close the input stream
            txtFile.close();
        }

        ////
        //Takes a file name as an input, then iterates through each character, dividing each line into
        //seperate words to be assigned to an appropriate variable depending on its position in the
        //file. These variables are then used to initialise a new Book object for each line in the file
        void loadBooks(string fileName){
            //Create an input stream
            ifstream txtFile(fileName);
            string currentLine;
            string currentWord;
            int wordNumber;
            
            //While EOF has not been reached
            while (getline(txtFile, currentLine)){
                //reset variables to default values
                wordNumber = 0;
                int newBookID = 0;
                string newBookName = "N/A";
                string newBookAuthor = "N/A";
                string newBookGenre = "N/A";
                int newBookPageCount = 0;
                bool newAvailability = true;
                currentWord.clear();
                int count = 0;
                //for each character in the line
                for (int i=0; i<currentLine.length()+1; i++){
                    //if the current word is the first word in the line or is after the fourth word in the line
                    if (1 > wordNumber || 3 < wordNumber){
                        //if the current character is whitespace or the end of the line has been reached
                        if (currentLine[i] == ' ' || i == currentLine.length()){
                            //iterate the word counter
                            wordNumber++;
                            //if it is the first word in the line, remove the 'B' character from the ID and parse it to an integer
                            if (wordNumber == 1){
                                currentWord.erase(0, 1);
                                newBookID = stoi(currentWord);
                                currentWord.clear();
                            }
                            //if it is the 5th word in the line it is the page count so just parse it as an integer
                            else if (wordNumber == 5){
                                newBookPageCount = stoi(currentWord);
                                currentWord.clear();
                            }
                            //if it is the 6th word in the line then it is the availability, so if it is '0', change the availability from the default of 'true' to 'false'
                            else if (wordNumber == 6){
                                if (currentWord == "0"){
                                    newAvailability = false;
                                }
                                currentWord.clear();
                            }
                        }
                        //otherwise add the current character to the current word
                        else {
                            currentWord = currentWord + currentLine[i];
                        }
                    }
                    //If it is the second third or fourth word
                    else {
                        //if both '"' marks in the phrase haven't been found
                        if (count != 2){
                            //add the current character to te current word
                            currentWord = currentWord + currentLine[i];
                            //if the current character is a '"' mark, add iterate the counter
                            if (currentLine[i] == '"'){
                                count++;
                            }
                        }
                        //otherwise, if it is the second word in the line, set it to the name variable and reset the counter
                        else if (wordNumber == 1){
                            wordNumber++;
                            newBookName = currentWord;
                            currentWord.clear();
                            count = 0;
                        }
                        //otherwise, if it is the third word in the line, set it to the author variable and reset the counter
                        else if (wordNumber == 2){
                            wordNumber++;
                            newBookAuthor = currentWord;
                            currentWord.clear();
                            count = 0;
                        }
                        //otherwise, if it is the fourth word in the line, set it to the genre variable and reset the counter
                        else if (wordNumber == 3){
                            wordNumber++;
                            newBookGenre = currentWord;
                            currentWord.clear();
                            count = 0;
                        }
                    }
                }
                //print the current variables (for testing)
                cout << newBookID << endl << newBookName << endl << newBookAuthor << endl << newBookGenre << endl << newBookPageCount << endl << newAvailability << endl;

                //initialise a new Book object with the variables found above and add it to the library
                Book newBook = Book(newBookID, newBookName, newBookAuthor, newBookGenre, newBookPageCount, newAvailability);
                addBook(newBook);
            }
            //close the input stream
            txtFile.close();
        }
};

//for testing
int main(){
    //create a new Library object
    Library lib;

    //run the loadBooks() function with the name of the books.txt file as the input
    lib.loadBooks("books.txt");

    //run the loadMembers() function with the name of the members.txt file as the input
    lib.loadMembers("members.txt");

    //run the displayAvailableBooks() function
    lib.displayAvailableBooks();

    //run the displayMembers() function
    lib.displayMembers();

    //quit
    return 0;
}
