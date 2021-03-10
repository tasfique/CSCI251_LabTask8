//Name-Tasfique Enam
//Student ID- 5886429
//Question1

#include <iostream>

using namespace std;

class Car {
private:
    string regNum;
    double miles;
public:
    Car(); //default constructor
    virtual ~Car() {};
    Car(string, double);

    void setRegNum(string);
    void setMiles(double);

    string getRegNum();
    double getMiles();

    void increaseMileage(double);
    virtual void display() = 0;

};

Car::Car() //default constructor
{
	regNum="";
	miles=0.0;
}

Car::Car(string r, double n) : regNum(r), miles(n) {} //non default

void Car::setRegNum(string regNum) //setter
{
	this->regNum=regNum;
}

void Car::setMiles(double miles) //setter
{
	this->miles=miles;
}

string Car::getRegNum() //getters.
{
	return regNum;
}

double Car::getMiles()
{
	return miles;
}

// memeber function
void Car::increaseMileage(double miles)
{
	this->miles+=miles;
}

void Car::display() //display function
{
	cout << "Registration Num : " << regNum << endl;
	cout << "Miles : " << miles << endl;
}

///Race Car Derived Class
class RaceCar : public Car
{
	private:
		string racingType;

	public:
		RaceCar(); //constructor
		~RaceCar(){}; //destructor
		RaceCar(string, double, string); //non default
		void setRacingType(string);
		string getRacingType();
		void display() override;
};

// DEFAULT CONSTRUCTOR
RaceCar::RaceCar() : Car()
{
	racingType="";
}

// NON-DEFAULT CONSTRUCTOR
RaceCar::RaceCar(string r, double n, string t) : Car(r, n), racingType(t) {}

// SETTER
void RaceCar::setRacingType(string racingType)
{
	this->racingType=racingType;
}

// GETTER
string RaceCar::getRacingType()
{
	return racingType;
}

// OVERRIDE DISPLAY FUNCTION
void RaceCar::display()
{
	cout << "Registration Num : " << getRegNum() << endl;
	cout << "Miles : " << getMiles() << endl;
	cout << "Racing Type : " << getRacingType() << endl;
	cout << endl;
}

///MPV derived class.
class MPV : public Car
{
	private:
		int capacity;

	public:
		MPV(); //constructor
		~MPV(){}; //destructor
		MPV(string, double, int); //non default
		void setCapacity(int);
		int getCapacity();
		void display() override;
};

MPV::MPV() : Car()
{
	capacity=0;
}

MPV::MPV(string r, double n, int c) : Car(r, n), capacity(c) {}

void MPV::setCapacity(int capacity)
{
	this->capacity=capacity;
}

int MPV::getCapacity()
{
	return capacity;
}

void MPV::display()
{
	cout << "Registration Num : " << getRegNum() << endl;
	cout << "Miles : " << getMiles() << endl;
	cout << "Racing Type : " << getCapacity() << endl;
	cout << endl;
}



int main() {
	Car* cars[2]; //POINTER ARRAY
	cars[0] = new RaceCar("3243534", 41, "OFF-ROAD");
	cars[1] = new MPV("32432432", 50, 200);

	// Display
	cars[0]->display();
	cars[1]->display();

	// Increasing Mileage
	cout<<"\n";
	cars[0]->increaseMileage(15);
	cars[1]->increaseMileage(20);

	// Display
	cars[0]->display();
	cars[1]->display();

    return 0;
}
