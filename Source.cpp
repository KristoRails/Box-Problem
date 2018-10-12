#include <iostream>
#include<cstdint>
#include<vector>
using namespace std;

class Box {
private:
	long long l, b, h;
public:

	//default constructor
	Box() 
	{
		l = b = h = 0;
	}

	//member initializer
	Box(long long length, long long breadth, long long height) :
		l(length), b(breadth), h(height)
	{
		//empty
	}

	//copy constructor
	Box(Box &copy)
	{
		l = copy.l;
		b = copy.b;
		h = copy.h;
	}

	//get functions
	long long getLength() const
	{
		return l;
	}
	long long getBreadth() const
	{
		return b;
	}
	long long getHeight() const
	{
		return h;
	}

	//functions
	long long CalculateVolume()
	{
		return l * b* h;
	}

	//operator overloading
	friend bool operator< (const Box& a, const Box& b)
	{
		if (a.l < b.l)
			return true;
		else if (a.b < b.b)
			return true;
		else if (a.h < b.h && a.b == b.b && a.l == b.l)
			return true;
		return false;
	}

	friend std::ostream& operator<<(std::ostream& os, const Box& output)
	{
		os << output.getLength()<<' '<< output.getBreadth() << ' ' << output.getHeight() << ' ';
		return os;
	}
};

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	check2();
	system("pause");
}