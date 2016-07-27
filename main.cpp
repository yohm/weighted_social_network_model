#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <boost/random.hpp>
#include <boost/timer.hpp>
#include "wsn_nd_ld_aging.hpp"

double RunSimulator(
    long net_size,
    double p_tri,
    double p_jump,
    double delta,
    double p_nd,
    double p_ld,
    double aging,
    double w_th,
    long t_max,
    long seed
  );

int main( int argc, char** argv) {

  if( argc != 11 ) {
    std::cerr << "Usage : ./main.out <N> <p_tri> <p_jump> <delta> <p_nd> <p_ld> <aging> <w_th> <t_max> <seed>" << std::endl;
    exit(1);
  }

  long net_size = boost::lexical_cast<long>  ( argv[1] );
  double p_tri  = boost::lexical_cast<double>( argv[2] );
  double p_jump = boost::lexical_cast<double>( argv[3] );
  double delta  = boost::lexical_cast<double>( argv[4] );
  double p_nd   = boost::lexical_cast<double>( argv[5] );
  double p_ld   = boost::lexical_cast<double>( argv[6] );
  double aging  = boost::lexical_cast<double>( argv[7] );
  double w_th   = boost::lexical_cast<double>( argv[8] );
  long t_max    = boost::lexical_cast<double>( argv[9] );
  long seed     = boost::lexical_cast<double>( argv[10]);

  std::cerr << "Lists of given parameters are as follows:" << std::endl
            << "net_size:\t" << net_size << std::endl
            << "p_tri:\t" << p_tri << std::endl
            << "p_jump:\t" << p_jump << std::endl
            << "delta:\t" << delta << std::endl
            << "p_nd:\t" << p_nd << std::endl
            << "p_ld:\t" << p_ld << std::endl
            << "aging:\t" << aging << std::endl
            << "w_th:\t" << w_th << std::endl
            << "t_max:\t" << t_max << std::endl
            << "seed:\t" << seed << std::endl;

  WsnNDLDAging sim(seed, net_size, p_tri, p_jump, delta,
                   p_nd, p_ld, aging, w_th);
  boost::timer t;
  sim.Run(t_max);
  std::ofstream fout("net.edg");
  sim.PrintEdge(fout);
  fout.close();
  std::cerr << "elapsed time : " << t.elapsed() << std::endl;
}

