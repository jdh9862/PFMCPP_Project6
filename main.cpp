/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */


#include <iostream>
#include <string>

struct T
{
    T(int inValue, const char* inName) : value(inValue), name(inName) {}   //1
    //2
    int value;
    //3
    std::string name;
};

struct Comparator                                //4
{
    T* compare(T& a, T& b) //5
    {
        if (a.value < b.value) return &a;
        if (a.value > b.value) return &b;
        return nullptr;
    }
};

struct U
{
    float first{0}, second{0};

    float update(const float& updatedValue)      //12
    {
        std::cout << "U's first value: " << first << std::endl;
        first = updatedValue;
        std::cout << "U's first updated value: " << first << std::endl;
        while (std::abs(second - first) > 0.001f)
        {
            second += 0.00001f;
        }
        std::cout << "U's second updated value: " << second << std::endl;
        return second * first;
    }
};

struct Updater
{
    static float update(U& that, const float& updatedValue)        //10
    {
        std::cout << "U's first value: " << that.first << std::endl;
        that.first = updatedValue;
        std::cout << "U's first updated value: " << that.first << std::endl;
        while (std::abs(that.second - that.first) > 0.001f)
        {
            /*
             write something that makes the distance between that->second and that->first get smaller
             */
            that.second += 0.00001f;
        }
        std::cout << "U's second updated value: " << that.second << std::endl;

        return that.second * that.first;
    }
};

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T t1(1, "first_T");                                             //6
    T t2(2, "second_T");                                             //6

    Comparator f;                                            //7
    auto *smaller = f.compare(t1, t2);                              //8
    if (smaller == nullptr)
    {
        std::cout << "the objects were equal" << std::endl;
    }
    else
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }

    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << Updater::update(u1, updatedValue)
              << std::endl;                  //11

    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.update(updatedValue) << std::endl;
}
