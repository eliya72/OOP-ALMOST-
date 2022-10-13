#include <iostream>

class Test
{
private:
    std::string name;
    std::string task;

public:
    Test(std::string n, std::string a)
    {
        name = n;
        task = a;
    }

    Test()
    {
        name = "";
        task = "";
    }

    auto getName() -> std::string
    {
        return name;
    }

    void setName(std::string n)
    {
        name = n;
    }

    auto getTask() -> std::string
    {
        return task;
    }

    void setTask(std::string a)
    {
        task = a;
    }

    ~Test()
    {
        std::cout << "collapsed" << std::endl;
    }
};

class Exam : public Test
{
private:
    std::string score;

public:
    Exam(std::string n, std::string a, std::string r) : Test(n, a)
    {
        score = r;
    }

    Exam() : Test()
    {
        score = "";
    }

    auto getScore() -> std::string
    {
        return score;
    }

    void setScore(std::string r)
    {
        score = r;
    }

    void print()
    {
        std::cout << "Name: " << getName() << ";  Tasks: " << getTask() << ";  Score: " << getScore() << std::endl;
    }
};

class FinalExam : public Exam
{
private:
    std::string held;

public:
    FinalExam(std::string n, std::string a, std::string r, std::string p) : Exam(n, a, r)
    {
        held = p;
    }

    FinalExam() : Exam()
    {
        held = "";
    }

    auto getHeld() -> std::string
    {
        return held;
    }

    void setHeld(std::string p)
    {
        held = p;
    }

    void print()
    {
        std::cout << "Name: " << getName() << ";  Tasks: " << getTask() << ";  Is held: " << getHeld() << std::endl;
    }
};

class Hire : public Test
{
private:
    std::string achievement;

public:
    Hire(std::string n, std::string a, std::string s) : Test(n, a)
    {
        achievement = s;
    }

    Hire() : Test()
    {
        achievement = "";
    }

    auto getSpecialty() -> std::string
    {
        return achievement;
    }

    void setSpecialty(std::string s)
    {
        achievement = s;
    }

    void print()
    {
        std::cout << "Test: " << getName() << ";  Tasks: " << getTask() << ";  Specialty: " << getSpecialty() << std::endl;
    }
};

int main()
{
    FinalExam proba("Loser", "20000", "001", "by Government");
    proba.print();
    Hire people("Lev", "10", "Producer");
    people.print();
}