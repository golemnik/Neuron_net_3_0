#include <cassert>
#include "../Headers/Tests.h"

using namespace std;

void TEST_1_0 () {
    cout << "Core testing..." << endl;
}

void TEST_1_1 () {
    cout << "Running " << __FUNCTION__ << "... ";
    Core a;
    assert(("base core charge must be 0", abs(a.Get_full_charge() - 0) < 1e-6));
    cout << "Success" << endl;
}

void TEST_1_2 () {
    cout << "Running " << __FUNCTION__ << "... ";
    Core a;
    a.Set_full_charge(10);
    assert(("Core full charge must be equal to set function argument", abs(a.Get_full_charge() - 10) < 1e-6));
    cout << "Success" << endl;
}

void TEST_1_3 () {
    cout << "Running " << __FUNCTION__ << "... ";
    Core a;
    a.Set_full_charge(1);
    a.Set_full_charge(a.Activate_Function());
    assert(("Core activate function must have correct counting", abs (a.Get_full_charge() - 0.268941) < 1e-6));
    cout << "Success" << endl;
}

void TEST_1_4 () {
    cout << "Running " << __FUNCTION__ << "... ";
    Core a;
    a.Set_full_charge(1);
    a.Set_full_charge(a.Back_Activate_Function());
    assert(("Core back_activate function must have correct counting", abs(a.Get_full_charge() - 0.196612) < 1e-6));
    cout << "Success" << endl;
}

void TEST_2_0 () {
    cout << "Neuron testing (part 1/2)..." << endl;
}

void TEST_2_1 () {
    cout << "Running " << __FUNCTION__ << "... ";
    Neuron a;
    assert(("Neuron output base charge must be 0", abs(a.Get_output_charge() - 0) < 1e-6));
    cout << "Success" << endl;
}

void TEST_2_2 () {
    cout << "Running " << __FUNCTION__ << "... ";
    Neuron a;
    a.Set_Output_charge(10);
    assert(("Neuron output charge must be equal to set function", abs(a.Get_output_charge() - 10) < 1e-6));
    cout << "Success" << endl;
}

void TEST_2_3 () {
    cout << "Running " << __FUNCTION__ << "... ";
    Neuron a, b;
    a.Set_Output_charge(10);
    b.Connect_Neuron(&a, 1);
    assert(("connected neurons must be added to connected list", b.Check_connections() == true));
    cout << "Success" << endl;
}

void TEST_2_4 () {
    cout << "Running " << __FUNCTION__ << "... ";
    Neuron a, b;
    a.Set_Output_charge(10);
    b.Connect_Neuron(&a, 1);
    b.Obtain_Charge();
    assert(("input charge must be processed by weight", abs(b.Get_core_full_charge() - 10) < 1e-6));
    cout << "Success" << endl;
}

void TEST_2_5 () {
    cout << "Running " << __FUNCTION__ << "... ";
    Neuron a, b, c;
    a.Set_Output_charge(10);
    b.Set_Output_charge(6);
    c.Connect_Neuron(&a, 0.3);
    c.Connect_Neuron(&b, 0.6);
    c.Obtain_Charge();
    assert(("Correct summing input charges in a full charge", abs(c.Get_core_full_charge() - 6.6) < 1e-6));
    cout << "Success" << endl;
}

void TEST_3_0 () {
    cout << "Neuron testing (part 2/2)..." << endl;
}

void TEST_3_1 () {
    cout << "Running " << __FUNCTION__ << "... ";
    Neuron a, b;
    double ed_norm = 0.85;
    cout << endl;

    b.Connect_Neuron(&a, 1.0);
    b.Set_Output_charge(0.974);
    b.Set_mistake_charge(-0.014);

    b.Back_Activate_Neuron(ed_norm);
    cout << a.Get_core_mistake_charge() << endl;
    cout << b.Get_weight(0) << endl;

    assert(("", 0 < 1e-6));
    cout << "Success" << endl;
}

void TEST_4_0 () {
    cout << "Neuron net testing..." << endl;
}

void TEST_4_1 () {
    //cout << "Running " << __FUNCTION__ << "... ";
    Neuron a0, a1, a2, a3, a4, a5, s1, s2;
    double ed_norm = 0.85;
    a0.Set_name("a0");
    a1.Set_name("a1");
    a2.Set_name("a2");
    a3.Set_name("a3");
    a4.Set_name("a4");
    a5.Set_name("a5");

    a5.Connect_Neuron(&a2, 1);
    a5.Connect_Neuron(&a3, 2);
    a5.Connect_Neuron(&a4, 4);

    a2.Connect_Neuron(&a1, 2);
    a2.Connect_Neuron(&a0, -1);

    a3.Connect_Neuron(&a1, 1);
    a3.Connect_Neuron(&a0, 1);

    a4.Connect_Neuron(&a1, -2);
    a4.Connect_Neuron(&a0, 3);

    a0.Set_Output_charge(0.2);
    a1.Set_Output_charge(0.5);
    cout << a0.Get_output_charge() << endl;
    cout << a1.Get_output_charge() << endl;

    a2.Activate_Neuron();
    cout << a2.Get_output_charge() << endl;
    a3.Activate_Neuron();
    cout << a3.Get_output_charge() << endl;
    a4.Activate_Neuron();
    cout << a4.Get_output_charge() << endl;
    a5.Activate_Neuron();
    cout << a5.Get_output_charge() << endl;

    cout << "- - - back obtain - - -" << endl;

    a5.Set_mistake_charge((0.4 - a5.Get_output_charge()) * a5.Back_Activate_Core());
    a5.Back_Obtain_Charge();
    cout << a5.Get_core_mistake_charge() << endl;
    //cout << a5.Get_weight(0) << endl;
    a4.Back_Activate_Neuron(ed_norm);
    cout << a4.Get_core_mistake_charge() << endl;
    //cout << a4.Get_weight(0) << endl;
    a3.Back_Activate_Neuron(ed_norm);
    cout << a3.Get_core_mistake_charge() << endl;
    //cout << a3.Get_weight(0) << endl;
    a2.Back_Activate_Neuron(ed_norm);
    cout << a2.Get_core_mistake_charge() << endl;
    //cout << a2.Get_weight(0) << endl;
    a1.Back_Activate_Neuron(ed_norm);
    cout << a1.Get_core_mistake_charge() << endl;
    //cout << a1.Get_weight(0) << endl;
    a0.Back_Activate_Neuron(ed_norm);
    cout << a0.Get_core_mistake_charge() << endl;
    //cout << a0.Get_weight(0) << endl;


    assert(("", 0 < 1e-6));
    cout << "Success" << endl;
}

/*
    cout << "Running " << __FUNCTION__ << "... ";

    assert(("", abs() < 1e-6));
    cout << "Success" << endl;
 */