#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>

//my library
#include "../Headers/Tests.h"
#include "../Headers/Neuron.h"

using namespace std;

void run_tests () {
    TEST_1_0();
    TEST_1_1();
    TEST_1_2();
    TEST_1_3();
    TEST_1_4();

    TEST_2_0();
    TEST_2_1();
    TEST_2_2();
    TEST_2_3();
    TEST_2_4();
    TEST_2_5();

    TEST_3_0();
    TEST_3_1();

    TEST_4_0();
    //TEST_4_1();
}

class InputNeuron : public Neuron {
public:
    InputNeuron (){
    }
    void Set_input (double new_charge) {
        Set_core_full_charge(new_charge);
    }
};

class OutputNeuron : public Neuron {
public:
    OutputNeuron () {

    }
    double Get_output () {
        return Get_output_charge();
    }
};

class NeuronNet {
private:
    double Ed_norm;
    double Pred_result;
    vector <InputNeuron> Input_ner;
    vector <Neuron> Hidden_ner;
    vector <OutputNeuron> Output_ner;

public:
    NeuronNet (vector <int> config) {
        Input_ner.resize(config[0]);
        Hidden_ner.resize(config[0]);
        Output_ner.resize(config[config.size()-1]);
    }
};

extern "C" int main() {
    //run_tests();

    //test commit

    TEST_4_1();

    return 0;
}
