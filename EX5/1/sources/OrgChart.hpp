
/**
 * @file OrgChart.hpp
 * @brief This class describes OrgChart. You can find in this class 2 classes of iterator(const_iterator,iterator)
 * @version 1.0
 * @date 2022-05-25
 * 
 * 
 * AUTHORS: Niv Kotek (Nivk99@gmail.com)
 * 
 * @copyright Coyright (C) 2022
 */


#pragma once
#include <queue>
#include <string>
#include <string.h>
#include <iostream>
#include <vector>
#include <typeinfo>
#include <sstream>

namespace ariel
{
	template<class T=std::string>
	class OrgChart
	{
	private:
		struct Node
		{
			T _value;
			std::vector<Node*>_children;
			uint _level_table;
			Node(const T& value,uint level_table=0):_value(value),_level_table(level_table){}
		};
		
		Node* m_first;
	
	public:

	/** c'tor
	 * @class OrgChart
	 * 
	 * @brief This method builds the class
	 * @return A class-type object
	 */
		OrgChart():m_first(nullptr){}

	/** destructor
	 * @class OrgChart
	 * 
	 * @brief This method deletes the objects of the class
	 * @return Does not return anything
	 */	
		~OrgChart()
		{
			if(m_first!=nullptr)
			{
				kill(m_first);
				delete m_first;
				m_first=nullptr;
			}
		}


	/**
	 * @class OrgChart
	 * 
	 * @brief This function helps to delete the objects of the class
	 * @param head - Pointer to delete
	 * @return  Does not return anything
	 */
		void kill(Node* &head)
		{
			for(auto &children:head->_children)
			{
				kill(children);
				delete children;
			}

		}

	/**
	 * @class OrgChart
	 * 
	 * @brief copy c'tor
	 * @param other - Deep copy object
	 * @return  Does not return anything
	 */
		OrgChart(const OrgChart<T>& other)
		{
			m_first=nullptr;
			this->add_root(other.m_first->_value);
			deep_copying(other.m_first);
		}
	/**
	 * @class OrgChart
	 * 
	 * @brief Method helped to copy c'tor
	 * @param node - Deep copy object
	 * @return  Does not return anything
	 */
		void deep_copying(Node* node)
		{
			for(auto ch: node->_children)
			{
				this->add_sub(node->_value,ch->_value);
				deep_copying(ch);
			}
		}

	/**
	 * @class OrgChart
	 * 
	 * @brief Operator =
	 * @param other - Object to =
	 * @return It's an object
	 */
		OrgChart& operator=(const OrgChart<T>& other)noexcept
		{
			if(this!=&other)
			{
				m_first=nullptr;
				this->add_root(other.m_first->_value);
				deep_copying(other.m_first);
			}
			return *this;

		}
	/**
	 * @class OrgChart
	 * 
	 * @brief Operator =
	 * @param other - Object to =
	 * @return  It's an object
	 */
		OrgChart &operator=( OrgChart<T>&& other )noexcept
		{
			if(this!=&other)
			{
				m_first=nullptr;
				this->add_root(other.m_first->_value);
				deep_copying(other.m_first);
			}
			return *this;
		}
	/**
	 * @class OrgChart
	 * 
	 * @brief move c'tor
	 * @param other - Object to move c'tor
	 * @return  Does not return anything
	 */
		OrgChart (OrgChart&& other )noexcept
		{
			m_first=other.m_first;
			other.m_first=nullptr;
		}

	/**
	 * @class OrgChart
	 * 
	 * @brief This method adds an object to the top of the tree
	 * @param name  Name to add
	 * @return A class-type object
	 */
		OrgChart& add_root(const T& name)
		{
			check_name(name);
			if(m_first==nullptr)
			{
				m_first=new Node(name,0);
			}
			else
			{
				m_first->_value=name;
			}
			return *this;

		}


	/**
	 * @class OrgChart
	 * 
	 * @brief This method adds an object to the top of the tree according to the parent
	 * @param one_person  Father's Name
	 * @param second_person  Name to add
	 * @return A class-type object
	 */
		OrgChart& add_sub (T one_person,T second_person)
		{
			if(m_first==nullptr)
			{
				throw std::runtime_error("Invalid input\n can't add sub before root");
			}
			check_name(one_person);
			check_name(second_person);
			Node* n=m_first;
			 bool bo=true;
			__add_sub(n,one_person,second_person,bo);
			if(bo)
			{
				throw std::runtime_error("Invalid input\n No person's name found");

			}
			return *this;
		}



