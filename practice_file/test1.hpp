#ifndef TEST1_HPP
#define TEST1_HPP

#include <iostream>
#include <string>

using namespace std;

/* Variables:
 *      (1) task = string of the work you need
 *      (2) importance = levesl of importance
 *              1 = IMPORTANT AF
 *              2 = IMPORTANT
 *              3 = MODERATELY IMPORTANT
 *              4 = NOT THAT IMPORTANT
 *              5 = LEISURELY IMPORTANT
 */


class Todo{
    private:
        // string task;
        // unsigned int importance;
    public: 
        Todo() : task(""), importance(0) {}
        string getTask() const;        
        unsigned int getImportance() const;
        bool operator<(const Todo& other);
        
        string task;
        unsigned int importance;

};
ostream& operator<<(ostream&, const Todo&) __attribute__((weak));
ostream& operator<<(ostream &out, const Todo &a){
    out << a.getTask() << "\n";
    out << a.getImportance() << "\n";
    return out;
}



#endif