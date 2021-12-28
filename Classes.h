#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <array>


using namespace std;


// Classes 


class Toll {        // might be unneccessary...
    public: 


    private:
        bool electronic;       // => false = with conductor
        bool entry;
        bool exit;

};



class Node {        
    public: 
        Node(int,bool,bool);
        ~Node();




    private: 
        int number_of_tolls;
                                // something to keep the tolls in...


};



class Seg {
    public:
        

   private:
        int number_of_vehicles;
        int max_capacity;
                                // something to keep the vehicles in....


};



class Attica {
    public:



    private: 
        int NSegs;          // number of Seg's
        Node first_node;
        Node last_node;
                            // Need something to keep the rest of the nodes in (array,vector,pointers,etc.) and/or segs of attica...

};

