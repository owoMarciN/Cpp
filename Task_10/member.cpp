#include "member.h"

int Member::CurrentYear = 2005;

Member::Member(){

}

Member::~Member(){

}
Member::Member(int birthYear, std::string name){
    BirthYear = birthYear;
    Update();
    Name = name;
}

Member::Member(const Member &M){
    BirthYear = M.BirthYear;
    CurrentYear = M.CurrentYear;
    Age = M.Age;
    Name = M.Name;
}

void Member::StatYearChange(int year){
    if(year > CurrentYear)
        CurrentYear = year;
    else
        std::cout << "The new year must be bigger then: " << CurrentYear << '\n';
}

void Member::Update(){
    if(Age != CurrentYear - BirthYear)
        Age = CurrentYear - BirthYear;
    else if(Age <= 0)
        std::cout << "Error: Wrong Birth Year\n";
}

void Member::YearChange(int year){
    StatYearChange(year);
    Update();
}

void Member::printName(std::string name){
    if(!name.empty())
        Name = name;
    std::cout << Name;
}

void Member::PrintAge(){
    Update();
    std::cout << Age;
}

void Population::Add(Member &m){
    PopList.push_back(m);
}

void Population::YearChange(int year){
    CurrentYear = year;
    Update();
}

void Population::Update(){
    for(auto &i : PopList){
        i.CurrentYear = this->CurrentYear;
        i.Update();
    }
}

void PrintPop(Population &Pop){
    Pop.Update();
    std::cout << Pop.CurrentYear << '\n';
    for(int i = 0; i < Pop.PopList.size(); i++){
        Pop.PopList[i].printName("");
        std::cout << ' ';
        Pop.PopList[i].PrintAge();
        std::cout << '\n';
    }
        
}

// Population::Population(){
   
// }

Population::Population(const Population &P){
    PopList = P.PopList;
    CurrentYear = P.CurrentYear;
}

Population::Population(){

}

Population::~Population(){

}