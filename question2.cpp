//Student Name- Tasfique Enam
//Student ID- 5886429
//Question2

#include <iostream>
using namespace std;

class Animal
{
	private:
		string name;
		double size;

	public:
		Animal();
		Animal(string, double);
		virtual ~Animal(){};
		void setName(string);
		void setSize(double);
		string getName();
		double getSize();
		virtual void display()=0;
};

Animal::Animal()
{
	name="";
	size=0.0;
}

Animal::Animal(string n, double s) : name(n), size(s) {}

void Animal::setName(string name)
{
	this->name=name;
}

void Animal::setSize(double size)
{
	this->size=size;
}

string Animal::getName()
{
	return name;
}

double Animal::getSize()
{
	return size;
}

void Animal::display()
{
	cout << name << " weighs " << size << " kg" << endl;
}

class Reptile : public Animal
{
	private:
		string habitat;

	public:
		Reptile();
		Reptile(string, double, string);
		virtual ~Reptile(){};
		void setHabitat(string);
		string getHabitat();
		void display() override;
};

Reptile::Reptile() : Animal()
{
	habitat="";
}
Reptile::Reptile(string n, double s, string h) : Animal(n, s), habitat(h) {}

void Reptile::setHabitat(string habitat)
{
	this->habitat=habitat;
}

string Reptile::getHabitat()
{
	return habitat;
}

void Reptile::display()
{
	if(habitat=="land")
	{
		cout << getName() << " weighs " << getSize() << " kg and lives on " << habitat << endl;
	}
	else
	{
		cout << getName() << " weighs " << getSize() << " kg and lives in " << habitat << endl;
	}
}

class Snake : public Reptile
{
	private:
		string poisonous;

	public:
		Snake();
		Snake(string, double, string, string);
		~Snake(){};
		void setPoisonous(string);
		string getPoisonous();
		void display() override;
};

Snake::Snake() : Reptile()
{
	poisonous="";
}

Snake::Snake(string n, double s, string h, string p) : Reptile(n, s, h), poisonous(p) {}

void Snake::setPoisonous(string poisonous)
{
	this->poisonous=poisonous;
}

string Snake::getPoisonous()
{
	return poisonous;
}

void Snake::display()
{
	if(getHabitat()=="land")
	{
		cout << getName() << " weighs " << getSize() << " kg and lives on " << getHabitat() << ". " << poisonous << endl;
	}
	else
	{
		cout << getName() << " weighs " << getSize() << " kg and lives in " << getHabitat() << ". " << poisonous << endl;
	}
}

int main()
{
	Animal* animals[4];
	animals[0]=new Reptile("Crocodile", 225, "salt water");
	animals[1]=new Reptile("Lizard", 0.005, "land");
	animals[2]=new Snake("Cobra", 9, "land", "It is very poisonous.");
	animals[3]=new Snake("Anaconda", 300, "swamps", "");

	for(int i=0; i<4; i++)
	{
		animals[i]->display();
	}
	return 0;
}

