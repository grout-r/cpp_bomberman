# include "Exception.hh"

Error::Error(std::string const & what) throw ()
{
  this->message = what;
}

Error::~Error() throw ()
{}

const char *			Error::what() const throw ()
{
  return (this->message.c_str());
}
