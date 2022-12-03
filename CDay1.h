
#include <string>
#include <vector>
#include <map>
#include <set>

class CCalorie
{
    private:
        std::vector<unsigned int> calories;
        

    public :
        CCalorie();
        void addCalorie(unsigned int data);
        unsigned int totalSumCalorie();
        virtual ~CCalorie();

};


class CDay1
{
    private:
        std::map<unsigned int, CCalorie> elfData;
        std::set<unsigned int> totalCalories;

    public:
        CDay1();
        void addElf(std::vector<std::string> elfData);
        unsigned int calculateHighestCalories();
        virtual ~CDay1();

};