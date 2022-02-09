#include <iostream>
#include <cstdint>
#include <cassert>



//______________________________________________________________________________________________________________________________________
//		Task 1
//______________________________________________________________________________________________________________________________________


class Power {
public:
	int x = 0;
	int y = 0;

	void set(int value1, int value2) {
		x = value1;
		y = value2;
	}

	void calculate() {
		std::cout << "Number " << x << " to the power of " << y << " is: " << pow(x, y) << std::endl;
	}
};



//______________________________________________________________________________________________________________________________________
//		Task 2
//______________________________________________________________________________________________________________________________________



class RGBA {
public:
	uint8_t m_red = 0, m_green = 0, m_blue = 0, m_alpha = 255;
	RGBA() {}
	RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) :
		m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {}
	void print() {
		std::cout << "Red is: " << static_cast<int>(m_red) << std::endl << "Green is: " << static_cast<int>(m_green) << std::endl
			<< "Blue is: " << static_cast<int>(m_blue) << std::endl << "Alpha is: " << static_cast<int>(m_alpha) << std::endl;
	}
};


//______________________________________________________________________________________________________________________________________
//		Task 3
//______________________________________________________________________________________________________________________________________


class Stack {
private:
	int m_array[10];
	int m_check;

public:
	void reset()
	{
		m_check = 0;
		for (size_t i = 0; i < 10; i++)
		{
			m_array[i] = 0;
		}
	}

	bool push(int value)
	{
		if (m_check == 10)
			return false;
		m_array[m_check++] = value;
		return true;
	}

	int pop()
	{
		assert(m_check > 0);
		return m_array[m_check--];
	}

	void print()
	{
		std::cout << "(";
		for (size_t i = 0; i < m_check; i++)
			std::cout << m_array[i] << " ";
		std::cout << ")" << std::endl;
	}
};


int main()
{
//__________________TASK1___________________

	Power check;
	check.set(3,4);
	check.calculate();
	std::cout << std::endl;

//__________________TASK2___________________

	RGBA one;
	one.print();
	std::cout << std::endl;
	RGBA two(4, 4, 6, 10);
	two.print();
	std::cout << std::endl;

//__________________TASK3___________________

	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	return 0;
}