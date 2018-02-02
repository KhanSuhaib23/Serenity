#pragma once

#include <iostream>

#include <GLEW\glew.h>

#include "DynamicArray.h"

namespace serenity { namespace utils {

	template <typename T>
	class LinkedList
	{
	private:
		GLsizei m_Size = 0;
		struct m_Element
		{
			T data;
			m_Element* next;
		};
		m_Element* m_Start = nullptr;

	public:
		m_Element* createNewNode(T data)
		{
			m_Element* newNode = new m_Element[1];
			newNode->data = data;
			newNode->next = nullptr;

			return newNode;
		}
		

		void push(T data)
		{
			m_Element* node = createNewNode(data);
			node->next = m_Start;
			m_Start = node;
			m_Size++;
		}

		void pop(int index = 0)
		{
			if (isEmpty())
			{
				std::cout << "Linked List Empty" << std::endl;
				exit(-1);
			}
			if (index == 0)
			{
				m_Element* node = m_Start;
				m_Start = m_Start->next;
				delete node;
				
			}
			else
			{
				m_Element* ptr = m_Start;

				for (int i = 1; i < index; i++)
				{
					ptr = ptr->next;
				}

				m_Element* node = ptr->next;
				ptr->next = ptr->next->next;

				delete node;
			}
			

			m_Size--;
		}

		T peek(int index = 0)
		{
			
			m_Element* ptr = m_Start;
			for (int i = 0; i < index; i++)
			{
				ptr = ptr->next;
			}
			if (ptr == nullptr) return nullptr;
			return ptr->data;
		}

		bool isEmpty()
		{
			return m_Start == nullptr;
		}

		void copyDynamicArray(DynamicArray<T> array)
		{
			for (GLuint i = 0; i < array.getSize(); i++)
			{
				push(array.get(i));
			}
		}

		inline GLsizei getSize() { return m_Size; }

	};

} }