	/**
	 * @class OrgChart
	 * 
	 * @brief This method helps to add an object according to the parent
	 * @param head Pointer to go through the list
	 * @param one_person  Father's Name
	 * @param second_person  Name to add
	 * @return  Does not return anything
	 */
		void __add_sub (Node* head,T& one_person,T& second_person,bool &bo)
		{
			if(head==nullptr)
			{
				return;
			}
			if(head->_value==one_person)
			{
				head->_children.push_back(new Node(second_person,head->_level_table+1));
				bo=false;
				return;
			}
			for(uint i=0;i<head->_children.size();i++)
			{
				__add_sub(head->_children.at(i),one_person,second_person,bo);
			}

		}	

	/**
	 * @class OrgChart
	 * 
	 * @brief This function helps to check the names in the inputs
	 * @param name Checking the name
	 * @return  Does not return anything
	 */
		static void check_name(const T& name)
		{
			if(typeid(name)==typeid(std::string))
			{
				std::string str;
				std::stringstream ss;  
  				ss << name;  
  				ss >> str; 
				
				if(str.empty())
				{
					throw std::runtime_error("Invalid input\n Must enter a valid string");

				}
				const int minInvalidValue=32;
				const int maxInvalidValue=126;
				for(uint i=0;i<str.size();i++)
				{
					if(str.at(i)<minInvalidValue||str.at(i)>maxInvalidValue)
					{
						throw std::runtime_error("Invalid input\n Must enter a valid string");
					}

				}
			}
			if(typeid(name)==typeid(char))
			{
				std::string str;
				std::stringstream ss;  
  				ss << name;  
  				ss >> str; 
				if(str.empty())
				{
					throw std::runtime_error("Invalid input\n Must enter a valid string");

				}
				
			}

		}


	/**
	 * @class friend OrgChart
	 * 
	 * @brief  This function builds the print of the class - to string
	 * @param out An ostream pointer to chain the names
	 * @param Org_chart Org Chart pointer to go through the listOrgChart
	 * @return An ostream object. To print the list
	 */
		friend std::ostream& operator<<(std::ostream &out,OrgChart &Org_chart)
		{
			//out<<"Organic chart size: "<<Org_chart._size<<"\n";
			print_level_preorder(out,Org_chart.m_first," ");
			return out;
		}


	/**
	 * @class OrgChart
	 * 
	 * @brief Auxiliary function for arranging printable objects
	 * @param out - Pointer to ostream
	 * @param node - Pointer to the current node
	 * @param str -String for stringing lines
	 * @return Does not return anything
	 */
	static void print_level_preorder(std::ostream &out, Node* &node, std::string str)
	{
        std::string temp;
		std::stringstream ss;  
  		ss << node->_value;  
  		ss >> temp; 
        out << str +"("+std::to_string(node->_level_table)+")"+ "---" + temp +"\n";
        str+= "|\t";
        for (auto &children:node->_children) 
		{
            print_level_preorder(out,children, str);
        }

	}

		enum levelType
		{
			beginLevelOrder,
			beginLevelOrderReverse,
			beginLevelPreorder

		};

	/**
	 * @class OrgChart
	 * 
	 * @brief This function sorts the list by level order
	 * @param node  Pointer to the first organ in the list
	 * @param vector_node  Vector insert node objects
	 * @return  Does not return anything
	 */
		static void _level_order(Node *node,std::vector<Node*> &vector_node)
		{
			std::queue<Node*>que;
			que.push(node);
			while (!que.empty())
			{
				Node* no=que.front();
				que.pop();
				vector_node.push_back(no);
				for(uint i=0;i<no->_children.size();i++)
				{
					que.push(no->_children.at(i));

				}	
			}

		}


	/**
	 * @class OrgChart
	 * 
	 * @brief This function sorts the list by reverse level order
	 * @param node Pointer to the first organ in the list
	 * @param vector_node  Vector insert node objects
	 * @return  Does not return anything
	 */
		static void _reverse_level_order(Node* &node,std::vector<Node*> &vector_node)
		{

			std::queue<Node*>que;
			std::vector<Node*> vect;
			que.push(node);

			while (!que.empty())
			{
				Node * no=que.front();
				que.pop();
				vect.push_back(no);
				for(int i=(no->_children.size()-1);i>=0;i--)
				{
					que.push(no->_children.at(uint(i)));

				}	

			}

			for(int i=(vect.size()-1);i>=0;i--)
			{
				vector_node.push_back(vect.at(uint(i)));
			}

		}

