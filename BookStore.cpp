#include<iostream>
#include<cstring>

using namespace std;

class Book{
	
	private:
	string bookTitle;
	int bookCost, bookStock;
	
public:
	Book(string title,double cost,int stock):bookCost(cost),bookStock(stock)
	{
		bookTitle=title;
	}
	
	~Book()
	{
		
	}

	void dispBookDetails()
	{
		cout<<"Title:"<<bookTitle<<endl;
		cout<<"Cost:"<<bookCost<<endl;
		cout<<"Stock:"<<bookStock<<endl;
		cout<<"-----------------------------------"<<endl;
	}

	bool searchForBook(string title)
	{
		char ch;
		bool status=false;
		if(title==bookTitle)
			status=true;
		return status;
	}
	
	void updateStock(int stock){
		bookStock+=stock;
	}
};

class BookCountSynth{
	public:
	static int bookCount;
	//bookCount=-1;
};
int  BookCountSynth::bookCount=-1;
class BookStore{
	private:
	string title;
	int cost, stock;
	Book *b[4];
	
	
	//Adding Books to The Book Store
	public:
	void AddBook(){
		
		int sfbFlag=0;
		//
		BookCountSynth::bookCount++;
		
		if(BookCountSynth::bookCount==4) cout<<"BookStore full"<<endl;
		
		else{
			cout<<"Enter the name of the book"<<endl;
			cin>>title;
			cout<<"Enter cost"<<endl;
			cin>>cost;
			cout<<"Enter stock"<<endl;
			cin>>stock;
			
		  	if(BookCountSynth::bookCount==0){
				b[BookCountSynth::bookCount]=new Book(title,cost,stock);
			}
		
			else{
				int i;
				for(i=0;i<BookCountSynth::bookCount;i++){				
					if(b[i]->searchForBook(title)==true){
					 sfbFlag=1;
					 break;
					}
					BookCountSynth::bookCount--;
				}
				if(sfbFlag==1){
					b[i]->updateStock(stock);
				    cout<<"Book with title: "<<title<<" already present. Stock updated to"<<stock<<endl;
				}
				else b[BookCountSynth::bookCount]=new Book(title,cost,stock);
				
			}
		}
	}
		
	
	void DispBook(){
		
	} 
	void SearchBook(){
		
	}
};

int main(){
	
	int choice;
	
	BookStore BS;
	while(1){
	
	cout<<"Enter your choice\n1.\tAdd a Book\n \n2.\tDisplay the Book details\n3.\tSearch a Book for the required Title and Stock"<<endl;
	cin>>choice;
	
	switch(choice){
		case 1:
			BS.AddBook();
			break;
		case 2:
			break;
		case 3:
			break;
		default:
			cout<<"Wrong Choice"<<endl;
	}
}
	return 0;
}
