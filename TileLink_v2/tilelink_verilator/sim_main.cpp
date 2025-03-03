#include "Vtlul_interconnect_tb.h"
#include "verilated.h"
#if VM_TRACE
#include "verilated_vcd_c.h"
#endif

vluint64_t main_time = 0;  // Current simulation time

// This function is called by $time in your Verilog design
double sc_time_stamp() {
    return main_time;
}

int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);

    // Create an instance of your testbench top-level module.
    Vtlul_interconnect_tb* top = new Vtlul_interconnect_tb;

#if VM_TRACE
    // Optional: Enable waveform tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace(tfp, 99);  // Trace depth of 99 levels
    tfp->open("sim.vcd");
#endif

    // Main simulation loop.
    // Your testbench's initial block drives the clocks and reset internally.
    // We simply call eval() repeatedly until the simulation finishes.
    while (!Verilated::gotFinish() && main_time < 200000) {
         top->eval();
         main_time++;
#if VM_TRACE
         tfp->dump(main_time);
#endif
    }

#if VM_TRACE
    tfp->close();
    delete tfp;
#endif

    top->final();
    delete top;
    return 0;
}
