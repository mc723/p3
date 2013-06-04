const char *project_name="mips1";
const char *project_file="mips1.ac";
const char *archc_version="2.0beta1";
const char *archc_options="-abi -dy ";

#include  <systemc.h>
#include  "mips1.H"
#include  "ac_tlm_mem.h"
#include  "ac_tlm_router.h"
#include  "ac_tlm_lock.h"

using user::ac_tlm_mem;
using user::ac_tlm_router;
using user::ac_tlm_lock;

int sc_main(int ac, char *av[])
{
  //!  ISA simulator

  mips1          mips1_proc1("mips1");
  mips1          mips1_proc2("mips2");
  mips1          mips1_proc3("mips3");
  mips1          mips1_proc4("mips4");
  mips1          mips1_proc5("mips5");
  mips1          mips1_proc6("mips6");
  mips1          mips1_proc7("mips7");
  mips1          mips1_proc8("mips8");



  ac_tlm_mem     mem("mem");
  ac_tlm_router  rou("rou");
  ac_tlm_lock	 lock("loc");

#ifdef AC_DEBUG
  ac_trace("mips1_proc1.trace");
#endif 

  //DAVID mips1_proc1.DM_port(mem.target_export);

  mips1_proc1.DM_port(rou.target_export); //CPU->ROU, DM=Data memory
  mips1_proc2.DM_port(rou.target_export);
  mips1_proc3.DM_port(rou.target_export);
  mips1_proc4.DM_port(rou.target_export);
  mips1_proc5.DM_port(rou.target_export);
  mips1_proc6.DM_port(rou.target_export);
  mips1_proc7.DM_port(rou.target_export);
  mips1_proc8.DM_port(rou.target_export);
  rou.MEM_port(mem.target_export);        //ROU->MEM
  rou.LOCK_port(lock.target_export);

  int copia_ac=ac;
  char copia[20][255];
  int tmp;
  for(tmp=0;tmp<ac;tmp++)
  {
  strcpy(copia[tmp],av[tmp]);
  }
  //cout<<copia[0]<<copia[1]<<endl;
  


  mips1_proc1.init(ac, av);
  for(tmp=0;tmp<ac;tmp++)
  {
  strcpy(av[tmp],copia[tmp]);
  }
  mips1_proc2.init(copia_ac,av);
  for(tmp=0;tmp<ac;tmp++)
  {
  strcpy(av[tmp],copia[tmp]);
  }
  mips1_proc3.init(copia_ac,av);
 for(tmp=0;tmp<ac;tmp++)
  {
  strcpy(av[tmp],copia[tmp]);
  }
  mips1_proc4.init(copia_ac,av);
 for(tmp=0;tmp<ac;tmp++)
  {
  strcpy(av[tmp],copia[tmp]);
  }
  mips1_proc5.init(copia_ac,av);
   for(tmp=0;tmp<ac;tmp++)
  {
  strcpy(av[tmp],copia[tmp]);
  } 
  mips1_proc6.init(copia_ac,av);
  for(tmp=0;tmp<ac;tmp++)
  {
  strcpy(av[tmp],copia[tmp]);
  }
  mips1_proc7.init(copia_ac,av);
  for(tmp=0;tmp<ac;tmp++)
  {
  strcpy(av[tmp],copia[tmp]);
  }
  mips1_proc8.init(copia_ac,av);


  cerr << endl;

  sc_start();

  mips1_proc1.PrintStat();
  mips1_proc2.PrintStat();
  mips1_proc3.PrintStat();
  mips1_proc4.PrintStat();
  mips1_proc5.PrintStat();
  mips1_proc6.PrintStat();
  mips1_proc7.PrintStat();
  mips1_proc8.PrintStat();
  cerr << endl;

#ifdef AC_STATS

  mips1_proc1.ac_sim_stats.time = sc_simulation_time();
  mips1_proc2.ac_sim_stats.time = sc_simulation_time();
  mips1_proc3.ac_sim_stats.time = sc_simulation_time();
  mips1_proc4.ac_sim_stats.time = sc_simulation_time();
  mips1_proc5.ac_sim_stats.time = sc_simulation_time();
  mips1_proc6.ac_sim_stats.time = sc_simulation_time();
  mips1_proc7.ac_sim_stats.time = sc_simulation_time();
  mips1_proc8.ac_sim_stats.time = sc_simulation_time();

  mips1_proc1.ac_sim_stats.print();
  mips1_proc2.ac_sim_stats.print();
  mips1_proc3.ac_sim_stats.print();
  mips1_proc4.ac_sim_stats.print();
  mips1_proc5.ac_sim_stats.print();
  mips1_proc6.ac_sim_stats.print();
  mips1_proc7.ac_sim_stats.print();
  mips1_proc8.ac_sim_stats.print();
#endif 

#ifdef AC_DEBUG
  ac_close_trace();
#endif 

  return mips1_proc1.ac_exit_status;
}
