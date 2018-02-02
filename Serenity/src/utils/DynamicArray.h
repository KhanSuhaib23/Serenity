#pragma once

#include <iostream>

#include <GLEW\glew.h>

namespace serenity { namespace utils {

	template <typename T>
	class DynamicArray
	{
	private:
		T* m_Start;
		GLuint m_Increement;
		GLuint m_Capacity;
		GLuint m_Size;
		GLboolean m_DynamicReduction;

	public:
		DynamicArray			(GLboolean			dynamicReduction = false)
		{
			m_Size = 0;
			m_Capacity = 10;
			m_Increement = 20;
			m_DynamicReduction = dynamicReduction;

			m_Start = new T[m_Capacity];
		}

		DynamicArray			(
									GLuint			capacity, 
									GLboolean		dynamicReduction = false
								)
		{
			m_Size = 0;
			m_Capacity = capacity;
			m_Increement = capacity * 2;
			m_DynamicReduction = dynamicReduction;

			m_Start = new T[m_Capacity];
		}

		DynamicArray			(
									GLuint			capacity, 
									GLuint			increement, 
									GLboolean		dynamicReduction = false
								)
		{
			m_Size = 0;
			m_Capacity = capacity;
			m_Increement = increement;
			m_DynamicReduction = dynamicReduction;

			m_Start = new T[m_Capacity];
		}

	public:
		void		push				(T data)
		{
			

			if (m_Size == m_Capacity)
			{
				if (m_Increement == 0)
				{
					std::cout << "Array Full Cannot Add More Elements" << std::endl;
					system("PAUSE");
					exit(-1);
				}
				increaseCapacity();
			}

			m_Start[m_Size] = data;
			m_Size++;
		}

		T			pop					()
		{
			if (m_Size == 0)
			{
				std::cout << "Cannot Remove More Elements" << std::endl;
				exit(-1);
			}

			if (m_DynamicReduction)
			{
				if (m_Size == m_Capacity - m_Increement && m_Capacity - m_Increement > 0)
				{
					std::cout << "Came Here" << std::endl;
					reduceCapacity();
				}
			}

			m_Size--;
			return m_Start[m_Size];
		}

		bool isEmpty()
		{
			return m_Size == 0;
		}

		void clear()
		{
			while (!isEmpty())
			{
				pop();
			}
		}

		T			operator[]			(GLuint index)
		{
			if (index >= m_Size)
			{
				std::cout << "Index Out Of Bounds" << std::endl;
				system("PAUSE");
				exit(-1);
			}
			return m_Start[index];
		}

		T			get			(GLuint index)
		{
			if (index >= m_Size)
			{
				std::cout << "Index Out Of Bounds" << std::endl;
				exit(-1);
			}
			return m_Start[index];
		}
		
		friend std::ostream& operator<< (std::ostream& output, DynamicArray& arr)
		{
			for (GLuint i = 0; i < arr.getSize(); i++)
			{
				output << arr[i] << " ";
			}

			return output;
		}

	private:

		void		reduceCapacity		()
		{
			m_Capacity -= m_Increement;
			T* result = new T[m_Capacity];
			for (GLuint i = 0; i < m_Size; i++)
			{
				result[i] = m_Start[i];
			}

			delete[] m_Start;

			m_Start = result;
		}

		void		increaseCapacity	()
		{
			m_Capacity += m_Increement;
			T* result = new T[m_Capacity];
			for (GLuint i = 0; i < m_Size; i++)
			{
				result[i] = m_Start[i];
			}

			delete[] m_Start;

			m_Start = result;
		}

	public:

		inline GLuint getSize() const { return m_Size; }
		inline GLuint getCapacity() const { return m_Capacity; }
		inline GLuint getIncreement() const { return m_Increement; }

	};

} }