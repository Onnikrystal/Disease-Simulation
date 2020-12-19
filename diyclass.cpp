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
    int populat;
    cout << "What population would you want to do: " << endl;
    cin >> populat;
    int day;
    cout << "How many day does it take to recover: " << endl;
    cin >> day;
    Population pop(populat, day);
    int count = 1;
    
    // prob that a person gets teh disease
    float prob;
    cout << "The probablity of a single person get the disease: " << endl;
    cin >> prob;
    pop.set_probability_of_transfer(prob);
    
    // portion of ppl vaccinated
    float vac;
    cout << "The portion of ppl get vaccinated: " << endl;
    cin >> vac;
    
    // number of ppl get into contact (situation 1)
    int contact;
    cout << "The number of people that a person comes into contact with per day: " << endl;
    cin >> contact;
    pop.set_contact_number(contact);
    
    // social distance adding (situation 2)
    int social_distance;
    cout << "What is the maximum number of people in a social distance: " << endl;
    cin >> social_distance;
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


