#include "Person.h"
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

  // The class
    Person::Person(){
      set_person();
    };
    void Person::set_person(){
      status = 0;       
      myState = "susceptible";
      blank = true;
    };
    string Person::status_string(){
        if (status == 0) {
            myState = "susceptible";}
        else if (status == -1) {
            myState = "recovered";}
        else if (status == -2) {
            myState = "vaccinated";}
        else {
            myState = "sick with " + std::to_string(status) + " day to go";}
        return myState;
    };
    void Person::update(){
        if (status > 0){
            status --;
        }
        if (status == 0 and blank == false){
            // cout << "someone rcovered" << endl;
            myState = "recovered";
            status = -1;
        }
    };
    void Person::infect(int n){
        if (status == 0){
            myState = "sick with " + std::to_string(n) + " day to go";
            blank = false;
            status = n;
        }
    };
    bool Person::is_stable() {
        if(status <= -1){
            return true;
        }
        else {
            return false;
        }
    };
    void Person::vaccinated() {
        status = -2;
        myState = "vaccinated";
    };