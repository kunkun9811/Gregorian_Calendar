#ifndef TODO_HPP
#define TODO_HPP

/* Variables:
 *      (1) task = string of the work you need
 *      (2) importance = level of importance
 *              1 = IMPORTANT AF
 *              2 = IMPORTANT
 *              3 = MODERATELY IMPORTANT
 *              4 = NOT THAT IMPORTANT
 *              5 = LEISURELY IMPORTANT
 */

#include <iostream>
#include <string>

using namespace std;


class Todo{
    private:
        string task;
        unsigned int importance;
    public: 
        Todo() : task(""), importance(0) {}
};

#endif