#ifndef SAMPLE_EMPLOYEE_H
#define SAMPLE_EMPLOYEE_H


class Employee {
public:
    Employee(int rate, bool separated, bool retired);

    int getRate() const;

    bool isSeparated() const;

    bool isRetired() const;

private:
    const int rate;
    const bool separated;
    const bool retired;
};


#endif //SAMPLE_EMPLOYEE_H