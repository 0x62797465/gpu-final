// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmem_serial_tb__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vmem_serial_tb::Vmem_serial_tb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : Vmem_serial_tb{_vcontextp__, _vcname__, true} {}

Vmem_serial_tb::Vmem_serial_tb(VerilatedContext* _vcontextp__, const char* _vcname__, bool _vcisRoot__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmem_serial_tb__Syms(contextp(), this, _vcname__, _vcisRoot__)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , rootp{&(vlSymsp->vlInst.TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vmem_serial_tb::Vmem_serial_tb(const char* _vcname__)
    : Vmem_serial_tb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmem_serial_tb::~Vmem_serial_tb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmem_serial_tb___024root___eval_debug_assertions(Vmem_serial_tb___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vmem_serial_tb___024root___eval_static(Vmem_serial_tb___024root* vlSelf);
void Vmem_serial_tb___024root___eval_initial(Vmem_serial_tb___024root* vlSelf);
VL_ATTR_COLD bool Vmem_serial_tb___024root___eval_stl(Vmem_serial_tb___024root* vlSelf, ::CData/*0:0*/ firstIteration);
void Vmem_serial_tb___024root___eval_sample(Vmem_serial_tb___024root* vlSelf);
bool Vmem_serial_tb___024root___eval_ico(Vmem_serial_tb___024root* vlSelf, ::CData/*0:0*/ firstIteration);
bool Vmem_serial_tb___024root___eval_act(Vmem_serial_tb___024root* vlSelf);
bool Vmem_serial_tb___024root___eval_inact(Vmem_serial_tb___024root* vlSelf);
bool Vmem_serial_tb___024root___eval_nba(Vmem_serial_tb___024root* vlSelf);
bool Vmem_serial_tb___024root___eval_obs(Vmem_serial_tb___024root* vlSelf);
bool Vmem_serial_tb___024root___eval_react(Vmem_serial_tb___024root* vlSelf);
void Vmem_serial_tb___024root___eval_postponed(Vmem_serial_tb___024root* vlSelf);
VL_ATTR_COLD void Vmem_serial_tb___024root___eval_final(Vmem_serial_tb___024root* vlSelf);
VL_ATTR_COLD void Vmem_serial_tb___024root___eval_dump_triggers__stl(Vmem_serial_tb___024root* vlSelf);
VL_ATTR_COLD void Vmem_serial_tb___024root___eval_dump_triggers__ico(Vmem_serial_tb___024root* vlSelf);
VL_ATTR_COLD void Vmem_serial_tb___024root___eval_dump_triggers__act(Vmem_serial_tb___024root* vlSelf);
VL_ATTR_COLD void Vmem_serial_tb___024root___eval_dump_triggers__nba(Vmem_serial_tb___024root* vlSelf);
VL_ATTR_COLD void Vmem_serial_tb___024root___eval_dump_triggers__obs(Vmem_serial_tb___024root* vlSelf);
VL_ATTR_COLD void Vmem_serial_tb___024root___eval_dump_triggers__react(Vmem_serial_tb___024root* vlSelf);

void Vmem_serial_tb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmem_serial_tb::eval_step\n"); );
    m_evalLoop.eval();
}

void Vmem_serial_tb::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vmem_serial_tb___024root___eval_debug_assertions(&(vlSymsp->vlInst.TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vmem_serial_tb::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
    vlSymsp->vlInst.TOP.__Vnontrivs.__VdlySched.cleanupForevered();
}

void Vmem_serial_tb::evalStatic() {
    Vmem_serial_tb___024root___eval_static(&(vlSymsp->vlInst.TOP));
}

void Vmem_serial_tb::evalInitial() {
    Vmem_serial_tb___024root___eval_initial(&(vlSymsp->vlInst.TOP));
}

bool Vmem_serial_tb::evalStl(bool firstIteration) {
    return Vmem_serial_tb___024root___eval_stl(&(vlSymsp->vlInst.TOP), firstIteration);
}

void Vmem_serial_tb::evalSample() {
    Vmem_serial_tb___024root___eval_sample(&(vlSymsp->vlInst.TOP));
}

bool Vmem_serial_tb::evalIco(bool firstIteration) {
    return Vmem_serial_tb___024root___eval_ico(&(vlSymsp->vlInst.TOP), firstIteration);
}

bool Vmem_serial_tb::evalAct() {
    return Vmem_serial_tb___024root___eval_act(&(vlSymsp->vlInst.TOP));
}

bool Vmem_serial_tb::evalInact() {
    return Vmem_serial_tb___024root___eval_inact(&(vlSymsp->vlInst.TOP));
}

bool Vmem_serial_tb::evalNba() {
    return Vmem_serial_tb___024root___eval_nba(&(vlSymsp->vlInst.TOP));
}

bool Vmem_serial_tb::evalObs() {
    return Vmem_serial_tb___024root___eval_obs(&(vlSymsp->vlInst.TOP));
}

bool Vmem_serial_tb::evalReact() {
    return Vmem_serial_tb___024root___eval_react(&(vlSymsp->vlInst.TOP));
}

void Vmem_serial_tb::evalPostponed() {
    Vmem_serial_tb___024root___eval_postponed(&(vlSymsp->vlInst.TOP));
}

void Vmem_serial_tb::evalFinal() {
    Vmem_serial_tb___024root___eval_final(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vmem_serial_tb::dumpTriggersStl() {
    Vmem_serial_tb___024root___eval_dump_triggers__stl(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vmem_serial_tb::dumpTriggersIco() {
    Vmem_serial_tb___024root___eval_dump_triggers__ico(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vmem_serial_tb::dumpTriggersAct() {
    Vmem_serial_tb___024root___eval_dump_triggers__act(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vmem_serial_tb::dumpTriggersNba() {
    Vmem_serial_tb___024root___eval_dump_triggers__nba(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vmem_serial_tb::dumpTriggersObs() {
    Vmem_serial_tb___024root___eval_dump_triggers__obs(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vmem_serial_tb::dumpTriggersReact() {
    Vmem_serial_tb___024root___eval_dump_triggers__react(&(vlSymsp->vlInst.TOP));
}

//============================================================
// Events and timing
bool Vmem_serial_tb::eventsPending() { return !vlSymsp->vlInst.TOP.__Vnontrivs.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vmem_serial_tb::nextTimeSlot() { return vlSymsp->vlInst.TOP.__Vnontrivs.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vmem_serial_tb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vmem_serial_tb::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmem_serial_tb::hierName() const { return vlSymsp->name(); }
const char* Vmem_serial_tb::modelName() const { return "Vmem_serial_tb"; }
unsigned Vmem_serial_tb::threads() const { return 1; }
void Vmem_serial_tb::prepareClone() const { contextp()->prepareClone(); }
void Vmem_serial_tb::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vmem_serial_tb::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vmem_serial_tb___024root__trace_decl_types(VerilatedVcd* tracep);

void Vmem_serial_tb___024root__trace_init_top(Vmem_serial_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmem_serial_tb___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmem_serial_tb___024root*>(voidSelf);
    Vmem_serial_tb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vmem_serial_tb___024root__trace_decl_types(tracep);
    Vmem_serial_tb___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmem_serial_tb___024root__trace_register(Vmem_serial_tb___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmem_serial_tb::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmem_serial_tb::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->vlInst.TOP), name(), false, 173);
    Vmem_serial_tb___024root__trace_register(&(vlSymsp->vlInst.TOP), stfp->spTrace());
}
