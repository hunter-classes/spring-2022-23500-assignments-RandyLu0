#include "person.h"

std::string Person::get_name() const{ return last+", "+first; }

int Person::get_id() const{ return idnum; }