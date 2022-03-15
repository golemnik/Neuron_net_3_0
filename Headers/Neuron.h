#include <iostream>
#include <vector>
//#include <cmath>

#include "Core.h"

using namespace std;

class Neuron {
private:
    string name;
    Core core;
    vector <Neuron*> uplinked;
    vector <double> weights;
    double output_charge;
public:
    Neuron ();

    double Set_core_full_charge (double new_charge);

    void Set_name (string new_name);

    string Get_name ();

    void Set_Output_charge (double new_output_charge);

    void Set_mistake_charge (double new_mistake);

    void Set_new_weight (double new_weight, int pos);

    double Get_weight (int pos);

    double Get_output_charge ();

    double Get_core_full_charge ();

    double Get_core_mistake_charge();

    void Connect_Neuron (Neuron *new_connect_ner, double new_weight);

    bool Check_connections ();

    void Obtain_Charge ();

    void Activate_Core ();

    void Activate_Neuron ();

    void Back_Obtain_Charge ();

    double Back_Activate_Core ();

    void Correct_weights (double Ed_norm);

    void Back_Activate_Neuron (double Ed_norm);

};
