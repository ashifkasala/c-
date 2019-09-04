//use of constructor and dynamic memory management
#include<iostream>
using namespace std;


class BookStore
{
	Book * book[4];
	int cost;
	char* title;
	char choice;
	int  stock;
				class Book
				{
				private:
					char *BookTitle;
					double BookCost;
					int BookStock;
				public:
					Book(char *title,double cost,int stock):BookTitle(new char[strlen(title)+1]),BookCost(cost),BookStock(stock)
					{
						strcpy(BookTitle,title);
					}
					
					~Book()
					{
						if(BookTitle != NULL)
						delete [] BookTitle;
					}
					void setBookStock(int stock)
						{
							BookStock = stock;
						}
					char* getBookTitle()
						{
							return BookTitle;
						}
						int getBookStock()
						{
							return BookStock;
						}
						int getBookCost()
						{
							return BookCost;
						}
						
						
				
				
				};

	public:
		~BookStore()
		{
			delete [] book;
		}
	void addBook()
	{
		cout<<"enter the book name,cost and stock"<<endl;
		cin>>title>>cost>>stock;
		if(isBookAvailable(title))
			{
				cout<<"Book is already present .Do you want to add some stock?";
				cin>>choice;
				
				if(choice == 'y')
					{
						for(int i=0;i<4;i++)
						{
							if(book[i]!=NULL && strcmp(book[i]->BookTitle,title)==0)
									book[i]->setBookStock(stock);
						}		
					}
					
					
						
			}
			else
				{
					cout<<"New book is added"<<endl;
						for(int i=0;i<4;i++)
						{
							if(book[i]!=NULL)
									book[i] = new Book(title,cost,stock);
						}
					
				}
							
		
		
	}

	
	void dispBookDetails()
	{
		for(int i=0;i<4;i++)
		{
		    if(book[i]!=NULL)
		    	{
				
				cout<<"Title:"<<book[i]->getBookTitle()<<endl;
				cout<<"Cost:"<<book[i]->getBookCost()<<endl;
				cout<<"Stock:"<<book[i]->getBookStock()<<endl;
				cout<<"-----------------------------------"<<endl;
				}
		}
	}		
	
	

	bool searchForBook(char title[25],int stock)
	{
		char ch;
		bool status=false;
		for(int i=0;i<4;i++)
			{
					
				if(strcmp(book[i]->getBookTitle(),title)==0)
				{
					status=true;
					if(stock<=book[i]->getBookStock())
					{
						cout<<"Book available with sufficient stock"<<endl;
						cout<<"Billing Cost:"<<((book[i]->getBookCost())*stock)<<endl;
						cout<<"enter y to purchase"<<endl;
						cin>>ch;
						if(ch=='y')
						{
							book[i]->setBookStock(book[i]->getBookStock() - stock);
							dispBookDetails();
						}
						
					}
					else
						cout<<"Book available but stock is insufficient"<<endl;
				}
				return status;
			}
	}
	bool isBookAvailable(const char* title)
	{
		for(int i=0;i<4;i++)
		{
			if(book[i]!=NULL && strcmp(book[i]->BookTitle,title)==0)
				return true;
		}
		return false;
	}
	void stop()
		{
			delete [] book;
		}
	
};

int main()
{
	int i;
	BookStore b1; 
	while(1)
		{
			cout<<"Enter 1: To add book 2:dispBookDetails 3: searchForBook 4: to exit"<<endl;
			cin>>i;
			switch(i)
				{
					case 1 :
							b1.addBook();
							break;
					case 2 : b1.dispBookDetails();
							break;
					case 3 : b1.searchForBook();
							break;
					case 4 : b1.stop();
							
					exit(0) ;
					 
				}
		}
		
	



}


