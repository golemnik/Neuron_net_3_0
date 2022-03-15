#include "../Headers/Neuron.h"

using namespace std;

Neuron::Neuron () {
    output_charge = 0;
}

double Neuron::Set_core_full_charge (double new_charge) {
    core.Set_full_charge(new_charge);
}

void Neuron::Set_Output_charge (double new_output_charge) {
    output_charge = new_output_charge;
}

void Neuron::Set_name (string new_name) {
    name = new_name;
}

string Neuron::Get_name () {
    return name;
}

void Neuron::Set_mistake_charge (double new_mistake) {
    core.Set_mistake_charge(new_mistake);
}

void Neuron::Set_new_weight (double new_weight, int pos) {
    weights[pos] = new_weight;
}

double Neuron::Get_weight (int pos) {
    return weights[pos];
}

double Neuron::Get_output_charge () {
    return output_charge;
}

double Neuron::Get_core_full_charge () {
    return core.Get_full_charge();
}

double Neuron::Get_core_mistake_charge() {
    return core.Get_mistake_charge();
}

void Neuron::Connect_Neuron (Neuron* new_connect_ner, double new_weight) {
    uplinked.push_back(new_connect_ner);
    weights.push_back(new_weight);
}

bool Neuron::Check_connections () {
    if (uplinked.size() == 0) {
        return false;
    }
    else {
        return true;
    }
}

void Neuron::Obtain_Charge () {
    if (Check_connections()) {
        double temp_charge = 0;

        for (int i = 0; i < uplinked.size(); i++) {
            temp_charge = temp_charge + uplinked[i]->Get_output_charge() * weights[i];
            //cout << uplinked[i]->Get_name() << " | " << weights[i] << " " << uplinked[i]->Get_output_charge() << endl;
            //cout << name << " | temp_charge = " << temp_charge << "| " << uplinked[i]->Get_name() << " output_charge = " << uplinked[i]->Get_output_charge() << " | weight = " << weights[i] << endl;
        }
        //cout << " | temp_charge = " << temp_charge << endl;
        core.Set_full_charge(temp_charge);
    }
    else {
        cout << "no connections" << endl;
    }
}

void Neuron::Activate_Core () {
    output_charge = core.Activate_Function();
}

void Neuron::Activate_Neuron () {
    Obtain_Charge();
    Activate_Core();
}
//- - - - -
void Neuron::Back_Obtain_Charge () {
    if (Check_connections()) {
        for (int i = 0; i < uplinked.size(); i++) {
            uplinked[i]->Set_mistake_charge(uplinked[i]->Get_core_mistake_charge() + core.Get_mistake_charge() * weights[i] * uplinked[i]->Back_Activate_Core());
            //cout << uplinked[i]->Get_core_mistake_charge() << endl;
        }
    }
    else {
        cout << "no connections" << endl;
    }
}

double Neuron::Back_Activate_Core () {
    return core.Back_Activate_Function();
}

void Neuron::Correct_weights (double Ed_norm) {
    for (int i = 0; i < uplinked.size(); i++) {
        Set_new_weight(Ed_norm * Get_core_mistake_charge() * uplinked[i]->core.Activate_Function(), i);
    }
}

void Neuron::Back_Activate_Neuron (double Ed_norm) {
    Back_Obtain_Charge();
    Correct_weights(Ed_norm);
}

