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
    // what population would you want to do?
    int populat = 20;
    int day = 10;
    Population pop(populat, day);
    int count = 1;
    
    // prob that a person gets teh disease
    float prob = 0.5;
    pop.set_probability_of_transfer(prob);
    
    // portion of ppl vaccinated
    float vac = 0.45;
    
    // number of ppl get into contact (situation 1)
    int contact = 5;
    pop.set_contact_number(contact);
    
    // social distance adding (situation 2)
    int social_distance = 0;
    pop.set_social_distance(social_distance);

    // vaccinated ppl is unrealistic because ppl moved around and 
    // it is impossible to behave like what this have behaved
    pop.get_vaccinated(vac);
    cout << "after vaccinated ";
    pop.print();
    while (pop.count_infected() == 0){
        pop.random_infection();
    }
    cout << "first ppl get disease ";
    pop.print();
    count ++;
    while(pop.count_infected() > 0){
        pop.update();
        cout << "In day" + std::to_string(count) << " : ";
        pop.print();
        count ++;
    }
}


