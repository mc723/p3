const char *project_name="mips1";
const char *project_file="mips1.ac";
const char *archc_version="2.0beta1";
const char *archc_options="-abi -dy ";

#include  <systemc.h>
#include  "mips1.H"
#include  "ac_tlm_mem.h"
#include  "ac_tlm_router.h"

using user::ac_tlm_mem;
using user::ac_tlm_router;

int sc_main(int ac, char *av[])
{
  //!  ISA simulator
  mips1          mips1_proc1("mips1");
  ac_tlm_mem     mem("mem");
  ac_tlm_router  rou("rou");

#ifdef AC_DEBUG
  ac_trace("mips1_proc1.trace");
#endif 

  //DAVID mips1_proc1.DM_port(mem.target_export);
  mips1_proc1.DM_port(rou.target_export); //CPU->ROU, DM=Data memory
  rou.MEM_port(mem.target_export);        //ROU->MEM

  mips1_proc1.init(ac, av);
  cerr << endl;

  sc_start();

  mips1_proc1.PrintStat();
  cerr << endl;

#ifdef AC_STATS
  mips1_proc1.ac_sim_stats.time = sc_simulation_time();
  mips1_proc1.ac_sim_stats.print();
#endif 

#ifdef AC_DEBUG
  ac_close_trace();
#endif 

  return mips1_proc1.ac_exit_status;
}
