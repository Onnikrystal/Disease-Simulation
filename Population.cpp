#include "Population.h"
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
        
    Population::Population (int npeople, int ndays_recovered){
        vector<Person> tmp(npeople);
        vec = tmp;
        set_days(ndays_recovered);
    };
    void Population::set_days(int recovered) {
      days_recovered = recovered;
    };
    void Population::random_infection(){
        int size = vec.size();
        int pos = rand() % (size);
        // cout << size << endl;
        vec[pos].infect(days_recovered); 
    };
    int Population::count_infected(){
        int count = 0;
        for (auto &e : vec){
          if (e.status > 0){
            count ++;  
          };
        };
        return count;
    };
    // seperate function to see if a ppl get contagiated
    void Population::if_bad_luck(int pos){
      if((rand() % 100) < prob){
          vec.at(pos).infect(days_recovered);
          // cout << "here1" << endl;
      }
    };
    void Population::contagion(int ori){
      // if it is situation 1
      if(contact != 0){
        int size = vec.size();
        int newitem;
        // get the array of group of ppl
        int array[size];
        bool unique = false;
        for(int i=0;i<size-1;i++){
          unique = false;
          while(!unique){
              // cout << "while";
              unique = true;
              newitem=std::rand() % size;
              for(int i1=0;i1<size-1;i1++){
                // cannot infect himself/herself
                // cout << newitem;
                 if(array[i1]==newitem or newitem == ori){
                    unique = false;}}}
          array[i]=newitem;
        }
        for(int j=0; j<contact; j++){
            // cout << "here2" << endl;
            if_bad_luck(array[j]);
        }
      }
      // if it is situation 2 aka social distance
      else{
        int group_number = floor(ori/social_distance);
        for (int k = group_number*social_distance; k<(group_number+1)*social_distance; k++){
          if(k != ori and k < vec.size()){
            if_bad_luck(k);
          }
        }
      }
    };
    void Population::update(){
       for (int i =0; i<vec.size(); i++){
         if(vec.at(i).status > 0){
            contagion(i);
         }
         vec.at(i).update();
        //  cout << vec.at(i).status_string();
       };
    };
    void Population::print(){
        for (auto &e : vec){
         if (e.myState == "susceptible"){
             cout << '?' << ' ';
         }
         else if (e.myState == "recovered"){
             cout << '-' << ' ';
         }
         else if(e.myState == "vaccinated"){
             cout << '!' << ' ';
         }
         else {
             cout << '+' << ' ';
         }
       };
       cout << '\n' << endl;
    };
    void Population::set_probability_of_transfer(float probability){
        prob = probability*100;
    };
    void Population::get_vaccinated(float vac){
        int ppl = int(vec.size() * vac);
        // cout << ppl;
        int pos = 0;
        for(int i=0; i<ppl; i++){
            pos = std::rand() % (vec.size());
            while(vec.at(pos).status == -2){
                pos = std::rand() % (vec.size());
            }
            // cout << pos << " ";
            vec.at(pos).vaccinated();
        };
    };
    void Population::set_contact_number(int ncontact){
        contact = ncontact;
    };
    void Population::set_social_distance(int nsocial_distance){
        social_distance = nsocial_distance;
    };

