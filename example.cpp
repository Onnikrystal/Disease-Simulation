#include "Person.h"
#include "Population.h"
#include <iostream>
#include <vector>
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using namespace std;

int main() {
	// simple example for just one person
    Person joe; 
    // cout << joe.status;
    int step = 1;
    for ( ; ; step++) {
        joe.update();
        // float bad_luck = (float) rand()/(float)RAND_MAX; 
        // if (bad_luck>.05){
            joe.infect(5);
        // }
        cout << "On day " << step << ", Joe is " << joe.status_string() << endl;
        if (joe.is_stable()) break;
    }
}