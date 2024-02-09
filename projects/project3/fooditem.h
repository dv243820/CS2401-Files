/*************************************************************************
    This is the record of a FoodItem.
    It includes the FoodItem's name, category, date added and priority
    
    Overloaded operators:
		> and >= compare based on date added
		< and <= compare based on priority
		== makes sure all data fields match
		!= will be true if one or more fields do not match

	Patricia Lindner	September 2022		CS 2401 OU EECS
*************************************************************************/
#include <iostream>
#include <string>
#include "date_new.h"

#ifndef FOODITEM_H
#define FOODITEM_H

class FoodItem{
	public:
		/**
		 * @brief Construct a new Food Item object
		 * 
		 * @param n - name (default "NA")
		 * @param c - category (default "NA")
		 * @param d - date (default 1/1/1970)
		 * @param p - priority (default -1)
		 * @return Date - the value of the added member variable
		 */
		FoodItem(std::string n = "NA", std::string c = "NA", Date d = Date(), int p = -1);

		/**
		 * @brief Get the name member
		 * 
		 * @return std::string - the value of the name member variable
		 */
		std::string get_name()const {return name;}

		/**
		 * @brief Get the category member
		 * 
		 * @return std::string - the value of the category member variable
		 */
        std::string get_category()const {return category;}

		/**
		 * @brief Get the added member
		 * 
		 * @return Date - the value of the added member variable
		 */
		Date get_added()const {return added;}

		/**
		 * @brief Get the priority member
		 * 
		 * @return int - the value of the priority member variable
		 */
		int get_priority()const {return priority;}

		/**
		 * @brief Set the added member
		 * 
		 * @param d - the date you want to set the added member variable to
		 */
		void set_added(Date d) {added = d;}

		/**
		 * @brief Less than operator that compares two FoodItem objects
		 * 		  based on their priority number
		 * 
		 * @param i - a FoodItem to compare to
		 * @return true - my priority is less than i's
		 * @return false - my priority is not less than i's
		 */
		bool operator < (const FoodItem& i)const {return priority < i.priority;}

		/**
		 * @brief Greater than operator that compares two FoodItem objects
		 * 		  based on the date they were added
		 * 
		 * @param i - a FoodItem to compare to
		 * @return true - my added date is after i's
		 * @return false - my added date is not after i's
		 */
		bool operator > (const FoodItem& i)const {return added > i.added;}

		/**
		 * @brief Less than or equal to operator that compares two FoodItem 
		 * 		  objects based on their priority number
		 * 
		 * @param i - a FoodItem to compare to
		 * @return true - my priority is less than or equal to i's
		 * @return false - my priority is not less than or equal to i's
		 */
		bool operator <= (const FoodItem& i)const {return !(priority > i.priority);}

		/**
		 * @brief Greater than or equal to operator that compares two FoodItem 
		 * 		  objects based on the date they were added
		 * 
		 * @param i - a FoodItem to compare to
		 * @return true - my added date is after or equal to i's
		 * @return false - my added date is not after or equal to i's
		 */
		bool operator >= (const FoodItem& i)const {return (added > i.added || added == i.added);}

		/**
		 * @brief Not equal comparison operator that compares two FoodItem objects
		 * 
		 * @param i - a FoodItem to compare to
		 * @return true - the two items have at least one different data field
		 * @return false - the two items have all the same data
		 */
		bool operator != (const FoodItem& i)const {return !(name == i.name && category == i.category && added == i.added && priority == i.priority);}

		/**
		 * @brief Equal comparison operator that compares two FoodItem objects
		 * 
		 * @param i - a FoodItem to compare to
		 * @return true - the two items have all the same data
		 * @return false - the two items have at least one different data field
		 */
		bool operator == (const FoodItem& i)const {return (name == i.name && category == i.category && added == i.added && priority == i.priority);}


		/**
		 * @brief This function reads in the data for a FoodItem.
		 * 		  If the stream passed is cin, the user will be prompted
		 * 		  If the stream passed is not cin, the data will be read in the order:
		 * 			name, category, added date, priority number
		 * 
		 * @param ins - the stream to read data from
		 */
		void input(std::istream& ins);

		/**
		 * @brief This function outputs the data for a FoodItem.
		 * 		  If the stream is cout, labels are put on the data
		 * 		  If the stream is not cout, the data is output one element per line in the format:
		 * 			name, category, added date, priority number
		 * 
		 * @param outs - the stream to write to
		 */
		void output(std::ostream& outs)const;

	private:
		std::string name;
        std::string category;
		Date added;
		int priority;
};


// Input and Output Operators for those who want to use them.

/**
 * @brief >> (input) operator so you can read in FoodItems like:
 * 		  ins >> i
 * 
 * @param ins - an input stream to read from
 * @param i - a FoodItem object to read the data into
 * @return std::istream& - return the stream passed in 
 */
std::istream& operator >> (std::istream& ins, FoodItem& i);

/**
 * @brief << (output) operator so you can output FoodItems like:
 * 		  outs << i
 * 
 * @param outs - an output stream to write to
 * @param i - a FoodItem object to display data about
 * @return std::ostream& - return the stream passed in
 */
std::ostream& operator << (std::ostream& outs, const FoodItem& i);

#endif