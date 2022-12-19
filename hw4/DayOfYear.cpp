#include "DayOfYear.hpp"
using namespace doy;
using namespace std;


DayOfYearSet::DayOfYear::DayOfYear(int o_day, int o_month)
{
    if (!(o_month >= 1 && o_month <= 12))
    {
        cout << "Incorrect date!!";
        exit(1);        
    }
    if (o_month == 1 || o_month == 3 || o_month == 5 || o_month == 7
            || o_month == 8 || o_month == 10 || o_month == 12)
        if (!(o_day >= 0 && o_day <= 31))
        {
            cout << "Incorrect date!!";
            exit(1);
        }
    else if (o_month == 4 || o_month == 6 || o_month == 9 || o_month == 11)
        if (!(o_day >= 0 && o_day <= 30))
        {
            cout << "Incorrect date!!";
            exit(1);
        }
    else if (o_month == 2)
        if (!(o_day >= 0 && o_day <= 29))
        {
            cout << "Incorrect date!!";
            exit(1);
        }
    day = o_day;
    month = o_month;    
}

void DayOfYearSet::DayOfYear::set_day(int day)
{
    this->day = day;
}

void DayOfYearSet::DayOfYear::set_month(int month)
{
    this->month = month;
}

DayOfYearSet::~DayOfYearSet()
{
    delete [] lst;
}

DayOfYearSet::DayOfYearSet(list<DayOfYear> &set)
{
    sze = set.size();
    lst = new DayOfYear [sze];
    list<DayOfYear>::iterator it;
    int i = 0;
    for (it = set.begin(); it != set.end(); ++it)
    {
        lst[i] = *it;
        i++;
    }
    i = 0;
    for (it = set.begin(); it != set.end(); ++it)
    {
        lst[i].set_day((*it).get_day());
        lst[i].set_month((*it).get_month());
        i++;
    }
}

DayOfYearSet::DayOfYearSet(const DayOfYearSet &other)
{
    sze = other.sze;
    decltype(lst) temp = new DayOfYear [sze];
    for (int i = 0; i < sze; i++)
        temp[i] = other.get_list()[i];
    this->lst = temp;
}

DayOfYearSet& DayOfYearSet::operator=(const DayOfYearSet& other)
{
    sze = other.sze;
    auto temp = new DayOfYear [sze];
    for (int i = 0; i < sze; i++)
        temp[i] = other.get_list()[i];
    delete [] this->lst;
    this->lst = temp;
    return (*this);
}

bool DayOfYearSet::operator==(const DayOfYearSet &other) const
{
    if ((*this).size() != other.size())
        return (false);
    vector<pair<int, int>> temp_arr1;
    vector<pair<int, int>> temp_arr2;
    for (int i = 0; i < size(); i++)
        temp_arr1.push_back(make_pair(get_list()[i].get_day(), get_list()[i].get_month()));
    for (int i = 0; i < other.size(); i++)
        temp_arr2.push_back(make_pair(other.get_list()[i].get_day(), other.get_list()[i].get_month()));
    sort(temp_arr1.begin(), temp_arr1.end());
    sort(temp_arr2.begin(), temp_arr2.end());
    for (int i = 0; i < size(); i++)
        if (temp_arr1[i] != temp_arr2[i])
            return (false);
    return (true);
}

bool DayOfYearSet::operator!=(const DayOfYearSet &other) const
{
    return (!((*this) == other));
}

void DayOfYearSet::remove(const DayOfYear &day)
{
    decltype(lst) temp = new DayOfYear [sze - 1];
    int j = 0;
    for (int i = 0; i < sze; i++)
    {
        if (!(lst[i].get_day() == day.get_day() && lst[i].get_month() == day.get_month()))
        {
            temp[j] = lst[i];
            j++;
        }
    }
    delete [] lst;
    lst = temp;
    sze--;
}

DayOfYearSet& DayOfYearSet::operator+(const DayOfYear &day)
{
    for (int i = 0; i < sze; i++)
        if (lst[i].get_day() == day.get_day() && lst[i].get_month() == day.get_month())
        {
            cout << "Dublicate detected during adding!!" << endl;
            return (*this);
        }
    decltype(lst) temp = new DayOfYear [sze + 1];
    for (int i = 0; i < sze; i++)
        temp[i] = lst[i];
    temp[sze] = day;
    delete [] lst;
    lst = temp;
    sze++;
    return (*this); 
}

DayOfYearSet& DayOfYearSet::operator-(const DayOfYear &day)
{
    decltype(lst) temp = new DayOfYear [sze - 1];
    int j = 0;
    for (int i = 0; i < sze; i++)
    {
        if (!(lst[i].get_day() == day.get_day() && lst[i].get_month() == day.get_month()))
        {
            temp[j] = lst[i];
            j++;
        }
    }
    delete [] lst;
    lst = temp;
    sze--;
    return (*this);    
}

