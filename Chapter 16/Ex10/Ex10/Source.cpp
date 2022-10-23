#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

//-------------------------------------------------------------------------------------------------
struct Review {
	std::string title;
	int rating;
	int price;
};
//-------------------------------------------------------------------------------------------------
bool operator<(const Review& r1, const Review& r2);
bool FillReview(Review& rr);
void ShowReview(const shared_ptr<Review>& rr);
bool sortByTitle(shared_ptr<Review> p1, shared_ptr<Review> p2);
bool sortByRating(shared_ptr<Review> p1, shared_ptr<Review> p2);
bool sortByPrice(shared_ptr<Review> p1, shared_ptr<Review> p2);
void print_menu();
//-------------------------------------------------------------------------------------------------
int main()
{

	vector<shared_ptr<Review>> books;
	Review temp;
	while (FillReview(temp))
	{
		shared_ptr<Review> t(new Review);
		t->title = temp.title;
		t->rating = temp.rating;
		t->price = temp.price;
		books.push_back(t);
	}
		
	print_menu();
	char select;

	while (cin >> select && select != 'q')
	{
		switch (select)
		{
			case 'f':
				cout << "Title reverse output:\nRating:\tTitle\tPrice:" << endl;
				for_each(books.rbegin(), books.rend(), ShowReview);
				cout << std::endl;
				print_menu();
				break;
			case 't':
				cout << "Sort by title:\nRating:\tTitle\tPrice:" << endl;
				sort(books.begin(), books.end(), sortByTitle);
				for_each(books.rbegin(), books.rend(), ShowReview);
				cout << std::endl;
				print_menu();
				break;
			case 'r':
				cout << "Sort by rating:\nRating:\tTitle\tPrice:" << endl;
				sort(books.begin(), books.end(), sortByRating);
				for_each(books.rbegin(), books.rend(), ShowReview);
				cout << std::endl;
				cout << std::endl;
				print_menu();
				break;
			case 'p':
				cout << "Sort by price:\nRating:\tTitle\tPrice:" << endl;
				sort(books.begin(), books.end(), sortByPrice);
				for_each(books.rbegin(), books.rend(), ShowReview);
				cout << std::endl;
				print_menu();
				break;
			default:
				cout << "Wrong input\n";
		}
	}

	std::cin.get();
	std::cin.get();
	return 0;
}
//-------------------------------------------------------------------------------------------------
bool operator<(const Review& r1, const Review& r2)
{
	if (r1.title < r2.title)
		return true;
	else if (r1.title == r2.title && r1.rating < r2.rating)
		return true;
	else
		return false;
}
//-------------------------------------------------------------------------------------------------
bool sortByTitle(shared_ptr<Review> p1, shared_ptr<Review> p2)
{
	if (p1->title < p2->title)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//-------------------------------------------------------------------------------------------------
bool sortByRating(shared_ptr<Review> p1, shared_ptr<Review> p2)
{
	if (p1->rating < p2->rating)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool sortByPrice(shared_ptr<Review> p1, shared_ptr<Review> p2)
{
	if (p1->price < p2->price)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//-------------------------------------------------------------------------------------------------
bool FillReview(Review& rr)
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr.title);

	if (rr.title == "quit")
	{
		return false;
	}

	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;

	if (!std::cin)
	{
		return false;
	}

	std::cout << "Enter book price: ";
	std::cin >> rr.price;

	if (!std::cin)
	{
		return false;
	}

	// Избавиться от остальной части строки ввода 
	while (std::cin.get() != '\n')
	{
		continue;
	}
	cout << endl;
	return true;
}
//-------------------------------------------------------------------------------------------------
void ShowReview(const shared_ptr<Review>& rr)
{
	std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}
//-------------------------------------------------------------------------------------------------
void print_menu()
{
	cout << "Please select the sort" << endl;
	cout << "t sort by title	r sort by rating" << endl;
	cout << "p sort by price	f sort by title reverse" << endl;
	cout << "q to quit" << endl;
}