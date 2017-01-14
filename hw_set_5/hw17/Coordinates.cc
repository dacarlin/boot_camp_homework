// -*- mode:c++;tab-width:2;indent-tabs-mode:t;show-trailing-whitespace:t;rm-trailing-spaces:t -*-
// vi: set ts=2 noet:

#include <iostream>
#include <string> 
#include <stdexcept>
#include "Landscape.cc"
#include "Coordinates.hh"

Coordinates::Coordinates()
{
  set_landscape_function( "sum_squares" );
}

Coordinates::Coordinates( std::string fxn )
{
  set_landscape_function( fxn );
}

Coordinates::Coordinates( Coordinates & src )
{
  landscape_ = src.landscape_;
  landscape_function_name_ = src.landscape_function_name_;

  set_x( src.x_ );
  set_y( src.y_ );
  update_z();
}

Coordinates::~Coordinates() {}

double
Coordinates::get_x()
{
  return x_;
}

void
Coordinates::set_x( double x )
{
  x_ = x;
  update_z();
}

void
Coordinates::modify_x( double delta )
{
  x_ += delta;
  update_z();
}

double
Coordinates::get_y()
{
  return y_;
}

void
Coordinates::set_y( double y )
{
  y_ = y;
  update_z();
}

void
Coordinates::modify_y( double delta )
{
  y_ += delta;
  update_z();
}

double
Coordinates::get_z()
{
  return z_;
}

void
Coordinates::update_z()
{
  // use the landscape to calculate new z
  // you need x and y to start
  z_ = landscape_->calculate_z( x_, y_ );
}

std::string
Coordinates::get_landscape_function()
{
  return landscape_function_name_;
}

void
Coordinates::set_landscape_function(std::string new_function) {

	landscape_function_name_ = new_function;

	if ( landscape_function_name_ == "sum_squares" ) {
		landscape_ = std::shared_ptr<Landscape> ( new SumSquares() );
	} else if ( landscape_function_name_ == "rastrigin" ) {
		landscape_ = std::shared_ptr<Landscape> ( new Rastrigin() );
	} else if ( landscape_function_name_ == "ackley" ) {
		landscape_ = std::shared_ptr<Landscape> ( new Ackley() );
	} else {
		throw std::invalid_argument( "The function '" + new_function + "' hasn't been defined! Valid options are 'sum_squares', 'rastrigin', and 'ackley'" );
	}
}
