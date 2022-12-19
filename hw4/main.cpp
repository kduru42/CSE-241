#include "DayOfYear.hpp"
using namespace doy;

int main()
{
    list<DayOfYearSet::DayOfYear> a;
    list<DayOfYearSet::DayOfYear> b;
    a.push_back(DayOfYearSet::DayOfYear(1, 2));
    a.push_back(DayOfYearSet::DayOfYear(2, 7));
    a.push_back(DayOfYearSet::DayOfYear(3, 8));
    a.push_back(DayOfYearSet::DayOfYear(30, 7));
    a.push_back(DayOfYearSet::DayOfYear(8, 12));
    b.push_back(DayOfYearSet::DayOfYear(15, 12));
    b.push_back(DayOfYearSet::DayOfYear(12, 4));
    b.push_back(DayOfYearSet::DayOfYear(18, 5));
    b.push_back(DayOfYearSet::DayOfYear(14, 7));
    b.push_back(DayOfYearSet::DayOfYear(25, 11));

    cout << "testing DayOfYearSet constructor with set parameter\n";
    cout << "list a to set1\n";
    DayOfYearSet set1(a);
    cout << set1;
    cout << "list b to set1_b\n";
    DayOfYearSet set1_b(b);
    cout << set1_b;

    cout << "\n\n\ntesting DayOfYear copy constructor\n";
    cout << "copying set1 to set2\n";
    DayOfYearSet set2(set1);
    cout << set2;

    cout << "\n\n\ntesting operator=\n";
    cout << "assigning set1 to set3\n";
    DayOfYearSet set3 = set1;
    cout << set3;
    cout << "assigning set1_b to set3\n";
    set3 = set1_b;
    cout << set3;

    cout << "\n\n\ntesting operator==\n";
    cout << "checkig if set3 and set1_b are equal\n";
    if (set3 == set1_b)
        cout << "They are equal\n";
    else
        cout << "They are not equal\n";

    cout << "\n\n\ntesting operator!=\n";
    cout << "checking if set3 and set1 are not equal\n";
    if (set3 != set1)
        cout << "They are not equal\n";
    else
        cout << "They are equal\n";

    cout << "\n\n\ntesting remove function\n";
    cout << "set3 before removing the element:\n";
    cout << set3;
    cout << "set3 after removing the element:\n";
    set3.remove(DayOfYearSet::DayOfYear(25, 11));
    cout << set3;
    cout << "and removing another element\n";
    set3.remove(DayOfYearSet::DayOfYear(14, 7));
    cout << set3;

    cout << "\n\n\ntesting size function\n";
    cout << "Size of set3 : " << set3.size() << endl;
    cout << "Size of set2 : " << set2.size() << endl;

    cout << "\n\n\ntesting operator+\n";
    cout << "set3 before adding an element\n";
    cout << set3;
    cout << "adding a new day to set3\n";
    set3 = set3 + set2.get_list()[0];
    cout << set3;
    cout << "adding another element to set3\n";
    set3 = set3 + set2.get_list()[1];
    cout << set3;

    cout << "\n\n\ntesting operator-\n";
    cout << "removing first element that we added to set3\n";
    set3 = set3 - set2.get_list()[0];
    cout << set3;
    cout << "and removing second element\n";
    set3 = set3 - set2.get_list()[1];
    cout << set3;

    DayOfYearSet set4(a);
    cout << "\n\n\ntestinf operator^\n";
    set2 = set2 + set3.get_list()[0];
    set2 = set2 + set3.get_list()[1];
    cout << "set3: \n" << set3;
    cout << "set2: \n" << set2;
    cout << "printing intersection of set3 and set2\n";
    set4 = set3 ^ set2;
    cout << set4;
    cout << "adding more elements\n";
    set2 = set2 + set3.get_list()[2];
    set4 = set3 ^ set2;
    cout << set4;


    cout << "\n\n\ntesting operator!\n";
    cout << "printing complement of set3\n";
    set4 = !set3;
    cout << set4;
    cout << "printing complement of set2\n";
    set4 = !set2;
    cout << set4;

    return (0);
}