	/**
	 * @class OrgChart
	 * 
	 * @brief This function sorts the list by level preorder
	 * @param node Pointer to the first organ in the list
	 * @param vector_node  Vector insert node objects
	 * @return  Does not return anything
	 */
		static void _level_preorder(Node* node,std::vector<Node*> &vector_node)
		{

			if(node==nullptr)
			{
				return;
			}
			vector_node.push_back(node);
			for(uint i=0;i<node->_children.size();i++)
			{
				_level_preorder(node->_children.at(i),vector_node);

			}

		}

		//CLASS ITERATOR
		class iterator
		{
		private:		
			Node* _pointer_to_current_node;
			std::vector<Node*> _vector_node;
			uint _index_vector;

		public:


	/**
	 * @class iterator
	 * 
	 * @brief This method builds the iterator
	 * @param ptr  pointer the first object in the list
	 * @param level  Choose according to which method to return the objects
	 * @return A new class type object
	 */
			iterator(Node* ptr = nullptr,levelType level=beginLevelOrder): _pointer_to_current_node(ptr),_index_vector(0)
			{
				if(ptr!=nullptr)
				{
					if(level==levelType::beginLevelPreorder)
					{
						_level_preorder(this->_pointer_to_current_node,this->_vector_node);
					}
					if(level==levelType::beginLevelOrderReverse)
					{
						_reverse_level_order(this->_pointer_to_current_node,this->_vector_node);
					}
					if(level==levelType::beginLevelOrder)
					{
						_level_order(this->_pointer_to_current_node,this->_vector_node);

					}

				}
			}
		
		

	/**
	 * @class iterator
	 * 
	 * @brief  This method returns the stage where the object is
	 * @return What level the object
	 */
			uint get_level_table()
			{
				return this->_vector_node.at(this->_index_vector)->_level_table;
			}


	/**
	 * @class iterator
	 * 
	 * @brief This method returns the value of the node
	 * @return The value of the node
	 */
			T& operator*() const
			{
				return this->_vector_node.at(this->_index_vector)->_value;
			}

	/**
	 * @class iterator
	 * 
	 * @brief This method returns the address of the node value
	 * @return The address of the value of the node
	 */
			T* operator->() const
			{
				return &(this->_vector_node.at(this->_index_vector)->_value);

			}


	/**
	 * @class iterator
	 * 
	 * @brief Promotes the node
	 * @return It's an object
	 */
	// ++i;
			iterator& operator++()
			{
				this->check_index();
				return *this;
			}

	/**
	 * @class iterator
	 * 
	 * @brief Promotes the node
	 * @param int - i++
	 * @return t's an object
	 */
	// i++;
			iterator operator++(int)
			{
				iterator tmp= *this;
				this->check_index();
				return tmp;
			}

	/**
	 * @class iterator
	 * 
	 * @brief This method checks whether this node is equal to the node of rhs
	 * @param rhs -  The node to test
	 * @return true OR Not true
	 */
			bool operator==(const iterator& rhs) const 
			{
				if(rhs._pointer_to_current_node!=nullptr)
				{
					return _vector_node.at(_index_vector)== rhs._vector_node.at(rhs._index_vector);
				}
				return _pointer_to_current_node == rhs._pointer_to_current_node;
			}


	/**
	 * @class iterator
	 * 
	 * @brief This method checks whether this node is not equal to the node of rhs
	 * @param rhs - The node to test
	 * @return true OR Not true
	 */
			bool operator!=(const iterator& rhs) const 
			{
				if(rhs._pointer_to_current_node!=nullptr)
				{
					return _vector_node.at(_index_vector)!= rhs._vector_node.at(rhs._index_vector);
				}
				return _pointer_to_current_node != rhs._pointer_to_current_node;

			}


	/**
	 * @class iterator
	 * 
	 * @brief Promotes the index and checks if it has reached the end
	 * @return  Does not return anything
	 */
			void check_index()
			{

				this->_index_vector++;
				if(this->_index_vector==this->_vector_node.size())
				{
					this->_pointer_to_current_node=nullptr;
				}

			}

		};  // END OF CLASS ITERATOR

