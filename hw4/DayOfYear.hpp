#ifndef _DAY_OF_YEAR_HPP_
# define _DAY_OF_YEAR_HPP_

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <list>
using namespace std;

namespace doy
{
    class DayOfYearSet
    {
        public:
        class DayOfYear
        {
            public:
                DayOfYear() {};
                DayOfYear(int o_day, int o_month);
                inline int    get_day() const {return (day);};
                inline int    get_month() const {return (month);};
                void          set_day(int day);
                void          set_month(int month);
            
            private:
                int day;
                int month;
        };
        DayOfYearSet() {};
        DayOfYearSet(list<DayOfYear> &set);
        DayOfYearSet(const DayOfYearSet &other);
        ~DayOfYearSet();
        DayOfYearSet&           operator=(const DayOfYearSet& other);
        friend std::ostream&    operator<<(std::ostream &output, const doy::DayOfYearSet& obj);
        bool                    operator==(const DayOfYearSet &other) const;
        bool                    operator!=(const DayOfYearSet &other) const;
        DayOfYearSet            &operator+(const DayOfYear &day);
        DayOfYearSet            &operator-(const DayOfYear &day);
        DayOfYearSet            operator^(const DayOfYearSet &other) const;
        DayOfYearSet            operator!() const;
        DayOfYear               &operator[](int i) const;
        void                    remove(const DayOfYear &day);
        inline DayOfYear        *get_list() const {return (lst);};
        inline int              size() const {return (sze);};

            

        private:
            DayOfYear   *lst;
            int         sze;
    };
}

#endif