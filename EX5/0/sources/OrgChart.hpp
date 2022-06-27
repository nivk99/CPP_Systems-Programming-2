
/**
 * @file OrgChart.hpp
 * @brief 
 * @version 1.0
 * @date 2022-05-15
 * 
 * 
 * AUTHORS: Niv Kotek (Nivk99@gmail.com)
 * 
 * @copyright Coyright (C) 2022
 */


#pragma once
#include <string>
#include <iostream>
#include <vector>

namespace ariel
{
	class OrgChart
	{
	private:
		struct Node
		{
			std::string _value;
			Node* _next;
			std::vector<Node*>_children;
			Node(const std::string& value, Node* next=nullptr): _value(value), _next(next) {}
		};

		Node* m_first;
		int _size;
	
	public:
		OrgChart();
		~OrgChart();
		void kill();
		bool isEmpty() const ;
		OrgChart& add_root(const std::string& name);
		OrgChart& add_sub (std::string one_person,std::string second_person);
		void __add_sub (Node* head,std::string& one_person,std::string& second_person);
		friend std::ostream& operator<<(std::ostream &out,OrgChart &Org_chart);

		class iterator
		{
		private:		
			Node* _pointer_to_current_node;
			std::vector<Node*> _vector_node;
			uint _index_vector;

		public:
			enum levelType
			{
				beginLevelOrder,
				beginLevelOrderReverse,
				beginLevelPreorder

			};

			iterator(Node* ptr = nullptr,levelType level=beginLevelOrder);
			static void _level_order(Node *node,std::vector<Node*> &vector_node);
			static void _reverse_level_order(Node* &node,std::vector<Node*> &vector_node);
			static void _level_preorder(Node* node,std::vector<Node*> &vector_node);

			std::string& operator*() const;
			std::string* operator->() const;
			// ++i;
			iterator& operator++();

			// i++;
			const iterator operator++(int);

			bool operator==(const iterator& rhs) const ;

			bool operator!=(const iterator& rhs) const ;
			void check_index();

		};  // END OF CLASS ITERATOR


		iterator begin();
		iterator end();

		iterator begin_level_order();
		iterator end_level_order();

		iterator begin_reverse_order();
		iterator reverse_order();

		iterator begin_preorder();
		iterator end_preorder();


	

	};
}