		//CLASS const_iterator
		class const_iterator
		{
			private:		
				Node* _pointer_to_current_node;
				std::vector<Node*> _vector_node;
				uint _index_vector;
			public:

	/**
	 * @class const_iterator
	 * 
	 * @brief This method builds the const_iterator
	 * @param ptr  pointer the first object in the list
	 * @param level  Choose according to which method to return the objects
	 * @return A new class type object
	 */
			const_iterator(Node* ptr = nullptr,levelType level=beginLevelOrder): _pointer_to_current_node(ptr),_index_vector(0)
			{
				if(ptr!=nullptr)
				{	
					if(level==levelType::beginLevelPreorder)
					{
						_level_preorder(this->_pointer_to_current_node,this->_vector_node);

					}
					if(level==levelType::beginLevelOrderReverse)
					{
						_reverse_level_order(this->_pointer_to_current_node,this->_vector_node);

					}
					if(level==levelType::beginLevelOrder)
					{
						_level_order(this->_pointer_to_current_node,this->_vector_node);

					}

				}
			}

	/**
	 * @class const_iterator
	 * 
	 * @brief  This method returns the stage where the object is
	 * @return What level the object
	 */
			uint get_level_table()
			{
				return this->_vector_node.at(this->_index_vector)->_level_table;
			}

	/**
	 * @class const_iterator
	 * 
	 * @brief This method returns the value of the node
	 * @return The value of the node
	 */
			const T& operator*() const
			{
				return this->_vector_node.at(this->_index_vector)->_value;

			}

	/**
	 * @class const_iterator
	 * 
	 * @brief This method returns the address of the node value
	 * @return The address of the value of the node
	 */
			const T* operator->() const
			{
				return &(this->_vector_node.at(this->_index_vector)->_value);

			}

	/**
	 * @class const_iterator
	 * 
	 * @brief Promotes the node
	 * @return It's an object
	 */
			const_iterator& operator++()
			{
				this->check_index();
				return *this;
			}

	/**
	 * @class const_iterator
	 * 
	 * @brief This method checks whether this node is equal to the node of rhs
	 * @param rhs -  The node to test
	 * @return true OR Not true
	 */
			bool operator==(const const_iterator& rhs) const 
			{
				if(rhs._pointer_to_current_node!=nullptr)
				{
					return _vector_node.at(_index_vector)== rhs._vector_node.at(rhs._index_vector);
				}
				return _pointer_to_current_node == rhs._pointer_to_current_node;

			}

	/**
	 * @class const_iterator
	 * 
	 * @brief This method checks whether this node is not equal to the node of rhs
	 * @param rhs - The node to test
	 * @return true OR Not true
	 */
			bool operator!=(const const_iterator& rhs) const 
			{
				if(rhs._pointer_to_current_node!=nullptr)
				{
					return _vector_node.at(_index_vector)!= rhs._vector_node.at(rhs._index_vector);
				}
				return _pointer_to_current_node != rhs._pointer_to_current_node;

			}

	/**
	 * @class const_iterator
	 * 
	 * @brief Promotes the index and checks if it has reached the end
	 * @return  Does not return anything
	 */
			void check_index()
			{
				this->_index_vector++;
				if(this->_index_vector==this->_vector_node.size())
				{
					this->_pointer_to_current_node=nullptr;
				}

			}
		}; // END OF CLASS const_iterator
		



		/**
		 * @class OrgChart
		 * 
		 * @brief Function for checking the iterator pointer
		 * @param node  Pointer for testing
		 * @return  Does not return anything
		 */

		static void check_iterator(Node* node) 
		{
			if(node==nullptr)
			{
				throw std::runtime_error("Invalid input\n chart is empty");
			}
		}

		/**
		 * @class OrgChart
		 * 
		 * @brief This method sends a pointer to the first object in the list by going over the list using the Level Order method
		 * @return A class-type object
		 */
		const_iterator cbegin() const
		{
			check_iterator(m_first);
			return const_iterator{m_first,levelType::beginLevelOrder};
		}

		/**
		 * @class OrgChart
		 * 
		 * @brief This method sends a pointer to the last object in the list by going over the list using the Level Order method
		 * @return A class-type object
		 */	
		const_iterator cend() const
		{
			check_iterator(m_first);
			return const_iterator{nullptr};
		}


