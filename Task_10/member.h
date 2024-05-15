#ifndef MEMBER_H_
#define MEMBER_H_

#include <iostream>
#include <string>
#include <vector>

class Member{
private:

    static int CurrentYear;
    int BirthYear;
    int Age = CurrentYear - BirthYear;
    std::string Name;

public:

    Member();
    Member(int birthYear, std::string name);
    Member(const Member &M);
    Member &operator=(const Member &M){
        BirthYear = M.BirthYear;
        CurrentYear = M.CurrentYear;
        Age = M.Age;
        Name = M.Name;
        return *this;
    }
    ~Member();

private:

    static void StatYearChange(int year);
    void Update();

public:

    void YearChange(int year);
    void printName(std::string name);
    void PrintAge();
    friend class Population;
};

class Population{
protected:

    std::vector<Member> PopList;
    int CurrentYear = 2005;

public:

    Population();
    //Population(Member &m, int currYear);
    Population(const Population &P);
    Population &operator=(const Population &P){
        this->PopList = P.PopList;
        this->CurrentYear = P.CurrentYear;
        return *this;
    }
    ~Population();
    void Add(Member &m);
    void YearChange(int year);
    friend void PrintPop(Population &Pop);

protected:

    void Update();

};

void PrintPop(Population &Pop);

#endif