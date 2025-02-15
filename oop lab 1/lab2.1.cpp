#include <iostream>
#include <string>
using namespace std;
struct Book{
    string title;
    string author;
    int year;
};

int main(){
    int n,filterYear;
    cout<<"Enter the number of books: ";
    cin>>n;
    Book* books=new Book[n];

    for(int i=0;i <n;i++){
        cout<<"Enter title,author,and year of book "<<i+1<<endl;
        cin.ignore();
        getline(cin,books[i].title);
        getline(cin,books[i].author);
        cin>>books[i].year;
    }

    cout<<"Enter the year to filter books: ";
    cin>>filterYear;

    cout<<"Books published after "<<filterYear<<endl;
    for(int i=0;i<n;i++){
        if(books[i].year>filterYear){
            cout<<books[i].title<<" by "<<books[i].author<<books[i].year<<endl;
        }
    }

    delete[]books;
    return 0;
}
