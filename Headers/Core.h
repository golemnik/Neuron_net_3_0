#include <iostream>

class Core {
private:
    double full_charge;
    double mistake_charge;
public:
    Core ();

    void Set_full_charge (double new_full_charge);

    double Get_full_charge ();

    double Activate_Function ();

    double Back_Activate_Function ();

    double Set_mistake_charge (double new_mistake_charge);

    double Get_mistake_charge ();
};
