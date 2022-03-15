#include "../Headers/Core.h"
#include <cmath>

using namespace std;

Core::Core () {
    full_charge = 0.0;
}

void Core::Set_full_charge (double new_full_charge) {
    full_charge = new_full_charge;
}

double Core::Get_full_charge () {
    return full_charge;
}

double Core::Activate_Function () {
    return 1 / (1 + exp(-1*full_charge));
}

double Core::Back_Activate_Function () {
    return Activate_Function() * (1.0 - Activate_Function());
}

double Core::Set_mistake_charge (double new_mistake_charge) {
    return mistake_charge = new_mistake_charge;
}

double Core::Get_mistake_charge () {
    return mistake_charge;
}