DayOfYearSet DayOfYearSet::operator^(const DayOfYearSet &other) const
{
    list<DayOfYearSet::DayOfYear> temp_lst;
    for (int i = 0; i < size(); i++)
        for (int j = 0; j < other.size(); j++)
            if (lst[i].get_day() == other.get_list()[j].get_day() && 
                    lst[i].get_month() == other.get_list()[j].get_month())
                        temp_lst.push_back(lst[i]);
    return (DayOfYearSet(temp_lst));
}

DayOfYearSet DayOfYearSet::operator!() const
{
    list<DayOfYearSet::DayOfYear> whole_year;
    for (int i = 1; i <= 31; i++)
    {
        whole_year.push_back(DayOfYearSet::DayOfYear(i, 1));
        for (int j = 0; j < sze; j++)
            if (lst[j].get_day() == i && lst[j].get_month() == 1)
            {
                whole_year.pop_back();
                break;
            }
    }
    for (int i = 1; i <= 29; i++)
    {
        whole_year.push_back(DayOfYearSet::DayOfYear(i, 2));
        for (int j = 0; j < sze; j++)
            if (lst[j].get_day() == i && lst[j].get_month() == 2)
            {
                whole_year.pop_back();
                break;
            }
    }
    for (int i = 1; i <= 31; i++)
    {
        whole_year.push_back(DayOfYearSet::DayOfYear(i, 3));
        for (int j = 0; j < sze; j++)
            if (lst[j].get_day() == i && lst[j].get_month() == 3)
            {
                whole_year.pop_back();
                break;
            }
    }
    for (int i = 1; i <= 30; i++)
    {
        whole_year.push_back(DayOfYearSet::DayOfYear(i, 4));
        for (int j = 0; j < sze; j++)
            if (lst[j].get_day() == i && lst[j].get_month() == 4)
            {
                whole_year.pop_back();
                break;
            }
    }
    for (int i = 1; i <= 31; i++)
    {
        whole_year.push_back(DayOfYearSet::DayOfYear(i, 5));
        for (int j = 0; j < sze; j++)
            if (lst[j].get_day() == i && lst[j].get_month() == 5)
            {
                whole_year.pop_back();
                break;
            }
    }
    for (int i = 1; i <= 30; i++)
    {
        whole_year.push_back(DayOfYearSet::DayOfYear(i, 6));
        for (int j = 0; j < sze; j++)
            if (lst[j].get_day() == i && lst[j].get_month() == 6)
            {
                whole_year.pop_back();
                break;
            }
    }
    for (int i = 1; i <= 31; i++)
    {
        whole_year.push_back(DayOfYearSet::DayOfYear(i, 7));
        for (int j = 0; j < sze; j++)
            if (lst[j].get_day() == i && lst[j].get_month() == 7)
            {
                whole_year.pop_back();
                break;
            }
    }
    for (int i = 1; i <= 31; i++)
    {
        whole_year.push_back(DayOfYearSet::DayOfYear(i, 8));
        for (int j = 0; j < sze; j++)
            if (lst[j].get_day() == i && lst[j].get_month() == 8)
            {
                whole_year.pop_back();
                break;
            }
    }
    for (int i = 1; i <= 30; i++)
    {
        whole_year.push_back(DayOfYearSet::DayOfYear(i, 9));
        for (int j = 0; j < sze; j++)
            if (lst[j].get_day() == i && lst[j].get_month() == 9)
            {
                whole_year.pop_back();
                break;
            }
    }
    for (int i = 1; i <= 31; i++)
    {
        whole_year.push_back(DayOfYearSet::DayOfYear(i, 10));
        for (int j = 0; j < sze; j++)
            if (lst[j].get_day() == i && lst[j].get_month() == 10)
            {
                whole_year.pop_back();
                break;
            }
    }
    for (int i = 1; i <= 30; i++)
    {
        whole_year.push_back(DayOfYearSet::DayOfYear(i, 11));
        for (int j = 0; j < sze; j++)
            if (lst[j].get_day() == i && lst[j].get_month() == 11)
            {
                whole_year.pop_back();
                break;
            }
    }
    for (int i = 1; i <= 31; i++)
    {
        whole_year.push_back(DayOfYearSet::DayOfYear(i, 12));
        for (int j = 0; j < sze; j++)
            if (lst[j].get_day() == i && lst[j].get_month() == 12)
            {
                whole_year.pop_back();
                break;
            }
    }
    return (DayOfYearSet(whole_year));
}

DayOfYearSet::DayOfYear& DayOfYearSet::operator[](int i) const
{
    if (!(i >= 0 && i < sze))
    {
        cout << "Attempt to access out of range" << endl;
        exit(1);
    }
    return (lst[i]);
}

namespace doy
{
    std::ostream& operator<<(std::ostream &output, const doy::DayOfYearSet &obj)
    {
        for (int i = 0; i < obj.size(); i++)
        {
            output << i + 1;
            output << ". Day's date: Day: ";
            output << obj.get_list()[i].get_day();
            output << " Month: ";
            output << obj.get_list()[i].get_month() << endl;
        }
        return (output);
    }
}
