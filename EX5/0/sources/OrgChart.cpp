
/**
 * @file OrgChart.cpp
 * @brief 
 * @version 1.0
 * @date 2022-05-15
 * 
 * AUTHORS: Niv Kotek (Nivk99@gmail.com)
 * 
 * @copyright Coyright (C) 2022
 */

#include "OrgChart.hpp"
#include <queue>
namespace ariel
{

	/**
	 *                                           @class OrgChart
	 *           _________________________________________________________________________________
	 */



	/**
	 * @brief
	 * @param
	 * @return
	 * 
	 */
	OrgChart::OrgChart():m_first(nullptr),_size(0)
	{

	}


	/**
	 * @brief
	 * @param
	 * @return
	 * 
	 */
	OrgChart::~OrgChart()
	{
		while (!isEmpty())
		{
			kill();
		}
			
	}


	/**
	 * @brief
	 * @param
	 * @return
	 */
	void OrgChart::kill()
	{
		Node *n=m_first;
		m_first=m_first->_next;
		delete n;
	}


	/**
	 * @brief
	 * @param
	 * @return
	 */

	bool OrgChart::isEmpty() const 
	{
		return m_first==nullptr;
	}


	/**
	 * @brief
	 * @param
	 * @return
	 */
	OrgChart& OrgChart::add_root(const std::string& name)
	{
		m_first=new Node(name,m_first);
		_size++;
		return *this;

	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	OrgChart& OrgChart::add_sub (std::string one_person,std::string second_person)
	{
		int size=_size;
		Node* n=m_first;
		__add_sub(n,one_person,second_person);
		if(size==_size)
		{
			throw std::runtime_error("Invalid input\n No person's name found");

		}
		return *this;

	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	void OrgChart::__add_sub (Node* head,std::string& one_person,std::string& second_person)
	{
		if(head==nullptr)
		{
			return;
		}
		if(head->_value==one_person)
		{
			head->_children.push_back(new Node(second_person,nullptr));
			_size++;
			return;
		}
		for(uint i=0;i<head->_children.size();i++)
		{
			__add_sub(head->_children.at(i),one_person,second_person);
		}
	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	std::ostream& operator<<(std::ostream &out,OrgChart &Org_chart) 
	{
		for( auto element : Org_chart)
  		{ 
    		out <<element << " <-- ";
 		} 
		return out;

	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	OrgChart::iterator OrgChart::begin() 
	{
		return iterator{m_first,iterator::levelType::beginLevelOrder};
	}

	/**
	 * @brief
	 * @param
	 * @return
	 */	
	OrgChart::iterator OrgChart::end()
	 {
		return iterator{nullptr};
	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	OrgChart::iterator OrgChart::begin_level_order()
	{
		return iterator{m_first,iterator::levelType::beginLevelOrder};
	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	OrgChart::iterator OrgChart::end_level_order()
	{
		return iterator{nullptr};

	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	OrgChart::iterator OrgChart::begin_reverse_order()
	{
		return iterator{m_first,iterator::levelType::beginLevelOrderReverse};

	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	OrgChart::iterator OrgChart::reverse_order()
	{
		return iterator{nullptr};

	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	OrgChart::iterator OrgChart::begin_preorder()
	{
		return iterator{m_first,iterator::levelType::beginLevelPreorder};

	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	OrgChart::iterator OrgChart::end_preorder()
	{
		return iterator{nullptr};

	}


	/**
	 *                                           @class iterator
	 *           _________________________________________________________________________________
	 */


	/**
	 * @brief
	 * @param
	 * @return
	 */
	OrgChart::iterator::iterator(Node* ptr ,levelType level): _pointer_to_current_node(ptr),_index_vector(0)
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
	 * @brief
	 * @param
	 * @return
	 */
	std::string& OrgChart::iterator::operator*() const
	{
		return this->_vector_node.at(this->_index_vector)->_value;
	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	std::string* OrgChart::iterator::operator->() const 
	{
		return &(this->_vector_node.at(this->_index_vector)->_value);
	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	// ++i;
	OrgChart::iterator& OrgChart::iterator::operator++()
	 {
		this->check_index();
		return *this;
	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	// i++;
	const OrgChart::iterator OrgChart::iterator::operator++(int)
	 {
		iterator tmp= *this;
		this->check_index();
		return tmp;
	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	bool OrgChart::iterator::operator==(const iterator& rhs) const 
	{
		return _pointer_to_current_node == rhs._pointer_to_current_node;
	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	bool OrgChart::iterator::operator!=(const iterator& rhs) const 
	{
		return _pointer_to_current_node != rhs._pointer_to_current_node;
	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	void OrgChart::iterator::check_index()
	{
		this->_index_vector++;
		if(this->_index_vector==this->_vector_node.size())
			{
				this->_pointer_to_current_node=nullptr;
			}

	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	void OrgChart::iterator::_level_order(Node *node,std::vector<Node*> &vector_node)
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
	 * @brief
	 * @param
	 * @return
	 */

	void OrgChart::iterator::_reverse_level_order(Node* &node,std::vector<Node*> &vector_node)
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
				uint j=static_cast<uint>(i);
				que.push(no->_children.at(j));

			}	

		}
		for(int i=(vect.size()-1);i>=0;i--)
		{
			uint j=static_cast<uint>(i);
			vector_node.push_back(vect.at(j));
		}

	}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	void OrgChart::iterator::_level_preorder(Node* node,std::vector<Node*> &vector_node)
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


} // namespace ariel

