/*
*****************************************************************************
						  Milestone - #1
Full Name     : Ngoc Diem Thy Nguyen
Student ID#   : 105310221
Email         : nnguyen90@myseneca.ca
Section       : NFF
Completed date: Nov 08, 2022
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
*****************************************************************************
*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H

namespace sdds
{
	const int MAX_NO_OF_ITEMS = 10;
	const int MAX_NAME_LEN = 50;

	class MenuItem
	{
		char m_content[MAX_NAME_LEN + 1];

		MenuItem();
		MenuItem(const char* title);
		MenuItem(const MenuItem& menuitem) = delete;
		std::ostream& display(std::ostream& os) const;
		MenuItem& operator=(const MenuItem& menuitem) = delete;
		friend class Menu;
	};

	class Menu
	{
		char m_title[MAX_NAME_LEN + 1];
		MenuItem m_item[MAX_NO_OF_ITEMS]{};
		int m_inde;
		int m_num;
	public:
		Menu();
		Menu(const char* title, int inde = 0);
		Menu(const Menu& menu) = delete;
		Menu& operator=(const Menu& menu) = delete ;
		Menu& operator=(const char* title);
		Menu& operator<<(const char* title);
		explicit operator bool() const;
		operator int() const;
		void setEmpty();
		bool isEmpty() const;
		void display() const;
		void add(const char* title);
		int run() const;
		void clear();
		bool isValid(const char* title) const;
	};
}

#endif // !SDDS_MENU_H