		/**
		 * @class OrgChart
		 * 
		 * @brief  This method sends a pointer to the first object in the list by going over the list using the Level Order method
		 * @return A class-type object
		 */
		const_iterator cbegin_level_order() const
		{
			check_iterator(m_first);
			return const_iterator{m_first,levelType::beginLevelOrder};
		}

		/**
		 * @class OrgChart
		 * 
		 * @brief This method sends a pointer to the last object in the list by going over the list using the level order method
		 * @return A class-type object
		 */
		const_iterator cend_level_order() const
		{
			check_iterator(m_first);
			return const_iterator{nullptr};
		}


		/**
		 * @class OrgChart
		 * 
		 * @brief This method sends a pointer to the first object in the list by going over the list using the reverse Level Order method
		 * @return A class-type object
		 */
		const_iterator cbegin_reverse_order() const
		{
			check_iterator(m_first);
			return const_iterator{m_first,levelType::beginLevelOrderReverse};
		}

		/**
		 * @class OrgChart
		 * 
		 * @brief This method sends a pointer to the last object in the list by going over the list using the reverse level order method
		 * @return A class-type object
		 */
		const_iterator creverse_order() const
		{
			check_iterator(m_first);
			return const_iterator{nullptr};
		}


		/**
		 * @class OrgChart
		 * 
		 * @brief This method sends a pointer to the first object in the list by going over the list using the preorder method
		 * @return A class-type object
		 */
		const_iterator cbegin_preorder() const
		{
			check_iterator(m_first);
			return const_iterator{m_first,levelType::beginLevelPreorder};
		}

		/**
		 * @class OrgChart
		 * 
		 * @brief This method sends a pointer to the last object in the list by going over the list using the preorder method
		 * @return A class-type object
		 */
		const_iterator cend_preorder() const
		{
			check_iterator(m_first);
			return const_iterator{nullptr};
		}


		/**
		 * @class OrgChart
		 * 
		 * @brief This method sends a pointer to the first object in the list by going over the list using the Level Order method
		 * @return A class-type object
		 */
		iterator begin() const
		{
			check_iterator(m_first);
			return iterator{m_first,levelType::beginLevelOrder};
		}

		/**
		 * @class
		 * 
		 * @brief This method sends a pointer to the last object in the list by going over the list using the Level Order method
		 * @return A class-type object
		 */	
		iterator end() const
		{
			check_iterator(m_first);
			return iterator{nullptr};
		}


		/**
		 * @class OrgChart
		 * 
		 * @brief This method sends a pointer to the first object in the list by going over the list using the Level Order method
		 * @return A class-type object
		 */
		iterator begin_level_order() const
		{
			check_iterator(m_first);
			return iterator{m_first,levelType::beginLevelOrder};
		}


		/**
		 * @class OrgChart
		 * 
		 * @brief This method sends a pointer to the last object in the list by going over the list using the Level Order method
		 * @return A class-type object
		 */
		iterator end_level_order() const
		{
			check_iterator(m_first);
			return iterator{nullptr};
		}

		/**
		 * @class OrgChart
		 * 
		 * @brief This method sends a pointer to the first object in the list by going over the list using the reverse Level Order method
		 * @return A class-type object
		 */
		iterator begin_reverse_order() const
		{
			check_iterator(m_first);
			return iterator{m_first,levelType::beginLevelOrderReverse};	
		}

		/**
		 * @class OrgChart
		 * 
		 * @brief This method sends a pointer to the last object in the list by going over the list using the reverse Level Order method
		 * @return A class-type object
		 */
		iterator reverse_order() const
		{
			check_iterator(m_first);
			return iterator{nullptr};
		}


		/**
		 * @class OrgChart
		 * 
		 * @brief This method sends a pointer to the first object in the list by going over the list using the preorder method
		 * @return A class-type object
		 */
		iterator begin_preorder() const
		{
			check_iterator(m_first);
			return iterator{m_first,levelType::beginLevelPreorder};	
		}

		/**
		 * @class OrgChart
		 * 
		 * @brief This method sends a pointer to the last object in the list by going over the list using the preorder method
		 * @return A class-type object
		 */
		iterator end_preorder() const
		{
			check_iterator(m_first);
			return iterator{nullptr};
		}
		
	

	};
}