#ifndef CLASS_H
#define CLASS_H 
 
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

class Person { 
        public:
        int status;
        string myState;
        bool blank;
        public:
            Person();
            void set_person();
            string status_string();
            void update();
            void infect(int n);
            bool is_stable();
            void vaccinated();
};
  
#endif 