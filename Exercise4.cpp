#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>
#include <vector>
#include <deque>


using namespace std;


const int max_number = 10;

// Defining a struct with constructors and destructors...


struct Point {
	double x;
	double y;
	
	Point(double,double);
	~Point();
	void set_point(double&,double&); 		// By reference 		// Mutators

	void printInfo() const;				// Accessors
	double get_x() const;
	double get_y() const;
	double get_distance(Point&, Point&);
	
};


class Line {
	public:	
		Line(Point&, Point&, double);
		~Line();

		double get_length() const;
	protected:
		Point x;
		Point y;
		double length;
};


class NamedLine: public Line {
	public:
		NamedLine(Point&, Point&, double, const char*);
		~NamedLine();

		char* get_name() const;
		void  set_name(const char*);
		void set_length_to_zero();
		
	private:
		char* name;
};

Line::Line(Point& a, Point& b, double l) : x(a), y(b) , length(l) {
	cout << "I drew a line...." << endl;	
}

Line::~Line() {
	cout << "Line has been erased...." << endl;
}


double Line::get_length() const {
	return this->length;
}




NamedLine::NamedLine(Point& a, Point& b, double l, const char* line_name) : Line(a,b,l) {
	name = new char[strlen(line_name) + 1];
	strcpy(name,line_name);
	cout << "A NAMED line has been created..." << endl;
}

NamedLine::~NamedLine() {
	delete[] name;
	cout << "Named line has been erased..." << endl;
}

char* NamedLine::get_name() const {
	return this->name;
}

void NamedLine::set_name(const char* line_name) {
	delete[] name;
	name = new char[strlen(line_name) + 1];
	strcpy(name,line_name);	
}

void NamedLine::set_length_to_zero() {
	this->length = 0;
}





Point::Point(double a, double b) : x(a) , y(b){
	cout << "I just constructed a point..." << endl;
}


Point::~Point() {
	cout << "Point has been deleted..." << endl;
}

void Point::set_point(double& a, double& b) {
	this->x = a;
	this->y = b;
}



void Point::printInfo() const {
	cout << this->x << "  " << this->y << endl << endl;
}


double Point::get_x() const {
	return this->x;
}


double Point::get_y() const {
	return this->y;
}


double Point::get_distance(Point& a, Point& b) {
	double distance = sqrt( (b.get_x() - a.get_x()) * (b.get_x() - a.get_x()) + (b.get_y() - a.get_y()) * (b.get_y() - a.get_y()) );
	return ( distance < 0 ? -distance : distance);
}


int main(int argc, char* argv[]) {
	

	long t = time(NULL);
	srand(t);
	cout << "Please insert the point's coordinates: " << endl;
	double x1,x2,y1,y2;
	cin >> x1 >> x2 >> y1 >> y2;
	
	
	Point a(x1,x2);
	Point b(y1,y2);


	
	a.printInfo();
	b.printInfo();
	
	cout << "OOR I could print them as such: " << endl;
	
	cout << "Point a has coordinates: " << "x = " << a.get_x() << " and y = " << a.get_y() << endl; 
	cout << "Point b has coordinates: " << "x = " << b.get_x() << " and y = " << b.get_y() << endl; 
	
	cout << endl << "MY HUMP MY HUMP MY HUMP" << endl;
	
	double z1 = a.get_x();
	double z2 = a.get_y();



	Line line(a,b,a.get_distance(a,b));
	cout << "Line has length :\t" << line.get_length() << endl;
	

	NamedLine n_line(a,b,a.get_distance(a,b), "AB");
	cout << "Name is :\t" << n_line.get_name() << endl;

	n_line.set_length_to_zero();
	cout << n_line.get_length() << endl;

	cout << endl << endl << endl << "Frequencies and period" << endl;

	vector<double> frequencies;
	vector<double> period;

	

 	for (int i = 0 ; i < max_number ; i++) {
		frequencies.push_back(rand() % 9 * max_number - i);	
		period.push_back(1 / frequencies.at(i));
	}


	cout << "The frequency vector's size is : " << frequencies.size() << " , capacity is: " << frequencies.capacity() << endl 
		 << "Respectively, the period vector's size is : " << period.size() << " , capacity is : " << period.capacity() << endl
		 << "Frequencies and Periods : " << endl;


	for (int i = 0 ; i < max_number ; i++) {
		cout << i + 1 << ". " << frequencies.at(i) << " , " << period.at(i) << "." << endl;
	}
	
	

	cout << endl << "Terms of Fourier sequence with amplitudes from 1 to " << max_number << " are: " << endl << endl;
	
	for (int i = 1 ; i < max_number ; i++) {
		cout << "For k = " << i << " : " << i << "e^(-j" << i << 2*3.14159*frequencies.at(i)*i << ")" << endl;
	}
	

	frequencies.clear();
	period.clear();

	cout << endl <<  argc << "\t" << argv[1] << endl << endl;

	return 0;
}