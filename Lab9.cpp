#include <iostream>

using namespace std;

class Numbers
{
public:
	double elements[5];
	Numbers(double n1, double n2, double n3, double n4, double n5)
	{
		elements[0] = n1;
		elements[1] = n2;
		elements[2] = n3;
		elements[3] = n4;
		elements[4] = n5;
	}
	Numbers()
	{
		for (int i = 0; i < 5; i++) elements[i] = 0;
	}
	~Numbers()
	{
		(void)0;
	}
	void SetNumbers()
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "Введiть число " << i + 1 << " : " << endl;
			cin >> elements[i];
		}
	}
	void GetNumbers()
	{
		for (int i = 0; i < 5; i++)	cout << "Число " << i + 1 << " : " << elements[i] << endl;
	}

	double Middle()
	{
		double sum = 0;
		for (int i = 0; i < 5; i++) sum += elements[i];
		return sum / 5.0;
	}
	Numbers operator +(Numbers n1)
	{
		Numbers a;
		for (int i = 0; i < 5; i++) a.elements[i] = this->elements[i] + n1.elements[i];
		return a;
	}

	Numbers operator -(Numbers n1)
	{
		Numbers a;
		for (int i = 0; i < 5; i++) a.elements[i] = this->elements[i] - n1.elements[i];
		return a;
	}

	Numbers operator +=(double n1)
	{
		Numbers a;
		for (int i = 0; i < 5; i++) a.elements[i] = this->elements[i] + n1;
		return a;
	}

	Numbers operator -=(double n1)
	{
		Numbers a;
		for (int i = 0; i < 5; i++) a.elements[i] = this->elements[i] - n1;
		return a;
	}

	Numbers operator ++()
	{
		Numbers a;
		for (int i = 0; i < 4; i++) a.elements[i+1] = this->elements[i];
		a.elements[0] = this->elements[4];
		return a;
	}

	Numbers operator --()
	{
		Numbers a;
		for (int i = 0; i < 4; i++) a.elements[i] = this->elements[i+1];
		a.elements[4] = this->elements[0];
		return a;
	}

	bool operator !=(Numbers n)
	{
		bool isEqual = true;
		for (int i = 0; i < 5; i++)
			if (this->elements[i] != n.elements[i]) isEqual = false;
		return !isEqual;
	}
};


int main()
{
	setlocale(LC_ALL, "Rus");
	Numbers numb;
	numb.SetNumbers();
	numb.GetNumbers();
	cout << numb.Middle() << endl;
	Numbers num(6.5, 2.5, 7.0, 10.9, 16.7);
	Numbers eq(6.5, 2.5, 7.0, 10.9, 16.7);
	num.GetNumbers();
	Numbers a = num + numb, b = numb - num, c = numb += 1.2,d = numb-=1.2;
	Numbers x = ++numb, y = --num;
	cout << " + " << endl;
	a.GetNumbers();
	cout << " - " << endl;
	b.GetNumbers();
	cout << " += " << endl;
	c.GetNumbers();
	cout << " -= " << endl;
	d.GetNumbers();
	cout << " ++ " << endl;
	x.GetNumbers();
	cout << " -- " << endl;
	y.GetNumbers();
	cout << "Введений масив рiвний тому що є?" << endl;
	eq != num ? cout << 1 << endl : cout << 0 << endl;
	system("pause");
}