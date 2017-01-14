// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

#include <cstdlib>
#include <cmath>
#include "Coordinates.hh"
#include "MonteCarlo.hh"
#include "Uniform.cc"

///// The following part contains the implementations of the MonteCarlo Class /////
///// Fill in below implementations of the constructors and other functions defined in MonteCarlo.hh

// constructor
MonteCarlo::MonteCarlo( Coordinates & xyz, float t ) :
  last_accepted_xyz_(xyz),
  temp_(t)
{
}

// destructor
MonteCarlo::~MonteCarlo()
{}

void
MonteCarlo::set_temperature( float t )
{
		temp_ = t;
}

float
MonteCarlo::get_temperature() const
{
  return temp_;
}

bool
MonteCarlo::boltzmann( Coordinates & new_xyz )
{
  // stored coords are in last_accepted_xyz_
  // new coords are passed as arg

  // compare the coords' z scores
  //

  // if "accept", meaning new xyz has lower z score,
  // set last_accepted_xyz_ to new coords  and return true

  // else reject, meaning new xyz has higher z score
  // overwrite passed in new_xyz with stored last_accepted_xyz_ and return false
  return true;
}

double
MonteCarlo::last_accepted_z() const
{
  return last_accepted_z_;
}
