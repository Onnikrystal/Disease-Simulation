#ifndef POPULATION_H
#define POPULATION_H 
 
#include <iostream>
#include <vector>
#include <algorithm>    // std::shuffle
#include <array>        // std::array
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock
#include "Person.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Population {
	public:
        vector<Person> vec;
        float prob;
        int contact;
        int social_distance;
        int days_recovered;
        Population (int npeople, int ndays_recovered);
        void set_days(int recovered);
        void random_infection();
        int count_infected();
        void if_bad_luck(int pos);
        void contagion(int ori);
        void update();
        void print();
        void set_probability_of_transfer(float probability);
        void get_vaccinated(float vac);
        void set_contact_number(int ncontact);
        void set_social_distance(int nsocial_distance);
};

  
#endif 