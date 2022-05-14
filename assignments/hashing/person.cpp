#include "person.h"

std::string Person::get_name() const{ return first+" "+last; }

int Person::get_id() const{ return idnum; }